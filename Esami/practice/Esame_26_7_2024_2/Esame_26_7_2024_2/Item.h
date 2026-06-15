#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;

class Item {

private:
	int codice;
	string nazione;
	string nome;
	float altezza;
public:
	Item(int c = int(), string n = string(), string no = string(), int a = int()) { codice = c; nazione = n; nome = no; altezza = a; }

	int getcodice() const { return codice; }
	float getaltezza() const { return altezza; }
	string getnome() const { return nome; }
	string getnazione() const { return nazione; }
	
	//ritorna true se ha tutti i campi inizializzati base
	bool isNull() {
		if (nome == "" && codice == 0 && altezza == 0 && nazione == "") return true;
		return false;
	}
};

inline ostream& operator << (ostream& os, const Item& i) {
	return os << "(" << i.getcodice() << "," << i.getnome() << "," << i.getnazione() << "," << i.getaltezza() << ") ";
}

#endif
