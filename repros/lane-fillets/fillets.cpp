#include <BRepBndLib.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepCheck_Analyzer.hxx>
#include <BRepFilletAPI_MakeChamfer.hxx>
#include <BRepFilletAPI_MakeFillet.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakePrism.hxx>
#include <BRepTools.hxx>
#include <BRepTools_WireExplorer.hxx>
#include <BRep_Tool.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <ChFi3d_ChBuilder.hxx>
#include <ChFi3d_FilBuilder.hxx>
#include <ChFiDS_ErrorStatus.hxx>
#include <ChFiDS_FaceInterference.hxx>
#include <ChFiDS_ListIteratorOfListOfStripe.hxx>
#include <ChFiDS_Spine.hxx>
#include <ChFiDS_Stripe.hxx>
#include <ChFiDS_SurfData.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Surface.hxx>
#include <Poly_Triangulation.hxx>
#include <Standard_Failure.hxx>
#include <Standard_VersionInfo.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopExp.hxx>
#include <TopExp_Explorer.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <TopOpeBRepDS_Surface.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_ListIteratorOfListOfShape.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Vertex.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Pnt.hxx>
#include <gp_Ax2.hxx>
#include <gp_Circ.hxx>
#include <gp_Dir.hxx>
#include <gp_Vec.hxx>
#include <gp.hxx>

#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <locale>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

