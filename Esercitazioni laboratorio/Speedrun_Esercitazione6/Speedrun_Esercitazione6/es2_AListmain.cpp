/*
Esercizio 2:Scrivere un programma per gestire una agenda telefonica contenente massimo 100
nominativi utilizzando una lista con array (classe AList). Ogni nominativo (classe Item) è composto da
una struttura dati contenente: Nome (string in caratteri minuscoli), Cognome (string in caratteri
minuscoli) e data di nascita (tre campi “giorno”, “mese”, “anno” in valori interi positivi). L’agenda va
letta da un file di testo contenente su ogni riga <nome> <cognome> <data di nascita> di una persona. La
data di nascita è espressa nella forma GG/MM/ANNO (es: 02/11/1990). L’agenda va stampata a video
ordinata in modo crescente per Cognome e, a parità di Cognome, per Nome, e a parità di Cognome e
Nome per data di nascita con uno qualsiasi degli algoritmi di ordinamento visti a lezione (modificando le
condizioni di confronto tra Item). (Soluzione alternativa: utilizzare un operatore “<” per la classe Item)
*/

const int MAXNOMINATIVI = 100;
#include "Es2_AListtest.h"
#include <fstream>

int main() {
	AList<Item> list;
	ifstream reading_file("agenda.txt");
	if (reading_file.is_open()) {
		string nome, cognome;
		char slash1, slash2;
		int gg, mm, yyyy;
		while (reading_file >> nome >> cognome >> gg >> slash1 >> mm >> slash2 >> yyyy)
			list.append(Item(nome, cognome, gg, mm, yyyy));
	}
	
	lprint(list);

	bubble(list);
	lprint(list);

	return 0;
}