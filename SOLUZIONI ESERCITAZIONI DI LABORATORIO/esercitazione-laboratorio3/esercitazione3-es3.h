#ifndef ES3
#define ES3

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

//Class for a pair of values of type T:
template<class T>
class Pair
{
public:
	Pair() { };
	Pair(T first_value, T second_value) { first = first_value; second = second_value; };

	void set_element(int position, T value)
	{
		if (position == 1)
			first = value;
		else if (position == 2)
			second = value;
		else
		{
			cout << "Error: Illegal pair position.\n";
			exit(1);
		}
	}

	T get_element(int position) const
	{
		if (position == 1)
			return first;
		else if (position == 2)
			return second;
		else
		{
			cout << "Error: Illegal pair position.\n";
			exit(1);
		}
	}

	void add_up(const Pair<T>& the_pair)
	{
		first = first + the_pair.first;
		second = second + the_pair.second;
	}

private:
	T first;
	T second;
};


#endif