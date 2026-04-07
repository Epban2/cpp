// Scrivere un programma che definisca due classi: Money e CreditCard. La classe Money deve contenere due dati membri privati interi (euros e cents). La classe Money deve anche contenere:
// •	Costruttore che inizializza a 0 entrambi i dati membri.
// •	metodi pubblici per impostare e leggere il valori dei dati membri: get_euros(), set_euros(int e), get_cents(), set_cents(int c)
// •	Un operatore ‘+’ definito come funzione non-membro: Money operator+(Money m1, Money m2)
// che esegue la somma di due oggetti Money sommando euro e centesimi (i centesimi se eccedono il valore di 100 vanno convertiti in euro: es 10.50 euro+ 5.70 euro= 16.20 euro)
// •	Un operatore ‘<<’ definito come funzione non-membro: ostream& operator<<(ostream& os, Money m) per stampare a video i dati membri euros e cents
// La classe CreditCard deve contenere tre dati membri privati: il nome del proprietario (string), il numero della carta di credito (string), il totale dei pagamenti effettuati (Money). La classe CreditCard deve anche contenere:
// •	Costruttore per creare una carta dato il nome del proprietario e il numero della carta.
// •	Una funzione membro print() per stampare il nome del proprietario e il numero
// •	Una funzione membro get_totalcharges() che restituisce il totale dei pagamenti
// •	Una funzione membro charge(string item, int e, int c) che aggiorna il totale dei pagamenti a seguito di una singola spesa (con causale “item”) di euro ‘e’ e di centesimi ‘c’ 
// Il programma principale crea un oggetto di tipo CrediCard, legge da un file di testo un elenco di spese e aggiorna il totale dei pagamenti. Il file di testo delle spese contiene per ogni riga le informazioni di una singola spesa su tre colonne: <causale della spesa> <euro> <centesimi> 
// es: 
// book 90 60
// pizza 20 50


#include "esercitazione2-es3.h"


int main()
{
	CreditCard cb("John Doe", "123456");
	cb.print();

	string operation;
	int e_charge;
	int c_charge;
	ifstream myfile("charges.txt");

	if (myfile.is_open()) {
		while (myfile >> operation >> e_charge >> c_charge) {
			cb.charge(operation, e_charge, c_charge);
		}
		myfile.close();
	}

	cout << "Total charges: " << cb.get_totalcharges();
}