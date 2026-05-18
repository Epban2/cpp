#include <iostream>
#include <string>
#include "es1_classItem.h"
#include "es1_bst.h"
#include <fstream>
#include "llist.h"
using namespace std;

//1 AA
//2 BB

int main() {
	ifstream file("info.dat");

	BST<Item, int> bst, bst2;
	int id; string data;

	if (file.is_open()) {
		while (file >> id >> data)
			bst.insert(Item(id, data));
	}
	file.close();


	cout << "Albero non bilanciato: " << endl;
	bst.show(cout);

	bst.balance();
	cout << endl << "Albero bilanciato: " << endl;
	bst.show(cout);
	cout << endl;

	id = 0;
	while (id >= 0) {
		cout << "Input dati secondo albero: key string: ";
		cin >> id >> data;
		if (id > 0)
			bst2.insert(Item(id, data));
	}

	cout << endl << "Albero non bilanciato: " << endl;
	bst2.show(cout);

	bst2.balance();
	cout << endl << "Albero bilanciato: " << endl;
	bst2.show(cout);

	/*
	scrivere un metodo “merge” della classe bst per recuperare i dati inseriti nei due alberi e inserirli
	in una lista singolarmente concatenata ordinata per ID crescente; qualora nei due alberi siano
	presenti nodi con lo stesso ID questi devono dare origine ad un singolo nodo nella lista ottenuto
	concatenando le stringhe con lo stesso ID
	*/
	string newname;
	LList<Item> lista;
	//inserisco il primo albero nella lista
	bst.inserisci_in_lista(lista);
	lprint(lista);

	cout << endl;

	// adesso faccio merge tra la lista ed un secondo albero
	cout << "Lista dopo merge: " << endl;
	bst2.merge(lista);
	lprint(lista);

	return 0;
}