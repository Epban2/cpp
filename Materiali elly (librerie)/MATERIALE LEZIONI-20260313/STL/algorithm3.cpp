#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
 vector<int> v;
 v.push_back(1);
 v.push_back(22);
 v.push_back(33);
 v.push_back(12);

 sort (v.begin(), v.end());
 for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
  { cout << *it << " "; }

 return 0;
}