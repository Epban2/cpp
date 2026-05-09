//ordinamento di k array ordinati di dimensione n

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "esercitazione8-es1-heap.h"

// Let us print out Items easily
ostream& operator<<(ostream& s, const Item& i)
{
	return s << i.key();
}

int main(int argc, char** argv) {

	const int k = 3, n = 4;
	int arr[k][n] = { { 1, 3, 5, 7 },
		{ 2, 4, 6, 8 },
		{ 0, 9, 10, 11 }};

	int sorted_array[n*k];

	MinHeapPQ<Item> minheap(k);

	for (int i=0; i<k; i++)
	{
		Item it(arr[i][0],i,1);
		minheap.insert(it);
	}
		
	int j = 0;
	for (int i=0; i<n*k; i++)
	{
		Item it=minheap.getmin();
		sorted_array[j] = it.key();

		if (it.next_element<n)
		{
		 Item toinsert(arr[it.array_id][it.next_element], it.array_id, it.next_element + 1);
		 minheap.insert(toinsert);
		}
		j++;
	}
	
	cout << endl << "sorted_array=";
	for (int i = 0; i<n*k; i++)
		cout <<  sorted_array[i] << " ";

	return 0;
}