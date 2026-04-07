#ifndef ES2
#define ES2

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

template <typename T>
T most_common(T *A, int size)
{
	T winner = A[0];
	int freq = 0;
	int i, j, tmp;
	for (i = 0; i<size; i++) {
		for (tmp = j = 0; j<size; j++)
			if (A[i] == A[j]) tmp++;
		if (tmp>freq) {
			freq = tmp;
			winner = A[i];
		}
	}
	return winner;
}

#endif