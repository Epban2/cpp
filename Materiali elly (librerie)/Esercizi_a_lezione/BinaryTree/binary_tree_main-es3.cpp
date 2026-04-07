#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "binary_tree-es3.h"

int main(int argc, char** argv) {
  
  BinaryTree<Item> myBT;
  Item it1(15);
  myBT.AddItem(it1);
  Item it2(8);
  myBT.AddItem(it2);
  Item it3(20);
  myBT.AddItem(it3);
  Item it4(3);
  myBT.AddItem(it4);
  Item it5(9);
  myBT.AddItem(it5);
  Item it6(23);
  myBT.AddItem(it6);
  Item it7(1);
  myBT.AddItem(it7);
  Item it8(4);
  myBT.AddItem(it8);
  Item it9(17);
  //myBT.AddItem(it9);
 
  myBT.traverse();

	
  cout << endl << "numero di elementi in albero: "<< myBT.count() << endl;
  cout << endl << "tree height: "<< myBT.height() << endl;

  if (myBT.test_children_number())
   cout << endl << "tutti i nodi hanno o zero figli o nessun figlio" << endl;
  else
   cout << endl << "non tutti i nodi hanno o zero figli o nessun figlio" << endl;

 return 0;
}