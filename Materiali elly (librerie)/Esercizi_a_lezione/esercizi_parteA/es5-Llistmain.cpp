// esercizio nuotatori

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

// Include the link template class
#include "link.h"

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "es5-ListTest.h"

const int best_swimmers = 10;

void selectionsort(List<Item>& L) {
	int min_pos;
	Item min_element;
	// se lunghezza <2 non fai nulla
	for (int i = 0; i<(L.length() - 1); i++) {
		L.moveToPos(i);
		min_element = L.getValue();
		min_pos = i;
		for (int j = i + 1; j<L.length(); j++) {
			L.moveToPos(j);
			Item it_temp = L.getValue();
			if (it_temp.key() < min_element.key())
			{
				min_pos = L.currPos();
				min_element = it_temp;
			}
		}
		L.moveToPos(min_pos);
		Item it_temp = L.remove();
		L.moveToPos(i);
		L.insert(it_temp);
	}

}



// Main routine 
int main(int argc, char** argv) {

	LList<Item> Lnuotatori;

	float tot_secondi = 0;
	string dati;

	string nome;
	int minuti;
	int secondi;
	int centesimi;

	ifstream myfile("50rn.txt");
	if (myfile.is_open()) {
		while (getline(myfile, nome, ';')) {
			getline(myfile, dati);
			istringstream token(dati);
			token >> minuti >> secondi >> centesimi;

			tot_secondi =  (float) ((minuti * 60 * 100) + (secondi * 100) + centesimi) / 100;
			Item temp(nome, minuti, secondi, tot_secondi);
			Lnuotatori.append(temp);
		}
	}
	myfile.close();

    cout << "Lnuotatori: "; lprint(Lnuotatori);
	selectionsort(Lnuotatori);
	cout << endl << "Lnuotatori: "; lprint(Lnuotatori);

	ofstream myoutput_file("top_ten.txt");
	Lnuotatori.moveToStart();
	cout << "best " << best_swimmers << " swimmers" << endl;
	for (int i = 0; i < best_swimmers; i++) {
		Item temp=Lnuotatori.getValue();
		cout << endl << temp;
		if (i!=0) myoutput_file << endl;
		myoutput_file << temp.getnome() << " " << temp.key();
		Lnuotatori.next();
	}

	myoutput_file.close();
	Lnuotatori.clear();

    cout << endl << "That is all.\n";

  return 0;
}