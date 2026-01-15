#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRep_Tool.hxx>
#include <BRepTools.hxx>
#include <Poly_Triangulation.hxx>
#include <Prs3d_Drawer.hxx>
#include <Standard_VersionInfo.hxx>
#include <StdPrs_ToolTriangulatedShape.hxx>
#include <TopExp.hxx>
#include <TopLoc_Location.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Shape.hxx>
#include <gp_Ax2.hxx>
#include <gp_Pnt.hxx>

#include <algorithm>
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
  Standard_Integer faces = 0;
  Standard_Integer facesWithTriangulation = 0;
  Standard_Integer totalNodes = 0;
  Standard_Integer totalTriangles = 0;
};

MeshStats CountTriangulation(const TopoDS_Shape& shape)
{
  MeshStats stats;
  TopTools_IndexedMapOfShape faces;
  TopExp::MapShapes(shape, TopAbs_FACE, faces);
  stats.faces = faces.Size();

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

std::string DeflectionModeToString(const Aspect_TypeOfDeflection mode)
{
  switch (mode)
  {
    case Aspect_TOD_RELATIVE:
      return "RELATIVE";
    case Aspect_TOD_ABSOLUTE:
      return "ABSOLUTE";
  }
  return "UNKNOWN";
}
} // namespace

int main()
{
  std::cout.imbue(std::locale::classic());

  const char* versionStr = OCCT_Version_String_Extended();
  const char* devStr = OCCT_DevelopmentVersion();

  const TopoDS_Shape box = BRepPrimAPI_MakeBox(gp_Pnt(0.0, 0.0, 0.0), gp_Pnt(10.0, 10.0, 10.0)).Shape();
  const TopoDS_Shape cylinder = BRepPrimAPI_MakeCylinder(gp_Ax2(gp_Pnt(0.0, 0.0, 0.0), gp::DZ()), 3.0, 10.0).Shape();

  struct Scenario
  {
    std::string name;
    Aspect_TypeOfDeflection mode = Aspect_TOD_ABSOLUTE;
    Standard_Real absDefl = 0.5;
    Standard_Real relCoeff = 0.01;
  };

  const std::vector<Scenario> scenarios = {
    {"abs_defl_0.5", Aspect_TOD_ABSOLUTE, 0.5, 0.01},
    {"abs_defl_0.05", Aspect_TOD_ABSOLUTE, 0.05, 0.01},
    {"rel_coeff_0.01", Aspect_TOD_RELATIVE, 0.5, 0.01},
  };

  auto runForShape = [&](const char* shapeName, const TopoDS_Shape& srcShape, const bool lastShape) {
    std::cout << "    " << JsonEscape(shapeName) << ": {\n";
    std::cout << "      \"scenarios\": {\n";

    for (size_t i = 0; i < scenarios.size(); ++i)
    {
      const Scenario& sc = scenarios[i];

      // Fresh shape each time to avoid reusing triangulation from other scenarios.
      TopoDS_Shape shape = srcShape;
      // Ensure there is no pre-existing triangulation.
      BRepTools::Clean(shape);

      Handle(Prs3d_Drawer) drawer = new Prs3d_Drawer();
      drawer->SetAutoTriangulation(Standard_True);
      drawer->SetTypeOfDeflection(sc.mode);
      drawer->SetMaximalChordialDeviation(sc.absDefl);
      drawer->SetDeviationCoefficient(sc.relCoeff);

      const Standard_Real effectiveDefl = StdPrs_ToolTriangulatedShape::GetDeflection(shape, drawer);
      const Standard_Boolean isTessellatedBefore = StdPrs_ToolTriangulatedShape::IsTessellated(shape, drawer);
      const Standard_Boolean didTessellate = StdPrs_ToolTriangulatedShape::Tessellate(shape, drawer);
      const Standard_Boolean isTessellatedAfter = StdPrs_ToolTriangulatedShape::IsTessellated(shape, drawer);

      const MeshStats stats = CountTriangulation(shape);
      const Standard_Boolean isClosed = StdPrs_ToolTriangulatedShape::IsClosed(shape);

      std::cout << "        " << JsonEscape(sc.name) << ": {\n";
      std::cout << "          \"deflection_mode\": " << JsonEscape(DeflectionModeToString(sc.mode)) << ",\n";
      std::cout << "          \"abs_deflection\": " << std::setprecision(17) << sc.absDefl << ",\n";
      std::cout << "          \"rel_coeff\": " << std::setprecision(17) << sc.relCoeff << ",\n";
      std::cout << "          \"effective_deflection\": " << std::setprecision(17) << effectiveDefl << ",\n";
      std::cout << "          \"is_tessellated_before\": " << (isTessellatedBefore ? "true" : "false") << ",\n";
      std::cout << "          \"tessellate_recomputed\": " << (didTessellate ? "true" : "false") << ",\n";
      std::cout << "          \"is_tessellated_after\": " << (isTessellatedAfter ? "true" : "false") << ",\n";
      std::cout << "          \"is_closed\": " << (isClosed ? "true" : "false") << ",\n";
      std::cout << "          \"triangulation\": { \"faces\": " << stats.faces
                << ", \"faces_with_triangulation\": " << stats.facesWithTriangulation
                << ", \"total_nodes\": " << stats.totalNodes
                << ", \"total_triangles\": " << stats.totalTriangles << " }\n";
      std::cout << "        }";

      if (i + 1 != scenarios.size())
      {
        std::cout << ",";
      }
      std::cout << "\n";
    }

    std::cout << "      }\n";
    std::cout << "    }" << (lastShape ? "\n" : ",\n");
  };

  std::cout << "{\n";
  std::cout << "  \"meta\": {\n";
  std::cout << "    \"occt_version\": " << JsonEscape(versionStr == nullptr ? "" : versionStr) << ",\n";
  std::cout << "    \"occt_dev\": " << JsonEscape(devStr == nullptr ? "" : devStr) << "\n";
  std::cout << "  },\n";
  std::cout << "  \"shapes\": {\n";
  runForShape("box", box, false);
  runForShape("cylinder", cylinder, true);
  std::cout << "  }\n";
  std::cout << "}\n";
  return 0;
}
