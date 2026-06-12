#include <iostream>
#include <vector>

#include <algorithm>
using namespace std;
int main() {

	vector<int> v;
	v.push_back(42);
	v.push_back(7);
	v.push_back(19);
	v.push_back(7);
	v.push_back(88);
	v.push_back(5);
	v.push_back(19);
	
	cout <<"size: " << v.size() << "; capacity: " << v.capacity() << endl;
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) cout << *it << " ";
	cout << endl;

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		if (it+1 != v.end())
		{
			if (*(it + 1) == (*it))
				it = v.erase(it);
		}

	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) cout << *it << " ";

	return 0;
}