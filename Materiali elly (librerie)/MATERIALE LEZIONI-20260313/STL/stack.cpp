#include <iostream>
using namespace std;
#include <stack>

int main()
{
	stack<int> s;
	s.push(11);
	s.push(33);
	s.push(26);
	s.push(50);
	s.push(2);

	cout << "s.size(): " << s.size() << endl;
	cout << "s.top(): " << s.top() << endl;
	s.pop();
	cout << "s.size(): " << s.size() << endl;
	cout << "s.top(): " << s.top() << endl;
	
	return 0;
}