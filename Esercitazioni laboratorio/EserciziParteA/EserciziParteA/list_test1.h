#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>
using namespace std;
#include "list.h"



class Prodotto {
private:
	string codice;
	string nomeprodotto;
	int quantita;

public:
	Prodotto() {}
	Prodotto(string c, string n, int q) {
		this->codice = c;
		this->nomeprodotto = n;
		this->quantita = q;
	}

	string getCodice() const { return this->codice; }
	string getNomeprodotto() const { return this->nomeprodotto; }
	int getQuantita() const { return this->quantita; }

	void setQuantita(int q) { this->quantita = q; }

};

inline ostream& operator << (ostream& r, const Prodotto& i) {
	return r << i.getCodice() << ", " << i.getNomeprodotto() << ", quantita: " << i.getQuantita() << endl;
}


struct ricetta {
	int numero;
	string descrizione;
	string ingrediente1;
	int quantita_ingr1;
	string ingrediente2;
	int quantita_ingr2;
};

class Item {
private:
	ricetta ric;
public:
	Item() {}
	Item(ricetta r) { ric = r; }
	// The following is for those times when we actually
	//   need to get a value, rather than compare objects.
	ricetta key() const { return ric; }
};

// Let us print out Items easily
inline ostream& operator<<(ostream& s, const Item& i)
{
	return s << "(" << i.key().numero << " " << i.key().descrizione << " " << i.key().ingrediente1 << "-" << i.key().quantita_ingr1 << " " << i.key().ingrediente2 << "-" << i.key().quantita_ingr2 << ")";
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
void lprint(List<E>& L) {
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