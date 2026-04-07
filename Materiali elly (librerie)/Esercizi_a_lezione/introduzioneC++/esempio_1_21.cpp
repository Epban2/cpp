// to_string example
#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
#include <sstream> 
using namespace std;

int main ()
{
  string pi = "pi is " + std::to_string(3.1415926);
  string perfect = std::to_string(1+2+4+7+14) + " is a number";
  cout << pi << '\n';
  cout << perfect << '\n';

  string Text = "456"; // string containing the number
  int Result;          //number which will contain the result
  istringstream convert(Text); // stringstream used for the conversion
  convert >> Result;
  cout << Result << endl;
}