#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>

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


#endif