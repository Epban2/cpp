#ifndef ESEMPIO_1_33
#define ESEMPIO_1_33

#include<iostream>
using namespace std;

template <typename X>
void scambia(X & a, X & b)
{
	X temp;
	temp = a;
	a = b;
	b = temp;
}

#endif