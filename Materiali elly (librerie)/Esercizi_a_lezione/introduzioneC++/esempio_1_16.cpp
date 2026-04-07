#include <string>
#include <iostream>
using namespace std;

int main() {
 string firstname = "Leland";
 string lastname = " Stanford";
 string fullname = firstname + lastname; // concat the two strings
 fullname += ", Jr"; // append another string
  fullname += '.'; // append a single char
 cout << firstname << lastname << endl;
 cout << fullname << endl;
 return 0;
}