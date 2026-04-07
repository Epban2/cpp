// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#include "book.h"
#include "graphutil.h"

// Include the graph classes -- Adjacency List
#include "es6-grlist.h"

// find function for Items.
// Return true if "K" is in list "L", false otherwise
int find(List<Edge>* L, int K) {
	Edge it;
	for (L->moveToStart(); L->currPos()<L->length(); L->next()) {
		it = L->getValue();
		if (K == it.vertex()) return L->currPos();  // Found K
	}
	return -1;                // K not found
}

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

  /*
  for (int k=0; k<G->n(); k++)
  {
	  for (int h = 0; h < G->n(); h++)
	  {
		  if (G->isEdge(k, h))
			  G->delEdge(k,h);
		  else
			  G->setEdge(k, h, 1);
	  }
  }
  */

  G->complement();
  
  Gprint(G);
 
  return 0;
}
