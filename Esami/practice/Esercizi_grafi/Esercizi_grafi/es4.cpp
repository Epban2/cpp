/*
Scrivere un programma per verificare se, dato un grafo connesso, e date in ingresso le etichette di due
nodi a e b, dal primo nodo è possibile arrivare al secondo attraverso un cammino di archi orientati.
Procedimento: eseguire un attraversamento DFS partendo dal nodo a.Se durante l’attraversamento si
incontra il vertice b allora il percorso esiste.
*/

#include "book.h"
#include "graphutil.h"

#include <iostream>
#include <fstream>
#include "grlist_es3.h"
using namespace std;

/*
a == nodo in uscita (partenza)
b == nodo in entrata (arrivo)
cerca la presenza di un cammino da a -> b
*/
bool DFS(Graph* G, int a, int b) {
	if (a == b) //passo base
		return true;

	G->setMark(a, VISITED); //visito il nodo

	for (int w = G->first(a); w < G->n(); w = G->next(a, w)) {

		if (G->getMark(w) == UNVISITED) {
			if (DFS(G, w, b)) // se la chiamata ricorsiva e' true (trovato il cammino) allora posso uscire
				return true;
		}
	}
	return false;

}

bool esiste_cammino(Graph* G, int a, int b) {
	for (int i = 0; i < G->n(); i++)G->setMark(i, UNVISITED); //ripulisco

	return DFS(G, a, b);

}


int main() {

	Graphl* G;
	ifstream file("esempio_directed.gph");
	G = createGraph<Graphl>(file);

	Gprint(G);

	bool connessi = false;
	//1) scorro tutti i vicini del nodo ricercato
	//2) studio in profondita' questo vicino finche' finisco i nodi/ trovo un cammino verso b -> break
	int a, b;
	cout << "Inserire i nodi a b da ricercare: ";
	cin >> a >> b;


	cout << "Cammino tra (" << a << "," << b << ") " << (esiste_cammino(G, a, b) ? "trovato!" : "non trovato") << endl;

	return 0;
}