#include <iostream>
using namespace std;
#include "minHeap_es3.h"


int main() {

	const int k = 3, n = 4;

	int arr[k][n] = { {1, 3, 5, 7},
					 {2, 4, 6, 8},
					 {0, 9, 10, 11} };

	//
	int* array = new int[k * n + 1];
	PQ<Item> minHeap(k);

	//
	for (int i = 0; i < k; i++) minHeap.insert(Item(arr[i][0], i, 1));


	//Ripetere le seguenti istruzioni n* k volte :
	//a.Estrarre l’elemento più piccolo dal min - heap e salvarlo nella prima posizione libera
	//	disponibile nell’array
	//	b.Inserire nel min - heap l’elemento successivo(se esiste) preso dallo stesso array a cui
	//	apparteneva l’elemento estratto dal min - heap
	int arrayIndex = 0;
	for (int i = 0; i < k * n; i++) {
		Item min = minHeap.getmin();
		array[arrayIndex++] = min.valore;
		//inserisco il successivo nell'heap
		if (min.indiceSuccessivo < n)
			minHeap.insert(Item(arr[min.indiceArrayProvenienza][min.indiceSuccessivo], min.indiceArrayProvenienza, min.indiceSuccessivo + 1));

	}
	for (int i = 0; i < k * n; i++) {
		cout << array[i] << ", ";
	}

	return 0;
}