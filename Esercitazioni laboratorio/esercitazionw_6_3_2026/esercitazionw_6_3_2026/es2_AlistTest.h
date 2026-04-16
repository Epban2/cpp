#ifndef LISTTEST_H
#define LISTTEST_H

#include <iostream>
#include <string>
using namespace std;

#include <alist.h>

class Item {
private:
	string nome; //minuscolo
	string cognome; //minuscolo

	int GG;
	int MM;
	int ANNO;
public:
	Item(string nome = "", string cognome = "", int giorno = 0, int mese = 0, int anno = 0) {
		this->nome = nome;
		this->cognome = cognome;
		this->GG = giorno;
		this->MM = mese;
		this->ANNO = anno;
		// GG/MM/ANNO (es: 02/11/1990) 
	}
	string getnome() {
		return this->nome;
	}
	string getcognome() {
		return this->cognome;
	}
	int getgiorno() {
		return this->GG;
	}
	int getmese() {
		return this->MM;
	}
	int getanno() {
		return this->ANNO;
	}
};



inline void Assert(bool val, string s) {
	if (!val) { // Assertion failed -- close the program
		cout << "Assertion Failed: " << s << endl;
		exit(-1);
	}
}

inline ostream& operator << (ostream& s, Item i) {
	s << i.getnome() << " " << i.getcognome() << " " << i.getgiorno() << "/" << i.getmese() << "/" << i.getanno() << endl;
	return s;
}

//inline bool operator < (Item i1, Item i2) {
//	bool one_first = false;
//	if (i1.getcognome() != i2.getcognome()) {
//		for (int i = 0; i < i1.getcognome().length(); i++) { //scorro tutte le lettere del cognome
//			if (i1.getcognome()[i] < i2.getcognome()[i]) {
//				return true;
//			}
//		}
//	}
//	return one_first;
//
//}

inline bool operator<(Item& i1, Item& i2) {
	if (i1.getcognome() != i2.getcognome())
		return i1.getcognome() < i2.getcognome();

	if (i1.getnome() != i2.getnome())
		return i1.getnome() < i2.getnome();

	// opzionale: confronto per data
	if (i1.getanno() != i2.getanno())
		return i1.getanno() < i2.getanno();
	if (i1.getmese() != i2.getmese())
		return i1.getmese() < i2.getmese();
	return i1.getgiorno() < i2.getgiorno();
}

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


#endif // !LIST_TEST_H
