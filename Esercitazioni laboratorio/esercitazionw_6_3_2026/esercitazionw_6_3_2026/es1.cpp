#include <iostream>

using namespace std;
const int N = 5;
int main1() {
	int a[N] = { 12,2,6,10,5 }, b[N] = { 0,-3, 6, -9, 12 }, c[N], d[N];
	for (int i = 0; i < N; i++) {
		c[i] = a[i] + b[N - 1 - i];
		if (a[i] > b[i]) d[i] = 1;
		else if (a[i] == b[i]) d[i] = 0;
		else d[i] = -1;
	}

	cout << "a: ";
	for (int i = 0; i < N; i++) {
		cout << a[i] << ", ";
	}
	cout << endl;
	cout << "b: ";
	for (int i = 0; i < N; i++) {
		cout <<b[i] << ", ";
	}
	cout << endl;
	cout << "c: ";
	for (int i = 0; i < N; i++) {
		cout << c[i] << ", ";
	}
	cout << endl;
	cout << "d: ";
	for (int i = 0; i < N; i++) {
		cout <<d[i] << ", ";
	}
	return 0;
}