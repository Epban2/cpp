#include "Money.h"
#include "CreditCard.h"
#include <sstream>
#include <fstream>

using namespace std;
int main() {
	Money m1,m2;

	m1.set_euros(5); m1.set_cents(50);
	m2.set_euros(0); m2.set_cents(80);
	
	cout << m1 <<m2;
	m1 =m1+ m2;
	cout << "m1+m2:" << m1;
	
	CreditCard cc1("Maurizio Mercuri", "123456789", m1),cc2("Carlo cafferata","987654321");
	cc1.charge("random", 3, 0);
	cc1.print();

	//leggo da file singola spesa su tre colonne: <causale della spesa> <euro> <centesimi> 
	string causale, euros_str, cents_str; int euros,cents;
	ifstream reading_file("charges.txt");
	if (reading_file.is_open()) {
		while (reading_file >> causale >> euros_str>> cents_str) {
			istringstream token_euros(euros_str), token_cents(cents_str);
			token_euros >> euros;  token_cents >> cents;
			cc2.charge(causale, euros, cents);
		}
	}
	cc2.print();
	return 0;
}