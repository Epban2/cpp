#include <iostream>
#include "Oggetto.h"
int main()
{
	Automobile auto1;
	auto1.print();

	double v1 = 23.22, v2 = 26.11;
	int i1 = 10, i2 = 39;
	cout << "Double: " << somma(v1, v2) << ", intero: " << (i1, i2) << endl;


	Automobile auto2(1, 2);
	Automobile* a_pointer = &auto2; //puntatore alla locaz. di memoria dell'oggetto
	cout << (*a_pointer == auto2 ? "Uguali": "Diversi");

}

//capire virtual, template (vanno messi negli header)