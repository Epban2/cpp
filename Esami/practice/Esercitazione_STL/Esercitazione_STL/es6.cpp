#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <set>
using namespace std;

/*
La funzione deve scorrere la mappa tramite iteratori, determinare quale esame ha il maggior numero di studenti promossi e stampare a video il nome di quell'esame e l'elenco ordinato delle matricole associate.
*/
void Stampa_Esame_Popoloso(map<string, set<int> >& registro) {
	int max = 0;
	map<string, set<int>>::iterator maxIt;

	for (map<string, set<int>>::iterator it = registro.begin(); it != registro.end(); it++) {
		int size = it->second.size();
		if (size > max) {
			max = size;
			maxIt = it;
		}
	}

	cout << "Esame piu' popoloso: " << maxIt->first << "; ";
	for (set<int>::iterator it = maxIt->second.begin(); it != maxIt->second.end(); it++)
		cout << *it << ", ";

}

int main() {
	map<string, set<int> > registro; //key: nome materia, set: set di matricole che hanno passato il determinato esame


	ifstream file("studenti.txt");
	if (file.is_open()) {
		string materia;
		int matricola;
		while (file >> materia >> matricola) {
			registro[materia].insert(matricola);
		}

	}
	file.close();

	cout << "Lista esami: \n";
	for (map<string, set<int>>::iterator it = registro.begin(); it != registro.end(); it++) {
		cout << it->first << ": ";
		for (set<int>::iterator mat = it->second.begin(); mat != it->second.end(); mat++) {
			cout << *mat << ", ";
		}
		cout << endl << endl;

	}


	Stampa_Esame_Popoloso(registro);
	cout << endl;


	return 0;
}