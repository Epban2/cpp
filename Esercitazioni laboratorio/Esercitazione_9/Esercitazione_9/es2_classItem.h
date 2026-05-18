#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;

template <typename keyType, typename dataType>
class Item {
private:
	dataType data;
	keyType keyval;
public:
	Item(keyType k = keyType(), dataType d = dataType()) { keyval = k; data = d; }
	keyType key() const { return keyval; }
	dataType getData() const { return data; }
	// stampa l'oggetto
	void show(ostream& os = cout) { os << keyval << " " << data << endl; }
};

template <typename keyType, typename dataType>
inline ostream& operator << (ostream& s, const Item<keyType, dataType>& i) {
	return s << "(" << i.key() << " " << i.getData() << ")";
}

#endif // !ITEM_H
