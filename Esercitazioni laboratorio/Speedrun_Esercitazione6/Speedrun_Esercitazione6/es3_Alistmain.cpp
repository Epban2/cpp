/*
Esercizio 3: Scrivere una funzione di ordinamento decrescente per liste utilizzando l’algoritmo “insertion
sort” void insertionsort(List<Item>&L)
*/

#include <iostream>
#include <alist.h>
#include <listtest.h>
#include <cstdlib>
using namespace std;

// j - 1 < j ([6, 8])
bool comp(List<Item>& L, int j) {
	
	L.moveToPos(j - 1);
	Item i1 = L.getValue(), i2;
	L.next(); i2 = L.getValue();
	return i2.key() > i1.key();
	
}

void insertionsort(List<Item>& L)
{
	for (int i =  0; i < L.length(); i++)
		for (int j = i; ((j > 0) && comp(L, j)); j--)
		{
			L.moveToPos(j - 1);
			Item i1 = L.remove();
			L.next(); 
			L.insert(i1);
		}
}



int main() {
	srand(time(NULL));
	AList<Item> list;
	while (list.length() < 20)
	list.append(Item(rand() % 100 + 1));

	lprint(list);
	insertionsort(list);
	lprint(list);


	return 0;
}