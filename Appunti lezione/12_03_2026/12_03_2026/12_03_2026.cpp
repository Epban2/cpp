#include "Shape.h"
#include "Example.h"
int main()
{
	Example e1,e2;
	cout << e1.get_counter() << endl;
	e2.set_counter(10);
	int v = 2;
	e2+&v;
	cout << e1.get_counter() << endl;
	
	Rectangle r(2, 6);
	cout << r;

	return 0;
}

