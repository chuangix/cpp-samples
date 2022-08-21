#include <iostream>
#include <limits>

using namespace std;

void showBuiltIn();
void showUserDefined();
void showFunctions();
void showPointers();
void showReferences();

int main() {
  cout << __FILE__ << endl;
  showBuiltIn();
  showUserDefined();
  showFunctions();
  showPointers();
  showReferences();
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

void showUserDefined() {}

void showFunctions() {}

void showPointers() {}

void showReferences() {}