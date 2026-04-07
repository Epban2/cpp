#include "esempio_1_36.h"

int main() {
	Item<int> item1;
	item1.SetData(120);
	item1.PrintData();

	Item<float> item2;
	item2.SetData(0.5);
	float n = item2.GetData();
	cout << endl << n;
	return 0;
}