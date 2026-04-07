#include <string>
#include <iostream>
using namespace std;

int main() {
 string oldSentence;
 oldSentence = "The quick brown fox jumped WAY over the lazy dog";
 int len = oldSentence.length();
 cout << "Original sentence: " << oldSentence << endl;
 int found = oldSentence.find("WAY ");
 string newSentence = oldSentence.substr(0, found);
 cout << "Modified sentence: " << newSentence << endl;
 newSentence += oldSentence.substr(found + 4);
 cout << "Completed sentence: " << newSentence << endl;
 return 0;
}