#ifndef OGGETTO_H
#define OGGETTO_H

#include <iostream>
using namespace std;

class Oggetto //Classe astratta
{
protected:
	int val;
	int num;

public:
	Oggetto() {
		this->val = 0;
		this->num = 0;
	}
	virtual void print() = 0;


	int getnum() { return this->num; }
	int getval() { return this->val; }
};

class Automobile : public Oggetto {
public:
	Automobile(int val = 0, int num = 0) :Oggetto() {
		this->val = val; this->num = num;
	}
	void print() {
		std::cout << this->val << "," << this->num << std::endl;
	}

	friend ostream& operator << (ostream& os, Automobile a) {
		os << a.num << ", " << a.val << endl;
		return os;
	}
};




//TEMPLATE
/*Per accomunare funzioni che differiscono solo per il tipo, così facendo generalizziamo con un tipo e l'algoritmo rimane lo stesso*/
template <typename TipoGenerico>
TipoGenerico somma (TipoGenerico v1, TipoGenerico v2) {
	return v1 + v2;
}

bool operator == (Automobile& a1, Automobile& a2)  {
	return a1.getnum() == a2.getnum() && a1.getval() == a2.getval() ? true : false;
}

#endif
