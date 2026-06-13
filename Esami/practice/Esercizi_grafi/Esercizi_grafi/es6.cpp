#include "book.h"
#include "graphutil.h"

#include <iostream>
#include <fstream>
#include "grlist_es6.h"
	using namespace std;

/*
Scrivere una funzione membro complement() che trasformi un grafo (descritto tramite lista di
successori) nel suo grafo complementare. Il grafo complementare è il grafo ottenuto eliminando tutti gli
archi presenti nel grafo originale ed inserendo tutti gli archi non presenti nel grafo originale.
*/

int main() {

	Graphl* G;
	ifstream file("esempio_directed.gph");
	G = createGraph<Graphl>(file);
	Gprint(G);
	cout << endl;

	G->complement();
	Gprint(G);

	return 0;
}