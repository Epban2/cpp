#include "List_test.h"
#include <fstream>
#include <sstream>
#include <astack.h>
const char SEPARATORE = ',';


void selection(LList<Item>& l)
{
	for (int i = 0; i < l.length(); i++) //Avanzamento esterno
	{
		int min = i;
		for (int j = i + 1; j <= l.length() - 1; j++) //Avanzamento interno, cerca il numero minore della sottosequenza
		{
			l.moveToPos(j);
			Item a = l.getValue();
			l.moveToPos(min);
			Item b = l.getValue();
			if (a > b) min = j;
		}
		l.moveToPos(i);
		Item a = l.getValue();

		l.moveToPos(min);
		Item b = l.remove();

		l.insert(a);
		l.moveToPos(i);
		l.remove();
		l.insert(b);


	}
}



int main() {
	// 1)
	LList<Item> lista_biglietti;
	ifstream file("bigliettiVenduti.txt");

	int num_biglietto;
	string str, nome, cognome;

	if (file.is_open()) {
		while (getline(file, str, SEPARATORE)) {
			istringstream token(str);
			token >> num_biglietto;
			getline(file, nome, SEPARATORE);
			file >> cognome;

			lista_biglietti.append(Item(nome, cognome, num_biglietto));
		}
	}
	file.close();

	//stampa: primo biglietto acquistato da Andrea Rossi :155

	Item* no_doppioni = new Item[lista_biglietti.length()];
	int list_length = 0;
	lista_biglietti.moveToStart();
	while (lista_biglietti.currPos() < lista_biglietti.length()) {
		bool found = false;
		//scorro la lista di appoggio

		for (int i = 0; i < list_length; i++) {
			if (no_doppioni[i] == lista_biglietti.getValue())
			{
				found = true;
				break;
			}
		}
		if (!found) // allora posso aggiungerlo alla lista e aumento la dimensione
			no_doppioni[list_length++] = lista_biglietti.getValue();

		lista_biglietti.next();
	}

	for (int i = 0; i < list_length; i++) {
		cout << "primo biglietto acquistato da " << no_doppioni[i];
	}
	delete[] no_doppioni;

	cout << endl << "Lista ordinata decrescente: " << endl;
	selection(lista_biglietti);
	lprint(lista_biglietti);

	// 3)Rimuovere dalla lista tutti gli elementi con numero di biglietto dispari


	LStack<Item> stack;

	for (lista_biglietti.moveToStart(); lista_biglietti.currPos() < lista_biglietti.length(); lista_biglietti.next()) {
		if (lista_biglietti.getValue().getNumeroBiglietto() % 2 != 0)
			lista_biglietti.remove();
	}
	
	for (lista_biglietti.moveToStart(); lista_biglietti.currPos() < lista_biglietti.length(); lista_biglietti.next()) {
		stack.push(lista_biglietti.getValue());
	}

	cout << endl << "Rimossi gli elementi dispari: " << endl;
	lprint(lista_biglietti);

	cout << endl << "Stack: " << endl;
	Lstackprint(stack);

	/* 4)
	Modificare lo stack dei biglietti creato al punto 3 scambiando il primo e l’ultimo elemento.Per
	scambiare i due elementi scrivere un algoritmo che utilizzi solamente un secondo stack di appoggio
	e variabili di tipo Item.Stampare il contenuto dello stack dopo lo scambio.Nell’esempio:
	Stack prima di inversione elementi : (12 Marco Venturi) (500 Andrea Rossi) (502 Andrea Rossi)
	(550 Elena Giannini) (1342 Marco Carretta) (2000 Francesco Fabbri) (2002 Francesco Fabbri)
	(2004 Giulio Rossi)
	Stack dopo inversione elementi : (2004 Giulio Rossi) (500 Andrea Rossi) (502 Andrea Rossi) (550
	Elena Giannini) (1342 Marco Carretta) (2000 Francesco Fabbri) (2002 Francesco Fabbri) (12 Marco Venturi)
	*/

	int stack_length = stack.length();
	LStack<Item> stack_appoggio;
	Item primo = stack.pop(), ultimo;
	
	while (stack.length() > 0) {
		stack_appoggio.push(stack.pop());
	}
	ultimo = stack_appoggio.pop();

	//rimetto nello stack originale invertendo top e coda
	stack.push(primo);
	while (stack.length() < stack_length - 1)
		stack.push(stack_appoggio.pop());
	stack_appoggio.clear();

	//metto in testa l'ultimo
	stack.push(ultimo);

	cout << endl << "Scambiato primo e ultimo: " << endl;
	Lstackprint(stack);

	return 0;
}