#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <time.h>  // Used by timing functions

#include <iostream>
using namespace std;

static string maxKey = "";

class Item {
private:
	string nome;
	int categoria;
	int numero;
public:
	Item(string n="", int c=0, int p=0) { nome = n; categoria = c; numero = p; }
	// The following is for those times when we actually
	//   need to get a value, rather than compare objects.
	int null()
	{
		return nome == maxKey;
	}
	string key() const { return nome; }
	int getcategoria()  const { return categoria; }
	int getnumero()  const { return numero; }
	void setnumero(int n) { numero = n; }
	void show(ostream& os = cout)
	{
		os << "("<< nome << "," << categoria << "," << numero << ") ";
	}
};
 
// Let us print out Items easily
inline ostream& operator<<(ostream& s, const Item& i)
{
	return s << "(" << i.key() << "," << i.getcategoria() << "," << i.getnumero() << ")";
}
#endif