/*
Scrivere un programma che crei una lista contenente oggetti Item con valori interi.
Si scriva una funzione che ricevendo in ingresso un riferimento alla lista la modifichi, memorizzando
nell’ultimo nodo il prodotto del penultimo ed ultimo nodo, nel penultimo il prodotto del terzultimo e del
penultimo e così via. Il primo elemento della lista non deve essere modificato.
Ad esempio, una lista contenente la sequenza di interi 4 6 2 3 9 verrà modificata dalla funzione nella list
a 4 24 12 6 27.
*/
#include <iostream>
#include <string>

#include "link.h"
#include "llist.h"
#include "ListTest.h"

const int N = 3;
using namespace std;

void editListFunction(LList<Item>& list);
int main()
{
	Item v1(4), v2(6), v3(2), v4(3), v5(9);

	LList<Item> list;
	list.append(v1), list.append(v2), list.append(v3), list.append(v4), list.append(v5);

	lprint<Item>(list);
	editListFunction(list);
	lprint<Item>(list);

	return 0;
}

void editListFunction(LList<Item>& list) {
	list.moveToEnd();
	while (list.currPos() > 1) {
		list.prev(); //Torna a sx poiché lui legge nella posizione a destra dell'indice (al primo è out of range)
		int curr = list.getValue().key();

		list.prev(); //prendo il precedente e ritorno in posizione corretta
		int prev = list.getValue().key();
		list.next();
		list.remove(); //sostituisco con il prodotto
		list.insert(curr * prev);
	}
}