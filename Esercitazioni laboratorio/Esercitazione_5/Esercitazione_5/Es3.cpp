/*
Salvare i numeri interi da 1 a N in uno stack e scrivere un algoritmo che utilizzi i dati nello stack per
calcolare il fattoriale di N
*/
#include <iostream>
#include <lstack.h>
#include <LStackTest.h>

int N = 5;

int main() {
	LStack<Item> stack;
	int fact = 1; //per definizione 0! = 1
	//std::cout << "Inserire N: ";
	//std::cin >> N;

	for (int i = 1; i <= N; i++)
		stack.push(Item(i));

	if (stack.topValue().key() != 0) { // se nella pila c'e' solo 0, esco (fact e' gia' inizializzata a 1)
		while (stack.length() > 0) {
			fact *= stack.pop().key();
		}
	}

	std::cout << std::endl << "Fattoriale di " << N << ": " << fact;
	return 0;
}