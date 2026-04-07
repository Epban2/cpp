#include "esercitazione2-es4.h"

string Persona::getInformation() {
	string s;
	s = nome.substr(0, 1) + ". " + cognome + ", " + std::to_string(anni);
	return s;
}