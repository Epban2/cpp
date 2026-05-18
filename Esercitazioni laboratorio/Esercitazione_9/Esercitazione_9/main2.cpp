#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "es2_bst.h"
#include "es2_classItem.h"

using namespace std;

int main() {
	ifstream file("telefoni.txt");
	//pal4, BIANCHI Valentina, 906049

	//oss. il keyType dell'item deve corrispondere con quello del bst, (ossia il secondo nella dichiarazione dell'albero)
	BST<Item<string, string>, string> bst1;	//key = nome  , data = ufficio
	BST<Item<int, string>, int> bst2;		//key = numero, data = nome

	if (file.is_open()) {
		string ufficio, nome, numstr; int num;
		while (getline(file, ufficio, ',')) {
			getline(file, nome, ',');
			getline(file, numstr);
			istringstream token(numstr);
			token >> num;
			bst1.insert(Item(nome, ufficio));
			bst2.insert(Item(num, nome));

		}
	}
	file.close();


	bst1.balance();
	bst1.show(cout);
	cout << endl;
	bst2.balance();
	bst2.show(cout);

	/*
	Stampi a video su ogni riga l’ufficio, il nome - cognome e il telefono di ogni persona(scrivere un
	algoritmo non efficiente basato su una visita del secondo albero utilizzando iterativamente la
	funzione “select”)
	*/
	cout << endl;
	for (int i = 0; i < bst2.tree_size(); i++) {
		//key = nome  , data = ufficio
		//key = numero, data = nome
		string ufficio, nome = bst2.select(i).getData(); int numero = bst2.select(i).key();
		ufficio = bst1.search(nome).getData();
		cout << endl << ufficio << " " << nome << " " << numero;

	}



	return 0;
}
