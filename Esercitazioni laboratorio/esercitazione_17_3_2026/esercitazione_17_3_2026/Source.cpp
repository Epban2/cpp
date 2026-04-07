#include "Mobile.h"
#include "Pair.h"
#include "Matrix2x2.h"

#include <iostream>
#include <string>
using namespace std;
template <class T> T max2(T primo, T secondo); //Restituisce il più grande tra due dati
template <class T> T max3(T primo, T secondo, T terzo); //Restituisce il più grande tra tre elementi sfruttando max2() per i primi due dati
template <typename T> T most_common(T* A, int size); /*che accetti in ingresso un array di elementi di tipo generico T e la sua dimensione “size” e fornisca in
uscita l’elemento dell’array ripetuto più volte.Se vi sono due o più elementi con lo stesso numero di
ripetizioni massimo la funzione restituisce il primo elemento trovato. */

int main() {
	//es.0
	Armadio armadio;
	armadio.setAltezza(200); armadio.setLarghezza(70); armadio.setNumeroAnte(2);

	//es.1
	int num1 = 10, num2 = 5;
	int max = max2(num1, num2);
	cout << max << endl;

	string s1 = "Ciao", s2 = "Mi chiamo Maurizio", s3 = "Nel mezzo del cammin di nostra vita...";
	cout << max3(s1, s2, s3) << endl;

	//es.2
	int arrInt[] = { 4, 8, 2, 8, 4, 9, 8, 4, 1 };
	int sizeInt = 9;

	cout << most_common(arrInt, sizeInt) << endl;

	//es.3
	Pair<int> p1(1, 2);
	Pair<int> p2;
	p2.set_element(0, 5);
	p2.set_element(1, 6);
	p1.add_up(p2);
	
	//es.4
	Matrix2x2 m1(1, 2, 3, 4), m2(5, 6, 7, 8);
	Matrix2x2 m3 = m1.Add(m2);
	cout << m3;
		
	return 0;

}

template <class T> T max2(T primo, T secondo) {
	return (primo > secondo) ? primo : secondo;
}

template <class T> T max3(T primo, T secondo, T terzo) {
	T max = max2(primo, secondo);
	return (max > terzo) ? max : terzo;
}

template <typename T> T most_common(T* A, int size) {
	//Array vuoto
	if (size <= 0)
		return T();

	//
	T most_common_value;
	int max = 0;
	for (int i = 0; i < size; i++) {
		int occurrences = 0;
		T value = A[i];
		for (int j = 0; j < size; j++) {
			if (A[j] == value)
				occurrences++;
		}
		if (occurrences > max) {
			max = occurrences;
			most_common_value = value;
		}
	}
	return most_common_value;
}
