#ifndef TEST_H
#define TEST_H

#include <iostream>
using namespace std;
#include <string>

#include "llist.h"

//“Item” contiene tre campi : il numero del biglietto(int), il cognome(string) e il
//nome(string) della persona che lo ha acquistato.Leggere dal file "bigliettiVenduti.txt" l’elenco dei
//biglietti venduti salvando le informazioni contenute in ogni riga(formato : <numero
//biglietto>, <nome>, <cognome>) in un elemento della lista.Ogni persona può avere acquistato più
//di un biglietto.I biglietti acquistati dalla stessa persona si trovano in righe consecutive del file.\

class Item {
private:
	int numerobiglietto;
	string nome;
	string cognome;

public:
	Item(int n = 0, string no = "", string c = "") { numerobiglietto = n; nome = no; cognome = c; }
	int getNumerobiglietto()const { return numerobiglietto; }
	string getNome()const { return nome; }
	string getCognome()const { return cognome; }
};

inline ostream& operator << (ostream& s, const Item& i) {
	return s << i.getNome() << " " << i.getCognome() << " :" << i.getNumerobiglietto() << endl;
}
//controlla se nome e cognome sono identici
inline bool operator == (const Item& i, const Item& i2) {
	return (i.getNome() == i2.getNome() && i.getCognome() == i2.getCognome());
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


// Transfer stack1 into stack2
template <typename E>
void LstackTransfer(LStack<E>& S1, LStack<E>& S2) {
	LStack<E> Stemp;
	while (S1.length() > 0)
	{
		E popped = S1.pop();
		Stemp.push(popped);
	}
	while (Stemp.length() > 0)
	{
		E popped = Stemp.pop();
		S1.push(popped);
		S2.push(popped);
	}
}

#endif // !TEST_H

