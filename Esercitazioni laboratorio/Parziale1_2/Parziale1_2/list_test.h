#ifndef TEST_H
#define TEST_H

#include <iostream>
using namespace std;
#include "list.h"
#include "lstack.h"

class Item {
private:
	int numerobiglietto;
	string cognome;
	string nome;

public:
	Item(int n = 0, string no = "", string c = "") {
		this->numerobiglietto = n;
		this->nome = no;
		this->cognome = c;
	}
	
	string getNome() const { return nome; }
	string getCognome() const { return cognome; }
	int getNumerobiglietto() const { return numerobiglietto; }

	friend bool operator == (const Item& i1, const Item& i2); // esempio per accedere direttamente ai campi senza richiedere getter


};

inline ostream& operator << (ostream& s, const Item& i) {
	return s << "(" << i.getNome() << " " << i.getCognome() << ", " << i.getNumerobiglietto() << ")" << endl;
}
inline bool operator == (const Item& i1, const Item& i2) {
	return (i1.nome == i2.nome && i1.cognome == i2.cognome);
}


class Premio {
private:
	float valore;
	string nome;

public:
	Premio(float v = 0, string n = "") { valore = v; nome = n; }

	string getNome() const { return nome; }
	float getValore() const { return valore; }
	friend ostream& operator << (ostream& s, const Premio& i);
};

inline ostream& operator << (ostream& s, const Premio& i) {
	return s << "(" << i.nome << " " << i.valore << ")";
}

// Assert: If "val" is false, print a message and terminate
// the program
inline void Assert(bool val, string s) {
	if (!val) { // Assertion failed -- close the program
		cout << "Assertion Failed: " << s << endl;
		exit(-1);
	}
}

// Print out the list (including showing position for the fence)
// Print list contents
template <typename E>
void lprint(List<E>& L) {
	int currpos = L.currPos();

	L.moveToStart();

	cout << "< ";
	int i;
	for (i = 0; i < currpos; i++) {
		cout << L.getValue() << " ";
		L.next();
	}
	cout << "| ";
	while (L.currPos() < L.length()) {
		cout << L.getValue() << " ";
		L.next();
	}
	cout << ">\n";
	L.moveToPos(currpos); // Reset the fence to its original position
}


// Print out the stack
template <typename E>
void Lstackprint(LStack<E>& S) {
	LStack<E> Stemp;
	while (S.length() > 0)
	{
		E popped = S.pop();
		cout << popped << " ";
		Stemp.push(popped);
	}
	while (Stemp.length() > 0)
	{
		E popped = Stemp.pop();
		S.push(popped);
	}
}


#endif