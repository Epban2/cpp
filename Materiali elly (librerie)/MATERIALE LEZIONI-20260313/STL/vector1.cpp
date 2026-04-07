#include <vector>
#include <iostream>
using namespace std;
int main() {
 vector<int> vNumbers;
 vNumbers.push_back(1);
 vNumbers.push_back(110);
 vNumbers.push_back(5);
 vNumbers.push_back(74);
 vNumbers[2] = 7;
 vNumbers.insert(vNumbers.begin() + 3, 22);
 cout << "vNumbers[0]="<< vNumbers[0] << endl;

 vNumbers.insert(vNumbers.end() - 1, 44);
 vector<int>::iterator it= vNumbers.begin();
 it++;
 *it = 555;
 
 for (int i = 0; i<vNumbers.size(); i++)
 {
	 cout << vNumbers[i] << " ";
 }
 cout << endl;
 // Print the vector using an iterator
 for (it = vNumbers.begin(); it != vNumbers.end(); it++)
 {
	 cout << *it << " ";
 }
 cout << endl;
 vector< int >::reverse_iterator p2;
 for (p2 = vNumbers.rbegin(); p2 != vNumbers.rend(); ++p2)
	cout << *p2 << " ";
 cout << endl;

 it = vNumbers.begin();
 it++;
 vNumbers.erase(it);
 for (it = vNumbers.begin(); it != vNumbers.end(); it++)
 {
	 cout << *it << " ";
 }
 cout << endl;
 vNumbers.clear();
 cout << "vNumbers.size()=" << vNumbers.size() << endl;
 return 0;
}