//Leggere da un file una sequenza di n numeri floating point (il file contiene un numero per ogni riga, la prima riga del file contiene il valore N) e rappresentarla con una lista L; stampare la lista. 
//Costruire una seconda lista L2 composta dai soli elementi di L maggiori della media; stampare L2. 
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

// Include the link template class
#include "link.h"

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "list-es3-listTest.h"

// Main routine for linked list driver class
int main(int argc, char** argv) {

  LList<Item> L1;  
  LList<Item> L2;
  int N;
  float number;

  ifstream myfile("numeri-float.txt");
  if (myfile.is_open()) {
	  myfile >> N;
	  while (myfile >> number) {
		  //cout << number << endl;
		  Item it(number);
		  L1.append(it);
	  }
	  myfile.close();
  }

  cout << "L1: "; lprint(L1);
  
  float mean = 0;
  Item it;
  for (L1.moveToStart(); L1.currPos()<L1.length(); L1.next()) {
	  it = L1.getValue();
	  mean += it.key();
  }
  mean /= N;
  cout << "mean: " << mean << endl;

  for (L1.moveToStart(); L1.currPos()<L1.length(); L1.next()) {
	  it = L1.getValue();
	  if (it.key() >= mean)
		  L2.append(it);
  }

  cout << "L2: "; lprint(L2);
  return 0;
}