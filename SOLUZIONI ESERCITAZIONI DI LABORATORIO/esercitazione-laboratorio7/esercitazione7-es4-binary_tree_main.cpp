#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "esercitazione7-es4-binary_tree.h"

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
  Item it5(1);
  myBT.AddItem(it5);
  Item it6(5);
  myBT.AddItem(it6);
  Item it7(4);
  myBT.AddItem(it7);
  Item it8(7);
  myBT.AddItem(it8);
  Item it9(9);
  myBT.AddItem(it9);
  Item it10(17);
  myBT.AddItem(it10);
  Item it11(23);
  myBT.AddItem(11);
  Item it12(16);
  myBT.AddItem(it2);
  Item it13(18);
  myBT.AddItem(it13);
  Item it14(21);
  myBT.AddItem(it14);
  Item it15(25);
  myBT.AddItem(it15);
  
  myBT.traverse();

	
  cout << endl << "numero di elementi in albero: "<< myBT.count() << endl;
  cout << endl << "tree height: "<< myBT.height() << endl;

 return 0;
}