#include "es2_AlistTest.h"
#include <iostream>
#include <fstream> // file
#include <sstream> // token


void bubble(AList<Item>& l)
{
	for (int i = 0; i < l.length(); i++)
		for (int j = l.length() - 1; j > i; j--) {
			l.moveToPos(j - 1);
			Item a= l.getValue(); // l[j-1]
			l.next();
			Item b = l.getValue();  // l[j]
			if (b < a) {
				l.moveToPos(j - 1);
				l.remove();      // rimuove a
				l.insert(b);     // inserisce b

				l.moveToPos(j);
				l.remove();      // rimuove b
				l.insert(a);     // inserisce a
			}
		}
}




int main() {
	AList<Item> list;
	ifstream file("agenda.txt");

	string nome, cognome, giorno;
	int gg, mm, yyyy;

	string data;

	while (file >> nome >> cognome >> data) {
		int gg, mm, yyyy;
		char slash1, slash2;

		istringstream ss(data);
		ss >> gg >> slash1 >> mm >> slash2 >> yyyy;

		list.append(Item(nome, cognome, gg, mm, yyyy));
	}

	cout << "Lista non ordinata: " << endl;
	lprint(list);

	bubble(list);
	cout << endl << "Lista ordinata in ordine crescente: " << endl;
	lprint(list);


	return 0;
}