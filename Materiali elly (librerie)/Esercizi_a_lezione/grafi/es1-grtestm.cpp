// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.


#include "book.h"
#include "graphutil.h"

// Include the graph classes -- Adjacency Matrix
#include "es1-grmat.h"

int main(int argc, char** argv) {
  Graphm* G;

  if (argc != 2) {
    cout << "Usage: grtestm <file>\n";
    exit(-1);
  }

  ifstream myfile(argv[1]);

  G = createGraph<Graphm>(myfile);
  if (G == NULL) {
    cout << "Unable to create graph\n";
    exit(-1);
  }

  Gprint(G);

  G->reverse();

  Gprint(G);
 
  return 0;
}
