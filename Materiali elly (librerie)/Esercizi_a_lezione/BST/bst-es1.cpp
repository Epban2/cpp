#include <iostream>
#include <stdlib.h>
#include "symbol_table_item.h"
#include "bst-es1.h"
#include <time.h>  // Used by timing functions

int main(int argc, char *argv[])
  { 
	srand(time(NULL));
	int N, maxN = atoi(argv[1]), sw = atoi(argv[2]);
    BST<Item, Key> bst;
    for (N = 0; N < maxN; N++)
      { Item v; 
        if (sw) v.random_element(); else if (!v.scan()) break;
        //if (!(st.search(v.key())).null()) continue;
        bst.insert(v); 
      }

	cout << endl;  bst.show(cout); cout << endl;
	
	Item x;
	x.keyval = 6;
	cout << "search_all_keys" << endl;
	bst.search_all_keys(x.key());
  }