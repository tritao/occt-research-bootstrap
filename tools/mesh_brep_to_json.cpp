#include <BRep_Builder.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <BRepTools.hxx>
#include <BRep_Tool.hxx>
#include <Poly_Triangulation.hxx>
#include <TopExp_Explorer.hxx>
#include <TopLoc_Location.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Shape.hxx>
#include <gp_Pnt.hxx>

#include <algorithm>
#include <cfloat>
#include <fstream>
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
          out << "\\u" << std::hex << std::setw(4) << std::setfill('0') << static_cast<int>(c) << std::dec
              << std::setw(0);
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

struct Mesh
{
  std::vector<double> positions;
  std::vector<unsigned int> indices;
  double minX = DBL_MAX, minY = DBL_MAX, minZ = DBL_MAX;
  double maxX = -DBL_MAX, maxY = -DBL_MAX, maxZ = -DBL_MAX;

  void addPoint(const gp_Pnt& p)
  {
    const double x = p.X();
    const double y = p.Y();
    const double z = p.Z();
    positions.push_back(x);
    positions.push_back(y);
    positions.push_back(z);
    minX = std::min(minX, x);
    minY = std::min(minY, y);
    minZ = std::min(minZ, z);
    maxX = std::max(maxX, x);
    maxY = std::max(maxY, y);
    maxZ = std::max(maxZ, z);
  }

  bool isVoid() const { return positions.empty(); }
};

bool ReadBRep(const std::string& path, TopoDS_Shape& out)
{
  BRep_Builder builder;
  return BRepTools::Read(out, path.c_str(), builder);
}

Mesh MakeMesh(TopoDS_Shape shape, const double deflection)
{
  Mesh mesh;

  // Ensure a fresh triangulation (avoid stale cached meshes).
  BRepTools::Clean(shape);

  // Mesh the whole shape.
  BRepMesh_IncrementalMesh mesher(shape, deflection, Standard_False, 0.5, Standard_True);
  mesher.Perform();

  for (TopExp_Explorer ex(shape, TopAbs_FACE); ex.More(); ex.Next())
  {
    const TopoDS_Face face = TopoDS::Face(ex.Current());
    TopLoc_Location loc;
    const Handle(Poly_Triangulation) tri = BRep_Tool::Triangulation(face, loc);
    if (tri.IsNull())
    {
      continue;
    }

    const gp_Trsf tr = loc.Transformation();
    const unsigned int baseIndex = static_cast<unsigned int>(mesh.positions.size() / 3);
    for (Standard_Integer i = 1; i <= tri->NbNodes(); ++i)
    {
      mesh.addPoint(tri->Node(i).Transformed(tr));
    }

    for (Standard_Integer i = 1; i <= tri->NbTriangles(); ++i)
    {
      Standard_Integer n1 = 0, n2 = 0, n3 = 0;
      tri->Triangle(i).Get(n1, n2, n3);
      // Poly_Triangulation indices are 1-based for nodes.
      mesh.indices.push_back(baseIndex + static_cast<unsigned int>(n1 - 1));
      mesh.indices.push_back(baseIndex + static_cast<unsigned int>(n2 - 1));
      mesh.indices.push_back(baseIndex + static_cast<unsigned int>(n3 - 1));
    }
  }

  return mesh;
}
} // namespace

int main(int argc, char** argv)
{
  std::cout.imbue(std::locale::classic());

  if (argc < 3)
  {
    std::cerr << "usage: mesh_brep_to_json <input.brep> <output.mesh.json> [deflection]\n";
    return 2;
  }

  const std::string inputPath = argv[1];
  const std::string outputPath = argv[2];
  const double deflection = argc >= 4 ? std::stod(argv[3]) : 0.05;

  TopoDS_Shape shape;
  if (!ReadBRep(inputPath, shape) || shape.IsNull())
  {
    std::cerr << "failed to read BREP: " << inputPath << "\n";
    return 1;
  }

  const Mesh mesh = MakeMesh(shape, deflection);

  std::ofstream out(outputPath);
  if (!out)
  {
    std::cerr << "failed to open output: " << outputPath << "\n";
    return 1;
  }

  out.imbue(std::locale::classic());
  out << "{\n";
  out << "  \"format\": \"occt-research-mesh-v1\",\n";
  out << "  \"counts\": { \"vertices\": " << (mesh.positions.size() / 3) << ", \"triangles\": " << (mesh.indices.size() / 3) << " },\n";
  out << "  \"bbox\": { \"is_void\": " << (mesh.isVoid() ? "true" : "false") << ", \"min\": ["
      << std::setprecision(17) << (mesh.isVoid() ? 0.0 : mesh.minX) << ", "
      << (mesh.isVoid() ? 0.0 : mesh.minY) << ", " << (mesh.isVoid() ? 0.0 : mesh.minZ) << "], \"max\": ["
      << (mesh.isVoid() ? 0.0 : mesh.maxX) << ", " << (mesh.isVoid() ? 0.0 : mesh.maxY) << ", "
      << (mesh.isVoid() ? 0.0 : mesh.maxZ) << "] },\n";

  out << "  \"positions\": [";
  for (size_t i = 0; i < mesh.positions.size(); ++i)
  {
    if (i) out << ",";
    out << std::setprecision(17) << mesh.positions[i];
  }
  out << "],\n";

  out << "  \"indices\": [";
  for (size_t i = 0; i < mesh.indices.size(); ++i)
  {
    if (i) out << ",";
    out << mesh.indices[i];
  }
  out << "]\n";
  out << "}\n";

  return 0;
}
