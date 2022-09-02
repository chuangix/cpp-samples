#include <boost/any.hpp>
#include <boost/optional.hpp>
#include <boost/variant.hpp>
#include <iostream>
#include <limits>

using namespace std;

void showBuiltIn();
void showEnumClass();
void showVariant();
void showStruct();
void showFunction();
void showSmartPointer();
void showReference();

int main() {
  showBuiltIn();
  showEnumClass();
  showVariant();
  showStruct();
  showFunction();
  showSmartPointer();
  showReference();
  return 0;
}

void showBuiltIn() {
  char c;
  int8_t i8;
  int16_t i16;
  int32_t i32;
  int64_t i64;
  uint8_t u8;
  uint16_t u16;
  uint32_t u32;
  uint64_t u64;
  float f;
  double d;
  bool b;
  cout << "The size of \"char\":" << sizeof(c)
       << ", min value:" << static_cast<double>(numeric_limits<char>::min())
       << ", max value:" << static_cast<double>(numeric_limits<char>::max())
       << endl;
  cout << "The size of \"int8_t\":" << sizeof(i8)
       << ", min value:" << static_cast<double>(numeric_limits<int8_t>::min())
       << ", max value:" << static_cast<double>(numeric_limits<int8_t>::max())
       << endl;
  cout << "The size of \"int16_t\":" << sizeof(i16)
       << ", min value:" << static_cast<double>(numeric_limits<int16_t>::min())
       << ", max value:" << static_cast<double>(numeric_limits<int16_t>::max())
       << endl;
  cout << "The size of \"int32_t\":" << sizeof(i32)
       << ", min value:" << static_cast<double>(numeric_limits<int32_t>::min())
       << ", max value:" << static_cast<double>(numeric_limits<int32_t>::max())
       << endl;
  cout << "The size of \"int64_t\":" << sizeof(i64)
       << ", min value:" << static_cast<double>(numeric_limits<int64_t>::min())
       << ", max value:" << static_cast<double>(numeric_limits<int64_t>::max())
       << endl;
  cout << "The size of \"uint8_t\":" << sizeof(u8)
       << ", min value:" << static_cast<double>(numeric_limits<uint8_t>::min())
       << ", max value:" << static_cast<double>(numeric_limits<uint8_t>::max())
       << endl;
  cout << "The size of \"uint16_t\":" << sizeof(u16)
       << ", min value:" << static_cast<double>(numeric_limits<uint16_t>::min())
       << ", max value:" << static_cast<double>(numeric_limits<uint16_t>::max())
       << endl;
  cout << "The size of \"uint32_t\":" << sizeof(u32)
       << ", min value:" << static_cast<double>(numeric_limits<uint32_t>::min())
       << ", max value:" << static_cast<double>(numeric_limits<uint32_t>::max())
       << endl;
  cout << "The size of \"uint64_t\":" << sizeof(u64)
       << ", min value:" << static_cast<double>(numeric_limits<uint64_t>::min())
       << ", max value:" << static_cast<double>(numeric_limits<uint64_t>::max())
       << endl;
  cout << "The size of \"float\":" << sizeof(f)
       << ", min value:" << static_cast<double>(numeric_limits<float>::min())
       << ", max value:" << static_cast<double>(numeric_limits<float>::max())
       << endl;
  cout << "The size of \"double\":" << sizeof(d)
       << ", min value:" << static_cast<double>(numeric_limits<double>::min())
       << ", max value:" << static_cast<double>(numeric_limits<double>::max())
       << endl;
  cout << "The size of \"bool\":" << sizeof(bool)
       << ", min value:" << static_cast<double>(numeric_limits<bool>::min())
       << ", max value:" << static_cast<double>(numeric_limits<bool>::max())
       << endl;
}

void showEnumClass() {
  enum class E : int16_t { Red = -3, Green, Blue = 6, White };
  E red = E::Red;
  E green = E::Green;
  E blue = E::Blue;
  E white = E::White;
  cout << "The content of \"enum\" type \"E\":{" << endl;
  cout << "\tRed:" << static_cast<int16_t>(E::Red) << endl;
  cout << "\tGreen:" << static_cast<int16_t>(E::Green) << endl;
  cout << "\tBlue:" << static_cast<int16_t>(E::Blue) << endl;
  cout << "\tWhite:" << static_cast<int16_t>(E::White) << endl;
  cout << "}" << endl;
  cout << "The value of \"enum\" red:" << static_cast<int16_t>(red) << endl;
  cout << "The value of \"enum\" green:" << static_cast<int16_t>(green) << endl;
  cout << "The value of \"enum\" blue:" << static_cast<int16_t>(blue) << endl;
  cout << "The value of \"enum\" white:" << static_cast<int16_t>(white) << endl;
}

void showVariant() {}

void showStruct() {
  struct S1 {
    uint32_t a;
    uint8_t b;
    uint8_t c;
  };
  struct S2 {
    uint8_t a;
    uint8_t b;
    uint32_t c;
  };
  struct S3 {
    uint8_t a;
    uint32_t b;
    uint8_t c;
  };
  struct S4 {
    uint32_t a;
    uint8_t b;
    uint32_t c;
  };
  struct S5 {
    S1 s1;
    S2 s2;
  };
  S1 s1 = {1, 2, 3};
  S2 s2;
  s2.a = 4;
  s2.b = 5;
  s2.c = 6;
  cout << "The content of \"struct\" object \"s1\":{" << endl;
  cout << "\ta:" << static_cast<uint32_t>(s1.a) << endl;
  cout << "\tb:" << static_cast<uint32_t>(s1.b) << endl;
  cout << "\tc:" << static_cast<uint32_t>(s1.c) << endl;
  cout << "}" << endl;
  cout << "The content of \"struct\" object \"s2\":{" << endl;
  cout << "\ta:" << static_cast<uint32_t>(s2.a) << endl;
  cout << "\tb:" << static_cast<uint32_t>(s2.b) << endl;
  cout << "\tc:" << static_cast<uint32_t>(s2.c) << endl;
  cout << "}" << endl;
  cout << "The size of \"S1\":" << sizeof(S1) << endl;
  cout << "The size of \"S2\":" << sizeof(S2) << endl;
  cout << "The size of \"S3\":" << sizeof(S3) << endl;
  cout << "The size of \"S4\":" << sizeof(S4) << endl;
  cout << "The size of \"S5\":" << sizeof(S5) << endl;
}

void showFunction() {}

void showSmartPointer() {}

void showReference() {}
