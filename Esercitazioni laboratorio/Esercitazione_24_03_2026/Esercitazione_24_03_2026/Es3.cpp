/*
Scrivere un programma che crei un array contenente N liste. Le liste contengono Item con valori interi
positivi. Il programma deve calcolare l’indice dell’array contenente la lista in cui compare l’elemento di
valore massimo tra gli elementi di tutte le liste.
*/
#include <iostream>
#include <string>

#include "link.h"
#include "llist.h"
#include "ListTest.h"

const int N = 3;
using namespace std;
int main3()
{
	Item v1(1),v2(2),v3(3),v4(4),v5(5),v10(10),v29(29);
	
	LList<Item> l1,l2,l3;
	l1.append(v1);	l1.append(v2); // , l1.append(v29);
	l2.append(v3);	l2.append(v4);
	l3.append(v5);	l3.append(v10);

	LList<Item> *lista[N] = { &l1,&l2,&l3 }; //Manuale
	int max = 0;
	int maxListIndex = 0;
	for (int i = 0; i < N; i++) { //scorro le lite {l1,l2,l3}
		for (int j = 0; j < lista[i]->length(); j++) { //Scorro in base alla lunghezza della sottolista (lista che contiene gli items)
			if (lista[i]->getValue().key() > max) {
				max = lista[i]->getValue().key();
				maxListIndex = i;
			}
			lista[i]->next();
		}
	}
	cout << "Max: " << max << ", list index: " << maxListIndex << endl;
	return 0;
}

