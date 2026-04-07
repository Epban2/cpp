#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main (int, char * [])
{
 vector<int> v;
 v.push_back(1); 
 v.push_back(2);
 v.push_back(3); 
 v.push_back(2);
 int i = 7;
 cout << i << " appears " << count(v.begin(), v.end(), i) << " times in v" << endl;
 i = 2;
 cout << i << " appears " << count(v.begin(), v.end(), i) << " times in v" << endl;
 return 0;
}