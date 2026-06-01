#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <string>
#include <iostream>	
using namespace std;

static string maxKey = "";

class Item
{
private:
	string nome_azione;
	char categoria_azione;
	int valore_azione;


public:
	Item(string nome = string(), char categoria = char(), int valore = int())
	{
		nome_azione = nome; categoria_azione = categoria; valore_azione = valore;
	}

	string key() const { return nome_azione; }
	int null()
	{
		return nome_azione == maxKey;
	}

	int getValore() const { return valore_azione; }

	void setValore(int v) { valore_azione = v; }

	char getCategoria() const { return categoria_azione; }

	void show(ostream& os = cout)
	{
		os << "(" << nome_azione << "," << categoria_azione << "," << valore_azione << ") ";
	}


};

inline ostream& operator<<(ostream& os, const Item& i)
{
	return os << "(" << i.key() << "," << i.getCategoria() << "," << i.getValore() << ") ";
}

inline bool operator < (const Item& i, int n) {
	return i.getValore() < n;
}

inline bool operator ==  (const Item& i, string s) {
	return i.key() == s;
}

#endif