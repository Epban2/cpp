#include "book.h"
#include "graphutil.h"

#include <iostream>
#include <fstream>
#include "grlist_es3.h"
using namespace std;

//Leggere in input un grafo orientato G = (V, E) e rappresentarlo mediante lista di successori.Letto in input
//un vertice v(0 <= v <= n) eliminare tutti gli spigoli entranti in v.

int main() {

	Graphl* G;
	ifstream file("esempio_directed.gph");
	G = createGraph<Graphl>(file);

	Gprint(G);

	int input;
	cout << "Inserire un vertice tra 0 e " << G->n() << ": ";
	cin >> input;

	for (int i = 0; i < G->n(); i++) {
		for (int w = G->first(i); w < G->n(); w = G->next(i, w)) {
			if (w == input)
				G->delEdge(i, input);
		}
	}
	//G->entrantiV(input);
	cout << endl;
	Gprint(G);

	return 0;
}