// writing on a text file
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ofstream myfile ("example.txt");
  int i=5;
  if (myfile.is_open())
  {
    myfile << "This is a line.\n";
    myfile << "This is another line.\n";
	myfile << i << " " << i+5;
    myfile.close();
  }
  else cout << "Unable to open file";
  return 0;
}