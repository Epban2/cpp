//Min-heap

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "esercitazione8-es1-heap.h"

int main(int argc, char** argv) {
	MinHeapPQ<int> minheap(20);

	minheap.insert(5);
	minheap.insert(17);
	minheap.insert(25);
	minheap.insert(2);
	minheap.insert(100);
	minheap.insert(90);
	minheap.insert(44);

	for (int i = 0; i < 7; i++)
		cout << "minheap min_element=" << minheap.getmin() << endl;

	cout << endl;

	return 0;
}