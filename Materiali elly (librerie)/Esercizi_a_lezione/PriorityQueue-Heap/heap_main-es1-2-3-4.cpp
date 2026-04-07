#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "heap-es1-2-3-4.h"

int main(int argc, char** argv) {

  PQ<int> prq(10);
  int a[7]= { 1, 23, 12, 9, 30, 2, 50};
  for (int i = 0; i < 7; i++)
	  prq.insert(a[i]);
  for (int i = 0; i < 3; i++)
	  cout << "priorityq max=" << prq.getmax() << endl;


  cout << endl;
  PQ<int> priorityq(10);
  priorityq.insert(5);
  priorityq.insert(50);
  priorityq.insert(12);
  priorityq.insert(27);
  priorityq.insert(11);

  cout << "priorityq second best=" << priorityq.get_secondbest() << endl;

  priorityq.increase_key(4, 30); // 5 si trova in posizione 4
  for (int i = 0; i < 5; i++) 
	  cout << "priorityq max=" << priorityq.getmax() << endl;

  int arr[9] = { 0, 90, 15, 10, 17, 12, 2, 7, 3 };
  //int arr[11] = { 0, 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 };

  isHeap(arr, 8) ? cout << "isHeap:Yes" << endl : cout << "isHeap:No" << endl;

  return 0;
}