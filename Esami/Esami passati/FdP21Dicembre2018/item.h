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
	int passeggeri;
	float velocita;
	string compagnia;
public:
	Item(string n = maxKey, int p = 0, float v = 0.0, string c = maxKey) { nome = n; passeggeri = p; velocita = v; compagnia = c;
	}
	// The following is for those times when we actually
	//   need to get a value, rather than compare objects.
	int null()
	{
		return compagnia == maxKey;
	}
	string key() const { return compagnia; }
	string getnome()  const { return nome; }
	void setnome(string n) { nome = n; }
	float getvelocita()  const { return velocita; }
	void setvelocita(float v)   { velocita =v; }
	int getpasseggeri()  const { return passeggeri; }
	void setpasseggeri(int p)  { passeggeri =p; }

	void show(ostream& os = cout)
	{
		os << "("<< nome << "," << passeggeri << "," << velocita << "," << compagnia << ") ";
	}
};
 
// Let us print out Items easily
inline ostream& operator<<(ostream& s, const Item& i)
{
	return s << "(" << i.getnome() << "," << i.getpasseggeri() << "," << i.getvelocita() << "," << i.key() << ")";
}
#endif