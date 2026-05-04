#include <iostream>
#include "binary_tree.h"

#include <string>
using namespace std;

class myItem {
private:
	string nome;

public:
	myItem(string n = "") { nome = n; }

	string getNome() const { return nome; }
};

inline ostream& operator << (ostream& s, const myItem& i) {
	return s << "(" << i.getNome() << ")";
}