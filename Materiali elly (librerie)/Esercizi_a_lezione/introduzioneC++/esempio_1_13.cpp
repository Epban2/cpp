#include <string>
#include <iostream>
using namespace std;

int main() {
 string small, large;
 small = "I am short";
 large = "I, friend, am a long and elaborate string indeed";
 cout << "The short string is " << small.length() << " characters." << endl;
 cout << "The large string is " << large.length() << " characters." << endl;
 return 0;
}