#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

string reverse_string(string s)
{
	string sreverse="";
	if (s.length() == 1)
		return s;
	else
	{
		sreverse += s[s.length()-1] + reverse_string(s.substr(0, s.length()-1));
	  return sreverse;
	}
}

// Main routine 
int main(int argc, char** argv) {
  string s1 = "abcdefgh";
  string sr;
  sr = reverse_string(s1);
  cout << sr << endl;
  return 0;
}