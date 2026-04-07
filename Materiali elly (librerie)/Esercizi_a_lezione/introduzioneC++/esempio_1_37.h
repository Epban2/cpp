#ifndef ESEMPIO_1_37
#define ESEMPIO_1_37

#include<iostream>
using namespace std;

template<typename T>
class Item {
private:
	T element;
public:
	Item(T n) 
		{
		element = n;
		}
	void Add(T n) {
		element = element + n;
	}
	T getItem()
	{
		return element;
	}
};


#endif