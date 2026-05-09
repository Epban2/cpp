#include <iostream>
using namespace std;
#include "minHeap.h"
const int L = 4;


int main() {

	PQ<int> minHeap(L);
	int len[L] = { 4,3,2,6 };
	for (int i = 0; i < L; i++)
		minHeap.insert(len[i]);

	int costo = 0;

	int l = L;
	while (l > 1) {
		int min1 = minHeap.getmin(), min2 = minHeap.getmin();
		costo += min1 + min2;
		minHeap.insert(min1 + min2);
		l--; // L -2(estrazioni) +1 (inserimento)

	}
	cout << "Costo minimo operazioni: " << costo << endl;

	return 0;
}