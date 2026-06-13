#include "book.h"
#include "graphutil.h"

#include <iostream>
#include <fstream>
#include "grlist_es5.h"
using namespace std;

/*
Scrivere una funzione membro reverse() che trasformi un grafo(descritto tramite lista di successori) nel
suo grafo opposto.L’opposto di un grafo è il grafo con il verso di tutti gli archi invertito.
*/

int main() {

	Graphl* G;
	ifstream file("esempio_directed.gph");
	G = createGraph<Graphl>(file);
	Gprint(G);
	cout << endl;

	G->reverse();
	Gprint(G);

	return 0;
}