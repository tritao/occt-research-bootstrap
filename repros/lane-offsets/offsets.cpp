#include <BRepBndLib.hxx>
#include <BRepOffset_Error.hxx>
#include <BRepOffset_MakeOffset.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <Bnd_Box.hxx>
#include <GeomAbs_JoinType.hxx>
#include <Message_ProgressRange.hxx>
#include <Standard_VersionInfo.hxx>
#include <TopExp.hxx>
#include <TopExp_Explorer.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Shape.hxx>

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include <vector>

namespace
{

std::string JsonEscape(const std::string& s)
{
  std::ostringstream oss;
  oss << '"';
  for (unsigned char c : s)
  {
    switch (c)
    {
      case '\\': oss << "\\\\"; break;
      case '"': oss << "\\\""; break;
      case '\b': oss << "\\b"; break;
      case '\f': oss << "\\f"; break;
      case '\n': oss << "\\n"; break;
      case '\r': oss << "\\r"; break;
      case '\t': oss << "\\t"; break;
      default:
        if (c < 0x20)
        {
          oss << "\\u" << std::hex << std::setw(4) << std::setfill('0') << int(c) << std::dec;
        }
        else
        {
          oss << char(c);
        }
        break;
    }
  }
  oss << '"';
  return oss.str();
}

const char* JoinTypeName(const GeomAbs_JoinType jt)
{
  switch (jt)
  {
    case GeomAbs_Arc: return "GeomAbs_Arc";
    case GeomAbs_Tangent: return "GeomAbs_Tangent";
    case GeomAbs_Intersection: return "GeomAbs_Intersection";
    default: return "UNKNOWN";
  }
}

const char* ModeName(const BRepOffset_Mode mode)
{
  switch (mode)
  {
    case BRepOffset_Skin: return "BRepOffset_Skin";
    case BRepOffset_Pipe: return "BRepOffset_Pipe";
    case BRepOffset_RectoVerso: return "BRepOffset_RectoVerso";
    default: return "UNKNOWN";
  }
}

const char* ErrorName(const BRepOffset_Error err)
{
  switch (err)
  {
    case BRepOffset_NoError: return "BRepOffset_NoError";
    case BRepOffset_UnknownError: return "BRepOffset_UnknownError";
    case BRepOffset_BadNormalsOnGeometry: return "BRepOffset_BadNormalsOnGeometry";
    case BRepOffset_C0Geometry: return "BRepOffset_C0Geometry";
    case BRepOffset_NullOffset: return "BRepOffset_NullOffset";
    case BRepOffset_NotConnectedShell: return "BRepOffset_NotConnectedShell";
    case BRepOffset_CannotTrimEdges: return "BRepOffset_CannotTrimEdges";
    case BRepOffset_CannotFuseVertices: return "BRepOffset_CannotFuseVertices";
    case BRepOffset_CannotExtentEdge: return "BRepOffset_CannotExtentEdge";
    case BRepOffset_UserBreak: return "BRepOffset_UserBreak";
    case BRepOffset_MixedConnectivity: return "BRepOffset_MixedConnectivity";
    default: return "UNKNOWN";
  }
}

struct ShapeStats
{
  int solids = 0;
  int shells = 0;
  int faces = 0;
  int edges = 0;
  int vertices = 0;
  double xmin = 0.0, ymin = 0.0, zmin = 0.0;
  double xmax = 0.0, ymax = 0.0, zmax = 0.0;
};

ShapeStats ComputeStats(const TopoDS_Shape& s)
{
  ShapeStats st;

  TopTools_IndexedMapOfShape tmp;
  TopExp::MapShapes(s, TopAbs_SOLID, tmp);
  st.solids = tmp.Extent();
  tmp.Clear();
  TopExp::MapShapes(s, TopAbs_SHELL, tmp);
  st.shells = tmp.Extent();
  tmp.Clear();
  TopExp::MapShapes(s, TopAbs_FACE, tmp);
  st.faces = tmp.Extent();
  tmp.Clear();
  TopExp::MapShapes(s, TopAbs_EDGE, tmp);
  st.edges = tmp.Extent();
  tmp.Clear();
  TopExp::MapShapes(s, TopAbs_VERTEX, tmp);
  st.vertices = tmp.Extent();

  Bnd_Box b;
  BRepBndLib::Add(s, b);
  if (!b.IsVoid())
  {
    b.Get(st.xmin, st.ymin, st.zmin, st.xmax, st.ymax, st.zmax);
  }
  return st;
}

void WriteShapeStats(std::ostream& out, const ShapeStats& st)
{
  out << "{\n";
  out << "      \"counts\": {"
      << "\"solids\": " << st.solids << ", "
      << "\"shells\": " << st.shells << ", "
      << "\"faces\": " << st.faces << ", "
      << "\"edges\": " << st.edges << ", "
      << "\"vertices\": " << st.vertices << "},\n";
  out << "      \"bbox\": {\"min\": ["
      << std::setprecision(17) << st.xmin << ", " << st.ymin << ", " << st.zmin << "], "
      << "\"max\": [" << st.xmax << ", " << st.ymax << ", " << st.zmax << "]}\n";
  out << "    }";
}

struct Args
{
  std::filesystem::path artifactsDir;
};

Args ParseArgs(int argc, char** argv)
{
  Args a;
  a.artifactsDir = "repros/lane-offsets/golden/artifacts";
  for (int i = 1; i < argc; ++i)
  {
    std::string_view v(argv[i]);
    if (v == "--artifacts-dir" && i + 1 < argc)
    {
      a.artifactsDir = argv[++i];
      continue;
    }
    if (v == "-h" || v == "--help")
    {
      std::cout << "usage: offsets [--artifacts-dir <dir>]\n";
      std::exit(0);
    }
    std::cerr << "unknown arg: " << v << "\n";
    std::exit(2);
  }
  return a;
}

struct CaseSummary
{
  std::string name;
  std::string kind;
  bool is_done = false;
  std::string error_name;
  std::string model_rel;
};

int CountList(const TopTools_ListOfShape& lst)
{
  int n = 0;
  for (TopTools_ListIteratorOfListOfShape it(lst); it.More(); it.Next())
    n += 1;
  return n;
}

void LastImages(const BRepAlgo_Image& img, const TopoDS_Shape& s, TopTools_ListOfShape& out)
{
  img.LastImage(s, out);
}

bool WriteModelJson(const Args& args,
                    const char* caseName,
                    const char* kind,
                    const TopoDS_Shape& inputShape,
                    const double offset,
                    const double tol,
                    const BRepOffset_Mode mode,
                    const bool intersection,
                    const bool selfInter,
                    const GeomAbs_JoinType joinType,
                    const bool removeIntEdges,
                    const bool precheckOk,
                    const TopoDS_Shape& badShape,
                    const BRepOffset_MakeOffset& algo,
                    const TopoDS_Shape& resultShape)
{
  const std::filesystem::path dir = args.artifactsDir / caseName;
  std::filesystem::create_directories(dir);
  const std::filesystem::path outPath = dir / "model.json";

  std::ofstream out(outPath, std::ios::binary);
  if (!out)
    return false;
  out.imbue(std::locale::classic());

  const ShapeStats inputStats = ComputeStats(inputShape);
  const ShapeStats badStats = badShape.IsNull() ? ShapeStats{} : ComputeStats(badShape);
  const ShapeStats resultStats = resultShape.IsNull() ? ShapeStats{} : ComputeStats(resultShape);

  TopTools_IndexedMapOfShape inputFaces;
  TopTools_IndexedMapOfShape inputEdges;
  TopExp::MapShapes(inputShape, TopAbs_FACE, inputFaces);
  TopExp::MapShapes(inputShape, TopAbs_EDGE, inputEdges);

  const BRepAlgo_Image& faceImg = algo.OffsetFacesFromShapes();
  const BRepAlgo_Image& edgeImg = algo.OffsetEdgesFromShapes();

  out << "{\n";
  out << "  \"format\": \"occt-research-brepoffset-model-v1\",\n";
  out << "  \"meta\": {\n";
  out << "    \"case\": " << JsonEscape(caseName) << ",\n";
  out << "    \"kind\": " << JsonEscape(kind) << ",\n";
  out << "    \"occt_version\": " << JsonEscape(OCCT_Version_String_Extended()) << ",\n";
  out << "    \"occt_dev\": " << JsonEscape(OCCT_DevelopmentVersion()) << "\n";
  out << "  },\n";

  out << "  \"params\": {\n";
  out << "    \"offset\": " << std::setprecision(17) << offset << ",\n";
  out << "    \"tol\": " << std::setprecision(17) << tol << ",\n";
  out << "    \"mode\": " << JsonEscape(ModeName(mode)) << ",\n";
  out << "    \"join_type\": " << JsonEscape(JoinTypeName(joinType)) << ",\n";
  out << "    \"intersection\": " << (intersection ? "true" : "false") << ",\n";
  out << "    \"self_inter\": " << (selfInter ? "true" : "false") << ",\n";
  out << "    \"remove_internal_edges\": " << (removeIntEdges ? "true" : "false") << "\n";
  out << "  },\n";

  out << "  \"input\":\n";
  out << "    ";
  WriteShapeStats(out, inputStats);
  out << ",\n";

  out << "  \"precheck\": {\n";
  out << "    \"ok\": " << (precheckOk ? "true" : "false") << ",\n";
  out << "    \"bad_shape\": ";
  if (badShape.IsNull())
  {
    out << "null\n";
  }
  else
  {
    out << "\n";
    out << "    ";
    WriteShapeStats(out, badStats);
    out << "\n";
  }
  out << "  },\n";

  out << "  \"result\": {\n";
  const bool isDone = algo.IsDone();
  out << "    \"is_done\": " << (isDone ? "true" : "false") << ",\n";
  out << "    \"error_name\": " << JsonEscape(ErrorName(algo.Error())) << ",\n";
  out << "    \"shape\": ";
  if (!isDone)
  {
    out << "null\n";
  }
  else
  {
    out << "\n";
    out << "    ";
    WriteShapeStats(out, resultStats);
    out << "\n";
  }
  out << "  },\n";

  out << "  \"history\": {\n";
  out << "    \"faces\": [\n";
  for (int i = 1; i <= inputFaces.Extent(); ++i)
  {
    const TopoDS_Shape f = inputFaces(i);
    const bool has = faceImg.HasImage(f);
    int nImages = 0;
    int nLast = 0;
    if (has)
    {
      nImages = CountList(faceImg.Image(f));
      TopTools_ListOfShape last;
      LastImages(faceImg, f, last);
      nLast = CountList(last);
    }
    out << "      {\"input_index\": " << i << ", \"has_image\": " << (has ? "true" : "false")
        << ", \"n_images\": " << nImages << ", \"n_last_images\": " << nLast << "}";
    out << (i == inputFaces.Extent() ? "\n" : ",\n");
  }
  out << "    ],\n";
  out << "    \"edges\": [\n";
  for (int i = 1; i <= inputEdges.Extent(); ++i)
  {
    const TopoDS_Shape e = inputEdges(i);
    const bool has = edgeImg.HasImage(e);
    int nImages = 0;
    int nLast = 0;
    if (has)
    {
      nImages = CountList(edgeImg.Image(e));
      TopTools_ListOfShape last;
      LastImages(edgeImg, e, last);
      nLast = CountList(last);
    }
    out << "      {\"input_index\": " << i << ", \"has_image\": " << (has ? "true" : "false")
        << ", \"n_images\": " << nImages << ", \"n_last_images\": " << nLast << "}";
    out << (i == inputEdges.Extent() ? "\n" : ",\n");
  }
  out << "    ]\n";
  out << "  }\n";

  out << "}\n";
  return true;
}

CaseSummary RunOffsetCase(const Args& args,
                          const std::string& name,
                          const double offset,
                          const double tol,
                          const BRepOffset_Mode mode,
                          const bool intersection,
                          const bool selfInter,
                          const GeomAbs_JoinType joinType,
                          const bool removeIntEdges)
{
  const TopoDS_Shape input = BRepPrimAPI_MakeBox(10.0, 10.0, 10.0).Shape();

  BRepOffset_MakeOffset algo;
  algo.Initialize(input,
                  offset,
                  tol,
                  mode,
                  intersection ? Standard_True : Standard_False,
                  selfInter ? Standard_True : Standard_False,
                  joinType,
                  Standard_False,
                  removeIntEdges ? Standard_True : Standard_False);

  const bool precheckOk = algo.CheckInputData(Message_ProgressRange());
  const TopoDS_Shape bad = precheckOk ? TopoDS_Shape() : algo.GetBadShape();

  if (precheckOk)
    algo.MakeOffsetShape(Message_ProgressRange());

  TopoDS_Shape result;
  if (algo.IsDone())
    result = algo.Shape();

  WriteModelJson(args,
                 name.c_str(),
                 "offset_shape",
                 input,
                 offset,
                 tol,
                 mode,
                 intersection,
                 selfInter,
                 joinType,
                 removeIntEdges,
                 precheckOk,
                 bad,
                 algo,
                 result);

  CaseSummary s;
  s.name = name;
  s.kind = "offset_shape";
  s.is_done = algo.IsDone();
  s.error_name = ErrorName(algo.Error());
  s.model_rel = std::string("artifacts/") + name + "/model.json";
  return s;
}

} // namespace

