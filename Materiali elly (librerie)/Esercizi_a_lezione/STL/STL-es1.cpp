#include <iostream> 
#include <vector> 
using namespace std;

int main()
{
	// Creazione di un contenitore "vettore di vettori" per composizione  
	vector<vector<int> > vv;

	int num = 0;
	// Inserimento di elementi
	for (int i = 0; i < 4; i++) {
		// Vector temporaneo per inserimento valori
		vector<int> v1;

		for (int j = 0; j < 5; j++) {
			v1.push_back(num);
			num += 3;
		}

		vv.push_back(v1);
	}

	vector<int> v2;
	//v2[0] = 1; v2[1] = 44; // errore!!!
	v2.push_back(1);
	v2.push_back(14);
	v2.push_back(49);

	vv[1] = v2;

	// Stampa del vettore di vettori
	for (int i = 0; i < vv.size(); i++) {
		for (int j = 0; j < vv[i].size(); j++)
			cout << vv[i][j] << " ";
		cout << endl;
	}

	for (int i = 0; i < vv.size(); i++) {
		vv[i].erase(vv[i].begin() + 1); // eliminazione secondo elemento di ciascun vettore
		vv[i].pop_back(); // eliminazione dell'ultimo elemento di ciascun vettore
	}
	cout << endl << endl;

	// Stampa del vettore di vettori
	vector<vector<int> >::iterator it;
	vector<int>::iterator it2;
	for (it = vv.begin(); it != vv.end(); it++) {
		for (it2 = (*it).begin(); it2 != (*it).end(); it2++)
			cout << (*it2) << " ";
		cout << endl;
	}

	return 0;
}