#ifndef CREDIT_CARD_H
#define CREDIT_CARD_H
#include <iostream>
#include <string>
#include "Money.h"

using namespace std;

class CreditCard
{
public:
	CreditCard();
	CreditCard(string nome, string numero_carta);
	CreditCard(string nome, string numero_carta, Money m);

	void print();
	void charge(string item, int e, int c);
	Money get_totalcharges(); //Restituisce il totale dei pagamenti

private:	
	string nome_proprietario;
	string numero_carta;
	Money pagamenti;

};

#endif