#include <iostream>
#include <string>

using namespace std;

#include <fstream> //ifstream, ofstream
#include <sstream> //per convertire stringa->int input da file

//lista
#include <llist.h>
#include <link.h>
#include <listTest.h>

class Persona {
private:
	string nome;
	string cognome;
	int eta;
public:
	Persona(string nome = "", string cognome = "", int eta = 0)
	{
		this->nome = nome;
		this->cognome = cognome;
		this->eta = eta;
	}
	string getNome() {
		return this->nome;
	}
	string getCognome() {
		return this->cognome;
	}
	int getEta() {
		return this->eta;
	}

	void setNome(string nome) {
		this->nome = nome;
	}
	void setCognome(string cognome) {
		this->cognome = cognome;
	}
	void setEta(int eta) {
		this->eta = eta;
	}


};
ostream& operator << (ostream& os, Persona p) {
	os << p.getNome() << " " << p.getCognome() << ", " << p.getEta();
	return os;
}



//
int main() {
	LList<Persona> persone;

	//dichiara variabili
	string nome, cognome, eta_str; int eta;
	ifstream reading_file("persone.txt");
	if (reading_file.is_open()) {
		while (reading_file >> nome >> cognome >> eta_str) {
			istringstream token_eta(eta_str);
			token_eta >> eta;
			persone.append(Persona(nome, cognome, eta));
		}
	}
	reading_file.close();

	//stampa con operator
	//cout << persone.getValue();

	lprint<Persona>(persone);



	return 0;
}