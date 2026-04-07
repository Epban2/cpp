//Scrivere un programma che legga da tastiera il raggio(variabile float) di un cerchio ne stampi l'area utilizzando una funzione che restituisca il valore dell'area attraverso un passaggio per riferimento.

#include<iostream>
using namespace std;

void area_cerchio(float r, float& a) {
	a = r * r * 3.14159;
}

int main() {
	float raggio; float area = 0;
	cout << "raggio:"; 
	cin >> raggio;
	area_cerchio(raggio, area); 
	cout << "Area: "<< area << endl;

	return 1;
}

