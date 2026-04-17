#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>
#include <llist.h>

using namespace std;


class Studente {
private:
	int eta;
	string cognome;
	float media_voti;
public:
	Studente(string cognome = "", int eta = 0, float media_voti = 0) {
		this->cognome = cognome;
		this->eta = eta;
		this->media_voti = media_voti;

	}

	string getcognome() {
		return this->cognome;
	}
	int geteta() {
		return this->eta;
	}
	float getmedia() {
		return this->media_voti;
	}

};

inline ostream& operator << (ostream& s, Studente studente) {
	s << studente.getcognome() << ", eta:  " << studente.geteta() << ", media: " << studente.getmedia() << endl;
	return s;
}

/*
Stampa la lista degli studenti
n = array size
*/
void lprint(Studente s[], int n) {
	for (int i = 0; i < n; i++)
		cout << s[i];
}


/*
Funzione generica che confronta due elementi e ritorna true se il secondo è minore del primo (effettuare quindi scambio)
*/
int comp(float  A, float B)
{
	if (B < A) return 1;
	else
		return 0;
}



//Ordinamento
void insertion(Studente s[], int length)
{

	for (int i = 1; i < length; i++)
		for (int j = i; ((j > 0) && comp(s [j].getmedia(), s[j - 1].getmedia())); j--)
		{
			Studente a = s[j - 1], b = s[j];
			s[j - 1] = b;
			s[j] = a;
		}
}

//Lprint per la LList
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


// Assert: If "val" is false, print a message and terminate
// the program
inline void Assert(bool val, string s) {
	if (!val) { // Assertion failed -- close the program
		cout << "Assertion Failed: " << s << endl;
		exit(-1);
	}
}


#endif