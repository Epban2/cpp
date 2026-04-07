#ifndef ES0
#define ES0

#include <iostream>
#include <string>

using namespace std;

class mobile
{
 private:
	int altezza, larghezza;
 public:
	mobile() { altezza = 0; larghezza = 0; }
	void setAltezza(int a) { altezza = a; }
	void setLarghezza(int l) { larghezza = l; }
	int getAltezza() { return altezza; }
	int getLarghezza() { return larghezza; }
};

class armadio : public mobile
{
 private:
	int numero_ante;
 public:
	armadio() { numero_ante = 0; }
	void setNumeroAnte(int an) { numero_ante = an; }
	int getNumeroAnte() { return numero_ante; }
};

#endif