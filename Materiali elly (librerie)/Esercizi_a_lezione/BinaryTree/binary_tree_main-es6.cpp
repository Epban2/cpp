#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "binary_tree-es6.h"


int main(int argc, char** argv) {
  
  BinaryTree<int>* myBT=new BinaryTree<int>;
  myBT->AddItem(25);
  myBT->AddItem(40);
  myBT->AddItem(32);
  myBT->AddItem(50);
  myBT->AddItem(35);
  myBT->AddItem(30);
  myBT->AddItem(45);
  myBT->AddItem(60);
  myBT->AddItem(39);  
  

  cout << endl; cout << endl;
  myBT->traverse();
  
  cout << endl << "maxwidth=" << myBT->maxWidth() << endl;

  return 0;
}