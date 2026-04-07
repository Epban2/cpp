#include "Money.h"

int Money::get_cents() {
	return this->cents;
}

int Money::get_euros() {
	return this->euros;
}

void Money::set_euros(int e) {
	this->euros = e;
}
void Money::set_cents(int c) {
	this->cents = c;
}

void Money::bonifico(int e, int c) {
	int euros = this->get_euros() + e;
	int cents = this->get_cents() + c;
	euros += cents / 100;
	cents %= 100;
	this->set_cents(cents);
	this->set_euros(euros);

}


/*Ritorna un oggetto money avente come valori la somma di m1 e m2 */
Money operator+(Money m1, Money m2) {
	int euros = (m1.get_euros() + m2.get_euros());
	int cents = (m1.get_cents() + m2.get_cents());
	euros += cents / 100;
	cents %= 100;
	m1.set_cents(cents);
	m1.set_euros(euros);
	return m1;
}

