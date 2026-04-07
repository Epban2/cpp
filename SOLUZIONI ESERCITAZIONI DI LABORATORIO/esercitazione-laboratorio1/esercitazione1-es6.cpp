//Scrivere un programma in cui dato il prezzo netto di un prodotto (variabile float inserita in ingresso da tastiera) lo sconti del 35% se tale prezzo è > 100 e poi aggiunga l'IVA del 22% stampando a video il risultato finale.

#include<iostream>
using namespace std;

int main() {
	float prezzo, prezzo_finale = 0; 
	cout << "prezzo:"; 
	cin >> prezzo;
	if (prezzo > 100)
			prezzo -= 0.35 * prezzo;
	prezzo_finale = prezzo + prezzo * 0.22;
	cout << prezzo_finale;

	return 1;
}

