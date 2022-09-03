#include <iostream>
#include <limits>
#include <string>

using namespace std;

void echoCharacter();
void echoInteger();
void echoString();
void echoLine();

int main() {
  echoCharacter();
  echoInteger();
  echoString();
  echoLine();
  return 0;
}

void echoCharacter() {
  char c;
  cout << "Input a character:";
  cin.get(c);
  cin.ignore(numeric_limits<streamsize>::max(),
             '\n');  //< @attention Clear redundant more than one character
  if (cin.bad()) {
    cout << "!! FATAL INPUT !!" << endl;
    cin.clear();
    abort();
  }
  if (cin.fail()) {
    cout << "!! WRONG INPUT !!" << endl;
    cin.clear();
    abort();
  }
  cout << "Your input is \"" << c << "\"" << endl;
}

void echoInteger() {
  int i;
  cout << "Input an integer:";
  cin >> i;
  cin.ignore(numeric_limits<streamsize>::max(),
             '\n');  //< @attention Clear redundant content like fraction
  if (cin.bad()) {
    cout << "!! FATAL INPUT !!" << endl;
    cin.clear();
    abort();
  }
  if (cin.fail()) {
    cout << "!! WRONG INPUT !!" << endl;
    cin.clear();
    abort();
  }
  cout << "Your input is \"" << i << "\"" << endl;
}

void echoString() {
  string s;
  cout << "Input a string:";
  cin >> s;
  cin.ignore(
      numeric_limits<streamsize>::max(),
      '\n');  //< @attention Clear redundant fragment splitted by SPACE or TAB
  if (cin.bad()) {
    cout << "!! FATAL INPUT !!" << endl;
    cin.clear();
    abort();
  }
  if (cin.fail()) {
    cout << "!! WRONG INPUT !!" << endl;
    cin.clear();
    abort();
  }
  cout << "Your input is \"" << s << "\"" << endl;
}

void echoLine() {
  string l;
  cout << "Input a line:";
  getline(cin, l);
  if (cin.bad()) {
    cout << "!! FATAL INPUT !!" << endl;
    cin.clear();
    abort();
  }
  if (cin.fail()) {
    cout << "!! WRONG INPUT !!" << endl;
    cin.clear();
    abort();
  }
  cout << "Your input is \"" << l << "\"" << endl;
}
