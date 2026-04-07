#ifndef ESEMPIO_1_32
#define ESEMPIO_1_32

#include<iostream>
using namespace std;

template <typename T>
T sumVector(T *array, int n) {
	T sum(0);
	for (int i = 0; i < n; ++i)
		sum += array[i];
	return (sum);
}

#endif