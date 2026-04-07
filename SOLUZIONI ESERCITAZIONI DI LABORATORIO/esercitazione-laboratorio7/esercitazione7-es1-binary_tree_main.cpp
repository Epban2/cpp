#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "esercitazione7-es1-binary_tree.h"

int main(int argc, char** argv) {
  
  BinaryTree<Item> myBT;
  Item it("pippo");
  myBT.AddItem(it);
 
  Item it2("topolino");
  myBT.AddItem(it2);

  Item it3("paperino");
  myBT.AddItem(it3);
 
  myBT.traverse();

	
  cout << endl << "numero di elementi in albero: "<< myBT.count() << endl;
  cout << endl << "tree height: "<< myBT.height() << endl;

 return 0;
}