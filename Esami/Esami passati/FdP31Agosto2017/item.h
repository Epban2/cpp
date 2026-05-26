#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <time.h>  // Used by timing functions

#include <iostream>
using namespace std;

static int maxKey = -10.0;

class Item {
private:
	string cognome;
	int eta;
	string citta;
	int matricola;
public:
	Item(string c = "", int ma = maxKey, string ci = "", int e = 0) { cognome = c; matricola = ma; citta = ci; eta= e; }
	// The following is for those times when we actually
	//   need to get a value, rather than compare objects.
	int null()
	{
		return matricola == maxKey;
	}
	int key() const { return matricola; }
	string getcognome()  const { return cognome; }
	string getcitta()  const { return citta; }
	int geteta()  const { return eta; }
	void show(ostream& os = cout)
	{
		os << "("<< cognome << "," << matricola << "," << citta << "," << eta << ") ";
	}
};
 
// Let us print out Items easily
inline ostream& operator<<(ostream& s, const Item& i)
{
	return s << "(" << i.getcognome() << "," << i.key() << "," << i.getcitta() << "," << i.geteta() << ")";
}
#endif