namespace
{
struct ProgramOptions
{
  std::filesystem::path artifactsDir;
  Standard_Real meshDeflection = 0.1; // coarse but stable for documentation-scale shapes
};

std::string JsonEscape(const std::string& input)
{
  std::ostringstream out;
  out << '"';
  for (const unsigned char c : input)
  {
    switch (c)
    {
      case '\\': out << "\\\\"; break;
      case '"': out << "\\\""; break;
      case '\b': out << "\\b"; break;
      case '\f': out << "\\f"; break;
      case '\n': out << "\\n"; break;
      case '\r': out << "\\r"; break;
      case '\t': out << "\\t"; break;
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

const char* TypeName(const Handle(Standard_Transient)& obj)
{
  return obj.IsNull() ? "NULL" : obj->DynamicType()->Name();
}

struct ShapeCounts
{
  Standard_Integer solids = 0;
  Standard_Integer faces = 0;
  Standard_Integer edges = 0;
  Standard_Integer vertices = 0;
};

Standard_Integer EdgeIndexIn(const std::vector<TopoDS_Edge>& edges, const TopoDS_Edge& e);
Standard_Integer VertexIndexIn(const std::vector<TopoDS_Vertex>& vertices, const TopoDS_Vertex& v);

ShapeCounts Count(const TopoDS_Shape& shape)
{
  ShapeCounts counts;
  TopTools_IndexedMapOfShape map;
  TopExp::MapShapes(shape, TopAbs_SOLID, map);
  counts.solids = map.Size();
  map.Clear();
  TopExp::MapShapes(shape, TopAbs_FACE, map);
  counts.faces = map.Size();
  map.Clear();
  TopExp::MapShapes(shape, TopAbs_EDGE, map);
  counts.edges = map.Size();
  map.Clear();
  TopExp::MapShapes(shape, TopAbs_VERTEX, map);
  counts.vertices = map.Size();
  return counts;
}

TopoDS_Shape MakeSplitRimCylinder(const Standard_Real radius, const Standard_Real height)
{
  // Build a cylindrical solid by extruding a 2-edge circular wire (two semicircles).
  // This ensures the rim is split into multiple tangent edges, so ChFiDS_Spine can have >1 edge.
  const gp_Ax2 ax(gp_Pnt(0, 0, 0), gp::DZ());
  const gp_Circ circ(ax, radius);
  const Standard_Real pi = std::acos(-1.0);
  const TopoDS_Edge e1 = BRepBuilderAPI_MakeEdge(circ, 0.0, pi).Edge();
  const TopoDS_Edge e2 = BRepBuilderAPI_MakeEdge(circ, pi, 2.0 * pi).Edge();

  BRepBuilderAPI_MakeWire mkWire;
  mkWire.Add(e1);
  mkWire.Add(e2);
  const TopoDS_Wire w = mkWire.Wire();

  const TopoDS_Face base = BRepBuilderAPI_MakeFace(w).Face();
  const TopoDS_Shape solid = BRepPrimAPI_MakePrism(base, gp_Vec(0, 0, height)).Shape();
  return solid;
}

std::vector<TopoDS_Edge> EdgesAtZCircle(const TopoDS_Shape& shape, const Standard_Real z, const Standard_Real tol)
{
  std::vector<TopoDS_Edge> out;
  TopTools_IndexedMapOfShape edgesMap;
  TopExp::MapShapes(shape, TopAbs_EDGE, edgesMap);
  out.reserve(edgesMap.Size());

  for (Standard_Integer i = 1; i <= edgesMap.Size(); ++i)
  {
    const TopoDS_Edge e = TopoDS::Edge(edgesMap(i));
    if (e.IsNull())
      continue;

    const TopoDS_Vertex v1 = TopExp::FirstVertex(e);
    const TopoDS_Vertex v2 = TopExp::LastVertex(e);
    const gp_Pnt p1 = BRep_Tool::Pnt(v1);
    const gp_Pnt p2 = BRep_Tool::Pnt(v2);
    if (std::abs(p1.Z() - z) > tol || std::abs(p2.Z() - z) > tol)
      continue;

    BRepAdaptor_Curve c(e);
    if (c.GetType() != GeomAbs_Circle)
      continue;

    out.push_back(e);
  }

  return out;
}

void PrintBBox(std::ostream& out, const TopoDS_Shape& shape)
{
  if (shape.IsNull())
  {
    out << "{ \"is_void\": true }";
    return;
  }

  Bnd_Box box;
  BRepBndLib::Add(shape, box);
  if (box.IsVoid())
  {
    out << "{ \"is_void\": true }";
    return;
  }

  Standard_Real xmin = 0, ymin = 0, zmin = 0, xmax = 0, ymax = 0, zmax = 0;
  box.Get(xmin, ymin, zmin, xmax, ymax, zmax);

  out << "{ \"is_void\": false, \"min\": [";
  out << std::setprecision(17) << xmin << ", " << ymin << ", " << zmin;
  out << "], \"max\": [";
  out << std::setprecision(17) << xmax << ", " << ymax << ", " << zmax;
  out << "] }";
}

std::string StripeStatusName(const ChFiDS_ErrorStatus st)
{
  switch (st)
  {
    case ChFiDS_Ok: return "ChFiDS_Ok";
    case ChFiDS_Error: return "ChFiDS_Error";
    case ChFiDS_WalkingFailure: return "ChFiDS_WalkingFailure";
    case ChFiDS_StartsolFailure: return "ChFiDS_StartsolFailure";
    case ChFiDS_TwistedSurface: return "ChFiDS_TwistedSurface";
  }
  return "Unknown";
}

std::string OrientationName(const TopAbs_Orientation o)
{
  switch (o)
  {
    case TopAbs_FORWARD: return "FORWARD";
    case TopAbs_REVERSED: return "REVERSED";
    case TopAbs_INTERNAL: return "INTERNAL";
    case TopAbs_EXTERNAL: return "EXTERNAL";
  }
  return "UNKNOWN";
}

gp_Pnt VertexPoint(const TopoDS_Vertex& v)
{
  return v.IsNull() ? gp_Pnt() : BRep_Tool::Pnt(v);
}

class ExFilBuilder final : public ChFi3d_FilBuilder
{
public:
  using ChFi3d_FilBuilder::ChFi3d_FilBuilder;
  const ChFiDS_ListOfStripe& Stripes() const { return myListStripe; }
  const Handle(TopOpeBRepDS_HDataStructure)& DataStructure() const { return myDS; }
};

class ExChBuilder final : public ChFi3d_ChBuilder
{
public:
  using ChFi3d_ChBuilder::ChFi3d_ChBuilder;
  const ChFiDS_ListOfStripe& Stripes() const { return myListStripe; }
  const Handle(TopOpeBRepDS_HDataStructure)& DataStructure() const { return myDS; }
};

Standard_Integer ClampI(const Standard_Integer v, const Standard_Integer lo, const Standard_Integer hi)
{
  return std::max(lo, std::min(hi, v));
}

Standard_Integer DefaultSampleCount()
{
  return 48;
}

Standard_Integer DefaultFaceBoundarySampleCount()
{
  return 32;
}

std::vector<Standard_Real> SampleEdgePolyline(const TopoDS_Edge& edge, const Standard_Integer samples)
{
  std::vector<Standard_Real> pts;
  if (edge.IsNull())
    return pts;

  BRepAdaptor_Curve c(edge);
  const Standard_Real f = c.FirstParameter();
  const Standard_Real l = c.LastParameter();
  const Standard_Integer n = ClampI(samples, 2, 256);
  pts.reserve(static_cast<size_t>(n) * 3);

  for (Standard_Integer i = 0; i < n; ++i)
  {
    const Standard_Real t = (i == n - 1) ? l : (f + (l - f) * (static_cast<Standard_Real>(i) / (n - 1)));
    const gp_Pnt p = c.Value(t);
    pts.push_back(p.X());
    pts.push_back(p.Y());
    pts.push_back(p.Z());
  }
  return pts;
}

std::vector<Standard_Real> SampleOuterWirePolyline(const TopoDS_Face& face, const Standard_Integer samplesPerEdge)
{
  std::vector<Standard_Real> pts;
  if (face.IsNull())
    return pts;

  TopoDS_Wire ow;
  try
  {
    ow = BRepTools::OuterWire(face);
  }
  catch (const Standard_Failure&)
  {
    return pts;
  }
  if (ow.IsNull())
    return pts;

  try
  {
    bool firstEdge = true;
    for (BRepTools_WireExplorer wex(ow); wex.More(); wex.Next())
    {
      const TopoDS_Edge e = wex.Current();
      std::vector<Standard_Real> seg = SampleEdgePolyline(e, samplesPerEdge);
      if (seg.empty())
        continue;
      if (!firstEdge && !pts.empty() && seg.size() >= 3)
      {
        pts.pop_back();
        pts.pop_back();
        pts.pop_back();
      }
      pts.insert(pts.end(), seg.begin(), seg.end());
      firstEdge = false;
    }
  }
  catch (const Standard_Failure&)
  {
    return std::vector<Standard_Real>();
  }
  return pts;
}

bool SampleCurve2d(const Handle(Geom2d_Curve)& c,
                   const Standard_Real first,
                   const Standard_Real last,
                   const Standard_Integer samples,
                   std::vector<Standard_Real>& uvOut)
{
  uvOut.clear();
  if (c.IsNull())
    return false;

  const Standard_Integer n = ClampI(samples, 2, 512);
  uvOut.reserve(static_cast<size_t>(n) * 2);
  for (Standard_Integer i = 0; i < n; ++i)
  {
    const Standard_Real t = (i == n - 1) ? last : (first + (last - first) * (static_cast<Standard_Real>(i) / (n - 1)));
    gp_Pnt2d p;
    try
    {
      p = c->Value(t);
    }
    catch (const Standard_Failure&)
    {
      return false;
    }
    uvOut.push_back(p.X());
    uvOut.push_back(p.Y());
  }
  return !uvOut.empty();
}

bool MapUvPolylineTo3d(const Handle(Geom_Surface)& surf,
                       const std::vector<Standard_Real>& uv,
                       std::vector<Standard_Real>& xyzOut)
{
  xyzOut.clear();
  if (surf.IsNull() || uv.size() < 2)
    return false;

  xyzOut.reserve((uv.size() / 2) * 3);
  for (size_t i = 0; i + 1 < uv.size(); i += 2)
  {
    const Standard_Real u = uv[i];
    const Standard_Real v = uv[i + 1];
    gp_Pnt p;
    try
    {
      p = surf->Value(u, v);
    }
    catch (const Standard_Failure&)
    {
      return false;
    }
    xyzOut.push_back(p.X());
    xyzOut.push_back(p.Y());
    xyzOut.push_back(p.Z());
  }
  return !xyzOut.empty();
}

void PrintNumArray(std::ostream& out, const std::vector<Standard_Real>& values)
{
  out << "[";
  for (size_t i = 0; i < values.size(); ++i)
  {
    if (i != 0)
      out << ", ";
    out << std::setprecision(17) << values[i];
  }
  out << "]";
}

void PrintPnt(std::ostream& out, const gp_Pnt& p)
{
  out << "[" << std::setprecision(17) << p.X() << ", " << p.Y() << ", " << p.Z() << "]";
}

void PrintCommonPoint(std::ostream& out, const char* label, const ChFiDS_CommonPoint& cp)
{
  out << "{ \"label\": " << JsonEscape(label) << ", ";
  out << "\"tol\": " << std::setprecision(17) << cp.Tolerance() << ", ";
  out << "\"param_spine\": " << std::setprecision(17) << cp.Parameter() << ", ";
  out << "\"is_vertex\": " << (cp.IsVertex() ? "true" : "false") << ", ";
  out << "\"is_on_arc\": " << (cp.IsOnArc() ? "true" : "false") << ", ";

  gp_Pnt p = cp.Point();
  if (cp.IsVertex())
  {
    try
    {
      p = VertexPoint(cp.Vertex());
    }
    catch (const Standard_Failure&)
    {
    }
  }
  out << "\"p\": ";
  PrintPnt(out, p);

  if (cp.IsOnArc())
  {
    try
    {
      const TopoDS_Edge a = cp.Arc();
      out << ", \"arc_transition\": " << JsonEscape(OrientationName(cp.TransitionOnArc())) << ", ";
      out << "\"arc_param\": " << std::setprecision(17) << cp.ParameterOnArc() << ", ";
      TopoDS_Vertex v1, v2;
      TopExp::Vertices(a, v1, v2);
      out << "\"arc_v1\": ";
      PrintPnt(out, VertexPoint(v1));
      out << ", \"arc_v2\": ";
      PrintPnt(out, VertexPoint(v2));
    }
    catch (const Standard_Failure&)
    {
    }
  }
  out << " }";
}

template <typename TBuilder>
bool WriteChFiDSModelJson(const TBuilder& builder,
                          const std::vector<TopoDS_Edge>& inputEdges,
                          const std::vector<TopoDS_Vertex>& inputVertices,
                          const char* caseName,
                          const char* kind,
                          const std::filesystem::path& path)
{
  try
  {
    std::filesystem::create_directories(path.parent_path());
  }
  catch (const std::exception&)
  {
    return false;
  }

  std::ofstream out(path, std::ios::binary);
  if (!out)
    return false;
  out.imbue(std::locale::classic());

  // Build a lookup from spine handle -> contour index (1-based).
  std::map<const ChFiDS_Spine*, Standard_Integer> spineToContour;
  const Standard_Integer nbElements = builder.NbElements();
  for (Standard_Integer ic = 1; ic <= nbElements; ++ic)
  {
    const Handle(ChFiDS_Spine) sp = builder.Value(ic);
    if (!sp.IsNull())
      spineToContour[sp.get()] = ic;
  }

  // Gather DS surfaces referenced by the export.
  std::set<Standard_Integer> faceIndices;
  std::set<Standard_Integer> surfaceIndices;
  const Handle(TopOpeBRepDS_HDataStructure) ds = builder.DataStructure();

  struct CornerRef
  {
    Standard_Integer stripe_index = 0;
    std::string stripe_id;
    Standard_Integer contour_index = 0;
    std::string end_kind; // "start" | "end"
    Standard_Integer edge_index = 0; // edge near the end (global input edge index)
  };
  std::map<Standard_Integer, std::vector<CornerRef>> cornerRefsByVertex;

  out << "{\n";
  out << "  \"format\": \"occt-research-chfids-model-v1\",\n";
  out << "  \"meta\": {\n";
  out << "    \"case\": " << JsonEscape(caseName) << ",\n";
  out << "    \"kind\": " << JsonEscape(kind) << ",\n";
  out << "    \"occt_version\": " << JsonEscape(OCCT_Version_String_Extended()) << ",\n";
  out << "    \"occt_dev\": " << JsonEscape(OCCT_DevelopmentVersion()) << "\n";
  out << "  },\n";
  out << "  \"stripes\": [\n";

  Standard_Integer stripeIndex = 0;
  for (ChFiDS_ListIteratorOfListOfStripe it(builder.Stripes()); it.More(); it.Next())
  {
    const Handle(ChFiDS_Stripe) stripe = it.Value();
    if (stripe.IsNull())
      continue;

    stripeIndex += 1;
    const Handle(ChFiDS_Spine) spine = stripe->Spine();
    Standard_Integer contourIndex = -1;
    if (!spine.IsNull())
    {
      const auto found = spineToContour.find(spine.get());
      if (found != spineToContour.end())
        contourIndex = found->second;
    }

    std::vector<Standard_Integer> edgeIds;
    std::vector<Standard_Real> spinePoints;
    std::vector<Standard_Integer> breakpoints;
    struct EdgeEndpoint
    {
      Standard_Integer edge_index = 0;
      Standard_Integer v1_index = 0;
      Standard_Integer v2_index = 0;
      gp_Pnt v1_p;
      gp_Pnt v2_p;
    };
    std::vector<EdgeEndpoint> edgeEndpoints;
    TopoDS_Vertex spineStartV;
    TopoDS_Vertex spineEndV;
    Standard_Integer spineStartVIndex = 0;
    Standard_Integer spineEndVIndex = 0;
    bool spineIsClosed = false;

    if (!spine.IsNull())
    {
      const Standard_Integer nbEdges = spine->NbEdges();
      edgeIds.reserve(static_cast<size_t>(nbEdges));
      edgeEndpoints.reserve(static_cast<size_t>(nbEdges));
      for (Standard_Integer ie = 1; ie <= nbEdges; ++ie)
      {
        const TopoDS_Edge e = spine->Edges(ie);
        const Standard_Integer eid = EdgeIndexIn(inputEdges, e);
        edgeIds.push_back(eid);

        TopoDS_Vertex v1, v2;
        TopExp::Vertices(e, v1, v2);
        const gp_Pnt p1 = VertexPoint(v1);
        const gp_Pnt p2 = VertexPoint(v2);
        edgeEndpoints.push_back(
          EdgeEndpoint{eid, VertexIndexIn(inputVertices, v1), VertexIndexIn(inputVertices, v2), p1, p2});

        std::vector<Standard_Real> seg = SampleEdgePolyline(e, DefaultSampleCount());
        if (!seg.empty())
        {
          // Avoid duplicating the seam point between consecutive edges.
          if (!spinePoints.empty() && seg.size() >= 3)
          {
            spinePoints.pop_back();
            spinePoints.pop_back();
            spinePoints.pop_back();
          }
          spinePoints.insert(spinePoints.end(), seg.begin(), seg.end());
        }
        breakpoints.push_back(static_cast<Standard_Integer>(spinePoints.size() / 3));
      }

      // Determine stripe endpoints (and whether it is a closed contour) using vertex degrees
      // within the spine edge chain. Open chain => two degree-1 vertices.
      TopTools_IndexedMapOfShape spineVerts;
      std::vector<Standard_Integer> deg;
      deg.reserve(static_cast<size_t>(nbEdges) * 2);
      for (Standard_Integer ie = 1; ie <= nbEdges; ++ie)
      {
        const TopoDS_Edge e = spine->Edges(ie);
        TopoDS_Vertex v1, v2;
        TopExp::Vertices(e, v1, v2);
        if (!v1.IsNull())
        {
          const Standard_Integer idx = spineVerts.Add(v1);
          if (static_cast<size_t>(idx) > deg.size())
            deg.resize(static_cast<size_t>(idx), 0);
          deg[static_cast<size_t>(idx - 1)] += 1;
        }
        if (!v2.IsNull())
        {
          const Standard_Integer idx = spineVerts.Add(v2);
          if (static_cast<size_t>(idx) > deg.size())
            deg.resize(static_cast<size_t>(idx), 0);
          deg[static_cast<size_t>(idx - 1)] += 1;
        }
      }

      std::vector<TopoDS_Vertex> ends;
      for (Standard_Integer i = 1; i <= spineVerts.Size(); ++i)
      {
        const Standard_Integer d = (i - 1 >= 0 && static_cast<size_t>(i - 1) < deg.size()) ? deg[static_cast<size_t>(i - 1)] : 0;
        if (d == 1)
          ends.push_back(TopoDS::Vertex(spineVerts(i)));
      }

      if (ends.size() == 2)
      {
        gp_Pnt p0;
        if (spinePoints.size() >= 3)
          p0 = gp_Pnt(spinePoints[0], spinePoints[1], spinePoints[2]);
        else
          p0 = VertexPoint(ends[0]);

        const Standard_Real d0 = p0.Distance(VertexPoint(ends[0]));
        const Standard_Real d1 = p0.Distance(VertexPoint(ends[1]));
        if (d0 <= d1)
        {
          spineStartV = ends[0];
          spineEndV = ends[1];
        }
        else
        {
          spineStartV = ends[1];
          spineEndV = ends[0];
        }
        spineIsClosed = false;
      }
      else
      {
        // Closed (or degenerate) contour; pick a stable "start" vertex from the first edge.
        TopoDS_Vertex v1, v2;
        TopExp::Vertices(spine->Edges(1), v1, v2);
        spineStartV = v1;
        spineEndV = v1;
        spineIsClosed = true;
      }

      spineStartVIndex = VertexIndexIn(inputVertices, spineStartV);
      spineEndVIndex = VertexIndexIn(inputVertices, spineEndV);
    }

    std::ostringstream stripeId;
    stripeId << "s" << stripeIndex;
    if (contourIndex > 0)
      stripeId << "-c" << contourIndex;
    if (!edgeIds.empty())
    {
      stripeId << "-e";
      for (size_t i = 0; i < edgeIds.size(); ++i)
      {
        if (i != 0)
          stripeId << "-";
        stripeId << edgeIds[i];
      }
    }

    if (stripeIndex != 1)
      out << ",\n";
    out << "    {\n";
    out << "      \"index\": " << stripeIndex << ",\n";
    out << "      \"id\": " << JsonEscape(stripeId.str()) << ",\n";
    out << "      \"contour_index\": " << contourIndex << ",\n";

    if (contourIndex > 0)
    {
      const ChFiDS_ErrorStatus st = builder.StripeStatus(contourIndex);
      out << "      \"stripe_status\": " << static_cast<int>(st) << ",\n";
      out << "      \"stripe_status_name\": " << JsonEscape(StripeStatusName(st)) << ",\n";
    }
    else
    {
      out << "      \"stripe_status\": -1,\n";
      out << "      \"stripe_status_name\": \"N/A\",\n";
    }
    out << "      \"choix\": " << stripe->Choix() << ",\n";
    out << "      \"spine\": {\n";
    out << "        \"edge_indices\": [";
    for (size_t i = 0; i < edgeIds.size(); ++i)
    {
      if (i != 0)
        out << ", ";
      out << edgeIds[i];
    }
    out << "],\n";
    out << "        \"endpoints\": { \"first\": ";
    if (!spineStartV.IsNull())
      PrintPnt(out, VertexPoint(spineStartV));
    else
      out << "null";
    out << ", \"last\": ";
    if (!spineEndV.IsNull())
      PrintPnt(out, VertexPoint(spineEndV));
    else
      out << "null";
    out << " },\n";
    out << "        \"endpoint_vertex_indices\": { \"first\": " << spineStartVIndex << ", \"last\": " << spineEndVIndex
        << ", \"is_closed\": " << (spineIsClosed ? "true" : "false") << " },\n";
    out << "        \"edges\": [";
    for (size_t i = 0; i < edgeEndpoints.size(); ++i)
    {
      if (i != 0)
        out << ", ";
      out << "{ \"edge_index\": " << edgeEndpoints[i].edge_index << ", \"v1_index\": " << edgeEndpoints[i].v1_index
          << ", \"v2_index\": " << edgeEndpoints[i].v2_index << ", \"v1\": ";
      PrintPnt(out, edgeEndpoints[i].v1_p);
      out << ", \"v2\": ";
      PrintPnt(out, edgeEndpoints[i].v2_p);
      out << " }";
    }
    out << "],\n";
    out << "        \"polyline_points\": ";
    PrintNumArray(out, spinePoints);
    out << ",\n";
    out << "        \"breakpoints\": [";
    for (size_t i = 0; i < breakpoints.size(); ++i)
    {
      if (i != 0)
        out << ", ";
      out << breakpoints[i];
    }
    out << "]\n";
    out << "      },\n";
    out << "      \"surfData\": [\n";

    const Handle(ChFiDS_HData) hdata = stripe->SetOfSurfData();
    const Standard_Integer nbSurfData = hdata.IsNull() ? 0 : hdata->Length();
    for (Standard_Integer i = 1; i <= nbSurfData; ++i)
    {
      const Handle(ChFiDS_SurfData) sd = hdata->Value(i);
      if (sd.IsNull())
        continue;

      const Standard_Integer s1 = sd->IndexOfS1();
      const Standard_Integer s2 = sd->IndexOfS2();
      const Standard_Integer sf = sd->Surf();
      faceIndices.insert(s1);
      faceIndices.insert(s2);
      surfaceIndices.insert(sf);

      if (i != 1)
        out << ",\n";
      out << "        {\n";
      out << "          \"index\": " << i << ",\n";
      out << "          \"ufspine\": " << std::setprecision(17) << sd->FirstSpineParam() << ",\n";
      out << "          \"ulspine\": " << std::setprecision(17) << sd->LastSpineParam() << ",\n";
      out << "          \"IndexOfS1\": " << s1 << ",\n";
      out << "          \"IndexOfS2\": " << s2 << ",\n";
      out << "          \"Surf\": " << sf << ",\n";
      out << "          \"twistOnS1\": " << (sd->TwistOnS1() ? "true" : "false") << ",\n";
      out << "          \"twistOnS2\": " << (sd->TwistOnS2() ? "true" : "false") << ",\n";
      out << "          \"commonPoints\": [\n";
      out << "            ";
      PrintCommonPoint(out, "first_on_s1", sd->VertexFirstOnS1());
      out << ",\n            ";
      PrintCommonPoint(out, "last_on_s1", sd->VertexLastOnS1());
      out << ",\n            ";
      PrintCommonPoint(out, "first_on_s2", sd->VertexFirstOnS2());
      out << ",\n            ";
      PrintCommonPoint(out, "last_on_s2", sd->VertexLastOnS2());
      out << "\n";
      out << "          ],\n";

      auto emitInterference = [&](const char* name,
                                  const ChFiDS_FaceInterference& fi,
                                  const Standard_Integer faceSurfIndex,
                                  const Standard_Integer filletSurfIndex) {
        out << "          \"" << name << "\": {\n";
        out << "            \"line_index\": " << fi.LineIndex() << ",\n";
        out << "            \"transition\": " << JsonEscape(OrientationName(fi.Transition())) << ",\n";
        out << "            \"first\": " << std::setprecision(17) << fi.FirstParameter() << ",\n";
        out << "            \"last\": " << std::setprecision(17) << fi.LastParameter() << ",\n";

        std::vector<Standard_Real> uvFace;
        std::vector<Standard_Real> uvSurf;
        std::vector<Standard_Real> xyzFace;
        std::vector<Standard_Real> xyzSurf;

        const bool haveUvFace =
          SampleCurve2d(fi.PCurveOnFace(), fi.FirstParameter(), fi.LastParameter(), DefaultSampleCount(), uvFace);
        const bool haveUvSurf =
          SampleCurve2d(fi.PCurveOnSurf(), fi.FirstParameter(), fi.LastParameter(), DefaultSampleCount(), uvSurf);

        out << "            \"pcurve_on_face_uv\": ";
        if (haveUvFace)
          PrintNumArray(out, uvFace);
        else
          out << "[]";
        out << ",\n";

        out << "            \"pcurve_on_surf_uv\": ";
        if (haveUvSurf)
          PrintNumArray(out, uvSurf);
        else
          out << "[]";
        out << ",\n";

        bool okFace3d = false;
        bool okSurf3d = false;
        if (!ds.IsNull() && haveUvFace && faceSurfIndex > 0 && faceSurfIndex <= ds->NbShapes())
        {
          const TopoDS_Shape faceShape = ds->Shape(faceSurfIndex);
          if (!faceShape.IsNull() && faceShape.ShapeType() == TopAbs_FACE)
          {
            const Handle(Geom_Surface) faceSurf = BRep_Tool::Surface(TopoDS::Face(faceShape));
            okFace3d = MapUvPolylineTo3d(faceSurf, uvFace, xyzFace);
          }
        }
        if (!ds.IsNull() && haveUvSurf && filletSurfIndex > 0 && filletSurfIndex <= ds->NbSurfaces())
        {
          const Handle(Geom_Surface) filletSurf = ds->Surface(filletSurfIndex).Surface();
          okSurf3d = MapUvPolylineTo3d(filletSurf, uvSurf, xyzSurf);
        }

        out << "            \"curve3d_on_face\": ";
        if (okFace3d)
          PrintNumArray(out, xyzFace);
        else
          out << "[]";
        out << ",\n";

        out << "            \"curve3d_on_surf\": ";
        if (okSurf3d)
          PrintNumArray(out, xyzSurf);
        else
          out << "[]";
        out << "\n";
        out << "          }";
      };

      out << "          \"interferences\": {\n";
      emitInterference("on_s1", sd->InterferenceOnS1(), s1, sf);
      out << ",\n";
      emitInterference("on_s2", sd->InterferenceOnS2(), s2, sf);
      out << "\n";
      out << "          }\n";
      out << "        }";
    }
    out << "\n";
    out << "      ]\n";
    out << "    }";

    // Collect corner context from stripe endpoints (open contours only).
    if (!spineIsClosed)
    {
      if (spineStartVIndex > 0)
      {
        const Standard_Integer nearEdge = (!edgeIds.empty() ? edgeIds.front() : 0);
        cornerRefsByVertex[spineStartVIndex].push_back(
          CornerRef{stripeIndex, stripeId.str(), contourIndex, "start", nearEdge});
      }
      if (spineEndVIndex > 0)
      {
        const Standard_Integer nearEdge = (!edgeIds.empty() ? edgeIds.back() : 0);
        cornerRefsByVertex[spineEndVIndex].push_back(
          CornerRef{stripeIndex, stripeId.str(), contourIndex, "end", nearEdge});
      }
    }
  }
  out << "\n";
  out << "  ],\n";

  out << "  \"corners\": [\n";
  bool firstCorner = true;
  for (const auto& [vertexIndex, refs] : cornerRefsByVertex)
  {
    if (vertexIndex <= 0)
      continue;
    if (refs.empty())
      continue;

    const TopoDS_Vertex v = (vertexIndex >= 1 && static_cast<size_t>(vertexIndex) <= inputVertices.size())
                              ? inputVertices[static_cast<size_t>(vertexIndex - 1)]
                              : TopoDS_Vertex();
    const gp_Pnt p = VertexPoint(v);

    if (!firstCorner)
      out << ",\n";
    firstCorner = false;
    out << "    { \"vertex_index\": " << vertexIndex << ", \"p\": ";
    PrintPnt(out, p);
    out << ", \"degree\": " << static_cast<Standard_Integer>(refs.size()) << ", \"refs\": [";
    for (size_t i = 0; i < refs.size(); ++i)
    {
      if (i != 0)
        out << ", ";
      out << "{ \"stripe_index\": " << refs[i].stripe_index << ", \"stripe_id\": " << JsonEscape(refs[i].stripe_id)
          << ", \"contour_index\": " << refs[i].contour_index << ", \"end\": " << JsonEscape(refs[i].end_kind)
          << ", \"edge_index\": " << refs[i].edge_index << " }";
    }
    out << "] }";
  }
  if (!firstCorner)
    out << "\n";
  out << "  ],\n";

  out << "  \"surfaces\": [\n";
  bool firstSurface = true;
  if (!ds.IsNull())
  {
    for (const Standard_Integer idx : surfaceIndices)
    {
      if (idx <= 0 || idx > ds->NbSurfaces())
        continue;
      const TopOpeBRepDS_Surface& s = ds->Surface(idx);
      if (!firstSurface)
        out << ",\n";
      firstSurface = false;
      out << "    { \"index\": " << idx << ", \"type\": " << JsonEscape(TypeName(s.Surface()))
          << ", \"tol\": " << std::setprecision(17) << s.Tolerance() << " }";
    }
  }
  if (!firstSurface)
    out << "\n";
  out << "  ]\n";
  out << ",\n";

  out << "  \"faces\": [\n";
  bool firstFace = true;
  if (!ds.IsNull())
  {
    for (const Standard_Integer idx : faceIndices)
    {
      if (idx <= 0 || idx > ds->NbShapes())
        continue;
      const TopoDS_Shape s = ds->Shape(idx);
      if (s.IsNull() || s.ShapeType() != TopAbs_FACE)
        continue;
      const TopoDS_Face f = TopoDS::Face(s);
      const Handle(Geom_Surface) surf = BRep_Tool::Surface(f);
      if (!firstFace)
        out << ",\n";
      firstFace = false;
      const std::vector<Standard_Real> boundary = SampleOuterWirePolyline(f, DefaultFaceBoundarySampleCount());
      out << "    { \"index\": " << idx << ", \"type\": " << JsonEscape(TypeName(surf));
      out << ", \"outer_wire_polyline\": [";
      for (std::size_t i = 0; i < boundary.size(); ++i)
      {
        if (i != 0)
          out << ", ";
        out << std::setprecision(17) << boundary[i];
      }
      out << "] }";
    }
  }
  if (!firstFace)
    out << "\n";
  out << "  ]\n";
  out << "}\n";

  return static_cast<bool>(out);
}

bool WriteMeshJson(const TopoDS_Shape& shape, const std::filesystem::path& path, const Standard_Real deflection)
{
  if (shape.IsNull())
    return false;

  try
  {
    BRepMesh_IncrementalMesh mesher(shape, deflection);
    mesher.Perform();
  }
  catch (const Standard_Failure&)
  {
    return false;
  }

  std::vector<Standard_Real> positions;
  std::vector<std::uint32_t> indices;
  positions.reserve(1024);
  indices.reserve(2048);

  Bnd_Box bbox;

  for (TopExp_Explorer ex(shape, TopAbs_FACE); ex.More(); ex.Next())
  {
    const TopoDS_Face face = TopoDS::Face(ex.Current());
    TopLoc_Location loc;
    const Handle(Poly_Triangulation) tri = BRep_Tool::Triangulation(face, loc);
    if (tri.IsNull())
      continue;

    const gp_Trsf trsf = loc.Transformation();
    const std::uint32_t base = static_cast<std::uint32_t>(positions.size() / 3);

    const Standard_Integer nbNodes = tri->NbNodes();
    for (Standard_Integer i = 1; i <= nbNodes; ++i)
    {
      gp_Pnt p = tri->Node(i);
      p.Transform(trsf);
      bbox.Add(p);
      positions.push_back(p.X());
      positions.push_back(p.Y());
      positions.push_back(p.Z());
    }

    const Standard_Integer nbTriangles = tri->NbTriangles();
    for (Standard_Integer i = 1; i <= nbTriangles; ++i)
    {
      Standard_Integer n1 = 0, n2 = 0, n3 = 0;
      tri->Triangle(i).Get(n1, n2, n3);
      // OCCT triangulation indices are 1-based; emit 0-based.
      indices.push_back(base + static_cast<std::uint32_t>(n1 - 1));
      indices.push_back(base + static_cast<std::uint32_t>(n2 - 1));
      indices.push_back(base + static_cast<std::uint32_t>(n3 - 1));
    }
  }

  if (positions.empty() || indices.empty())
    return false;

  try
  {
    std::filesystem::create_directories(path.parent_path());
  }
  catch (const std::exception&)
  {
    return false;
  }

  std::ofstream out(path, std::ios::binary);
  if (!out)
    return false;

  out.imbue(std::locale::classic());

  out << "{\n";
  out << "  \"format\": \"occt-research-mesh-v1\",\n";
  out << "  \"counts\": { \"vertices\": " << (positions.size() / 3) << ", \"triangles\": " << (indices.size() / 3)
      << " },\n";
  out << "  \"bbox\": ";
  if (bbox.IsVoid())
  {
    out << "{ \"is_void\": true },\n";
  }
  else
  {
    Standard_Real xmin = 0, ymin = 0, zmin = 0, xmax = 0, ymax = 0, zmax = 0;
    bbox.Get(xmin, ymin, zmin, xmax, ymax, zmax);
    out << "{ \"is_void\": false, \"min\": [" << std::setprecision(17) << xmin << ", " << ymin << ", " << zmin
        << "], \"max\": [" << std::setprecision(17) << xmax << ", " << ymax << ", " << zmax << "] },\n";
  }

  out << "  \"positions\": [";
  for (std::size_t i = 0; i < positions.size(); ++i)
  {
    if (i != 0)
      out << ", ";
    out << std::setprecision(17) << positions[i];
  }
  out << "],\n";

  out << "  \"indices\": [";
  for (std::size_t i = 0; i < indices.size(); ++i)
  {
    if (i != 0)
      out << ", ";
    out << indices[i];
  }
  out << "]\n";
  out << "}\n";

  return static_cast<bool>(out);
}

void EmitArtifacts(std::ostream& out,
                   const ProgramOptions& opts,
                   const char* name,
                   const TopoDS_Shape& input,
                   const TopoDS_Shape& result,
                   const TopoDS_Shape& badShape)
{
  if (opts.artifactsDir.empty())
  {
    out << "      \"artifacts\": { \"enabled\": false }\n";
    return;
  }

  const std::filesystem::path caseDir = opts.artifactsDir / name;
  const std::filesystem::path inputPath = caseDir / "input.mesh.json";
  const std::filesystem::path resultPath = caseDir / "result.mesh.json";
  const std::filesystem::path badPath = caseDir / "bad.mesh.json";

  const bool wroteInput = WriteMeshJson(input, inputPath, opts.meshDeflection);
  const bool wroteResult = result.IsNull() ? false : WriteMeshJson(result, resultPath, opts.meshDeflection);
  const bool wroteBad = badShape.IsNull() ? false : WriteMeshJson(badShape, badPath, opts.meshDeflection);

  out << "      \"artifacts\": {\n";
  out << "        \"enabled\": true,\n";
  out << "        \"input_mesh\": " << JsonEscape((std::string("artifacts/") + name + "/input.mesh.json")) << ",\n";
  out << "        \"result_mesh\": " << JsonEscape((std::string("artifacts/") + name + "/result.mesh.json")) << ",\n";
  out << "        \"bad_mesh\": " << JsonEscape((std::string("artifacts/") + name + "/bad.mesh.json")) << ",\n";
  out << "        \"wrote_input\": " << (wroteInput ? "true" : "false") << ",\n";
  out << "        \"wrote_result\": " << (wroteResult ? "true" : "false") << ",\n";
  out << "        \"wrote_bad\": " << (wroteBad ? "true" : "false") << "\n";
  out << "      }\n";
}

TopoDS_Vertex FindMinCornerVertex(const TopoDS_Shape& shape)
{
  TopTools_IndexedMapOfShape verts;
  TopExp::MapShapes(shape, TopAbs_VERTEX, verts);

  TopoDS_Vertex best;
  Standard_Real bestScore = 0.0;
  for (Standard_Integer i = 1; i <= verts.Size(); ++i)
  {
    const TopoDS_Vertex v = TopoDS::Vertex(verts(i));
    const gp_Pnt p = VertexPoint(v);
    const Standard_Real score = p.X() + p.Y() + p.Z();
    if (best.IsNull() || score < bestScore)
    {
      best = v;
      bestScore = score;
    }
  }
  return best;
}

std::vector<TopoDS_Edge> EdgesIncidentToVertex(const TopoDS_Shape& shape, const TopoDS_Vertex& v)
{
  std::vector<TopoDS_Edge> edges;
  if (v.IsNull())
    return edges;

  TopTools_IndexedMapOfShape mapEdges;
  TopExp::MapShapes(shape, TopAbs_EDGE, mapEdges);
  for (Standard_Integer i = 1; i <= mapEdges.Size(); ++i)
  {
    const TopoDS_Edge e = TopoDS::Edge(mapEdges(i));
    TopoDS_Vertex v1;
    TopoDS_Vertex v2;
    TopExp::Vertices(e, v1, v2);
    if (!v1.IsNull() && v1.IsSame(v))
      edges.push_back(e);
    else if (!v2.IsNull() && v2.IsSame(v))
      edges.push_back(e);
  }
  return edges;
}

std::map<std::string, int> SurfaceTypeHistogram(const TopoDS_Shape& shape)
{
  std::map<std::string, int> hist;
  TopTools_IndexedMapOfShape faces;
  TopExp::MapShapes(shape, TopAbs_FACE, faces);
  for (Standard_Integer i = 1; i <= faces.Size(); ++i)
  {
    const TopoDS_Face face = TopoDS::Face(faces(i));
    const Handle(Geom_Surface) surf = BRep_Tool::Surface(face);
    const std::string type = TypeName(surf);
    hist[type] += 1;
  }
  return hist;
}

void PrintSurfaceHistogram(std::ostream& out, const std::map<std::string, int>& hist)
{
  out << "{";
  bool first = true;
  for (const auto& [name, count] : hist)
  {
    if (!first)
      out << ", ";
    first = false;
    out << JsonEscape(name) << ": " << count;
  }
  out << "}";
}

Standard_Integer EdgeIndexIn(const std::vector<TopoDS_Edge>& edges, const TopoDS_Edge& e)
{
  for (Standard_Integer i = 0; i < static_cast<Standard_Integer>(edges.size()); ++i)
  {
    if (!e.IsNull() && edges[static_cast<size_t>(i)].IsSame(e))
      return i + 1;
  }
  return 0;
}

Standard_Integer VertexIndexIn(const std::vector<TopoDS_Vertex>& vertices, const TopoDS_Vertex& v)
{
  for (Standard_Integer i = 0; i < static_cast<Standard_Integer>(vertices.size()); ++i)
  {
    if (!v.IsNull() && vertices[static_cast<size_t>(i)].IsSame(v))
      return i + 1;
  }
  return 0;
}

Standard_Integer CountGeneratedFacesForEdges(BRepFilletAPI_MakeFillet& mk, const std::vector<TopoDS_Edge>& edges)
{
  Standard_Integer total = 0;
  for (const auto& e : edges)
  {
    const TopTools_ListOfShape& gen = mk.Generated(e);
    for (TopTools_ListIteratorOfListOfShape it(gen); it.More(); it.Next())
    {
      const TopoDS_Shape s = it.Value();
      if (s.ShapeType() == TopAbs_FACE)
        total += 1;
    }
  }
  return total;
}

Standard_Integer CountGeneratedFacesForEdges(BRepFilletAPI_MakeChamfer& mk,
                                             const std::vector<TopoDS_Edge>& edges)
{
  Standard_Integer total = 0;
  for (const auto& e : edges)
  {
    const TopTools_ListOfShape& gen = mk.Generated(e);
    for (TopTools_ListIteratorOfListOfShape it(gen); it.More(); it.Next())
    {
      const TopoDS_Shape s = it.Value();
      if (s.ShapeType() == TopAbs_FACE)
        total += 1;
    }
  }
  return total;
}

std::map<std::string, int> ComputedSurfaceTypeHistogram(BRepFilletAPI_MakeFillet& mk,
                                                        const Standard_Integer    ic)
{
  std::map<std::string, int> hist;
  const Standard_Integer nb = mk.NbComputedSurfaces(ic);
  for (Standard_Integer is = 1; is <= nb; ++is)
  {
    const Handle(Geom_Surface) surf = mk.ComputedSurface(ic, is);
    hist[TypeName(surf)] += 1;
  }
  return hist;
}

void EmitFilletCase(std::ostream& out,
                    const char* name,
                    const ProgramOptions& opts,
                    const TopoDS_Shape& input,
                    const std::vector<TopoDS_Edge>& inputEdges,
                    const std::vector<TopoDS_Edge>& edgesToFillet,
                    const Standard_Real radius,
                    const bool last)
{
  BRepFilletAPI_MakeFillet mk(input);
  for (const auto& e : edgesToFillet)
  {
    mk.Add(radius, e);
  }

  bool didThrow = false;
  std::string exception;
  try
  {
    mk.Build();
  }
  catch (const Standard_Failure& ex)
  {
    didThrow = true;
    exception = ex.GetMessageString() == nullptr ? "" : ex.GetMessageString();
  }

  const Standard_Integer nbContours = mk.NbContours();
  const Standard_Integer nbFaultyContours = mk.NbFaultyContours();
  const Standard_Integer nbFaultyVertices = mk.NbFaultyVertices();
  const Standard_Boolean hasResult = mk.HasResult();
  const Standard_Boolean isDone = mk.IsDone();

  TopoDS_Shape result;
  if (isDone)
  {
    try
    {
      result = mk.Shape();
    }
    catch (const Standard_Failure& ex)
    {
      didThrow = true;
      if (exception.empty())
        exception = ex.GetMessageString() == nullptr ? "" : ex.GetMessageString();
    }
  }

  TopoDS_Shape badShape;
  if (hasResult)
  {
    try
    {
      badShape = mk.BadShape();
    }
    catch (const Standard_Failure&)
    {
    }
  }

  if (!opts.artifactsDir.empty())
  {
    TopTools_IndexedMapOfShape vertsMap;
    TopExp::MapShapes(input, TopAbs_VERTEX, vertsMap);
    std::vector<TopoDS_Vertex> inputVertices;
    inputVertices.reserve(static_cast<size_t>(vertsMap.Size()));
    for (Standard_Integer i = 1; i <= vertsMap.Size(); ++i)
      inputVertices.push_back(TopoDS::Vertex(vertsMap(i)));

    ExFilBuilder builder(input);
    for (const auto& e : edgesToFillet)
    {
      builder.Add(e);
      Standard_Integer indexInContour = 0;
      const Standard_Integer ic = builder.Contains(e, indexInContour);
      if (ic > 0)
      {
        builder.SetRadius(gp_XY(0., radius), ic, indexInContour);
        builder.SetRadius(gp_XY(1., radius), ic, indexInContour);
      }
    }
    try
    {
      builder.Compute();
    }
    catch (const Standard_Failure&)
    {
    }
    WriteChFiDSModelJson(builder, inputEdges, inputVertices, name, "fillet", (opts.artifactsDir / name / "model.json"));
  }

  const ShapeCounts counts = Count(result);
  const ShapeCounts badCounts = Count(badShape);
  const Standard_Boolean isValid = result.IsNull() ? Standard_False : BRepCheck_Analyzer(result).IsValid();
  const Standard_Integer generatedFaces = isDone ? CountGeneratedFacesForEdges(mk, edgesToFillet) : 0;
  const Standard_Integer nbSurfaces = isDone ? mk.NbSurfaces() : 0;

  out << "    " << JsonEscape(name) << ": {\n";
  out << "      \"kind\": \"fillet\",\n";
  out << "      \"params\": { \"radius\": " << std::setprecision(17) << radius << " },\n";
  out << "      \"selection\": { \"edges_added\": " << edgesToFillet.size() << " },\n";
  out << "      \"build\": {\n";
  out << "        \"did_throw\": " << (didThrow ? "true" : "false") << ",\n";
  out << "        \"exception\": " << JsonEscape(exception) << ",\n";
  out << "        \"is_done\": " << (isDone ? "true" : "false") << ",\n";
  out << "        \"nb_contours\": " << nbContours << ",\n";
  out << "        \"nb_surfaces\": " << nbSurfaces << ",\n";
  out << "        \"nb_faulty_contours\": " << nbFaultyContours << ",\n";
  out << "        \"faulty_contours\": [";
  for (Standard_Integer i = 1; i <= nbFaultyContours; ++i)
  {
    if (i != 1)
      out << ", ";
    out << mk.FaultyContour(i);
  }
  out << "],\n";
  out << "        \"nb_faulty_vertices\": " << nbFaultyVertices << ",\n";
  out << "        \"faulty_vertices\": [";
  for (Standard_Integer i = 1; i <= nbFaultyVertices; ++i)
  {
    const TopoDS_Vertex v = mk.FaultyVertex(i);
    const gp_Pnt p = VertexPoint(v);
    const Standard_Real tol = v.IsNull() ? 0.0 : BRep_Tool::Tolerance(v);
    if (i != 1)
      out << ", ";
    out << "{ \"iv\": " << i << ", \"p\": [";
    out << std::setprecision(17) << p.X() << ", " << p.Y() << ", " << p.Z();
    out << "], \"tol\": " << std::setprecision(17) << tol << " }";
  }
  out << "],\n";
  out << "        \"has_result\": " << (hasResult ? "true" : "false") << ",\n";
  out << "        \"generated_faces_from_selected_edges\": " << generatedFaces << ",\n";
  out << "        \"contours\": [\n";
  for (Standard_Integer ic = 1; ic <= nbContours; ++ic)
  {
    const Standard_Integer nbEdges = mk.NbEdges(ic);
    const Standard_Integer nbSurf = mk.NbSurf(ic);
    const ChFiDS_ErrorStatus st = mk.StripeStatus(ic);
    const Standard_Integer nbComputedSurfaces = mk.NbComputedSurfaces(ic);
    out << "          {";
    out << "\"ic\": " << ic << ", ";
    out << "\"nb_edges\": " << nbEdges << ", ";
    out << "\"edge_indices\": [";
    for (Standard_Integer ie = 1; ie <= nbEdges; ++ie)
    {
      if (ie != 1)
        out << ", ";
      out << EdgeIndexIn(inputEdges, mk.Edge(ic, ie));
    }
    out << "], ";
    out << "\"nb_surf\": " << nbSurf << ", ";
    out << "\"stripe_status\": " << static_cast<int>(st) << ", ";
    out << "\"stripe_status_name\": " << JsonEscape(StripeStatusName(st));
    out << ", \"nb_computed_surfaces\": " << nbComputedSurfaces << ", ";
    out << "\"computed_surface_types\": ";
    PrintSurfaceHistogram(out, ComputedSurfaceTypeHistogram(mk, ic));
    out << "}";
    if (ic != nbContours)
      out << ",";
    out << "\n";
  }
  out << "        ]\n";
  out << "      },\n";
  out << "      \"result\": {\n";
  out << "        \"is_valid\": " << (isValid ? "true" : "false") << ",\n";
  out << "        \"counts\": { \"solids\": " << counts.solids << ", \"faces\": " << counts.faces
      << ", \"edges\": " << counts.edges << ", \"vertices\": " << counts.vertices << " },\n";
  out << "        \"bbox\": ";
  PrintBBox(out, result);
  out << ",\n";
  out << "        \"surface_types\": ";
  PrintSurfaceHistogram(out, SurfaceTypeHistogram(result));
  out << "\n";
  out << "      },\n";
  out << "      \"partial_result\": {\n";
  out << "        \"has_bad_shape\": " << (hasResult ? "true" : "false") << ",\n";
  out << "        \"bad_shape_counts\": { \"solids\": " << badCounts.solids << ", \"faces\": " << badCounts.faces
      << ", \"edges\": " << badCounts.edges << ", \"vertices\": " << badCounts.vertices << " },\n";
  out << "        \"bad_shape_bbox\": ";
  PrintBBox(out, badShape);
  out << "\n";
  out << "      },\n";
  EmitArtifacts(out, opts, name, input, result, badShape);
  out << "    }" << (last ? "\n" : ",\n");
}

void EmitFilletCaseVarRadius(std::ostream& out,
                             const char* name,
                             const ProgramOptions& opts,
                             const TopoDS_Shape& input,
                             const std::vector<TopoDS_Edge>& inputEdges,
                             const std::vector<TopoDS_Edge>& edgesToFillet,
                             const Standard_Real r1,
                             const Standard_Real r2,
                             const bool last)
{
  BRepFilletAPI_MakeFillet mk(input);
  for (const auto& e : edgesToFillet)
  {
    mk.Add(r1, r2, e);
  }

  bool didThrow = false;
  std::string exception;
  try
  {
    mk.Build();
  }
  catch (const Standard_Failure& ex)
  {
    didThrow = true;
    exception = ex.GetMessageString() == nullptr ? "" : ex.GetMessageString();
  }

  const Standard_Integer nbContours = mk.NbContours();
  const Standard_Integer nbFaultyContours = mk.NbFaultyContours();
  const Standard_Integer nbFaultyVertices = mk.NbFaultyVertices();
  const Standard_Boolean hasResult = mk.HasResult();
  const Standard_Boolean isDone = mk.IsDone();

  TopoDS_Shape result;
  if (isDone)
  {
    try
    {
      result = mk.Shape();
    }
    catch (const Standard_Failure& ex)
    {
      didThrow = true;
      if (exception.empty())
        exception = ex.GetMessageString() == nullptr ? "" : ex.GetMessageString();
    }
  }

  TopoDS_Shape badShape;
  if (hasResult)
  {
    try
    {
      badShape = mk.BadShape();
    }
    catch (const Standard_Failure&)
    {
    }
  }

  if (!opts.artifactsDir.empty())
  {
    TopTools_IndexedMapOfShape vertsMap;
    TopExp::MapShapes(input, TopAbs_VERTEX, vertsMap);
    std::vector<TopoDS_Vertex> inputVertices;
    inputVertices.reserve(static_cast<size_t>(vertsMap.Size()));
    for (Standard_Integer i = 1; i <= vertsMap.Size(); ++i)
      inputVertices.push_back(TopoDS::Vertex(vertsMap(i)));

    ExFilBuilder builder(input);
    for (const auto& e : edgesToFillet)
    {
      builder.Add(e);
      Standard_Integer indexInContour = 0;
      const Standard_Integer ic = builder.Contains(e, indexInContour);
      if (ic > 0)
      {
        builder.SetRadius(gp_XY(0., r1), ic, indexInContour);
        builder.SetRadius(gp_XY(1., r2), ic, indexInContour);
      }
    }
    try
    {
      builder.Compute();
    }
    catch (const Standard_Failure&)
    {
    }
    WriteChFiDSModelJson(builder, inputEdges, inputVertices, name, "fillet", (opts.artifactsDir / name / "model.json"));
  }

  const ShapeCounts counts = Count(result);
  const ShapeCounts badCounts = Count(badShape);
  const Standard_Boolean isValid = result.IsNull() ? Standard_False : BRepCheck_Analyzer(result).IsValid();
  const Standard_Integer generatedFaces = isDone ? CountGeneratedFacesForEdges(mk, edgesToFillet) : 0;
  const Standard_Integer nbSurfaces = isDone ? mk.NbSurfaces() : 0;

  out << "    " << JsonEscape(name) << ": {\n";
  out << "      \"kind\": \"fillet\",\n";
  out << "      \"params\": { \"r1\": " << std::setprecision(17) << r1 << ", \"r2\": " << std::setprecision(17)
      << r2 << " },\n";
  out << "      \"selection\": { \"edges_added\": " << edgesToFillet.size() << " },\n";
  out << "      \"build\": {\n";
  out << "        \"did_throw\": " << (didThrow ? "true" : "false") << ",\n";
  out << "        \"exception\": " << JsonEscape(exception) << ",\n";
  out << "        \"is_done\": " << (isDone ? "true" : "false") << ",\n";
  out << "        \"nb_contours\": " << nbContours << ",\n";
  out << "        \"nb_surfaces\": " << nbSurfaces << ",\n";
  out << "        \"nb_faulty_contours\": " << nbFaultyContours << ",\n";
  out << "        \"faulty_contours\": [";
  for (Standard_Integer i = 1; i <= nbFaultyContours; ++i)
  {
    if (i != 1)
      out << ", ";
    out << mk.FaultyContour(i);
  }
  out << "],\n";
  out << "        \"nb_faulty_vertices\": " << nbFaultyVertices << ",\n";
  out << "        \"faulty_vertices\": [";
  for (Standard_Integer i = 1; i <= nbFaultyVertices; ++i)
  {
    const TopoDS_Vertex v = mk.FaultyVertex(i);
    const gp_Pnt p = VertexPoint(v);
    const Standard_Real tol = v.IsNull() ? 0.0 : BRep_Tool::Tolerance(v);
    if (i != 1)
      out << ", ";
    out << "{ \"iv\": " << i << ", \"p\": [";
    out << std::setprecision(17) << p.X() << ", " << p.Y() << ", " << p.Z();
    out << "], \"tol\": " << std::setprecision(17) << tol << " }";
  }
  out << "],\n";
  out << "        \"has_result\": " << (hasResult ? "true" : "false") << ",\n";
  out << "        \"generated_faces_from_selected_edges\": " << generatedFaces << ",\n";
  out << "        \"contours\": [\n";
  for (Standard_Integer ic = 1; ic <= nbContours; ++ic)
  {
    const Standard_Integer nbEdges = mk.NbEdges(ic);
    const Standard_Integer nbSurf = mk.NbSurf(ic);
    const ChFiDS_ErrorStatus st = mk.StripeStatus(ic);
    const Standard_Integer nbComputedSurfaces = mk.NbComputedSurfaces(ic);
    out << "          {";
    out << "\"ic\": " << ic << ", ";
    out << "\"nb_edges\": " << nbEdges << ", ";
    out << "\"edge_indices\": [";
    for (Standard_Integer ie = 1; ie <= nbEdges; ++ie)
    {
      if (ie != 1)
        out << ", ";
      out << EdgeIndexIn(inputEdges, mk.Edge(ic, ie));
    }
    out << "], ";
    out << "\"nb_surf\": " << nbSurf << ", ";
    out << "\"stripe_status\": " << static_cast<int>(st) << ", ";
    out << "\"stripe_status_name\": " << JsonEscape(StripeStatusName(st));
    out << ", \"nb_computed_surfaces\": " << nbComputedSurfaces << ", ";
    out << "\"computed_surface_types\": ";
    PrintSurfaceHistogram(out, ComputedSurfaceTypeHistogram(mk, ic));
    out << "}";
    if (ic != nbContours)
      out << ",";
    out << "\n";
  }
  out << "        ]\n";
  out << "      },\n";
  out << "      \"result\": {\n";
  out << "        \"is_valid\": " << (isValid ? "true" : "false") << ",\n";
  out << "        \"counts\": { \"solids\": " << counts.solids << ", \"faces\": " << counts.faces
      << ", \"edges\": " << counts.edges << ", \"vertices\": " << counts.vertices << " },\n";
  out << "        \"bbox\": ";
  PrintBBox(out, result);
  out << ",\n";
  out << "        \"surface_types\": ";
  PrintSurfaceHistogram(out, SurfaceTypeHistogram(result));
  out << "\n";
  out << "      },\n";
  out << "      \"partial_result\": {\n";
  out << "        \"has_bad_shape\": " << (hasResult ? "true" : "false") << ",\n";
  out << "        \"bad_shape_counts\": { \"solids\": " << badCounts.solids << ", \"faces\": " << badCounts.faces
      << ", \"edges\": " << badCounts.edges << ", \"vertices\": " << badCounts.vertices << " },\n";
  out << "        \"bad_shape_bbox\": ";
  PrintBBox(out, badShape);
  out << "\n";
  out << "      },\n";
  EmitArtifacts(out, opts, name, input, result, badShape);
  out << "    }" << (last ? "\n" : ",\n");
}

void EmitChamferCase(std::ostream& out,
                     const char* name,
                     const ProgramOptions& opts,
                     const TopoDS_Shape& input,
                     const std::vector<TopoDS_Edge>& inputEdges,
                     const std::vector<TopoDS_Edge>& edgesToChamfer,
                     const Standard_Real dist,
                     const bool last)
{
  BRepFilletAPI_MakeChamfer mk(input);
  for (const auto& e : edgesToChamfer)
  {
    mk.Add(dist, e);
  }

  bool didThrow = false;
  std::string exception;
  try
  {
    mk.Build();
  }
  catch (const Standard_Failure& ex)
  {
    didThrow = true;
    exception = ex.GetMessageString() == nullptr ? "" : ex.GetMessageString();
  }

  const Standard_Integer nbContours = mk.NbContours();
  const Standard_Boolean isDone = mk.IsDone();

  TopoDS_Shape result;
  if (isDone)
  {
    try
    {
      result = mk.Shape();
    }
    catch (const Standard_Failure& ex)
    {
      didThrow = true;
      if (exception.empty())
        exception = ex.GetMessageString() == nullptr ? "" : ex.GetMessageString();
    }
  }

  const ShapeCounts counts = Count(result);
  const Standard_Boolean isValid = result.IsNull() ? Standard_False : BRepCheck_Analyzer(result).IsValid();
  const Standard_Integer generatedFaces = isDone ? CountGeneratedFacesForEdges(mk, edgesToChamfer) : 0;

  if (!opts.artifactsDir.empty())
  {
    TopTools_IndexedMapOfShape vertsMap;
    TopExp::MapShapes(input, TopAbs_VERTEX, vertsMap);
    std::vector<TopoDS_Vertex> inputVertices;
    inputVertices.reserve(static_cast<size_t>(vertsMap.Size()));
    for (Standard_Integer i = 1; i <= vertsMap.Size(); ++i)
      inputVertices.push_back(TopoDS::Vertex(vertsMap(i)));

    ExChBuilder builder(input);
    for (const auto& e : edgesToChamfer)
      builder.Add(dist, e);
    try
    {
      builder.Compute();
    }
    catch (const Standard_Failure&)
    {
    }
    WriteChFiDSModelJson(builder, inputEdges, inputVertices, name, "chamfer", (opts.artifactsDir / name / "model.json"));
  }

  out << "    " << JsonEscape(name) << ": {\n";
  out << "      \"kind\": \"chamfer\",\n";
  out << "      \"params\": { \"dist\": " << std::setprecision(17) << dist << " },\n";
  out << "      \"selection\": { \"edges_added\": " << edgesToChamfer.size() << " },\n";
  out << "      \"build\": {\n";
  out << "        \"did_throw\": " << (didThrow ? "true" : "false") << ",\n";
  out << "        \"exception\": " << JsonEscape(exception) << ",\n";
  out << "        \"is_done\": " << (isDone ? "true" : "false") << ",\n";
  out << "        \"nb_contours\": " << nbContours << ",\n";
  out << "        \"nb_surfaces\": -1,\n";
  out << "        \"nb_faulty_contours\": -1,\n";
  out << "        \"faulty_contours\": [],\n";
  out << "        \"nb_faulty_vertices\": -1,\n";
  out << "        \"faulty_vertices\": [],\n";
  out << "        \"has_result\": false,\n";
  out << "        \"generated_faces_from_selected_edges\": " << generatedFaces << ",\n";
  out << "        \"contours\": [\n";
  for (Standard_Integer ic = 1; ic <= nbContours; ++ic)
  {
    const Standard_Integer nbEdges = mk.NbEdges(ic);
    const Standard_Integer nbSurf = mk.NbSurf(ic);
    out << "          {";
    out << "\"ic\": " << ic << ", ";
    out << "\"nb_edges\": " << nbEdges << ", ";
    out << "\"edge_indices\": [";
    for (Standard_Integer ie = 1; ie <= nbEdges; ++ie)
    {
      if (ie != 1)
        out << ", ";
      out << EdgeIndexIn(inputEdges, mk.Edge(ic, ie));
    }
    out << "], ";
    out << "\"nb_surf\": " << nbSurf << ", ";
    out << "\"stripe_status\": -1, ";
    out << "\"stripe_status_name\": \"N/A\"";
    out << ", \"nb_computed_surfaces\": -1, ";
    out << "\"computed_surface_types\": {}";
    out << "}";
    if (ic != nbContours)
      out << ",";
    out << "\n";
  }
  out << "        ]\n";
  out << "      },\n";
  out << "      \"result\": {\n";
  out << "        \"is_valid\": " << (isValid ? "true" : "false") << ",\n";
  out << "        \"counts\": { \"solids\": " << counts.solids << ", \"faces\": " << counts.faces
      << ", \"edges\": " << counts.edges << ", \"vertices\": " << counts.vertices << " },\n";
  out << "        \"bbox\": ";
  PrintBBox(out, result);
  out << ",\n";
  out << "        \"surface_types\": ";
  PrintSurfaceHistogram(out, SurfaceTypeHistogram(result));
  out << "\n";
  out << "      },\n";
  out << "      \"partial_result\": {\n";
  out << "        \"has_bad_shape\": false,\n";
  out << "        \"bad_shape_counts\": { \"solids\": 0, \"faces\": 0, \"edges\": 0, \"vertices\": 0 },\n";
  out << "        \"bad_shape_bbox\": { \"is_void\": true }\n";
  out << "      },\n";
  EmitArtifacts(out, opts, name, input, result, TopoDS_Shape());
  out << "    }" << (last ? "\n" : ",\n");
}
} // namespace

int main(int argc, char** argv)
{
  std::cout.imbue(std::locale::classic());

  ProgramOptions opts;
  for (int i = 1; i < argc; ++i)
  {
    const std::string arg = argv[i];
    if (arg == "--artifacts-dir" && i + 1 < argc)
    {
      opts.artifactsDir = std::filesystem::path(argv[++i]);
    }
    else if (arg == "--mesh-deflection" && i + 1 < argc)
    {
      opts.meshDeflection = std::stod(argv[++i]);
    }
  }

  const char* versionStr = OCCT_Version_String_Extended();
  const char* devStr = OCCT_DevelopmentVersion();

  const TopoDS_Shape box = BRepPrimAPI_MakeBox(gp_Pnt(0.0, 0.0, 0.0), gp_Pnt(10.0, 10.0, 10.0)).Shape();
  const TopoDS_Shape cylSplit = MakeSplitRimCylinder(5.0, 10.0);

  TopTools_IndexedMapOfShape edgesMap;
  TopExp::MapShapes(box, TopAbs_EDGE, edgesMap);
  std::vector<TopoDS_Edge> edges;
  edges.reserve(edgesMap.Size());
  for (Standard_Integer i = 1; i <= edgesMap.Size(); ++i)
  {
    edges.push_back(TopoDS::Edge(edgesMap(i)));
  }

  std::vector<TopoDS_Edge> singleEdge;
  if (!edges.empty())
    singleEdge.push_back(edges.front());

  const TopoDS_Vertex vCorner = FindMinCornerVertex(box);
  const std::vector<TopoDS_Edge> cornerEdges = EdgesIncidentToVertex(box, vCorner);

  TopTools_IndexedMapOfShape cylEdgesMap;
  TopExp::MapShapes(cylSplit, TopAbs_EDGE, cylEdgesMap);
  std::vector<TopoDS_Edge> cylEdges;
  cylEdges.reserve(cylEdgesMap.Size());
  for (Standard_Integer i = 1; i <= cylEdgesMap.Size(); ++i)
  {
    cylEdges.push_back(TopoDS::Edge(cylEdgesMap(i)));
  }
  const std::vector<TopoDS_Edge> cylTopRimEdges = EdgesAtZCircle(cylSplit, 10.0, 1e-7);

  std::cout << "{\n";
  std::cout << "  \"meta\": {\n";
  std::cout << "    \"occt_version\": " << JsonEscape(versionStr == nullptr ? "" : versionStr) << ",\n";
  std::cout << "    \"occt_dev\": " << JsonEscape(devStr == nullptr ? "" : devStr) << "\n";
  std::cout << "  },\n";
  std::cout << "  \"inputs\": {\n";
  std::cout << "    \"box\": { \"bbox\": ";
  PrintBBox(std::cout, box);
  std::cout << ", \"counts\": { \"solids\": " << Count(box).solids << ", \"faces\": " << Count(box).faces
            << ", \"edges\": " << Count(box).edges << ", \"vertices\": " << Count(box).vertices << " } }\n";
  std::cout << "    ,\n    \"cylinder_split\": { \"bbox\": ";
  PrintBBox(std::cout, cylSplit);
  std::cout << ", \"counts\": { \"solids\": " << Count(cylSplit).solids << ", \"faces\": " << Count(cylSplit).faces
            << ", \"edges\": " << Count(cylSplit).edges << ", \"vertices\": " << Count(cylSplit).vertices << " } }\n";
  std::cout << "  },\n";
  std::cout << "  \"cases\": {\n";

  EmitFilletCase(std::cout, "single_edge_radius_1", opts, box, edges, singleEdge, 1.0, false);
  EmitFilletCase(std::cout, "corner_3_edges_radius_1", opts, box, edges, cornerEdges, 1.0, false);
  EmitFilletCase(std::cout, "cylinder_split_rim_radius_1", opts, cylSplit, cylEdges, cylTopRimEdges, 1.0, false);
  EmitFilletCaseVarRadius(std::cout, "single_edge_var_radius_0_5_to_2", opts, box, edges, singleEdge, 0.5, 2.0, false);
  EmitFilletCase(std::cout, "single_edge_radius_100", opts, box, edges, singleEdge, 100.0, false);
  EmitChamferCase(std::cout, "single_edge_chamfer_dist_1", opts, box, edges, singleEdge, 1.0, false);
  EmitChamferCase(std::cout, "corner_3_edges_chamfer_dist_1", opts, box, edges, cornerEdges, 1.0, true);

  std::cout << "  }\n";
  std::cout << "}\n";
  return 0;
}
