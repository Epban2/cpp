#include <iostream>
using namespace std;

#include <vector>

int main() {

	vector<int> vect;

	vect.push_back(6);
	vect.push_back(7);
	vect.push_back(8);
	vect.push_back(9);


	vector<int>::iterator it = find(vect.begin(), vect.end(), 7);
	if (it == vect.end())
		cout << "non trovato" << endl;
	else cout << "trovato" << endl;

	return 0;
}