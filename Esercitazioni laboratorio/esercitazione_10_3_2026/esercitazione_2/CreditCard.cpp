#include "CreditCard.h"

CreditCard::CreditCard() {
	this->nome_proprietario = "";
	this->numero_carta = "";
	Money pagamento;
	this->pagamenti = pagamento;
};

CreditCard::CreditCard(string nome, string numero_carta) {
	this->nome_proprietario = nome;
	this->numero_carta = numero_carta;
	Money pagamento;
	this->pagamenti = pagamento;
}
CreditCard::CreditCard(string nome, string numero_carta, Money m) {
	this->nome_proprietario = nome;
	this->numero_carta = numero_carta;
	this->pagamenti = m;
}

void CreditCard::print() {
	cout << this->nome_proprietario << ", " << this->numero_carta << ", credito: " << pagamenti;
}

void CreditCard::charge(string item, int e, int c) {
	this->pagamenti.bonifico(e, c);
}

Money CreditCard::get_totalcharges() {
	return this->pagamenti;
}