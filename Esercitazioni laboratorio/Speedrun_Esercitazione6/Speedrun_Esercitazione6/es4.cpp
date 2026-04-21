/*
Esercizio 4: Scrivere un programma che legga da file un numero N (memorizzato nella prima riga) che
rappresenta il numero di studenti di una classe. Ogni riga successiva del file contiene il cognome (string),
l’età (int) e la media (float) dei voti di ciascuno studente nel formato: <cognome> <età> <media voti>
Esempio:
8
Rossi 24 24.56
Bianchi 23 18.2
Verdi 30 29.65
Blu 22 28.30
Rosa 19 27.3
Gialli 25 27.3
Neri 24 25.56
Viola 21 30.0
Il programma chiede all’utente due interi positivi (num_scelti ed eta_max). L’elenco degli studenti viene
salvato in un array di dimensione N allocato dinamicamente. Gli elementi dell’array sono oggetti di una
classe Item che contiene una struttura dati “studente” (con tre campi cognome, età e media voti). Dopo
aver ordinato l’array in modo decrescente secondo la media dei voti (utilizzando un qualsiasi algoritmo)
viene creata una lista concatenata che contiene i num_scelti studenti con la media più alta che hanno
un’età strettamente inferiore a eta_max e la stampa a video. Nell’esempio, con num_scelti uguale=4 ed
eta_max=25 la lista deve contenere gli studenti: Viola 30, Blu 28.3, Rosa 27.3 e Neri 25.56.
*/

#include "es4_test.h"
#include <fstream>
#include <llist.h>

int main() {
	int N;
	ifstream file("studenti.txt");
	if (file.is_open())
		file >> N;

	Item* list = new Item[N];


	if (file.is_open()) {
		string cognome; int eta; float media;
		for (int i = 0; i < N; i++) {
			file >> cognome >> eta >> media;
			list[i] = Item(cognome, eta, media);
		}


	}
	lprint(list, N);

	int nmax, etamax;

	cout << endl << "Inserire il numero di studenti e l'eta massima: ";
	cin >> nmax >> etamax;


	//ordinamento per media decrescente
	bubble(list, N);
	LList<Item> llist;
	for (int i = 0; (i < N && llist.length() < nmax); i++) {
		if (list[i].getEta() < etamax)
			llist.append(list[i]);
	}

	listPrint(llist);

	delete[] list;
	file.close();
	return 0;
}