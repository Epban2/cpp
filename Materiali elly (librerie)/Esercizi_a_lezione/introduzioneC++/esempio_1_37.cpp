#include "esempio_1_37.h"
#include <string>

int main() {
	Item<int> item1(3);
	Item<string> item2("pippo");
	
	item1.Add(5);
	item2.Add("topolino");

	cout << item1.getItem() << endl;
	cout << item2.getItem() << endl;

	return 0;
}