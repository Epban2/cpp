#include "book.h"
#include "graphutil.h"

#include <iostream>
#include <fstream>
#include "grlist_es2.h"
using namespace std;

//Letti in input due numeri interi n e k(0 < k < n), scrivere una funzione membro della classe Graphl(grafo
//con rappresentazione mediante lista di successori) per costruire un grafo orientato G = (V, E) in modo
//casuale tale che V = { 0,1,2, ...,n‐1 } e ogni vertice abbia al massimo k spigoli uscenti..

int main() {

	int k = 5;
	int n = 8;
	
	Graphl G(n);
	G.createRandomGraph(k);

	Gprint(&G);


	return 0;
}