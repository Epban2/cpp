#ifndef ES1
#define ES1

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

template <class T> T max2(T primo, T secondo)
{
	return (primo > secondo ? primo : secondo);
}

template <class T> T max3(T primo, T secondo, T terzo)
{
	return max2(max2(primo,secondo),terzo);
}

#endif