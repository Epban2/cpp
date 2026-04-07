#include <iostream> 
#include <queue>
#include <list>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;



int main()
{
	list<queue<int> > lista_di_code;
	queue<int> q1,q2,q3,q4;

	q1.push(30); q1.push(12); q1.push(1); q1.push(203); q1.push(10);
	q2.push(7); 
	q3.push(14); q3.push(29); q3.push(45); q3.push(100);
	q4.push(2); q4.push(13); q4.push(8);

	lista_di_code.push_back(q1);
	lista_di_code.push_back(q2);
	lista_di_code.push_back(q3);
	lista_di_code.push_back(q4);
	
	list<queue<int> >::iterator last = lista_di_code.end();
	list<queue<int> >::iterator penultimo = --last;
	for (list<queue<int> >::iterator it = lista_di_code.begin(); it != penultimo; it++) {
		if ((*it).size()>0)
		{
			int val = (*it).front();
			(*it).pop();
			list<queue<int> >::iterator successivo= it;
			++successivo;
			(*successivo).push(val);
		}

	};
	
	for (list<queue<int> >::iterator it = lista_di_code.begin(); it != lista_di_code.end(); it++) {
		while (!(*it).empty())
		{
			cout << (*it).front() << " ";
			(*it).pop();
		}
		cout << endl;
	};

	return 0;
}