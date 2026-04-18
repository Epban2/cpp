#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>
using namespace std;
#include <alist.h>

class Item {
private:
	string citta;
	float temperatura;
	int umidita;
public:
	Item(string citta = "", float temperatura = 0, int umidita = 0) {
		this->citta = citta;
		this->temperatura = temperatura;
		this->umidita = umidita;
	}
	string getcitta() {
		return this->citta;
	}
	float getumidita() {
		return this->umidita;
	}
	int gettemperatura() {
		return this->temperatura;
	}

};

inline ostream& operator << (ostream& s, Item i) {
	s << i.getcitta() << " , temperatura: " << i.gettemperatura() << ", umidita': " << i.getumidita() << endl;
	return s;
}


// Ordinare l'array in ordine crescente di Umidità utilizzando l'algoritmo Selection Sort.

void selection(Item a[], int length)
{
	for (int i = 0; i < length; i++) //Avanzamento esterno
	{
		int min = i;
		for (int j = i + 1; j < length; j++) //Avanzamento interno, cerca il numero minore della sottosequenza
			if (a[j].getumidita() < a[min].getumidita()) min = j;
		{
			Item item_a = a[i], item_b = a[min];
			a[i] = item_b; a[min] = item_a;
		}
	}
}

void lprint(Item a[], int length) {
	for (int i = 0; i < length; i++)
		cout << a[i];
}


// Assert: If "val" is false, print a message and terminate
// the program
inline void Assert(bool val, string s) {
	if (!val) { // Assertion failed -- close the program
		cout << "Assertion Failed: " << s << endl;
		exit(-1);
	}
}

// Print out the list (including showing position for the fence)
// Print list contents
template <typename E>
void Lprint(List<E>& L) {
	int currpos = L.currPos();

	L.moveToStart();

	cout << "< ";
	int i;
	for (i = 0; i < currpos; i++) {
		cout << L.getValue() << " ";
		L.next();
	}
	cout << "| ";
	while (L.currPos() < L.length()) {
		cout << L.getValue() << " ";
		L.next();
	}
	cout << ">\n";
	L.moveToPos(currpos); // Reset the fence to its original position
}


#endif