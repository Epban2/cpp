#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <iomanip>

#include "bst.h"
#include "listTest.h"
#include <list>
using namespace std;

void findnext3 (LQueue<Item>& Q, string s)
{
	int found = 0;
	for (int i = 0; i < Q.length(); i++)
	{
		Item dequeued = Q.dequeue();
		Q.enqueue(dequeued);
		if ((dequeued.getnome()==s) && ((i+3)< Q.length()))
		{
			Item nextdeq;
			found = 1;
			for (int k = 0; k < 3; k++)
			{
				i++;
				nextdeq = Q.dequeue();
				Q.enqueue(nextdeq);
			}
			cout << nextdeq << endl;
		}	
	}
	if (found == 0)
		cout << "nessuno" << endl;
}

int main(int argc, char *argv[])
  { 
	BST<Item,string> albero_quotidiani;
	LQueue<Item> Q1;
	list<Item> l1;
	ifstream myfile("quotidiani.txt");
	int anno;
	string nome, sede,stringa;
	float tiratura;

	if (myfile.is_open()) {
		while (getline(myfile, nome, ',')) {
			getline(myfile, stringa, ',');
			istringstream token(stringa);
			token >> tiratura;
			getline(myfile, sede, ',');
			getline(myfile, stringa);
			istringstream token2(stringa);
			token2 >> anno;
			Item it(nome, tiratura, sede, anno);
			if (tiratura > 7.1)
				Q1.enqueue(it); //inserimento in coda
		}
	}
	else
	{
		cout << "Errore di apertura del file" << endl;
		return -1;
	}
	myfile.close();

	cout << endl << endl << "Q1: stampa coda Q1" << endl;
	Lqueueprint(Q1);

	for (int i = 0; i < Q1.length(); i++)
	{
		Item dequeued = Q1.dequeue();
		if (albero_quotidiani.search(dequeued.key()).null())
			albero_quotidiani.insert(dequeued);
		Q1.enqueue(dequeued);
	}

	cout << endl << endl << "Q1: stampa albero" << endl;
	albero_quotidiani.balance();
	albero_quotidiani.show(cout);

	for (int i = 0; i < Q1.length(); i++)
	{
		Item dequeued = Q1.dequeue();
		l1.push_back(dequeued);
		Q1.enqueue(dequeued);
	}

	list<Item>::iterator viterator= l1.begin();
	while (viterator != l1.end())
	{
		if (((*viterator).getanno() > 1886) && ((*viterator).getanno() < 1952))
		{
			Item todelete = *viterator;
			viterator = l1.erase(viterator);
			list<Item>::iterator vbegin = l1.begin();
			l1.insert(vbegin, todelete); 
		}
		else viterator++;
	}
	cout << endl << endl << "Q2: stampa list";
	for (viterator = l1.begin(); viterator != l1.end(); viterator++)
	{
		cout << *viterator << " ";
	}

	cout << endl << endl << "Q3: terzo elemento dopo Il Tirreno: "; 
	findnext3(Q1, "Il Tirreno");
	cout << endl << endl << "Q3: terzo elemento dopo Il Tempo: ";
	findnext3(Q1, "Il Tempo");

	cout << endl << endl << "Q4: stampa albero" << endl;
	albero_quotidiani.modifica_valori();
	albero_quotidiani.show(cout);
	return 0;
  }