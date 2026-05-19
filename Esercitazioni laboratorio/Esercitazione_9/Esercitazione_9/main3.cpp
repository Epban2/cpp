#include <iostream>
#include <string>

using namespace std;
#include <fstream>

#include "es3_bst.h"
#include "es3_classItem.h"

//171636,Bacciolo Davide,24,davide.bacciolo@studenti.unipr.it
const string filenameA = "parteA.txt";
const string filenameB = "parteB.txt";
const char SEPARATORE = ',';

void letturaFile(BST<Item, int>& bst, string filename) {
	ifstream file(filename);
	if (file.is_open()) {
		string str, cognome, nome, str2, email;
		int matricola, voto;

		while (getline(file, str, SEPARATORE)) {
			matricola = stoi(str);
			getline(file, cognome, ' ');
			getline(file, nome, SEPARATORE);
			getline(file, str2, SEPARATORE);
			if (str2 == "INSUFFICIENTE") voto = 0;
			else voto = stoi(str2);
			getline(file, email);
			bst.insert(Item(matricola, voto));
		}

	}
	file.close();

}

int main() {
	BST<Item, int> bstA, bstB;
	letturaFile(bstA, filenameA);
	letturaFile(bstB, filenameB);

	cout << endl;

	bstA.balance();
	bstA.show(cout);

	cout << endl;
	bstB.balance();
	bstB.show(cout);


	cout << endl << "Media prove studenti: " << endl;
	bstA.visitaAlbero(bstB);

	// 3. stampi la media dei voti sufficienti per ciascuna delle due prove
	cout << endl;
	cout << "Media voti sufficienti prova A: " << bstA.mediaSufficienti() << endl;
	cout << "Media voti sufficienti prova B: " << bstB.mediaSufficienti();

	return 0;
}