#include <iostream>
#include <stdlib.h>
#include "symbol_table_item.h"
#include "bst.h"
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
	cout << "stampa albero con attraversamento pre-order prima del bilanciamento:";
	cout << endl;  bst.show(cout); cout << endl;

	//cout << "height=" << bst.tree_height() << endl;
	bst.balance();
	cout << "stampa albero con attraversamento pre-order dopo bilanciamento:";
	cout << endl;  bst.show(cout); cout << endl;
	//cout << "height=" << bst.tree_height() << endl;

	Item x;
	x.keyval = 9;
	if ((bst.search(x.key())).null()) cout << "test di ricerca di elemento: non trovato x.key()=" << x.key() << endl;
	 else cout << "test di ricerca di elemento: trovato x.key()=" << x.key() << endl;

	 x = bst.select(2);
	 cout << "seleziono e rimuovo l'elemento con la terza chiave piu' piccola st.select(2)="<< x.keyval << endl;

	 bst.remove(x);
	 bst.show(cout); cout << endl;

	 BST<Item, Key> bst2;
	 Item el;
	 el.keyval = 10;
	 bst2.insert_root(el);
	 el.keyval = 20;
	 bst2.insert_root(el);
	 el.keyval = 5;
	 bst2.insert_root(el);
	 el.keyval = 15;
	 bst2.insert_root(el);

	 cout << "insert_root" << endl;
	 bst2.show(cout); cout << endl;

	 BST<Item, Key> bst3;
	 el.keyval = 7;
	 bst3.rand_insert(el);
	 el.keyval = 22;
	 bst3.rand_insert(el);
	 el.keyval = 3;
	 bst3.rand_insert(el);
	 el.keyval = 19;
	 bst3.rand_insert(el);

	 cout << "rand_insert" << endl;
	 bst3.show(cout); cout << endl;

	 cout << "join" << endl;
	 bst2.join(bst3); 
	 bst2.show(cout); cout << endl;
	 cout << "bst3 dopo join" << endl;
	 bst3.show(cout); cout << endl;
  }