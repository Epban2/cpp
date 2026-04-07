#ifndef MONEY_H
#define MONEY_H
#include <iostream>
using namespace std;

class Money
{
public:
	inline Money() {
		this->cents = 0;
		this->euros = 0;
	};
	int get_euros();
	int get_cents();
	void set_cents(int);
	void set_euros(int);
	void bonifico(int, int); //Somma al saldo un una cifra in euro e centesimi

private:
	int euros;
	int cents;
}; //chiusura classe

Money operator+(Money m1, Money m2);
inline ostream& operator<<(ostream& os, Money m) {
	os << m.get_euros() << "," << m.get_cents() << "$" << endl;
	return os;
};

#endif
