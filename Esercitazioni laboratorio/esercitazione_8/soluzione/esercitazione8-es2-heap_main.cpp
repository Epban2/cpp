// n funi

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "esercitazione8-es1-heap.h"

const int L = 4;

int main(int argc, char** argv) {
	
	int len[L] = { 4, 3, 2, 6 };

	MinHeapPQ<int> minheap(20);

	for (int i = 0; i < L; i++)
		minheap.insert(len[i]);
	
	int total_cost = 0;
	for (int i = 0; i < L-1; i++)
	{
		int min = minheap.getmin();
		int second = minheap.getmin();

		total_cost += min + second;
		minheap.insert(min+second);
	}

	cout << "Total cost= " << total_cost << endl;

	return 0;
}