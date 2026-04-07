#include "esercitazione2-es3.h"

Money operator+(Money m1, Money m2)
{
	int e = m1.get_euros() + m2.get_euros();
	int c = m1.get_cents() + m2.get_cents();
	e += c / 100;
	c %= 100;
	Money res(e, c);
	return res;
}

void CreditCard::print()
{
	cout << "Card owned by " << owner_name << ", Number: " << number << endl;
}

void CreditCard::charge(string item, int e, int c)
{
	Money spesa(e, c);
	cout << "Operation: " << item << " euros:" << e << " cents:" << c << endl;
	totalcharges = totalcharges + spesa;
}