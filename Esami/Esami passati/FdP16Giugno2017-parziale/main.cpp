#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

using namespace std;

#include "item.h"
#include "heap.h"
#include "bst.h"

const int N = 1000;
const int iter = 2;

  int main(int argc, char** argv) {
	  PQ<Item> pq_array[3]; // è stato aggiunto un costruttore di default alla classe PQ (riga 57 del file "heap.h")
	  ifstream myfile("spettatori.txt");
	  string name;
	  string queue;
	  string city;
	  string priority;
	  int pr;
	  int count = 0;
	  if (myfile.is_open()) {
		  while (getline(myfile, name, ';')) {
			  getline(myfile, queue, ';');
			  getline(myfile, city, ';');
			  getline(myfile, priority);
			  istringstream token(priority);
			  token >> pr;
			  Item temp(name, city, pr);
			  if (queue == "L")
				  pq_array[0].insert(temp);
			  else if (queue == "M")
				  pq_array[1].insert(temp);
			  else if (queue == "H")
				  pq_array[2].insert(temp);
			  count++;
		  }
	  }
	  else
	  {
		  cout << "Errore di apertura del file" << endl;
		  return -1;
	  }
	  myfile.close();

	  for (int k = 0; k<iter; k++)
	  {
		  for (int i = 2; i >= 0; i--) {
			  int count = i + 1;
			  while (!pq_array[i].empty() && count>0)
			  {
				  Item max = pq_array[i].getmax();
				  cout << "entra al concerto: " << max.key() << endl;
				  count--;
			  }
		  }
	  }

	  BST<Item, string> bst;

	  for (int i = 2; i >= 0; i--) {
		  while (!pq_array[i].empty())
		  {
			  Item max = pq_array[i].getmax();
			  bst.insert(max);
		  }
	  }

	  bst.balance();
	  cout << endl << "stampa contenuto albero delle persone non ammesse (pre-order)" << endl;
	  int numero_esclusi = bst.stampa_e_conta("Parma", cout);
	  cout << endl << "numero persone di Parma escluse dal concerto: " << numero_esclusi << endl << endl;
	  string str_n = "Giuseppe Longo";
	  Item padre = bst.trova_padre(str_n);
	  if (!padre.null())
		  cout << "padre di " << str_n << ": " << padre << endl;
	  else
		  cout << "nessun nodo padre di " << str_n << endl;
	  str_n = "Marina Castelli";
	  padre = bst.trova_padre(str_n);
	  if (!padre.null())
		  cout << "padre di " << str_n << ": " << padre << endl;
	  else
		  cout << "nessun nodo padre di " << str_n << endl;
	  return 0;
  }