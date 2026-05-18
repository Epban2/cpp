#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;
const int maxKey = 1000;

class Item {
private:
	string data;
	int keyval;
public:
	Item(int k = maxKey, string d = "") { keyval = k; data = d; }
	int key() const { return keyval; }
	string getData() const { return data; }
	// stampa l'oggetto
	void show(ostream& os = cout) { os << keyval << " " << data << endl; }
};

inline ostream& operator << (ostream& s, const Item& i) {
	return s << "(" << i.key() << " " << i.getData() << ")";
}

#endif // !ITEM_H
