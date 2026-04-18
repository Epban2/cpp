#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>
using namespace std;
#include <llist.h>
#include <lstack.h>

class Item {
private:
	string cognome, nome;
	int numero_biglietto;
public:
	Item(string cognome = "", string nome = "", int numero_biglietto = 0) {
		this->cognome = cognome;
		this->nome = nome;
		this->numero_biglietto = numero_biglietto;
	}
	string getcognome() {
		return this->cognome;
	}
	string getnome() {
		return this->nome;
	}
	int getnum_biglietto() {
		return this->numero_biglietto;
	}
};

inline ostream& operator<< (ostream& s, Item i) {
	s << i.getnome() << " " << i.getcognome() << ", numero: " << i.getnum_biglietto() << endl;
	return s;
}

//Effettua controllo su nome e cognome
inline bool operator == (Item& a, Item& b) {
	if (a.getnome() == b.getnome() && a.getcognome() == b.getcognome())
		return 1;
	else return 0;
}


//Creare una classe “Premio” contenente : il nome di un premio(string) e il suo valore in euro(float).
class Premio {
private:
	string nome;
	float valore;
public:
	Premio(string nome = "", float valore = 0) {
		this->nome = nome;
		this->valore = valore;
	}
	string getnome() {
		return this->nome;
	}
	float getvalore() {
		return this->valore;
	}

};
inline ostream& operator<< (ostream& s, Premio i) {
	s << "(" << i.getnome() << " " << i.getvalore() << ")" << endl;
	return s;
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
void Lprint(List<E>& L) {
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

// array dinamici
void lprint(Premio a[], int length) {
	for (int i = 0; i < length; i++)
		cout << a[i];

}

// Print out the stack
template <typename E>
void Lstackprint(LStack<E>& S) {
	LStack<E> Stemp;
	while (S.length() > 0)
	{
		E popped = S.pop();
		cout << popped;
		Stemp.push(popped);
	}
	while (Stemp.length() > 0)
	{
		E popped = Stemp.pop();
		S.push(popped);
	}
}



//Ordinare la lista per numero di biglietto decrescente utilizzando BubbleSort e stamparla a video.
void bubble(LList<Item>& L)
{
	for (int i = 0; i < (L.length() - 1); i++)
		for (int j = L.length() - 1; j > i; j--)
		{

			L.moveToPos(j - 1);
			Item a = L.getValue();

			L.next();
			Item b = L.getValue();

			if (b.getnum_biglietto() > a.getnum_biglietto()) {
				L.moveToPos(j - 1);
				L.remove(); L.remove();
				L.insert(a);
				L.insert(b);
			}
		}
}



#endif
