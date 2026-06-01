
#include <iostream>
#include <fstream>
#include <string>
#include "Item.h"
#include "bst.h"
#include "llist.h"
#include "listTest.h"
using namespace std;


const string FILENAME1 = "elenco_azioni.txt";
const string FILENAME2 = "variazioni_prezzo.txt";

void clearScreen() { cout << endl << endl; }

int main()
{
	ifstream file(FILENAME1);
	int dimensione = 0;

	if (file.is_open())
		file >> dimensione;

	Item* azioni_copy = new Item[dimensione];
	LList<Item> lista;

	if (file.is_open()) {
		string nome_azione; char categoria_azione; int valore_azione;

		for (int i = 0; i < dimensione; i++)
		{
			file >> nome_azione >> categoria_azione >> valore_azione;
			Item newItem = Item(nome_azione, categoria_azione, valore_azione);
			azioni_copy[i] = newItem; lista.append(newItem);
		}

	}
	file.close();


	Item* azioni = new Item[dimensione];
	BST<Item, string> tree;

	for (int i = 0; i < dimensione; i++) {
		Item item;
		int min = 1000;
		int min_index = 0;
		for (int j = 0; j < dimensione; j++) {
			if (azioni_copy[j] < min) {
				min = azioni_copy[j].getValore();
				item = azioni_copy[j];
				min_index = j;
			}
		}
		azioni_copy[min_index].setValore(1000);

		azioni[i] = item;
		tree.insert_root(item);
		cout << azioni[i];
	}
	delete[] azioni_copy;

	clearScreen();




	tree.balance();

	/*
	Eliminare dall’albero tutti gli elementi che
	nell’array hanno categoria “C” e si trovano in una posizione di indice pari(0 incluso).
	*/

	for (int i = 0; i < dimensione; i++) {
		if (azioni[i].getCategoria() == 'C' && i % 2 == 0)
			tree.remove(azioni[i]);
	}

	tree.show(cout);
	clearScreen();

	ifstream file2(FILENAME2);
	if (file2.is_open()) {
		string nome; int variazione;
		while (file2 >> nome >> variazione) {
			//Scorro l'array e trovo l'item con la stessa chiave
			for (int index = 0; index < dimensione; index++) {
				Item i = azioni[index];
				if (i == nome) {
					azioni[index].setValore(i.getValore() + variazione); //aggiorno valore
					//sposto

					if (variazione > 0) { // se è aumentato, controllo se spostare a dx
						i = azioni[index];
						for (int j = index + 1; j < dimensione; j++)
						{
							if (i.getValore() > azioni[j].getValore()) {
								azioni[j - 1] = azioni[j]; azioni[j] = i; //scambiati (portato in avanti di 1 quello aggiornato
							}
							else break;
						}
					}


					else if (variazione < 0) { //sposta a sx
						i = azioni[index];
						for (int j = index - 1; j > 0; j--)
						{
							if (i.getValore() < azioni[j].getValore()) {
								azioni[j] = azioni[j + 1]; azioni[j - 1] = i; //scambiati (portato in avanti di 1 quello aggiornato
							}
							else break;
						}
					}
					break;
				}
			}
		}
	}
	file2.close();

	//azioni[prima] : (rcs,C,-135) (edison,A,-20) (airbus,B,2) (eni,A,35) (barilla,D,35) (telecom,C,44) (tiscali,C,55) (fca,B,76)
	//azioni[dopo]  : (rcs,C,-150) (eni,A,35) (telecom,C,44) (edison,A,50) (tiscali,C,55) (fca,B,80) (barilla,D,135) (airbus,B,302)

	for (int index = 0; index < dimensione; index++)
		cout << azioni[index];

	clearScreen();
	//Scrivere una procedura per l’aggiornamento degli elementi della lista come descritto al punto 3 (non
	//è consentito utilizzare algoritmi di ordinamento di liste).

	ifstream file3(FILENAME2);
	if (file3.is_open()) {
		string nome; int variazione;
		while (file3 >> nome >> variazione) {
			for (lista.moveToStart(); lista.currPos() < lista.length(); lista.next()) {
				Item i = lista.getValue();

				if (i == nome) {

					i.setValore(i.getValore() + variazione);
					lista.remove();
					lista.moveToStart(); // mi rimetto all'inizio

					while (lista.currPos() < lista.length()) {
						if (i.getValore() > lista.getValue().getValore())
							lista.next();
						else break;
					}

					lista.insert(i);
					lprint(lista);
					break;
				}
			}
		}
	}
	file3.close();


	clearScreen();
	delete[] azioni;
	return 0;

}

