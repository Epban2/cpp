#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

#include "lqueue.h"
#include "LQueueTest.h"
#include "heap.h"
#include <queue>

#include "selection.h"

int main(int argc, char** argv) {
	  LQueue<Item> q1;
	  queue<Item> q2;
	  PQ<Item> pq_lunapark1(30);
	  PQ<Item> pq_lunapark2(30);
	  ifstream myfile("lunapark.txt");

	  string str="";
	  string nome="";
	  string nazione= "";
	  int codice=0;
	  float altezza = 0.0;
	  if (myfile.is_open()) {
		  while (getline(myfile, str, ';')) {
			  istringstream token(str);
			  token >> codice;
			  getline(myfile, nome, ';');
			  getline(myfile, nazione, ';');
			  getline(myfile, str);
			  istringstream token2(str);
			  token2 >> altezza;
			  Item it(codice, nome, nazione, altezza);
			  if (nazione == "United States")
				  q1.enqueue(it);
			  else
				  q2.push(it);
		  }
	  }
	  else
	  {
		  cout << "Errore di apertura del file" << endl;
		  return -1;
	  }
	  myfile.close();

	  cout << "1: stampa coda q1" << endl;
	  Lqueueprint(q1);
	  cout << endl << "1: stampa coda q2" << endl;
	  for (int i = 0; i < q2.size(); i++)
	  {
		  Item dequeued = q2.front();
		  cout << dequeued << " ";
		  q2.pop();
		  q2.push(dequeued);
	  }

	  int l = q1.length();
	  Item prev;
	  for (int i = 0; i < l; i++)
	  {
		  Item dequeued = q1.dequeue();
		  if ((dequeued.getaltezza()<92) || ((i>0) && (dequeued.getaltezza()>prev.getaltezza())))
			 q1.enqueue(dequeued);
		  prev = dequeued;
	  }
	  l = q2.size();
	  for (int i = 0; i < l; i++)
	  {
		  Item dequeued = q2.front(); 
		  q2.pop();
		  if ((dequeued.getaltezza() < 92) || ((i > 0) && (dequeued.getaltezza() > prev.getaltezza())))
			  q2.push(dequeued);
		  prev = dequeued;
	  }
	  cout << endl << endl << "2: stampa coda q1" << endl;
	  Lqueueprint(q1);
	  cout << endl << "2: stampa coda q2" << endl;
	  for (int i = 0; i < q2.size(); i++)
	  {
		  Item dequeued = q2.front();
		  cout << dequeued << " ";
		  q2.pop();
		  q2.push(dequeued);
	  }

	  cout << endl << endl << "3: stampa array ordinato" << endl;
	  int N = q1.length() + q2.size();
	  Item* array_lunpark = new Item[N];
	  int j = 0; int i=0;
	  while (q1.length()>0)
	  {
		  Item dequeued = q1.dequeue();
		  array_lunpark[j] = dequeued;
		  j++;
	  }
	  while (!q2.empty())
	  {
		  Item dequeued = q2.front();
		  q2.pop();
		  array_lunpark[i+j] = dequeued;
		  i++;
	  }
	  selection(array_lunpark, 0, N - 1);
	  for (int i = 0; i < N; i++)
	  {
		  cout << array_lunpark[i] << " ";
		  if (array_lunpark[i].getnazione() == "United States")
			  pq_lunapark1.insert(array_lunpark[i]);
		  else if (array_lunpark[i].getnazione() == "Germany")
			  pq_lunapark2.insert(array_lunpark[i]);
	  }

	  cout << endl << endl << "4: stampa elementi estratti da priority queues" << endl;
	  while ((!pq_lunapark1.empty()) || (!pq_lunapark2.empty()))
	  {
		  Item max1 = pq_lunapark1.getmax();
		  Item max2 = pq_lunapark2.getmax();
		  pq_lunapark1.insert(max1);
		  pq_lunapark2.insert(max2);
		  if ((pq_lunapark1.size()>pq_lunapark2.size()) || ((pq_lunapark1.size() == pq_lunapark2.size()) && (max1.getnome() > max2.getnome())))
			  cout << pq_lunapark1.getmax() << " ";
		  else
			  cout << pq_lunapark2.getmax() << " ";
	  }

	  system("pause");
	  return 0;
  }

