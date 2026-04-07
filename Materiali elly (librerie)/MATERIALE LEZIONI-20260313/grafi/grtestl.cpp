// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Simple program to test graph construction:
// Reads graph from a file and builds it.
// Use any of the files in this directory with a .gph extension.
// This version is for the Adjancency List representation

#include "book.h"
#include "graphutil.h"

// Include the graph classes -- Adjacency List
#include "grlist.h"

// Simple program to test graph construction:
// Version for Adjancency List representation
int main(int argc, char** argv) {
  Graph* G;

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

  cout << "next(1, 4)=" << G->next(1, 4) << endl;
  cout << "first(5)=" << G->first(5) << endl;
  cout << "next(1, 5)=" << G->next(1, 5) << endl;
  cout << "next(1, 2)=" << G->next(1, 2) << endl;
  cout << "next(0, 2)=" << G->next(0, 2) << endl;
  G->setEdge(1, 4, 5);
  Gprint(G);
  G->delEdge(1, 4);
  Gprint(G);
  cout << "Number of vertices is " << G->n() << "\n";
  cout << "Number of edges is " << G->e() << "\n";
  return 0;
}
