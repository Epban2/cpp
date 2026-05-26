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
		if (counter == 2) {
			cout << "Q3: terzo elemento dopo " << s << " :" << i << endl;
			break;
		}
		
		else 
		{
			counter++;
			cout << counter << ", ";
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
	Q2: stampa list(Il Tempo, 7.26, Rome, 1944) (Alto Adige, 7.367, Bolzano, 1945) (La Sicilia, 7.633, Catania, 1945) (La Provincia, 13.207, Como, 1892)
	(L'Adige,18.787,Trento,1945) (La Nuova Sardegna,19.529,Sassari,1891) (Il Mattino,23.966,Naples,1892) (Messaggero Veneto,26.043,Udine,1946)
	(L'Unione Sarda,26.284,Cagliari,1889) (Il Gazzettino,43.661,Venice,1887) (Il Messaggero,62.466,Rome,1878) (La Nazione,36.468,Florence,1859)
	(Dolomiten, 31.762, Bolzano, 1882) (L'Eco di Bergamo,28.77,Bergamo,1880) (Il Secolo XIX,21.964,Genoa,1886) (Gazzetta di
	Parma, 21.207, Parma, 1735) (L'Arena,18.644,Verona,1866) (Il Tirreno,17.911,Livorno,1877) (Il Giorno,17.202,Milan,1956) (Il
	Piccolo, 12.959, Trieste, 1881) (Gazzetta di Mantova, 11.634, Mantua, 1664) (Il Mattino di Padova, 10.378, Padua, 1978) (Gazzetta del
	Sud, 9.143, Messina, 1952) (La Nuova Venezia, 7.595, Venice, 1978)
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
	for (list<Item>::iterator it = L1.begin(); it != L1.end(); it++) {
		Item i = (*it);
		if (i.getAnno() > 1886 && i.getAnno() < 1952) {
			L1.push_front(i);
			it = L1.erase(it);
		}
	}

	cout << endl << endl;
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
	LQueue<Item> Q2,Q3;
	copiaCoda(Q1, Q2);
	copiaCoda(Q1, Q3);
	prossimo_quotidiano(Q2,"Il Tirreno");
	prossimo_quotidiano(Q3,"Il Tempo");


	return 0;

}

