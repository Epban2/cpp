#include <iostream>
#include <string>
#include <list>
using namespace std;

void main() {
	list< int > l1;

	l1.push_back(1);
	l1.push_back(22);
	l1.push_back(4);
	l1.push_back(31);
	l1.push_back(4);
	l1.push_back(13);
	
	for (list<int>::iterator it = l1.begin(); it != l1.end(); it++) {
		cout << (*it) << " ";
	};
	
	list<int>::iterator it= l1.begin();
	it++;
	it=l1.insert(it, 5);
	it++;
	l1.insert(it, 15);
	cout << endl;

	for (list<int>::iterator it = l1.begin(); it != l1.end(); it++) {
		cout << (*it) << " ";
	};
}