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
			if (it_temp.getNumerobiglietto() > min_element.getNumerobiglietto())
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

	//155, Andrea, Rossi
	ifstream file("bigliettiVenduti.txt");
	if (file.is_open()) {
		int numero;
		string str, nome, cognome;
		while (getline(file, str, ',')) {
			istringstream token(str);
			token >> numero;
			getline(file, nome, ',');
			getline(file, cognome);
			listabiglietti.append(Item(numero, nome, cognome));
		}

		file.close();
	}
	else
		cout << "error opening file" << endl;

	lprint(listabiglietti);


	// 2)
	for (listabiglietti.moveToStart(); listabiglietti.currPos() < listabiglietti.length(); listabiglietti.next()) {
		bool flag = false;
		if (listabiglietti.currPos() > 0) {
			listabiglietti.prev();
			Item past = listabiglietti.getValue();
			listabiglietti.next();
			if (past == listabiglietti.getValue())
				flag = true;
		}
		if (!flag)
			cout << "primo biglietto acquistato da " << listabiglietti.getValue().getNome() << " " << listabiglietti.getValue().getCognome() << " : " << listabiglietti.getValue().getNumerobiglietto() << endl;

	}

	cout << endl << "Selection sort: " << endl;
	selectionsort(listabiglietti);
	lprint(listabiglietti);



	// 3)
	//Rimuovere dalla lista tutti gli elementi con numero di biglietto dispari.Stampare a video il contenuto
	//della lista.Creare uno stack di elementi “Item” e inserire nello stack tutti gli elementi della lista
	//contenente i biglietti pari partendo dalla testa fino alla coda.Stampare a video il contenuto dello
	//stack.

	listabiglietti.moveToStart();
	while (listabiglietti.currPos() < listabiglietti.length()) {
		if ((listabiglietti.getValue().getNumerobiglietto() % 2) != 0) {
			listabiglietti.remove();
		}
		else {
			stackbiglietti.push(listabiglietti.getValue());
			listabiglietti.next();
		}
	}
	cout << endl << "No dispari: " << endl;
	lprint(listabiglietti);
	cout << endl << "stack: " << endl;
	Lstackprint(stackbiglietti);
	
	// 4)
	//Modificare lo stack dei biglietti creato al punto 3 scambiando il primo e l’ultimo elemento.Per
	//scambiare i due elementi scrivere un algoritmo che utilizzi solamente un secondo stack di appoggio
	//e variabili di tipo Item.Stampare il contenuto dello stack dopo lo scambio.Nell’esempio
	
	LStack<Item> stackappoggio;

	Item primo, ultimo;
	primo = stackbiglietti.pop();
	while (stackbiglietti.length() > 0)
		stackappoggio.push(stackbiglietti.pop());

	ultimo = stackappoggio.pop();

	stackbiglietti.push(primo);
	while (stackappoggio.length() > 0)
		stackbiglietti.push(stackappoggio.pop());
	stackbiglietti.push(ultimo);

	cout << endl << "Invertiti primo_ultimo: " << endl;
	Lstackprint(stackbiglietti);

	
	return 0;
}