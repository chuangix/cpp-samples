#include <iostream>

using namespace std;

int main()
{
    cout << __FILE__ << endl;
    char c;
    uint8_t u8;
    uint16_t u16;
    uint32_t u32;
    uint64_t u64;
    int8_t i8;
    int16_t i16;
    int32_t i32;
    int64_t i64;
    float f;
    double d;
    bool b;
    cout << "The size of \"char\":" << sizeof(c) << endl;
    cout << "The size of \"uint8_t\":" << sizeof(u8) << endl;
    cout << "The size of \"uint16_t\":" << sizeof(u16) << endl;
    cout << "The size of \"uint32_t\":" << sizeof(u32) << endl;
    cout << "The size of \"uint64_t\":" << sizeof(u64) << endl;
    cout << "The size of \"int8_t\":" << sizeof(i8) << endl;
    cout << "The size of \"int16_t\":" << sizeof(i16) << endl;
    cout << "The size of \"int32_t\":" << sizeof(i32) << endl;
    cout << "The size of \"int64_t\":" << sizeof(i64) << endl;
    cout << "The size of \"bool\":" << sizeof(bool) << endl;
    return 0;
}