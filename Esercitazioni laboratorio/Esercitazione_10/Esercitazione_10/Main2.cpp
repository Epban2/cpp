/*
Esercizio 2: Creare una lista singolarmente concatenata della classe LList, chiamata “lista_di_liste”, i cui
elementi siano costituiti da liste della classe STL list contenenti oggetti di una classe Item(classe con un
campo “key” di tipo intero).Inserire nella “lista_di_liste” 4 liste STL con elementi Item con valori “key” a
scelta.Scrivere un algoritmo per determinare il valore “key” massimo tra tutti gli Item della
“lista_di_liste”.
*/
#include <iostream>
using namespace std;

#include <list>

#include "llist.h"
#include "listTest.h"

#include <ctime>

int main() {
	srand(time(NULL));
	LList<list<Item>> llista;

	for (int i = 0; i < 4; i++) { //4 liste
		list<Item> l;
		while (l.size() != 5)
			l.push_back(rand() % 100 + 1);

		llista.append(l);
	}


	int max = 0;
	for (llista.moveToStart(); llista.currPos() < llista.length(); llista.next()) {
		list<Item> curr = llista.getValue();
		for (list<Item>::iterator it = curr.begin(); it != curr.end(); it++)
		{
			if ((*it).get_key() > max)
				max = (*it).get_key();
			cout << *it << " ";
		}

		cout << endl;
	}
	cout << "\n" << "Max nelle liste: " << max << endl;;

	return 0;
}