int main(int argc, char** argv)
{
  const Args args = ParseArgs(argc, argv);

  std::vector<CaseSummary> cases;
  cases.push_back(RunOffsetCase(args, "box_offset_arc_1", 1.0, 1e-6, BRepOffset_Skin, false, false, GeomAbs_Arc, false));
  cases.push_back(
    RunOffsetCase(args, "box_offset_intersection_1", 1.0, 1e-6, BRepOffset_Skin, false, false, GeomAbs_Intersection, false));
  cases.push_back(RunOffsetCase(args, "null_offset_0", 0.0, 1e-6, BRepOffset_Skin, false, false, GeomAbs_Arc, false));

  std::cout.imbue(std::locale::classic());
  std::cout << "{\n";
  std::cout << "  \"format\": \"occt-research-offsets-v1\",\n";
  std::cout << "  \"meta\": {\n";
  std::cout << "    \"occt_version\": " << JsonEscape(OCCT_Version_String_Extended()) << ",\n";
  std::cout << "    \"occt_dev\": " << JsonEscape(OCCT_DevelopmentVersion()) << "\n";
  std::cout << "  },\n";
  std::cout << "  \"cases\": [\n";
  for (size_t i = 0; i < cases.size(); ++i)
  {
    const auto& c = cases[i];
    std::cout << "    {\n";
    std::cout << "      \"case\": " << JsonEscape(c.name) << ",\n";
    std::cout << "      \"kind\": " << JsonEscape(c.kind) << ",\n";
    std::cout << "      \"is_done\": " << (c.is_done ? "true" : "false") << ",\n";
    std::cout << "      \"error_name\": " << JsonEscape(c.error_name) << ",\n";
    std::cout << "      \"model\": " << JsonEscape(c.model_rel) << "\n";
    std::cout << "    }" << (i + 1 == cases.size() ? "\n" : ",\n");
  }
  std::cout << "  ]\n";
  std::cout << "}\n";
  return 0;
}
