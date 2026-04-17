#include "es3_insertionsortTest.h"
#include <cstdlib>

int const N = 10, RANDMIN = 0, RANDMAX = 50;

int main() {
	srand(time(NULL));
	AList<Item> list;
	
	while (list.length() < N)
		list.append(Item(rand() % (RANDMAX - RANDMIN + 1) + RANDMIN));
	
	cout << "Array non ordinato: " << endl;
	lprint(list);
	
	insertion(list);
	cout << "Array ordinato: " << endl;
	lprint(list);

	return 0;
}