#include <iostream>
#include "Person.h"
#include <fstream> //file
#include <sstream> //token
using namespace std;
void writeFile(Person* persone, int num_persone);
void readFile(Person* persone);

int main() {
	Person persona1("Mauro", "Ricco", 60);
	Person persona2("Piero", "Bandini", 20);
	Person persona3("Mauro", "Ricco", 60);
	Person persona4("Piero", "Bandini", 20);
	Person persona5("Mauro", "Ricco", 60);
	Person persona6("Mauro", "Ricco", 60);
	Person persona7("Piero", "Bandini", 20);

	cout << persona1.getFullName() << "," << persona1.getAnni() << endl;
	cout << persona2.getFullName() << "," << persona2.getAnni() << endl;

	if (persona1 > persona2)
		cout << "p1 e' piu' anziana di p2"<<endl;
	else
		cout << "p1 e' piu' giovane di p2"<<endl;


	Person* persone_ptr;
	persone_ptr = new Person[7]; // Allocazione di 7 persone "vuote"
	persone_ptr[0] = persona1;
	persone_ptr[1] = persona2;
	persone_ptr[2] = persona3;
	persone_ptr[3] = persona4;
	persone_ptr[4] = persona5;
	persone_ptr[5] = persona6;
	persone_ptr[6] = persona7;
		

	writeFile(persone_ptr, 7);
	delete[] persone_ptr;


	cout << "\nLettura persone da file: " << endl;
	Person persone[7];
	readFile(persone);
	for (int i = 0; i < 7; i++) {
		cout << persone[i].informazioni() << endl;
	}
	return 0;
}

//################################à

void writeFile(Person* persone, int num_persone) {
	ofstream file("persone.txt");
	if (file.is_open()) {
		for (int i = 0; i < num_persone; i++) 
			file << persone[i].informazioni()<<endl;
		
	}
	else{
		cout << "Errore nell'apertura del file! mon pier";
		return;
	}
	file.close();
}

void readFile(Person* persone) {
	string nome, cognome, anni_str;  int anni;
	int i = 0;
	ifstream readingFile("persone.txt");
	if (readingFile.is_open()) {
		while (readingFile >> nome >> cognome >> anni_str) {
			istringstream token(anni_str);
			token >> anni;
			persone[i] = Person(nome, cognome, anni);
			i++;
		}
	}else {
		cout << "Errore nell'apertura del file! mon pier";
		return;
	}
	readingFile.close();
}
