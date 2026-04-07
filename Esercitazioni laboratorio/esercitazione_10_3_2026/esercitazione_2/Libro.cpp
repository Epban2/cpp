#include "Libro.h"

Libro::Libro() {
	this->titolo = "";
	this->pagine = 0;
}
Libro::Libro(string titolo, int pagine) {
	this->titolo = titolo;
	this->pagine = pagine;
}

int Libro::getPagine() {
	return this->pagine;
}


string Libro::getTitolo() {

	return this->titolo;
}

void Libro::setPagine(int pagine) {
	this->pagine = pagine;
}

void Libro::setTitolo(string titolo) {
	this->titolo = titolo;
}

void Libro::printLibro() {
	cout << this->titolo << ", pagine." << this->pagine << endl;
}

ostream& operator<< (ostream& os, const Libro& l){ 
	os << "Titolo: " << l.titolo << ", Pagine: " << l.pagine;
	return os;
}

bool Libro::operator== (Libro l2) const { //metodo const perché non modifica l'oggetto
	return (this->titolo == l2.titolo && this->pagine == l2.pagine);
}
