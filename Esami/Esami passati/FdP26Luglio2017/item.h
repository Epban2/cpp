#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <time.h>  // Used by timing functions

#include <iostream>
using namespace std;

static int maxKey = -10;

class Item {
private:
	string titolo;
	int codice;
	string editore;
	int prezzo;
public:
	Item(string t = "", int c = 0, string e = "", int p = maxKey) { titolo = t; codice = c; editore = e; prezzo= p; }
	// The following is for those times when we actually
	//   need to get a value, rather than compare objects.
	int null()
	{
		return prezzo == maxKey;
	}
	int key() const { return prezzo; }
	string gettitolo()  const { return titolo; }
	int getcodice()  const { return codice; }
	string geteditore()  const { return editore; }
	void setprezzo(int p)  { prezzo=p; }
	void settitolo(string t) { titolo = t; }
	void show(ostream& os = cout)
	{
		os << "("<< titolo << "," << codice << "," << editore << "," << prezzo << ") ";
	}
};
 
// Let us print out Items easily
inline ostream& operator<<(ostream& s, const Item& i)
{
	return s << "(" << i.gettitolo() << "," << i.getcodice() << "," << i.geteditore() << "," << i.key() << ")";
}
#endif