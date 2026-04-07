#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "binary_tree-es7.h"


int main(int argc, char** argv) {
  
  BinaryTree<Item>* myBT=new BinaryTree<Item>;
 
  Item it1(25);
  myBT->AddItem(it1);
  Item it2(40);
  myBT->AddItem(it2);
  Item it3(32);
  myBT->AddItem(it3);
  Item it4(50);
  myBT->AddItem(it4);
  Item it5(35);
  myBT->AddItem(it5);
  Item it6(30);
  myBT->AddItem(it6);
  Item it7(45);
  myBT->AddItem(it7);
  Item it8(60);
  myBT->AddItem(it8);
  Item it9(39);
  myBT->AddItem(it9);
  
  myBT->traverse();
  cout << endl; cout << endl;
  myBT->stampa_altezze_minimali();
 

  return 0;
}