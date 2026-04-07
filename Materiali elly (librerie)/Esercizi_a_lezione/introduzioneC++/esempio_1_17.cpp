#include <string>
#include <iostream>
using namespace std;

int main() {
 string sentence = "Yes, we went to Gates after we left the dorm.";
 int firstWe = sentence.find("we"); // finds the first "we"
 int secondWe = sentence.find("we", firstWe + 1); // finds "we" in "went"
 int thirdWe = sentence.find("we", secondWe + 1); // finds the last "we"
 int gPos = sentence.find('G');
 int zPos = sentence.find('Z'); // returns string::npos
 cout << "First we: " << firstWe << endl;
 cout << "Second we: " << secondWe << endl;
 cout << "Third we: " << thirdWe << endl;
 cout << "Is G there? ";
 cout << (gPos != string::npos ? "Yes!" : "No!") << endl;
 cout << "Is Z there? ";
 cout << (zPos != string::npos ? "Yes!" : "No!") << endl;
 return 0;
}