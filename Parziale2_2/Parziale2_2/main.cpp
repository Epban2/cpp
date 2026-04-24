#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


#include "llist.h"
#include "lstack.h"
#include "esame_listTest.h"

//"bigliettiVenduti.txt" l’elenco dei
//biglietti venduti salvando le informazioni contenute in ogni riga(formato: <numero
//	biglietto>, <nome>, <cognome>) in un elemento della lista.Ogni persona può avere acquistato più
//	di un biglietto.I biglietti acquistati dalla stessa persona si trovano in righe consecutive del file.
const char SEPARATORE = ',';



void selectionsort(List<Item>& L) {
	int min_pos;
	Item min_element;
	// se lunghezza <2 non fai nulla
	for (int i = 0; i < L.length() - 1; i++) {
		L.moveToPos(i);
		min_element = L.getValue();
		min_pos = i;
		for (int j = i + 1; j < L.length(); j++) {
			L.moveToPos(j);
			Item it_temp = L.getValue();
			if (it_temp.getNumerobiglietto() > min_element.getNumerobiglietto()) //ordine decrescente
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

int main() {
	LList<Item> listabiglietti;
	LStack<Item> stackbiglietti;

	// 1)
	ifstream filebiglietti("bigliettiVenduti.txt");
	if (filebiglietti.is_open()) {
		int numero;
		string nome, cognome, str;
		while (getline(filebiglietti, str, SEPARATORE)) {
			istringstream token(str);
			token >> numero;
			getline(filebiglietti, nome, SEPARATORE);
			getline(filebiglietti, cognome);
			listabiglietti.append(Item(numero, nome, cognome));
		}
		filebiglietti.close();
	}

	// 2)

	for (listabiglietti.moveToStart(); listabiglietti.currPos() < listabiglietti.length(); listabiglietti.next()) {
		if (listabiglietti.currPos() > 0) {
			Item attuale = listabiglietti.getValue();
			listabiglietti.prev();
			if (attuale != listabiglietti.getValue()) //se sono diversi allora lo stampo
				cout << "primo biglietto acquistato da " << attuale;
			listabiglietti.next();
		}
		else //il primo elemento non controlla
			cout << "primo biglietto acquistato da " << listabiglietti.getValue();
	}



	selectionsort(listabiglietti);
	cout << endl << "Ordine decrescente:" << endl;
	lprint(listabiglietti);


	// 3)
	//Rimuovere dalla lista tutti gli elementi con numero di biglietto dispari.Stampare a video il contenuto
	//della lista.Creare uno stack di elementi “Item” e inserire nello stack tutti gli elementi della lista
	//contenente i biglietti pari partendo dalla testa fino alla coda.Stampare a video il contenuto dello
	//stack.

	listabiglietti.moveToStart();
	while (listabiglietti.currPos() < listabiglietti.length()) {
		if (listabiglietti.getValue().getNumerobiglietto() % 2 == 0) {
			stackbiglietti.push(listabiglietti.getValue());
			listabiglietti.next();
		}
		else
			listabiglietti.remove();

	}
	cout << endl << "Stack: " << endl;
	Lstackprint(stackbiglietti);

	// 4)
	//Modificare lo stack dei biglietti creato al punto 3 scambiando il primo e l’ultimo elemento.Per
	//scambiare i due elementi scrivere un algoritmo che utilizzi solamente un secondo stack di appoggio
	//e variabili di tipo Item.Stampare il contenuto dello stack dopo lo scambio.Nell’esempio

	LStack<Item> stackappoggio;
	Item primo, ultimo;
	primo = stackbiglietti.topValue();
	int length = stackbiglietti.length();
	while (stackappoggio.length() < length) {
		stackappoggio.push(stackbiglietti.pop());
	}

	ultimo = stackappoggio.pop();
	stackbiglietti.push(primo);
	while (stackbiglietti.length() < (length-1)) {
		stackbiglietti.push(stackappoggio.pop());

	}

	cout << endl << "Primo e ultimo invertiti: " << endl;
	stackbiglietti.push(ultimo);
	Lstackprint(stackbiglietti);
	
	cout << endl << "That is all.\n";

	return 0;
}