#include <iostream>
using namespace std;
#include "minHeap.h"

int main() {

	PQ<int> minHeap(10);

	minHeap.insert(5);
	minHeap.insert(3);
	minHeap.insert(8);
	minHeap.insert(2);
	minHeap.insert(1);
	minHeap.insert(6);
	minHeap.insert(4);
	minHeap.insert(0);
	cout << (minHeap.empty() ? "L'heap e' vuoto" : "L'heap non e' vuoto") << endl;

	for (int i = 0; i < 8; i++)
		cout << minHeap.getmin() << ", ";

	cout << endl<< (minHeap.empty()? "L'heap e' vuoto" : "L'heap non e' vuoto");

	return 0;
}