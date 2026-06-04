#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;

class Item {
private:
	string nome;
	string citta;
	int valore;

public:
	Item(string n = string(), string c = string(), int v = int()) { nome = n; citta = c; valore = v; }
	string key() const { return nome; }
	string getCitta() const { return citta; }
	int getValore() const { return valore; }

	void show(ostream& os = cout)
	{
		os << nome << " (" << citta << ") ";
	}


};

inline ostream& operator << (ostream& os, const Item& i) {
	return os << i.key() << " (" << i.getCitta() << ") ";
}

//Non e' il controllo sulla chiave (string) ma sul valore di priorita' per l'estrazione dalla coda
inline bool operator < (const Item& i1, const Item& i2) {
	return i1.getValore() < i2.getValore();
}


#endif // !ITEM_H
