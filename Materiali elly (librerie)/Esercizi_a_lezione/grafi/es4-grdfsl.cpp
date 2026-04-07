// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#include "book.h"
#include "grlist.h"
#include "graphutil.h"

// Start with some implementations for the abstract functions
void PreVisit(Graph* G, int v) {
  cout << "PreVisit vertex " << v << "\n";
}

void PostVisit(Graph* G, int v) {
  cout << "PostVisit vertex " << v << "\n";
}

bool DFS(Graph* G, int u, int b) { // Depth first search
  PreVisit(G, u);           // Take appropriate action
  G->setMark(u, VISITED);
  for (int w = G->first(u); w < G->n(); w = G->next(u, w))
	  if (G->getMark(w) == UNVISITED)
		  if (w == b) return true;
		  else if (DFS(G, w, b))
			  return true;
  return false;
}


bool doTraverse(Graph* G, int a, int b) {
  return DFS(G, a, b);
}

bool graphTraverse(Graph* G, int a, int b) {
  int v;
  for (v=0; v<G->n(); v++)
    G->setMark(v, UNVISITED);  // Initialize mark bits
  
  return doTraverse(G, a, b);
}


int main(int argc, char** argv) {
  Graph* G;

  if (argc != 2) {
    cout << "Usage: grdfsl <file>\n";
    exit(-1);
  }

  ifstream myfile(argv[1]);

  G = createGraph<Graphl>(myfile);
  if (G == NULL) {
    cout << "Unable to create graph\n";
    exit(-1);
  }
  Gprint(G);

  int a = 2;
  int b = 4;
  int path = graphTraverse(G,a,b);
  if (path)
	  cout << "Path exists" << endl;
  else
	  cout << "Path does not exist" << endl;
  return 0;
}
