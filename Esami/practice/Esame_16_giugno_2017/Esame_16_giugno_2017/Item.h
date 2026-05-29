#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;

class Item {
private:
	string nome;
	int quantita;
	int categoria;
public:
	Item(string n = "", int c = 0, int q = 0) { nome = n; quantita = q; categoria = c; }

	string key() const { return nome; }
	int getQuantita() const { return quantita; }
	void setQuantita(int q) { quantita = q; }
	int getCategoria() const { return categoria; }

	void show(ostream& os = cout)
	{
		os << "(" << nome << "," << categoria << "," << quantita << ") ";
	}
};

inline ostream& operator << (ostream& os, const Item& i)
{
	return os << "(" << i.key() << "," << i.getCategoria() << "," << i.getQuantita() << ") ";
}

inline bool operator == (Item& i1, Item& i2) {
	return i1.key() == i2.key();
}

#endif // !ITEM_H
