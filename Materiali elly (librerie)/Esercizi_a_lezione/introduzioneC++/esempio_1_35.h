#ifndef ESEMPIO_1_35
#define ESEMPIO_1_35

#include<iostream>
using namespace std;

template <class T>
class myclass {
	T value1, value2;
public:
	myclass(T first, T second)
	{
		value1 = first; value2 = second;
	}
	//T getmax();
	T getmax()
	{
		T retval;
		retval = value1>value2 ? value1 : value2;
		return retval;
	}
};

/*
template <class T> T myclass<T>::getmax()
{
	T retval;
	retval = value1>value2 ? value1 : value2;
	return retval;
}
*/

#endif