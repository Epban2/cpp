#ifndef EXAMPLE_H
#define EXAMPLE_H
#include <iostream>
using namespace std;
class Example
{
public:
	static int counter;

	int get_counter() {
		return this->counter;
}
	void set_counter(int counter) {
		this->counter = counter;
}

};

inline void operator+ (Example e, int* v) {
	e.set_counter(e.counter + *v);
}

#endif