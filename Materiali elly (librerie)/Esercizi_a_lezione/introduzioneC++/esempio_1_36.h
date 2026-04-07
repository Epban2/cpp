#ifndef ESEMPIO_1_36
#define ESEMPIO_1_36

#include<iostream>
using namespace std;

template<class T>
class Item
{
	T Data;
public:

	void SetData(T nValue)
	{
		Data = nValue;
	}

	T GetData() const
	{
		return Data;
	}

	void PrintData()
	{
		cout << Data;
	}
};

#endif