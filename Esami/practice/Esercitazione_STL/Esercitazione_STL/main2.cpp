/*
Esercizio 2: Creare una lista singolarmente concatenata della classe LList, chiamata “lista_di_liste”, i cui
elementi siano costituiti da liste della classe STL list contenenti oggetti di una classe Item (classe con un
campo “key” di tipo intero). Inserire nella “lista_di_liste” 4 liste STL con elementi Item con valori “key” a
scelta. Scrivere un algoritmo per determinare il valore “key” massimo tra tutti gli Item della
“lista_di_liste”.
*/


#include <iostream>
#include <list>
#include "llist.h"
#include <ctime>
#include <time.h>
#include "listTest.h"
using namespace std;

void fillList(list<Item>& l) {
	for (int i = 0; i < 5; i++)
		l.push_back(Item(rand() % 30 + 1));

}

int main() {
	srand(time(NULL));
	LList<list<Item>> lista_di_liste;

	list<Item> l1;
	list<Item> l2;
	list<Item> l3;
	list<Item> l4;

	fillList(l1);
	fillList(l2);
	fillList(l3);
	fillList(l4);

	lista_di_liste.append(l1);
	lista_di_liste.append(l2);
	lista_di_liste.append(l3);
	lista_di_liste.append(l4);

	int max = 0;
	for (lista_di_liste.moveToStart(); lista_di_liste.currPos() < lista_di_liste.length(); lista_di_liste.next()) {
		list<Item> lista = lista_di_liste.getValue();
		list<Item>::iterator it = lista.begin();
		for (; it != lista.end(); it++) {
			cout << *it << " ";
			if (max < (*it).key()) {
				max = (*it).key();
			}
		}
		cout << endl;
	}
	cout << "max: " << max << endl;

	return 0;
}