// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.


#include "book.h"
#include "graphutil.h"

// Include the graph classes -- Adjacency Matrix
#include "grmat.h"

int main(int argc, char** argv) {
  Graphm G(5);

  G.setEdge(0, 1, 1);
  G.setEdge(1, 2, 1);
  G.setEdge(2, 1, 1); 
  G.setEdge(3, 0, 1);
  G.setEdge(0, 4, 1);

  Gprint(&G);
 
  return 0;
}
