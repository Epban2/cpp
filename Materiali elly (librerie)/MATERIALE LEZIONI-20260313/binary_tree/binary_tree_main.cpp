#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "binary_tree.h"

int main(int argc, char** argv) {
  srand(time(NULL));

  BinaryTree<int> *myBT = new BinaryTree<int>;
  myBT->AddItem(1);
  myBT->AddItem(0);
  myBT->AddItem(5);
  myBT->AddItem(2);
  myBT->AddItem(14);
  myBT->AddItem(1);
  myBT->AddItem(10);
  myBT->AddItem(4);
  //myBT->AddItem(4);

  myBT->traverse();
   
  cout << endl << "numero di elementi in albero: "<< myBT->count() << endl;
  cout << endl << "tree height: "<< myBT->height() << endl;

  const int N=10;
  Item a[N];
  for (int i = 0; i < N; i++) 
  {
   Item temp(1000 * ((1.0*rand() / RAND_MAX)));
   a[i] = temp;
  }
       

  cout << "vettore: ";
  for (int i = 0; i < N; i++) 
	  cout << a[i] << " ";

  cout << endl;

  BinaryTree<Item> *myBT2 = new BinaryTree<Item>;
  myBT2->createTournament(a,0,N-1);
  myBT2->traverse();


 return 0;
}