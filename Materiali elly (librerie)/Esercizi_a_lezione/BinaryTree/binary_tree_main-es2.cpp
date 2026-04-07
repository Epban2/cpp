#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "binary_tree-es2.h"

int main(int argc, char** argv) {
  
  BinaryTree<Item> myBT;
  Item it1(74);
  myBT.AddItem(it1);
  Item it2(45);
  myBT.AddItem(it2);
  Item it3(84);
  myBT.AddItem(it3);
  Item it4(27);
  myBT.AddItem(it4);
  Item it5(58);
  myBT.AddItem(it5);
  Item it6(56);
  myBT.AddItem(it6);
  Item it7(88);
  myBT.AddItem(it7);
  Item it8(89);
  myBT.AddItem(it8);
  Item it9(87);
  myBT.AddItem(it9);
 
  myBT.traverse();

  if (myBT.count()>0)
  {
	Item min_item=myBT.min();
	cout << endl << "tree min value:" << min_item.key();
   }

 return 0;
}