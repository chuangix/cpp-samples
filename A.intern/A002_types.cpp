#include <exception>
#include <iostream>
#include <limits>
#include <memory>
#include <string>

#include <boost/any.hpp>
#include <boost/optional.hpp>
#include <boost/variant.hpp>

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

void useGet(const boost::variant<int, string> &);
void useRtti(const boost::variant<int, string> &);
void useVisitor(const boost::variant<int, string> &);

void showVariant() {
  boost::variant<int, string> v = "Hello world";
  useGet(v);
  useRtti(v);
  useVisitor(v);
}

void useGet(const boost::variant<int, string> &v) {
  try {
    cout << boost::get<int>(v) << endl;
  } catch (exception &e) {
    cout << e.what() << endl;
  }
  cout << boost::get<string>(v) << endl;
}

void useRtti(const boost::variant<int, string> &v) {
  if (v.type() == typeid(int)) {
    cout << boost::get<int>(v) << endl;
  } else if (v.type() == typeid(string)) {
    cout << boost::get<string>(v) << endl;
  }
}

void useVisitor(const boost::variant<int, string> &v) {
  class visitor : public boost::static_visitor<void> {
   public:
    void operator()(const int &i) const { cout << i << endl; }
    void operator()(const string &str) const { cout << str << endl; }
  };
  boost::apply_visitor(visitor(), v);
}

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

void showUniquePointer();
void showSharedPointer();
void showWeakPointer();

void showSmartPointer() {
  showUniquePointer();
  showSharedPointer();
  showWeakPointer();
}

void showUniquePointer() {}

