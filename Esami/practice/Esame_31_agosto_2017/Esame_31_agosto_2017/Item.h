#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include "llist.h"
#include "listTest.h"
using namespace std;

class Item {
private:
	int matricola;
	string cognome;
	string citta;
	int eta;
public:
	Item(int m = int(), string co = string(), string ci = string(), int e = int()) { matricola = m; cognome = co; citta = ci; eta = e; }

	int key() const { return matricola; }
	int geteta() const { return eta; }
	string getcitta() const { return citta; }
	string getcognome() const { return cognome; }

	void show(ostream& os = cout) { os << "(" << cognome << "," << matricola << "," << citta << "," << eta << ") "; }

};

inline ostream& operator<<(ostream& s, const Item& i)
{
	return s << "(" << i.getcognome() << "," << i.key() << "," << i.getcitta() << "," << i.geteta() << ") ";
}





#endif // !#define ITEM_H
