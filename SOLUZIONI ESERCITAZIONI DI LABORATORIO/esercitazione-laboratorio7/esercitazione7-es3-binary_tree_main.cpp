#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "esercitazione7-es3-binary_tree.h"


int main(int argc, char** argv) {
  
  BinaryTree<Item>* myBT=new BinaryTree<Item>;
  Item it1(25);
  myBT->AddItem(it1);
  Item it2(19);
  myBT->AddItem(it2);
  Item it3(32);
  myBT->AddItem(it3);
  Item it4(22);
  myBT->AddItem(it4);
  Item it5(30);
  myBT->AddItem(it5);

  BinaryTree<Item>* myBT2=new BinaryTree<Item>;
  Item ita(25);
  myBT2->AddItem(ita);
  Item itb(19);
  myBT2->AddItem(itb);
  Item itc(3);
  myBT2->AddItem(itc);
  Item itd(22);
  myBT2->AddItem(itd);
  Item ite(30);
  myBT2->AddItem(ite);

  cout << endl; cout << endl;
  myBT2->traverse();
  cout << endl; cout << endl;
 
  int result = myBT->equal_tree(myBT2);
  if (result)
	  cout << "trees are equal" << endl;
  else
	  cout << "trees are not equal" << endl;

  return 0;
}