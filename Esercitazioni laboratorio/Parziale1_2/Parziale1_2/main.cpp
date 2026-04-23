#include "list_test.h"
#include "llist.h"
#include <fstream>
#include <string>
#include <iostream>
#include "lstack.h"
#include <time.h>  // time
#include <cstdlib> //rand, srand
using namespace std;


void bubblesort(List<Item>& L) {
	for (int i = 0; i < (L.length() - 1); i++) {
		for (int j = (L.length() - 1); j > i; j--) {
			L.moveToPos(j);
			Item it_j = L.getValue();
			L.moveToPos(j - 1);
			Item it_jj = L.getValue();
			if (it_jj.getNumerobiglietto() < it_j.getNumerobiglietto())
			{
				L.moveToPos(j);
				Item removed = L.remove();
				L.moveToPos(j - 1);
				L.insert(removed);
			}
		}
	}
}



int main() {
	srand(time(NULL));

	LList<Item> listabiglieti;
	LStack<Premio> stackpremi;

	ifstream file_biglietti("biglietti.txt");
	if (file_biglietti.is_open()) {
		int n;
		string nome, cognome;
		while (file_biglietti >> n >> nome >> cognome)
			listabiglieti.append(Item(n, nome, cognome));
		file_biglietti.close();
	}

	bubblesort(listabiglieti);
	lprint(listabiglieti);

	//Lettura premi
	int k;
	cout << endl << "Inserire il numero di premi da estrarre: ";
	cin >> k;
	Premio* premiestratti = new Premio[k];
	if (k > 0) {
		ifstream file_premi("premi.txt");
		if (file_premi.is_open()) {
			for (int i = 0; i < k; i++) {
				string nome; float valore;
				file_premi >> nome >> valore;
				premiestratti[i] = Premio(valore / 100, nome);
			}
			file_premi.close();
		}
	}
	cout << endl;
	//Invertire primo con ultimo premio
	Premio primo = premiestratti[0];
	premiestratti[0] = premiestratti[k - 1];
	premiestratti[k-1] = primo;

	for (int i = k - 1; i >= 0; i--)
		stackpremi.push(premiestratti[i]);

	Lstackprint(stackpremi);
	cout << endl;

	//Per ciascun premio contenuto nello stack selezionare in modo casuale un biglietto vincitore
	//contenuto nella lista dei biglietti venduti.Stampare a video i nomi dei vincitori e il premio attribuito a
	//ciascuno di essi.Ciascuna persona può ricevere un solo premio(controllare nome e cognome).
	//Scrivere una soluzione che non elimini elementi dall’elenco dei biglietti(suggerimento: utilizzare una
	//lista di appoggio).Esempio di stampa per K = 4	
	
	LList<Item> vincitori; //L'indice è l'indice del premio vinto
	int counter = 0;
	while (vincitori.length() < k) {
		//Estraggo un vincitore
		int randomindex = rand() % listabiglieti.length();
		listabiglieti.moveToPos(randomindex);
		Item estratto = listabiglieti.getValue();
		bool giapresente = false;
		//Controllo che non sia già presente nella lista vincitori
		for (vincitori.moveToStart(); vincitori.currPos() < vincitori.length(); vincitori.next()) {
			if (vincitori.getValue() == estratto) {
				giapresente = true;
				break;
			}
		} //endfor
		if (!giapresente) {
			vincitori.append(estratto);
			cout << "Il premio " << premiestratti[counter++].getNome() << " viene attribuito a " << estratto.getNome() << " " << estratto.getCognome() << endl;
		}
	}

	delete[] premiestratti;

	return 0;
}