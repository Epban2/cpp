#include <iostream>

using namespace std;

// Simple class Count
class Count {
public:
	int x;
	void print() { cout << x << endl; }
};


int main() {
	Count counter; // create counter object
	Count	*counterPtr = &counter; // pointer to counter
	Count	&counterRef = counter; // reference to counter
	cout << "Assign 7 to x and print using the object's name: ";
	counter.x = 7; // assign 7 to data member x
	counter.print(); // call member function print
	cout << "Assign 8 to x and print using a reference: ";
	counterRef.x = 8; // assign 8 to data member x
	counterRef.print(); // call member function print
	cout << "Assign 10 to x and print using a pointer: ";
	counterPtr->x = 10; // assign 10 to data member x
	counterPtr->print(); // call member function print
	return 0;
}
