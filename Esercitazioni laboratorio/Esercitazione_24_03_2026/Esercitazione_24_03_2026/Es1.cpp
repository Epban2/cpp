#include <iostream>
#include "link.h"
#include "llist.h"
#include "alist.h"
#include "ListTest.h"

using namespace std;

/*accetti come parametri in ingresso i riferimenti alle liste L1, L2, L3.*/
void insert_ordered(AList<Item>& l1, AList<Item>& l2, AList<Item>& l3);


int main()
{
	AList<Item> l1, l2, l3;
	l1.append(Item(5)); l1.append(Item(1)); l1.append(Item(3));
	l2.append(Item(10)); l2.append(Item(12)); l2.append(Item(7)); l2.append(Item(2));

	insert_ordered(l1, l2, l3);
	lprint<Item>(l3);

	return 0;
}

void insert_ordered(AList<Item>& l1, AList<Item>& l2, AList<Item>& l3) {

	// 1. UNIONE (Sicurezza: assicuriamoci che partano da 0)
	l1.moveToStart();
	l2.moveToStart();
	l3.moveToStart();

	while (l1.currPos() < l1.length()) {
		l3.insert(l1.getValue()); // Inseriamo l'Item direttamente
		l3.next();
		l1.next();
	}
	while (l2.currPos() < l2.length()) {
		l3.insert(l2.getValue());
		l3.next();
		l2.next();
	}

	// Selection Sort Decrescente
	for (int i = 0; i < l3.length() - 1; i++) {

		// Riportiamo il cursore alla posizione di partenza 'i'
		l3.moveToStart();
		for (int step = 0; step < i; step++) l3.next();

		int max_val = l3.getValue().key();
		int max_pos = i;
		int current_pos = i;

		// A. Cerchiamo il massimo nella parte non ancora ordinata
		while (l3.currPos() < l3.length()) {
			if (l3.getValue().key() > max_val) {
				max_val = l3.getValue().key();
				max_pos = current_pos;
			}
			l3.next();       // ORA avanza sempre! Niente loop infinito.
			current_pos++;
		}

		// B. Se il massimo non è già nella posizione corretta 'i', lo spostiamo
		if (max_pos != i) {
			// Vai alla posizione del massimo e rimuovilo
			l3.moveToStart();
			for (int step = 0; step < max_pos; step++) l3.next();
			Item max_item = l3.remove(); // Rimuove e salva l'elemento

			// Torna alla posizione 'i' e inseriscilo
			l3.moveToStart();
			for (int step = 0; step < i; step++) l3.next();
			l3.insert(max_item);
		}
	}
}