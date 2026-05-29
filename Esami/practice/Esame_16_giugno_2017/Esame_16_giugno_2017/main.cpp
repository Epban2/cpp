#include "LList.h"
#include "listTest.h"
#include "Item.h"
#include <iostream>
#include <fstream>
using namespace std;
#include <string>
#include "bst.h"

const string FILENAME = "prodotti.txt";

void bubblesort(List<Item>& L) {
	for (int i = 0; i < (L.length() - 1); i++) {
		for (int j = (L.length() - 1); j > i; j--) {
			L.moveToPos(j);
			Item it_j = L.getValue();
			L.moveToPos(j - 1);
			Item it_jj = L.getValue();
			if (it_jj.key() < it_j.key())
			{
				L.moveToPos(j);
				Item removed = L.remove();
				L.moveToPos(j - 1);
				L.insert(removed);
			}
		}
	}
}

int main()
{
	ifstream file(FILENAME);
	LList<Item> lista;

	if (file.is_open()) {
		string nome; int categoria, quantita;
		while (file >> nome >> categoria >> quantita)
		{
			Item i(nome, categoria, quantita);
			for (lista.moveToStart(); lista.currPos() < lista.length(); lista.next()) {
				Item curr = lista.getValue();
				if (i == curr) {
					i.setQuantita(i.getQuantita() + curr.getQuantita());
					lista.remove();
				}

			}
			lista.append(i);
		}
	}
	file.close();

	bubblesort(lista);
	lprint(lista);

	BST<Item, string> albero;
	for (lista.moveToStart(); lista.currPos() < lista.length(); lista.next())
		albero.insert(lista.getValue());

	albero.balance();
	cout << "\n\nAlbero: ";
	albero.show(cout);


	/*
	Riorganizzare la lista creata al punto 2 in modo tale che tutti gli elementi la cui categoria è minore o
	uguale a 3 si trovino prima di tutti gli altri elementi (nota: non è necessario mantenere ordinati gli
	elementi, non utilizzare liste di appoggio). Stampare a video la lista.
	*/

	int i = 0;
	for (lista.moveToStart(); i < lista.length(); i++) {
		if (lista.getValue().getCategoria() <= 3) {
			Item toremove = lista.remove();
			lista.moveToStart();
			lista.insert(toremove);
		}
		lista.moveToPos(i);

	}
	cout << "\n\nLista: ";
	lprint(lista);

	cout << "\n\nFoglie con quantita <=25: ";
	cout << albero.higherQuantity() << "\n\n";
	return 0;
}
