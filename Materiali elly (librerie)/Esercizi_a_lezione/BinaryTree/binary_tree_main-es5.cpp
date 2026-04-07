#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "binary_tree-es5.h"

int main(int argc, char** argv) {
  
  BinaryTree<int> myBT;
  myBT.AddItem(25);
  myBT.AddItem(15);
  myBT.AddItem(8);
  myBT.AddItem(20);
  myBT.AddItem(3);
  myBT.AddItem(9);
  myBT.AddItem(23);
  myBT.AddItem(1);
  myBT.AddItem(4);
  myBT.AddItem(17);
  myBT.traverse();
 
 
  BinaryTree<int> myBT2;

  /*myBT2.AddItem_levelorder(74);
  myBT2.AddItem_levelorder(21);
  myBT2.AddItem_levelorder(12);
  myBT2.AddItem_levelorder(33);
  myBT2.AddItem_levelorder(1);
  myBT2.AddItem_levelorder(42);
  myBT2.AddItem_levelorder(8);
  myBT2.AddItem_levelorder(77);*/

  myBT2.AddItem_levelorder(25);
  myBT2.AddItem_levelorder(15);
  myBT2.AddItem_levelorder(8);
  myBT2.AddItem_levelorder(20);
  myBT2.AddItem_levelorder(3);
  myBT2.AddItem_levelorder(9);
  myBT2.AddItem_levelorder(23);
  myBT2.AddItem_levelorder(1);
  myBT2.AddItem_levelorder(4);
  myBT2.AddItem_levelorder(17);
  
  
  cout << endl; cout << endl;
  myBT2.traverse();
  
 return 0;
}