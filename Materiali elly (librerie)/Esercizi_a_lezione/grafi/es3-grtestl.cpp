// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#include "book.h"
#include "graphutil.h"

// Include the graph classes -- Adjacency List
#include "grlist.h"

int main(int argc, char** argv) {
  Graphl* G;

  if (argc != 2) {
    cout << "Usage: grtestl <file>\n";
    exit(-1);
  }

  string line;
  ifstream myfile(argv[1]);

  G = createGraph<Graphl>(myfile);
  if (G == NULL) {
    cout << "Unable to create graph\n";
    exit(-1);
  }

  Gprint(G);

  int k;
  cout << "Inserire il numero di un nodo:";
  cin >> k;
  if (k >= G->n())
  {
	  cout << "k>=n" << endl;
	  exit(-1);
  }

  for (int i = 0; i<G->n(); i++)
   for (int w = G->first(i); w < G->n(); w = G->next(i, w))
   {
	   if (w == k)
		   G->delEdge(i,k);
   }

  Gprint(G);

  return 0;
}
