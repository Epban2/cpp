//v1

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "lqueue.h"
#include "LQueueTest.h"
#include "bst.h"
#include <list>
using namespace std;

const string FILENAME = "quotidiani.txt";
const char SEPARATORE = ',';

template <typename E>
void copiaCoda(LQueue<E>& originale, LQueue<E>& clone) {
	clone.clear(); // Per sicurezza, svuotiamo la coda di destinazione

	int n = originale.length();
	for (int i = 0; i < n; i++) {
		// 1. Estrai dalla testa
		E elemento = originale.dequeue();

		// 2. Mettilo nella coda di lavoro (il clone)
		clone.enqueue(elemento);

		// 3. Rimettilo in fondo alla coda originale!
		originale.enqueue(elemento);
	}
}



/*
Scrivere una funzione che accetti come parametro Q1 e una stringa e che stampi, se esite, l’elemento
che in Q1 si trova tre posizioni più indietro rispetto all’elemento con <nome> uguale alla stringa
passata come argomento. Chiamare la funzione due volte con le stringhe “Il Tirreno” e “Il Tempo”.
Q3: terzo elemento dopo Il Tirreno: (Il Piccolo,12.959,Trieste,1881)
Q3: terzo elemento dopo Il Tempo: nessuno
*/
void prossimo_quotidiano(LQueue<Item>& Q, const string& s) {
	bool trovato = false;
	int counter = 0;
	while (Q.length() > 0) {
		Item i = Q.dequeue();
		if (counter == 2 && trovato) {
			cout << "Q3: terzo elemento dopo " << s << " :" << i << endl;
			return;
		}

		else if (trovato)
		{
			counter++;
		}

		if (i.getNome() == s) {
			trovato = true;
		}
	}
	cout << "Q3: terzo elemento dopo " << s << " : nessuno" << endl;

}

int main()
{
	//1)
	LQueue<Item> Q1;
	BST<Item, string> albero_quotidiani;
	ifstream reading_file(FILENAME);
	if (reading_file.is_open())
	{
		string nome, sede, tiratura_str, anno_str;
		float tiratura; int anno;
		while (getline(reading_file, nome, SEPARATORE)) {
			getline(reading_file, tiratura_str, SEPARATORE);
			getline(reading_file, sede, SEPARATORE);
			getline(reading_file, anno_str);
			istringstream token1(tiratura_str);
			token1 >> tiratura;
			istringstream token2(anno_str);
			token2 >> anno;
			if (tiratura > 7.1)
				Q1.enqueue(Item(nome, tiratura, sede, anno));

		}

	}
	reading_file.close();
	cout << "Stampa Q1: " << endl;
	Lqueueprint(Q1);

	/*
	Stampare Q1.Dopo aver stampato Q1
	inserire in albero_quotidiani gli elementi di Q1 solo se in albero_quotidiani non è già presente un
	elemento con la stessa <sede>.Dopo l’inserimento nell’albero Q1 deve contenere gli stessi elementi
	iniziali.Bilanciare albero_quotidiani e stamparlo con visita post - order.
	*/
	cout << "\n\n";

	LQueue<Item> appoggio;
	while (Q1.length() > 0) {
		Item item_cercato = albero_quotidiani.search(Q1.frontValue().key());
		if (item_cercato.key() == "") { // key default -> non trovato, nullitem -> inserisco nell'albero
			albero_quotidiani.insert(Q1.frontValue());
		}
		appoggio.enqueue(Q1.dequeue());
	}
	while (appoggio.length() > 0) {
		Q1.enqueue(appoggio.dequeue());
	}

	albero_quotidiani.balance();
	cout << "Stampa Albero: " << endl;
	albero_quotidiani.show(cout);



	//2)Creare una lista L1 di STL di oggetti Item. Inserire in coda in L1 tutti gli elementi di Q1. Dopo
	/*
	l’inserimento Q1 deve contenere gli stessi elementi iniziali.
	Dopo l’inserimento scrivere un algoritmo che scorra la lista L1 e
	che sposti in testa in L1 tutti gli elementi con <anno> strettamente maggiore
	di 1886 e strettamente minore di 1952. Stampare L1.
	*/

	list<Item> L1;
	//inserisco nella lista tutta la coda
	while (Q1.length() > 0) {
		L1.push_back(Q1.dequeue());
	}

	//reinserisco in Q1 gli elementi
	for (list<Item>::iterator it = L1.begin(); it != L1.end(); it++) {
		Q1.enqueue((*it));
	}

	//sposto in testa tutti gli elementi con <anno> strettamente maggiore di 1886 e strettamente minore di 1952

	for (list<Item>::iterator it = L1.begin(); it != L1.end();) {
		Item i = (*it);
		if (i.getAnno() > 1886 && i.getAnno() < 1952) {
			L1.push_front(i);
			it = L1.erase(it);
		}
		else
			it++;
		//Poiché erase sposta in avanti di uno il puntatore a causa della cancellazione, va rimossa dalla condizione del for l'incremento automatico e gestito manualmente (avremmo altrimenti un incremento di 2 quando sposta in avanti)
	}

	cout << endl << endl << "Q2)\n";
	//stampo la lista
	for (list<Item>::iterator it = L1.begin(); it != L1.end(); it++) cout << *it;



	//3)
	/*
	Scrivere una funzione che accetti come parametro Q1 e una stringa e che stampi, se esite, l’elemento
	che in Q1 si trova tre posizioni più indietro rispetto all’elemento con <nome> uguale alla stringa
	passata come argomento. Chiamare la funzione due volte con le stringhe “Il Tirreno” e “Il Tempo”.
	Q3: terzo elemento dopo Il Tirreno: (Il Piccolo,12.959,Trieste,1881)
	Q3: terzo elemento dopo Il Tempo: nessuno
	*/
	cout << endl << endl;
	LQueue<Item> Q2, Q3;

	copiaCoda(Q1, Q2);
	copiaCoda(Q1, Q3);
	prossimo_quotidiano(Q2, "Il Tirreno");
	prossimo_quotidiano(Q3, "Il Tempo");


	//Q4)
	albero_quotidiani.editMaxKey();
	albero_quotidiani.editMiddleValue();
	cout << "\n\nQ4)" << endl;
	albero_quotidiani.show(cout);

	cout << endl;
	return 0;

}

