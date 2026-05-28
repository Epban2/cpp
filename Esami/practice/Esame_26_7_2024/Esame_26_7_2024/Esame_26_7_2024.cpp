#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Lqueue.h" //LQueue
#include "LQueueTest.h" //item, lqueueprint()
#include "quicksort.h" //quicksort()
using namespace std;
#include <queue> //queue

#include "heap.h" //PQ

const string FILENAME = "lunapark.txt";
const char SEPARATORE = ';';

void clearScreen() { cout << endl << endl; }

/*
Scrivere un algoritmo iterativo che ad ogni iterazione elimini e stampi l’elemento preso dalla coda di priorità che contiene
più elementi tra le due o, a parità di lunghezza delle due code di priorità, elimini e stampi l’elemento
preso da pq_lunapark1 o pq_lunapark2 con il campo <nome> alfabeticamente maggiore.
*/
void extractAndPrint(PQ<Item>& pq1, PQ<Item>& pq2) {
	cout << "4: stampa elementi estratti da priority queues ";
	while (!pq1.empty() || !pq2.empty()) {
		Item i;
		if (pq1.length() > pq2.length())
			i = pq1.getmax();
		else if (pq2.length() > pq1.length())
			i = pq2.getmax();
		else {
			Item i1 = pq1.getmax();
			Item i2 = pq2.getmax();
			if (i1.getNome() >= i2.getNome()) {
				i = i1;
				pq2.insert(i2);
			}
			else {
				i = i2;
				pq1.insert(i1);
			}
		}
		cout << i;
	}
}

int main()
{
	LQueue<Item> q1, q1_copy; //coda LQueue
	queue<Item> q2, q2_copy; // coda stl

	ifstream file(FILENAME);
	if (file.is_open()) {

		string codice_str, nome, nazione;
		int codice;
		float altezza;

		while (getline(file, codice_str, SEPARATORE)) {
			istringstream token(codice_str);
			token >> codice;

			getline(file, nome, SEPARATORE);
			getline(file, nazione, SEPARATORE);
			file >> altezza;
			Item i(codice, nome, nazione, altezza);
			if (nazione == "United States")
				q1.enqueue(i);
			else
				q2.push(i);

		}

	}
	file.close();

	cout << "1: stampa coda q1 ";
	Lqueueprint(q1);
	clearScreen(); cout << "1: stampa coda q2 ";
	q2_copy = q2;
	while (q2_copy.size() > 0) {
		cout << q2_copy.front();
		q2_copy.pop();
	}


	/* .Q2.
	Scrivere un algoritmo che elimini da q1 e q2 tutti gli elementi tranne quelli che hanno una <altezza>
	strettamente minore di 92, e tranne quelli che hanno una <altezza> strettamente maggiore
	rispetto all’elemento precedente(non si applica al primo elemento).Mantenere lo stesso ordine
	degli elementi.Stampare le code q1 e q2.
	*/
	Item before = q1.frontValue();
	while (q1.length() > 0) {
		Item i = q1.dequeue();
		if (i.getAltezza() < 92 || i.getAltezza() > before.getAltezza())
			q1_copy.enqueue(i);
		before = i;
	}
	q1.clear(); // 
	//rimetto in coda originale q1
	while (q1_copy.length() > 0) q1.enqueue(q1_copy.dequeue());


	// coda stl
	queue<Item> q3;
	before = q2.front();

	while (q2.size() > 0) {
		Item i = q2.front();
		q2.pop();

		if (i.getAltezza() < 92 || i.getAltezza() > before.getAltezza())
			q3.push(i);
		before = i;
	}

	while (q3.size() > 0) { q2.push(q3.front()); q3.pop(); }


	clearScreen();
	cout << "\n2: stampa coda q1 ";
	Lqueueprint(q1);
	clearScreen(); cout << "2: stampa coda q2 ";
	q2_copy = q2;
	while (q2_copy.size() > 0) {
		cout << q2_copy.front();
		q2_copy.pop();
	}


	// 3)
	/*
	Creare un array “array_lunapark” di oggetti Item con allocazione dinamica della memoria e
	dimensione pari alla somma delle lunghezze delle code q1 e q2.Estrarre tutti gli elementi da q1 e
	q2 e inserirli in array_lunapark.Ordinare array_lunapark per <codice> crescente utilizzando
	l’algoritmo SelectionSort.Stampare array_lunapark.
	*/
	int dim = q1.length() + q2.size();
	Item* array_lunapark = new Item[dim];

	int index = 0;
	for (; q1.length() > 0; index++)
		array_lunapark[index] = q1.dequeue();

	for (; q2.size() > 0; index++)
	{
		array_lunapark[index] = q2.front();
		q2.pop();
	}


	clearScreen();
	quicksort(array_lunapark, 0, dim - 1);
	cout << "3: stampa array ordinato ";
	for (index = 0; index < dim; index++)
		cout << array_lunapark[index];


	//4)
	/*
	 Creare due code di priorità di oggetti Item (“pq_lunapark1” e “pq_lunapark2”) della classe pq, con
	priorità il campo <codice>. Inserire gli elementi di array_lunapark con <nazione>="United States"
	in pq_lunapark1, e gli elementi con <nazione>="Germany" in pq_lunapark2. Aggiungere un
	metodo alla classe pq per restituire la lunghezza della coda di priorità. Scrivere un algoritmo
	iterativo che ad ogni iterazione elimini e stampi l’elemento preso dalla coda di priorità che contiene
	più elementi tra le due o, a parità di lunghezza delle due code di priorità, elimini e stampi l’elemento
	preso da pq_lunapark1 o pq_lunapark2 con il campo <nome> alfabeticamente maggiore.
	*/

	PQ<Item> pq_lunapark1(30), pq_lunapark2(30);
	for (index = 0; index < dim; index++) {
		Item curr = array_lunapark[index];
		if (curr.getNazione() == "United States")
			pq_lunapark1.insert(curr);
		else if (curr.getNazione() == "Germany")
			pq_lunapark2.insert(curr);

	}

	clearScreen();
	extractAndPrint(pq_lunapark1, pq_lunapark2);

	clearScreen();
	delete[] array_lunapark;
	return 0;
}
