// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.


#include "book.h"
#include "graphutil.h"

// Include the graph classes -- Adjacency List
#include "es2-grlist.h"

#include <ctime>


int main(int argc, char** argv) {
  srand(time(NULL));
  int n, k;
  cout << "Inserire il numero di nodi n del grafo:";
  cin >> n;
  cout << "Inserire il valore k (k<n):";
  cin >> k;
  if (k >= n) 
  {
	  cout << "k>=n" << endl;
	  exit(-1);
  }
	
  Graphl G(n);
  G.createRandomGraph(k);

  Gprint(&G);

  return 0;
}
