#include <iostream>

using namespace std;
const int N = 5;
int main2() {
	int persona1[31] = {};
	int persona2[31] = {};
	int num = -1;

	cout << "giorni liberi primo collega: ";
	do {
		cin >> num;
		persona1[num] = 1;
	} while (num > 0 && num <= 31);
	
	
	cout << "giorni liberi secondo collega: ";
	do {
		cin >> num;
		persona2[num] = 1;
	} while (num > 0 && num <= 31);

	//##
	cout << "Entrambi i colleghi sono liberi il: ";

	for (int i = 0; i <= 31; i++) {
		if (i!=0 && persona1[i] != 0 && persona1[i] == persona2[i])
			cout << i << ", ";
	}
	return 0;
} 