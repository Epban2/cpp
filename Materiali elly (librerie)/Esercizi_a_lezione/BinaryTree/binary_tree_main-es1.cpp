#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "binary_tree-es1.h"

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

  BinaryTree<Item> myBT2;
  Item it10(74);
  myBT2.AddItem(it10);
  Item it11(45);
  myBT2.AddItem(it11);
  Item it12(58);
  myBT2.AddItem(it12);
  Item it13(56);
  myBT2.AddItem(it13);
  Item it14(27);
  myBT2.AddItem(it14);
  Item it15(84);
  myBT2.AddItem(it15);
  Item it16(88);
  myBT2.AddItem(it16);
  Item it17(87);
  myBT2.AddItem(it17);
  Item it18(89);
  myBT2.AddItem(it18);

  cout << endl;
  myBT2.traverse();

 return 0;
}