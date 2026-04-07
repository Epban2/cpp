#ifndef PERSON_H
#include "Person.h"
#include <string>
#include <iostream>

Person::Person() {
	this->nome = "";
	this->cognome = "";
	this->anni = 0;
};

Person::Person(string nome, string cognome, int anni){
	this->nome = nome;
	this->cognome = cognome;
	this->anni= anni;
}

string Person::getFullName() {
	return "Mi chiamo: " + this->nome + " " + this->cognome;
}

int Person::getAnni() {
	return this->anni;
}

bool Person::operator > (const Person& p2) {
	return this->anni > p2.anni;
}

string Person::informazioni() {
	return this->nome + " " + this->cognome+" "   + std::to_string(this->anni);

}

#endif