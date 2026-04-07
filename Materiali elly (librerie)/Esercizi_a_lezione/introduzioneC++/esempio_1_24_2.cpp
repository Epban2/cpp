//In un esercizio di telepatia, un sensitivo scommette di essere in grado di indovinare almeno 3 numeri 
//consecutivi, in una sequenza di N numeri interi pensati da uno spettatore. Si scriva un programma che 
//carichi da un file la sequenza dei numeri dello spettatore (il file contiene N nella prima riga e i numeri della sequenza nella seconda riga separati da spazi), e verifichi se il sensitivo dice la verità.
//Il programma acquisisce dal sensitivo i 3 numeri (da tastiera).
//Il programma legge il file e crea un array di dimensione N, con allocazione dinamica, e verifica se esiste, nella sequenza di N numeri, una sotto‐sequenza di 3 numeri esattamente 
//uguale a quella inserita dal sensitivo.

#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
	int N, i, j, trovato=1;
	int telepata[3];

	ifstream myfile("sequenza.txt");
	myfile >> N;
	int *sequenza = new int[N];
	for (i = 0; i<N; i++) {
		myfile >> sequenza[i];
	}

	cout << "Sequenza letta da file" << endl;
	for (i = 0; i<N; i++) {
		cout << sequenza[i] << " ";
	}

	cout << endl << "Leggo i 3 elementi della sequenza:"<< endl;
	for (i = 0; i<3; i++)
	{
		cout << "Inserire il valore della sequenza del telepata "<< i << "/3: ";
		cin >> telepata[i];
	}
	for (i = 0; i<N-2; i++)
	{
		trovato = 1;
		for (j = 0; j<3; j++)
			if (sequenza[i + j] != telepata[j])
		    {
			 trovato = 0; break;
		    } // esco dal ciclo for e passo al prossimo carattere della sequenza 
		if (trovato == 1) // vuol dire che sono arrivato qui senza il break quindi avendo trovato tutta la sequenza 
			break;
	}

	delete[] sequenza;

	if (trovato == 1)
		cout << "Incredibile!!! Il telepata ha indovinato!!!";
	else
		cout << "E' solo un buffone!!! Non ha indovinato!!!";
	return 0;
}