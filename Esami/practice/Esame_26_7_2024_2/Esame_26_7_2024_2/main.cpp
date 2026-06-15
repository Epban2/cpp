#include "Item.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <queue> //stl
#include "lqueue.h"
#include "LQueueTest.h"
#include "heap.h"
using namespace std;

const char SEPARATORE = ';';
void clear() { cout << endl << endl; }

void printQueue(queue<Item>& q) {
	queue<Item> copy = q;
	while (!copy.empty()) {
		Item  i = copy.front();
		copy.pop();
		cout << i;
	}

}

void selection(Item a[], int l, int r)
{
	for (int i = l; i < r; i++) //Avanzamento esterno
	{
		int min = i;
		for (int j = i + 1; j <= r; j++) //Avanzamento interno, cerca il numero minore della sottosequenza
			if (a[j].getcodice() < a[min].getcodice()) min = j;
		Item temp = a[i];
		a[i] = a[min];
		a[min] = temp;

	}
}

int main()
{
	//1; Kingda Ka; United States; 127.2
	ifstream file("lunapark.txt");
	LQueue<Item> q1;
	queue<Item> q2; //coda stl

	//formato: <codice>; <nome>; <nazione>; <altezza> dove

	if (file.is_open()) {
		string codicestr, nome, nazione, altezzastr;
		int codice; float altezza;
		while (getline(file, codicestr, SEPARATORE)) {

			getline(file, nome, SEPARATORE);
			getline(file, nazione, SEPARATORE);
			getline(file, altezzastr);
			istringstream tokencodice(codicestr);
			istringstream tokenaltezza(altezzastr);
			tokencodice >> codice;
			tokenaltezza >> altezza;
			Item i(codice, nazione, nome, altezza);

			if (nazione == "United States")
				q1.enqueue(i);
			else q2.push(i);
		}
	}
	file.close();

	cout << "1: stampa coda q1 ";
	Lqueueprint(q1);

	clear();
	cout << "1: stampa coda q2 ";
	printQueue(q2);

	/*
	Scrivere un algoritmo che elimini da q1 e q2 tutti gli elementi tranne quelli che hanno una <altezza>
	strettamente minore di 92, e tranne quelli che hanno una <altezza> strettamente maggiore
	rispetto all’elemento precedente(non si applica al primo elemento).Mantenere lo stesso ordine
	degli elementi.Stampare le code q1 e q2.
	*/
	clear();
	Item previous;
	int length = q1.length();
	for (int i = 0; i < length; i++)
	{
		bool insert = false;
		Item dequeued = q1.dequeue();
		//reinserirlo solo se:
		// altezza h < 92 o h > h_precedente
		if (i > 0 && !previous.isNull() && dequeued.getaltezza() > previous.getaltezza())
			insert = true;


		if (dequeued.getaltezza() < 92)
			insert = true;

		if (insert) {
			q1.enqueue(dequeued);
			previous = dequeued;

		}
	}
	cout << "2: stampa coda q1 ";
	Lqueueprint(q1);

	//coda stl
	int q2length = q2.size();
	Item previous2;
	queue<Item> q2_copy;

	for (int i = 0; i < q2length; i++)
	{
		bool insert = false;
		Item dequeued = q2.front();
		q2.pop();

		if (i > 0 && !previous2.isNull() && dequeued.getaltezza() > previous2.getaltezza())
			insert = true;


		if (dequeued.getaltezza() < 92)
			insert = true;

		if (insert)
			q2.push(dequeued);

		previous2 = dequeued;

	}

	cout << "\n\n2: stampa coda q2 ";
	printQueue(q2);

	/*
	Creare un array “array_lunapark” di oggetti Item con allocazione dinamica della memoria e
	dimensione pari alla somma delle lunghezze delle code q1 e q2.Estrarre tutti gli elementi da q1 e
	q2 e inserirli in array_lunapark.Ordinare array_lunapark per <codice> crescente utilizzando
	l’algoritmo SelectionSort.Stampare array_lunapark.
	*/
	clear();

	int arrayLength = q1.length() + q2.size();
	Item* array_lunapark = new Item[arrayLength];
	int count = 0;
	while (q1.length() > 0) {
		Item i = q1.dequeue();
		array_lunapark[count++] = i;
	}
	while (!q2.empty()) {
		Item i = q2.front();
		q2.pop();
		array_lunapark[count++] = i;
	}

	selection(array_lunapark, 0, arrayLength - 1);
	cout << "3: stampa array ordinato\n";
	for (int i = 0; i < arrayLength; i++)
		cout << array_lunapark[i];

	clear();

	/*
	Creare due code di priorità di oggetti Item(“pq_lunapark1” e “pq_lunapark2”) della classe pq, con
	priorità il campo <codice>.Inserire gli elementi di array_lunapark con < nazione >= "United States"
	in pq_lunapark1, e gli elementi con < nazione >= "Germany" in pq_lunapark2.Aggiungere un
	metodo alla classe pq per restituire la lunghezza della coda di priorità.Scrivere un algoritmo
	iterativo che ad ogni iterazione elimini e stampi l’elemento preso dalla coda di priorità che contiene
	più elementi tra le due o, a parità di lunghezza delle due code di priorità, elimini e stampi l’elemento
	preso da pq_lunapark1 o pq_lunapark2 con il campo <nome> alfabeticamente maggiore.
	*/
	PQ<Item> pq_lunapark1(arrayLength), pq_lunapark2(arrayLength);
	for (int i = 0; i < arrayLength; i++) {
		Item it = array_lunapark[i];
		if (it.getnazione() == "United States")
			pq_lunapark1.insert(it);
		else if (it.getnazione() == "Germany")
			pq_lunapark2.insert(it);
	}


	//Scrivere un algoritmo
	//	iterativo che ad ogni iterazione elimini e stampi l’elemento preso dalla coda di priorità che contiene
	//	più elementi tra le due o, a parità di lunghezza delle due code di priorità, elimini e stampi l’elemento
	//	preso da pq_lunapark1 o pq_lunapark2 con il campo <nome> alfabeticamente maggiore.

	cout << "4: stampa elementi estratti da priority queues ";
	while (!pq_lunapark1.empty() || !pq_lunapark2.empty()) { //finche' non sono entrambe vuote
		if (pq_lunapark1.length() > pq_lunapark2.length()) {
			cout << pq_lunapark1.getmax();
		}
		else if (pq_lunapark2.length() > pq_lunapark1.length()) {
			cout << pq_lunapark2.getmax();

		}
		else if (pq_lunapark2.length() == pq_lunapark1.length()) {
			Item i1 = pq_lunapark1.getmax();
			Item i2 = pq_lunapark2.getmax();
			if (i1.getnome() > i2.getnome()) {
				cout << i1;
				pq_lunapark2.insert(i2);
			}
			else { // i2 >= i1
				cout << i2;
				pq_lunapark1.insert(i1);
			}
		}
		else {
			//se siamo arrivati qui, significa che una delle due e' vuota, allora estraggo dall'altra
			if (pq_lunapark1.empty())
				cout << pq_lunapark2.getmax();
			else
				cout << pq_lunapark1.getmax();
		}
	}
	clear();
	return 0;
}

