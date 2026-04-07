// Linked list class test program

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <time.h>  // Used by timing functions

using namespace std;

// Include the link template class
#include "link.h"

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "esercitazione6-es4-listTest.h"

#include "esercitazione6-es4-comp.h"
#include "bubble.h"

// Main routine 
int main(int argc, char** argv) {
	int N;
	LList<Item> lista_stud;
	Item* studenti=NULL; //puntatore inizializzato a NULL
	studente st;
	float eta_max;
	int num_scelti;

	cout << "inserire numero studenti richiesti" << endl;
	cin >> num_scelti;
    cout << "inserire eta massima" << endl;
	cin >> eta_max;
  
	ifstream myfile("studenti.txt");
	if (myfile.is_open()) {
		myfile >> N;
		studenti = new Item[N];
		for (int i = 0; i < N; i++) {
			myfile >> st.cognome >> st.anni >> st.mediavoti;
			Item item_tmp(st);
			studenti[i] = item_tmp;
		}
		myfile.close();
	}

	bubble<Item>(studenti,0,N-1);
	for (int i = 0; i < N; i++) {
		cout << studenti[i] << endl;
	}

	for (int i = 0; i < N; i++) {
		if (studenti[i].key().anni<eta_max)
		{
			lista_stud.insert(studenti[i]);
			if (lista_stud.length() == num_scelti)
				break;
		}
	}
    cout << endl << "lista_stud: "; lprint(lista_stud);
    cout << "That is all.\n";

    return 0;
}