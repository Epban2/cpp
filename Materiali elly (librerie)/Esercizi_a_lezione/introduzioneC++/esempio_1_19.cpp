#include <string>
#include <iostream>
using namespace std;

int main() {
 string sentence = "this is a test string.";
 cout << sentence << endl;
 // Insert "phrase" at position 5 in sentence
 sentence.insert(5, "phrase ");
 cout << sentence << endl;
 // Replace the 5 characters " test" in "this phrase is a test string." 
 // with the string "n example" in sentence
 sentence.replace(16, 5, "n example");
 cout << sentence << endl;
 return 0;
}