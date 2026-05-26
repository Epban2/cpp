#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <time.h>  // Used by timing functions
#include <string>
#include <iostream>
using namespace std;

static string maxKey = "";

class Item {
private:
	string azione;
	string categoria;
	int prezzo;
public:
	Item(string a="", string c="", int p=0) { azione = a; categoria = c; prezzo = p; }
	// The following is for those times when we actually
	//   need to get a value, rather than compare objects.
	int null()
	{
		return azione == maxKey;
	}
	string key() const { return azione; }
	string getcategoria()  const { return categoria; }
	int getprezzo()  const { return prezzo; }
	void setprezzo(int n) { prezzo = n; }
	void show(ostream& os = cout)
	{
		os << "("<< azione << "," << categoria << "," << prezzo << ") ";
	}
	int operator< (Item input)
	{
		if (prezzo < input.getprezzo()) return 1;
		else return 0;
	}
	int operator> (Item input)
	{
		if (prezzo > input.getprezzo()) return 1;
		else return 0;
	}
};
 
// Let us print out Items easily
inline ostream& operator<<(ostream& s, const Item& i)
{
	return s << "(" << i.key() << "," << i.getcategoria() << "," << i.getprezzo() << ")";
}
#endif