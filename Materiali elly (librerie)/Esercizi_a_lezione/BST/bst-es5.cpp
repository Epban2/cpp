#include <iostream>
#include <stdlib.h>
#include "item-es3.h"
#include "bst-es5.h"
#include <time.h>  // Used by timing functions

int main(int argc, char *argv[])
  { 
	srand(time(NULL));
	int N, maxN = atoi(argv[1]), sw = atoi(argv[2]);
    BST<Item, Key> bst;
    for (N = 0; N < maxN; N++)
      { Item v; 
        if (sw) v.random_element(); else if (!v.scan()) break;
        if (!(bst.search(v.key())).null()) continue;
        bst.insert(v); 
      }
	cout << endl;  bst.show(cout); cout << endl;

	int somma = bst.sum();
	cout << "sum= " << bst.sum() << endl;

	if (bst.tree_size() > 0)
	{
		float media = (float)somma / (float)bst.tree_size();
		cout << "media= " << media << endl;

		Item closest = bst.find_closest_tomean(media);
		cout << "closest to mean= ";
		closest.show(cout);
	}
	else
		cout << "albero vuoto" << endl;
  }