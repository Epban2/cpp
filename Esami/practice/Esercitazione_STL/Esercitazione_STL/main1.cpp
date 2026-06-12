/*
Esercizio 1: Creare una lista di numeri interi come oggetto della classe STL list e inizializzare la lista con i
seguenti valori: (1,22,4,31,4,13). Stampare il contenuto della lista. Utilizzando la funzione “insert”
inserire il numero “5” in posizione 1 nella lista e, successivamente, inserire il numero “15” in posizione 2.
Stampare il contenuto della lista.
*/

#include <iostream>
#include <list>
using namespace std;

int main() {
	list<int> lista;
	lista.push_back(1);
	lista.push_back(22);
	lista.push_back(int(4));
	lista.push_back(int(31));
	lista.push_back(4);
	lista.push_back(13);
	list<int>::iterator it = lista.begin();
	for (; it != lista.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	it = lista.begin();
	it++;
	lista.insert(it, 5);
	lista.insert(it,15);

	for (it = lista.begin(); it != lista.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}