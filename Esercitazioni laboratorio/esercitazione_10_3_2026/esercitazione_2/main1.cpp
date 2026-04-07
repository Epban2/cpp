#include "Libro.h"

int main1() {
	Libro libro1;
	libro1.setTitolo("I promessi sposi"); libro1.setPagine(1000);
	Libro libro2("Dialoghi con Leuco", 150);

	libro2.printLibro();
	libro1 + libro2;
	
	cout << libro1 <<endl;
	Libro*libro3 = &libro2; //libro3 punta alla stessa locaz. di memoria (sono la stessa cosa, libro3 = 000F23.. qualche indirizzo hex)
	cout <<libro2<<", "<<*libro3<< ((libro2 == *libro3) ? "true" : "false");
	return 0;
}