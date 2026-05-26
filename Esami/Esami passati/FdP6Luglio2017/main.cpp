#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

using namespace std;

#include "item.h"
#include "bst.h"

#include "llist.h"
#include "ListTest.h"

int insert_ordered_array(Item arr[], int last, Item it)
{
	int i = last;
	while ((i > 0) && (it < arr[i-1]))
	{
		arr[i] = arr[i-1];
		i = i-1;
	}
	arr[i] = it;
	return i;
}

void  print_array(Item arr[], int last)
{
	for (int i = 0; i < last; i++)
		cout << arr[i];
}

void aggiorna_array(Item arr[], int N, int pos)
{
	Item it = arr[pos];
	int i=pos;
	if (pos>0 && (it < arr[pos-1]))
	{
		for (i=pos; i>0 && it<arr[i-1]; i--)
			arr[i] = arr[i-1];
	}
	else if (pos<N-1 && (it > arr[pos+1]))
	{
		for (i=pos; i<N-1 && arr[i+1]<it; i++)
			 arr[i] = arr[i+1];
	}
	arr[i] = it;
}

void aggiorna_lista(LList<Item>& Lazioni, int pos, int var_prezzo)
{
	Lazioni.moveToPos(pos);
	Item it = Lazioni.getValue();
	it.setprezzo(it.getprezzo() + var_prezzo);
	int final_pos=pos;
	
	if (var_prezzo>0)
	{
		Lazioni.next();
		while (Lazioni.currPos()<Lazioni.length()) {
			Item it_temp = Lazioni.getValue();
			if (it_temp<it)
			{
				Lazioni.next();
				final_pos++;
			}	
			else break;
		}
	}
	else if (var_prezzo<0 && final_pos>0)
	{
		Lazioni.prev();
		while (Lazioni.currPos()>=0) {
			Item it_temp = Lazioni.getValue();
			if (it<it_temp)
			{
				Lazioni.prev();
				final_pos--;
				if (final_pos == 0) break;
			}
			else break;
		}
	}
	Lazioni.moveToPos(pos);
	Lazioni.remove();
	Lazioni.moveToPos(final_pos);
	Lazioni.insert(it);
}

int main(int argc, char** argv) {
	  LList<Item> Lazioni;
	  BST<Item, string> albero_azioni;
	  ifstream myfile("elenco_azioni.txt");
	  string azione;
	  string categoria;
	  int prezzo_iniziale;
	  int N;
	  Item* item_array;
	  if (myfile.is_open()) {
		  myfile >> N;
		  item_array = new Item[N];
		  int count = 0;
		  while (myfile >> azione >> categoria >> prezzo_iniziale) {
			  Item temp(azione, categoria, prezzo_iniziale);
			  insert_ordered_array(item_array, count, temp);
			  count++;
		  }
	  }
	  else
	  {
		  cout << "Errore di apertura del file" << endl;
		  return -1;
	  }
	  myfile.close();

	  cout << "STAMPA ARRAY" << endl;
	  print_array(item_array, N);

	  for (int i = 0; i<N; i++)
	  {
		  albero_azioni.insert_root(item_array[i]);
	  }
	  albero_azioni.balance();
	  for (int i = 0; i<N; i++)
	  {
		 if (i%2==0 && item_array[i].getcategoria()=="C")
		   albero_azioni.remove(item_array[i]);
	  }
	  cout << endl << endl << "STAMPA ALBERO AZIONI (in-order)" << endl;
	  albero_azioni.show(cout);
	  cout << endl << endl;

	  for (int i = 0; i<N; i++)
	  {
		  Lazioni.append(item_array[i]);
	  }
	  cout << endl << endl << "STAMPA LISTA" << endl;
	  lprint(Lazioni);

	  cout << endl << endl << "STAMPA OPERAZIONI" << endl;
	  int var_prezzo;
	  ifstream myfile2("variazioni_prezzo.txt");
	  if (myfile2.is_open()) {
		  while (myfile2 >> azione >> var_prezzo) {
			  for (int i=0; i<N; i++)
			   { 
				  if (item_array[i].key() == azione)
				  {
					  item_array[i].setprezzo(item_array[i].getprezzo()+var_prezzo);
					  aggiorna_lista(Lazioni, i, var_prezzo);
					  aggiorna_array(item_array, N, i); break;
				  }
			   }
			  print_array(item_array, N);
			  cout << endl; lprint(Lazioni);
			  cout << endl;
		  }
	  }
	  else
	  {
		  cout << "Errore di apertura del file" << endl;
		  return -1;
	  }
	  myfile2.close();

	  return 0;
  }