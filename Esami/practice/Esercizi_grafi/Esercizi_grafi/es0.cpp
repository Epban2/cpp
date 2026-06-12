
#include "book.h"
#include "grmat.h" //matrice di adiacenza (grafo stesso)
#include "graphutil.h" // metodi di stampa / creazione da file

#include <iostream>
using namespace std;

int main()
{
	//Scrivere un programma che utilizzi il metodo setEdge per creare un oggetto della classe Graphm

	Graphm graph(5); //inizializzi il numero di vertici (nodi)

	graph.setEdge(0, 1, 1); // da 0 a 1 con costo 1
	graph.setEdge(0, 4, 1); // da 0 a 4 con costo 1
	graph.setEdge(1, 2, 1); // da 1 a 2 con costo 1
	graph.setEdge(2, 1, 1); // da 2 a 1 con costo 1
	graph.setEdge(3, 0, 1); // da 3 a 0 con costo 1

	Gprint(&graph);

	return 0;
}
