#ifndef ES4
#define ES4

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

template <class T>
class Matrix2x2
{
public:
		Matrix2x2(T m11, T m12, T m21, T m22);    //constructor
		Matrix2x2() {m[0][0] = 0; m[0][1] = 0; m[1][0]=0; m[1][1] = 0;}; //default constructor
		Matrix2x2<T> Add(Matrix2x2 x);
		T m[2][2];
};

template <class T>
Matrix2x2<T>::Matrix2x2(T m11, T m12, T m21, T m22)
{
		m[0][0] = m11;
		m[0][1] = m12;
		m[1][0] = m21;
		m[1][1] = m22;
}

template <class T>
Matrix2x2<T> Matrix2x2<T>::Add(Matrix2x2 x)
{
		Matrix2x2<T> sum;
		sum.m[0][0] = m[0][0] + x.m[0][0];
		sum.m[0][1] = m[0][1] + x.m[0][1];
		sum.m[1][0] = m[1][0] + x.m[1][0];
		sum.m[1][1] = m[1][1] + x.m[1][1];
		return sum;
}

#endif