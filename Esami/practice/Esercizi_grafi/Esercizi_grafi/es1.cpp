#include "book.h"
#include "graphutil.h"

#include <iostream>
#include <fstream>
#include "grmat_es1.h"
using namespace std;

//Scrivere una funzione membro reverse() che trasformi un grafo(descritto tramite matrice di adiacenza)
//nel suo grafo opposto.L’opposto di un grafo è il grafo con il verso di tutti gli archi invertito.Verificare il
//funzionamento della funzione su un grafo letto da file oppure costruito tramite chiamate alla funzione
//setEdge.

int main() {

	ifstream file("esempio_directed.gph");
	Graphm* G;
	G = createGraph<Graphm>(file);

	if (G == NULL) {
		cout << "Impossibile creare il grafo!\n";
		exit(-1);
	}
	
	Gprint(G);
	G->reverse();
	Gprint(G);
	

	return 0;
}