#include <NCollection_List.hxx>
#include <Precision.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Standard_VersionInfo.hxx>
#include <gp_Ax1.hxx>
#include <gp_Dir.hxx>
#include <gp_Pnt.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec.hxx>

#include <cmath>
#include <iomanip>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>

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

void PrintReal(std::ostream& out, const Standard_Real value)
{
  out << std::setprecision(17) << value;
}

void PrintPnt(std::ostream& out, const gp_Pnt& pnt)
{
  out << '[';
  PrintReal(out, pnt.X());
  out << ", ";
  PrintReal(out, pnt.Y());
  out << ", ";
  PrintReal(out, pnt.Z());
  out << ']';
}

class DemoTransient : public Standard_Transient
{
public:
  explicit DemoTransient(const Standard_Integer theValue)
      : myValue(theValue)
  {
  }

  Standard_Integer Value() const { return myValue; }

private:
  Standard_Integer myValue = 0;
};
} // namespace

int main()
{
  std::cout.imbue(std::locale::classic());

  const char* versionStr = OCCT_Version_String_Extended();
  const char* devStr = OCCT_DevelopmentVersion();

  // Precision / tolerances
  const Standard_Real confusion = Precision::Confusion();
  const Standard_Real squareConfusion = Precision::SquareConfusion();
  const Standard_Real angular = Precision::Angular();
  const Standard_Real pConfusion = Precision::PConfusion();

  // gp basics
  const Standard_Real gpResolution = gp::Resolution();
  const gp_Pnt p0(10.0, 0.0, 0.0);

  gp_Trsf rotZ;
  rotZ.SetRotation(gp_Ax1(gp_Pnt(0.0, 0.0, 0.0), gp_Dir(0.0, 0.0, 1.0)), 0.5);
  gp_Trsf tr;
  tr.SetTranslation(gp_Vec(1.0, 2.0, 3.0));
  const gp_Trsf combo = tr * rotZ;
  const gp_Pnt p1 = p0.Transformed(combo);

  // Handle / refcount semantics (intrusive refcount on Standard_Transient)
  Handle(DemoTransient) h1 = new DemoTransient(42);
  const Standard_Integer rcAfterNew = h1->GetRefCount();
  Handle(DemoTransient) h2 = h1;
  const Standard_Integer rcAfterCopy = h1->GetRefCount();
  h2.Nullify();
  const Standard_Integer rcAfterNullifyCopy = h1->GetRefCount();

  // NCollection sanity (use ordered container to keep deterministic)
  NCollection_List<Standard_Integer> list;
  list.Append(1);
  list.Append(2);
  list.Append(3);
  Standard_Integer sum = 0;
  for (NCollection_List<Standard_Integer>::Iterator it(list); it.More(); it.Next())
  {
    sum += it.Value();
  }

  std::cout << "{\n";
  std::cout << "  \"meta\": {\n";
  std::cout << "    \"occt_version\": " << JsonEscape(versionStr == nullptr ? "" : versionStr) << ",\n";
  std::cout << "    \"occt_dev\": " << JsonEscape(devStr == nullptr ? "" : devStr) << ",\n";
  std::cout << "    \"sizeof\": {\n";
  std::cout << "      \"Standard_Integer\": " << sizeof(Standard_Integer) << ",\n";
  std::cout << "      \"Standard_Real\": " << sizeof(Standard_Real) << ",\n";
  std::cout << "      \"void_ptr\": " << sizeof(void*) << "\n";
  std::cout << "    }\n";
  std::cout << "  },\n";

  std::cout << "  \"precision\": {\n";
  std::cout << "    \"confusion\": ";
  PrintReal(std::cout, confusion);
  std::cout << ",\n";
  std::cout << "    \"square_confusion\": ";
  PrintReal(std::cout, squareConfusion);
  std::cout << ",\n";
  std::cout << "    \"angular\": ";
  PrintReal(std::cout, angular);
  std::cout << ",\n";
  std::cout << "    \"p_confusion\": ";
  PrintReal(std::cout, pConfusion);
  std::cout << "\n";
  std::cout << "  },\n";

  std::cout << "  \"gp\": {\n";
  std::cout << "    \"resolution\": ";
  PrintReal(std::cout, gpResolution);
  std::cout << ",\n";
  std::cout << "    \"transform\": {\n";
  std::cout << "      \"angle_rad\": ";
  PrintReal(std::cout, 0.5);
  std::cout << ",\n";
  std::cout << "      \"translation\": [1, 2, 3],\n";
  std::cout << "      \"p0\": ";
  PrintPnt(std::cout, p0);
  std::cout << ",\n";
  std::cout << "      \"p1\": ";
  PrintPnt(std::cout, p1);
  std::cout << "\n";
  std::cout << "    }\n";
  std::cout << "  },\n";

  std::cout << "  \"handles\": {\n";
  std::cout << "    \"value\": " << h1->Value() << ",\n";
  std::cout << "    \"refcount_after_new\": " << rcAfterNew << ",\n";
  std::cout << "    \"refcount_after_copy\": " << rcAfterCopy << ",\n";
  std::cout << "    \"refcount_after_nullify_copy\": " << rcAfterNullifyCopy << "\n";
  std::cout << "  },\n";

  std::cout << "  \"ncollection\": {\n";
  std::cout << "    \"list\": {\n";
  std::cout << "      \"size\": " << list.Size() << ",\n";
  std::cout << "      \"sum\": " << sum << "\n";
  std::cout << "    }\n";
  std::cout << "  }\n";
  std::cout << "}\n";

  return 0;
}

