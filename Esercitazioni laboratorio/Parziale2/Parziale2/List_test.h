#ifndef TEST_H
#define TEST_H
#include <iostream>
#include <string>
using namespace std;
#include <llist.h>
#include <cstdlib> // rand, srand
#include <ctime> //time

#include <lstack.h>

class Item {

private:
	string nome, cognome;
	int numero_biglietto;

public:
	Item(string nome = "", string cognome = "", int numero_biglietto = 0) {
		this->nome = nome;
		this->cognome = cognome;
		this->numero_biglietto = numero_biglietto;
	}

	string getNome() const { return this->nome; }
	string getCognome() const { return this->cognome; }
	int getNumeroBiglietto() const { return this->numero_biglietto; }
};

inline ostream& operator << (ostream& s, Item i) {
	return s << i.getNumeroBiglietto() << " " << i.getNome() << " " << i.getCognome() << endl;
}

// num_biglietto1 > num_biglietto2
inline bool operator > (Item& a, Item& b) {
	return a.getNumeroBiglietto() > b.getNumeroBiglietto();
}

// nome1 == nome2 e cognome1 == cognome2
inline bool operator == (Item a, Item b) {
	return (a.getNome() == b.getNome() && a.getCognome() == b.getCognome());
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
void lprint(LList<Item>& L) {
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





#endif // !TEST_H
