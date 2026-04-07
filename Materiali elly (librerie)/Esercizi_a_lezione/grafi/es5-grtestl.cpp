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
#include "es5-grlist.h"

void selectionsort(List<Edge>* L) {
	int min_pos;
	Edge min_element;
	// se lunghezza <2 non fai nulla
	for (int i = 0; i<L->length() - 1; i++) {
		L->moveToPos(i);
		min_element = L->getValue();
		min_pos = i;
		for (int j = i + 1; j<L->length(); j++) {
			L->moveToPos(j);
			Edge it_temp = L->getValue();
			if (it_temp.vertex() < min_element.vertex())
			{
				min_pos = L->currPos();
				min_element = it_temp;
			}
		}
		L->moveToPos(min_pos);
	    Edge it_temp = L->remove();
		L->moveToPos(i);
		L->insert(it_temp);
	}

}


// Simple program to test graph construction:
// Version for Adjancency List representation
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

  G->reverse();
  
  Gprint(G);
 
  return 0;
}
