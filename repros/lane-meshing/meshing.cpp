#include <BRepBndLib.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRep_Tool.hxx>
#include <Poly_Triangulation.hxx>
#include <Standard_VersionInfo.hxx>
#include <TopExp.hxx>
#include <TopLoc_Location.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Shape.hxx>
#include <gp_Ax2.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>

#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include <vector>

namespace
{
std::string JsonEscape(const std::string& input)
{
  std::ostringstream out;
  out << '"';
  for (const unsigned char c : input)
  {
    switch (c)
    {
      case '\\':
        out << "\\\\";
        break;
      case '"':
        out << "\\\"";
        break;
      case '\b':
        out << "\\b";
        break;
      case '\f':
        out << "\\f";
        break;
      case '\n':
        out << "\\n";
        break;
      case '\r':
        out << "\\r";
        break;
      case '\t':
        out << "\\t";
        break;
      default:
        if (c < 0x20)
        {
          out << "\\u" << std::hex << std::setw(4) << std::setfill('0')
              << static_cast<int>(c) << std::dec << std::setw(0);
        }
        else
        {
          out << static_cast<char>(c);
        }
        break;
    }
  }
  out << '"';
  return out.str();
}

struct MeshStats
{
  Standard_Integer faceCount = 0;
  Standard_Integer facesWithTriangulation = 0;
  Standard_Integer totalNodes = 0;
  Standard_Integer totalTriangles = 0;
  Standard_Integer statusFlags = 0;
};

MeshStats MeshAndCount(const TopoDS_Shape& shape,
                       const Standard_Real deflection,
                       const Standard_Real angle)
{
  // Each run uses a fresh shape instance (callers pass a new shape) to avoid
  // reusing previous triangulation.
  BRepMesh_IncrementalMesh mesher(shape, deflection, Standard_False, angle, Standard_False);

  MeshStats stats;
  stats.statusFlags = mesher.GetStatusFlags();

  TopTools_IndexedMapOfShape faces;
  TopExp::MapShapes(shape, TopAbs_FACE, faces);
  stats.faceCount = faces.Size();

  for (Standard_Integer i = 1; i <= faces.Size(); ++i)
  {
    const TopoDS_Face face = TopoDS::Face(faces(i));
    TopLoc_Location loc;
    const Handle(Poly_Triangulation) triangulation = BRep_Tool::Triangulation(face, loc);
    if (triangulation.IsNull())
    {
      continue;
    }
    stats.facesWithTriangulation += 1;
    stats.totalNodes += triangulation->NbNodes();
    stats.totalTriangles += triangulation->NbTriangles();
  }

  return stats;
}
} // namespace

int main()
{
  std::cout.imbue(std::locale::classic());

  const char* versionStr = OCCT_Version_String_Extended();
  const char* devStr = OCCT_DevelopmentVersion();

  struct RunParams
  {
    Standard_Real deflection = 0.5;
    Standard_Real angle = 0.5;
  };
  const std::vector<RunParams> runs = {
    {0.5, 0.5},  // coarse
    {0.01, 0.5}  // finer (deflection-driven)
  };

  std::cout << "{\n";
  std::cout << "  \"meta\": {\n";
  std::cout << "    \"occt_version\": " << JsonEscape(versionStr == nullptr ? "" : versionStr) << ",\n";
  std::cout << "    \"occt_dev\": " << JsonEscape(devStr == nullptr ? "" : devStr) << ",\n";
  std::cout << "    \"default_angle_rad\": " << std::setprecision(17) << runs.front().angle << "\n";
  std::cout << "  },\n";

  std::cout << "  \"shapes\": {\n";

  auto emitShape = [&](const char* name, const std::function<TopoDS_Shape()>& makeShape, const bool last) {
    std::cout << "    " << JsonEscape(name) << ": {\n";
    std::cout << "      \"runs\": [\n";
    for (size_t idx = 0; idx < runs.size(); ++idx)
    {
      const RunParams p = runs[idx];
      const TopoDS_Shape s = makeShape();
      const MeshStats st = MeshAndCount(s, p.deflection, p.angle);
      std::cout << "        {";
      std::cout << "\"deflection\": " << std::setprecision(17) << p.deflection << ", ";
      std::cout << "\"angle_rad\": " << std::setprecision(17) << p.angle << ", ";
      std::cout << "\"face_count\": " << st.faceCount << ", ";
      std::cout << "\"faces_with_triangulation\": " << st.facesWithTriangulation << ", ";
      std::cout << "\"total_nodes\": " << st.totalNodes << ", ";
      std::cout << "\"total_triangles\": " << st.totalTriangles << ", ";
      std::cout << "\"status_flags\": " << st.statusFlags << "}";
      if (idx + 1 != runs.size())
      {
        std::cout << ",";
      }
      std::cout << "\n";
    }
    std::cout << "      ]\n";
    std::cout << "    }" << (last ? "\n" : ",\n");
  };

  emitShape("box", []() {
    return BRepPrimAPI_MakeBox(gp_Pnt(0.0, 0.0, 0.0), gp_Pnt(10.0, 10.0, 10.0)).Shape();
  }, false);

  emitShape("cylinder", []() {
    // Cylinder axis along Z, shifted to avoid being centered at origin to keep bbox non-symmetric.
    const gp_Ax2 ax(gp_Pnt(3.0, 2.0, 0.0), gp::DZ());
    return BRepPrimAPI_MakeCylinder(ax, 3.0, 10.0).Shape();
  }, true);

  std::cout << "  }\n";
  std::cout << "}\n";
  return 0;
}
