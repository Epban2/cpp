#include "esercitazione3-es0.h"

int main()
{
	mobile m;
	m.setAltezza(1);
	m.setLarghezza(2);

	cout << m.getAltezza() << " " << m.getLarghezza() << endl;

	armadio a;
	a.setAltezza(1);
	a.setLarghezza(2);
	a.setNumeroAnte(5);
	cout << a.getAltezza() << " " << a.getLarghezza() << " " << a.getNumeroAnte() << endl;

	return 1;
}