void showSharedPointer() {
  struct St {
    int a;
  };
  St st;
  St *pst = &st;
  cout << "The original naked pointer points 0x" << hex << pst << endl;
  St &rst = st;
  const St &crst = st;
  shared_ptr<St> sp;
  cout << "The reference count after default construction is " << sp.use_count()
       << " and it points 0x" << hex << sp.get() << endl;
  sp = make_shared<St>();
  cout << "The reference count of the original shared pointer is "
       << sp.use_count() << " and it points 0x" << hex << sp.get() << endl;
  shared_ptr<St> &rsp = sp;
  cout
      << "The reference count of reference to original shared pointer [RSP] is "
      << rsp.use_count() << " and it points 0x" << hex << rsp.get() << endl;
  const shared_ptr<St> &crsp = sp;
  cout << "The reference count of const reference to original shared pointer "
          "[CRSP] is "
       << crsp.use_count() << " and it points 0x" << hex << crsp.get() << endl;
  shared_ptr<St> sp1CopyConstructByNakedPtr(pst);
  cout << "The reference count of copy construction using naked pointer once "
          "is  "
       << sp1CopyConstructByNakedPtr.use_count() << " and it points 0x" << hex
       << sp1CopyConstructByNakedPtr.get() << " => can be compiled but WRONG"
       << endl;
  shared_ptr<St> sp2CopyConstructByNakedPtr(pst);
  cout << "The reference count of copy construction using naked pointer twice "
          "is "
       << sp2CopyConstructByNakedPtr.use_count() << " and it points 0x" << hex
       << sp2CopyConstructByNakedPtr.get() << " => can be compiled but WRONG"
       << endl;
  shared_ptr<St> sp1CopyConstructBySharedPtr(sp);
  cout << "The reference count of copy construction using shared pointer once "
          "is  "
       << sp1CopyConstructBySharedPtr.use_count() << " and it points 0x" << hex
       << sp1CopyConstructBySharedPtr.get() << endl;
  shared_ptr<St> sp2CopyConstructBySharedPtr(sp);
  cout << "The reference count of copy construction using shared pointer twice "
          "is "
       << sp2CopyConstructBySharedPtr.use_count() << " and it points 0x" << hex
       << sp2CopyConstructBySharedPtr.get() << endl;
  shared_ptr<St> sp1CopyConstructByNew(new St());
  cout << "The reference count of copy construction using \"new\" once is  "
       << sp1CopyConstructByNew.use_count() << " and it points 0x" << hex
       << sp1CopyConstructByNew.get() << endl;
  shared_ptr<St> sp2CopyConstructByNew(new St());
  cout << "The reference count of copy construction using \"new\" twice is "
       << sp2CopyConstructByNew.use_count() << " and it points 0x" << hex
       << sp2CopyConstructByNew.get() << endl;
  shared_ptr<St> sp1CopyConstructByMakeShared(make_shared<St>());
  cout << "The reference count of copy construction using \"make_shared()\" "
          "once is  "
       << sp1CopyConstructByMakeShared.use_count() << " and it points 0x" << hex
       << sp1CopyConstructByMakeShared.get() << endl;
  shared_ptr<St> sp2CopyConstructByMakeShared(make_shared<St>());
  cout << "The reference count of copy construction using \"make_shared()\" "
          "twice is "
       << sp2CopyConstructByMakeShared.use_count() << " and it points 0x" << hex
       << sp2CopyConstructByMakeShared.get() << endl;
  shared_ptr<St> sp1AssignConstructByNakedPtr = shared_ptr<St>(pst);
  cout << "The reference count of assign construction using naked pointer "
          "once is  "
       << sp1AssignConstructByNakedPtr.use_count() << " and it points 0x" << hex
       << sp1AssignConstructByNakedPtr.get() << " => can be compiled but WRONG"
       << endl;
  shared_ptr<St> sp2AssignConstructByNakedPtr = shared_ptr<St>(pst);
  cout << "The reference count of assign construction using naked pointer "
          "twice is "
       << sp2AssignConstructByNakedPtr.use_count() << " and it points 0x" << hex
       << sp2AssignConstructByNakedPtr.get() << " => can be compiled but WRONG"
       << endl;
  shared_ptr<St> sp1AssignConstructBySharedPtr = shared_ptr<St>(sp);
  cout << "The reference count of assign construction using shared pointer "
          "once is  "
       << sp1AssignConstructBySharedPtr.use_count() << " and it points 0x"
       << hex << sp1AssignConstructBySharedPtr.get() << endl;
  shared_ptr<St> sp2AssignConstructBySharedPtr = shared_ptr<St>(sp);
  cout << "The reference count of assign construction using shared pointer "
          "twice is "
       << sp2AssignConstructBySharedPtr.use_count() << " and it points 0x"
       << hex << sp2AssignConstructBySharedPtr.get() << endl;
  shared_ptr<St> sp1AssignConstructByNew = shared_ptr<St>(new St());
  cout << "The reference count of assign construction using \"new\" once is  "
       << sp1AssignConstructByNew.use_count() << " and it points 0x" << hex
       << sp1AssignConstructByNew.get() << endl;
  shared_ptr<St> sp2AssignConstructByNew = shared_ptr<St>(new St());
  cout << "The reference count of assign construction using \"new\" twice is "
       << sp2AssignConstructByNew.use_count() << " and it points 0x" << hex
       << sp2AssignConstructByNew.get() << endl;
  shared_ptr<St> sp1AssignConstructByMakeShared = make_shared<St>();
  cout << "The reference count of assign construction using \"make_shared()\" "
          "once is  "
       << sp1AssignConstructByMakeShared.use_count() << " and it points 0x"
       << hex << sp1AssignConstructByMakeShared.get() << endl;
  shared_ptr<St> sp2AssignConstructByMakeShared = make_shared<St>();
  cout << "The reference count of assign construction using \"make_shared()\" "
          "twice is  "
       << sp2AssignConstructByMakeShared.use_count() << " and it points 0x"
       << hex << sp2AssignConstructByMakeShared.get() << endl;
  sp.reset();
  sp = make_shared<St>();
  shared_ptr<St> sp1;
  shared_ptr<St> sp2;
  shared_ptr<St> sp3;
  shared_ptr<St> sp4;
  shared_ptr<St> sp5;
  cout << "The original naked pointer [P] points 0x" << hex << pst << endl;
  cout << "The reference count of the original shared pointer [SP] is "
       << sp.use_count() << " and it points 0x" << hex << sp.get() << endl;
  cout << "The reference count of shared pointer [SP1] is " << sp1.use_count()
       << " and it points 0x" << hex << sp1.get() << endl;
  cout << "The reference count of shared pointer [SP2] is " << sp2.use_count()
       << " and it points 0x" << hex << sp2.get() << endl;
  cout << "The reference count of shared pointer [SP3] is " << sp3.use_count()
       << " and it points 0x" << hex << sp3.get() << endl;
  cout << "The reference count of shared pointer [SP4] is " << sp3.use_count()
       << " and it points 0x" << hex << sp4.get() << endl;
  cout << "The reference count of shared pointer [SP5] is " << sp3.use_count()
       << " and it points 0x" << hex << sp5.get() << endl;
  sp1 = shared_ptr<St>(pst);
  cout << "Copy a naked pointer to a shared pointer [SP1] = [P]:" << endl;
  cout << "The reference count of [SP1] is " << sp1.use_count()
       << " and it points 0x" << hex << sp1.get()
       << " => can be compiled but WRONG" << endl;
  sp2 = shared_ptr<St>(pst);
  cout << "Copy a naked pointer to a shared pointer [SP2] = [P]:" << endl;
  cout << "The reference count of [SP1] is " << sp1.use_count()
       << " and it points 0x" << hex << sp1.get()
       << " => can be compiled but WRONG" << endl;
  cout << "The reference count of [SP2] is " << sp2.use_count()
       << " and it points 0x" << hex << sp2.get()
       << " => can be compiled but WRONG" << endl;
  sp3 = sp;
  cout << "Copy a shared pointer to another shared pointer [SP3] = [SP]:"
       << endl;
  cout << "The reference count of [SP3] is " << sp3.use_count()
       << " and it points 0x" << hex << sp3.get() << endl;
  cout << "The reference count of [SP4] is " << sp4.use_count()
       << " and it points 0x" << hex << sp4.get() << endl;
  cout << "The reference count of [SP5] is " << sp5.use_count()
       << " and it points 0x" << hex << sp5.get() << endl;
  cout << "The reference count of the original shared pointer [SP] is "
       << sp.use_count() << " and it points 0x" << hex << sp.get() << endl;
  cout
      << "The reference count of reference to original shared pointer [RSP] is "
      << rsp.use_count() << " and it points 0x" << hex << rsp.get() << endl;
  sp4 = rsp;
  cout << "Copy a reference of original shared pointer to another shared "
          "pointer [SP4] = [RSP]:"
       << endl;
  cout << "The reference count of [SP3] is " << sp3.use_count()
       << " and it points 0x" << hex << sp3.get() << endl;
  cout << "The reference count of [SP4] is " << sp4.use_count()
       << " and it points 0x" << hex << sp4.get() << endl;
  cout << "The reference count of [SP5] is " << sp5.use_count()
       << " and it points 0x" << hex << sp5.get() << endl;
  cout << "The reference count of const reference to original shared pointer "
          "[CRSP] is "
       << crsp.use_count() << " and it points 0x" << hex << crsp.get() << endl;
  sp5 = crsp;
  cout << "Copy a const reference of original shared pointer to another shared "
          "pointer [SP5] = [CRSP]:"
       << endl;
  cout << "The reference count of [SP3] is " << sp3.use_count()
       << " and it points 0x" << hex << sp3.get() << endl;
  cout << "The reference count of [SP4] is " << sp4.use_count()
       << " and it points 0x" << hex << sp4.get() << endl;
  cout << "The reference count of [SP5] is " << sp5.use_count()
       << " and it points 0x" << hex << sp5.get() << endl;
}

void showWeakPointer() {}

void showReference() {}
