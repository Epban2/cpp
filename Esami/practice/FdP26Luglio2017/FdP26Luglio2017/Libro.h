#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <string>
using namespace std;


class Libro {
private:
	string nomelibro;
	string nomeeditore;
	int prezzo;
	int codicelibro;

public:
	Libro(string nome = string(), string editore = string(), int p = int(), int codice = int()) {
		nomelibro = nome;
		nomeeditore = editore;
		prezzo = p;
		codicelibro = codice;
	}

	int key() const { return prezzo; }
	int getcodice() const { return codicelibro; }
	string getnome() const { return nomelibro; }
	string geteditore() const { return nomeeditore; }

	void show(ostream& os = cout) { os << "(" << nomelibro << "," << codicelibro << "," << nomeeditore << "," << prezzo << ") "; }
};

inline ostream& operator << (ostream& os, const Libro& l) {
	return os << "(" << l.getnome() << "," << l.getcodice() << "," << l.geteditore() << "," << l.key() << ") ";
}

#endif