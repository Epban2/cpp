#include <iostream>
#include <lstack.h>
#include <LStackTest.h>

//Inverte una pila
template <typename E>void Reverse(LStack<E>& S);

int main() {
	/*
	Scrivere una funzione template template <typename E> void Reverse(LStack<E>& S)
	per invertire una pila (stack) sfruttando la funzione di copia di una pila vista a lezione
	LstackTransfer(LStack<E>& S1, LStack<E>& S2)
	*/
	LStack<Item> stack1;
	stack1.push(Item(1));stack1.push(Item(2));stack1.push(Item(3));stack1.push(Item(4));stack1.push(Item(5));stack1.push(Item(6));

	cout << "Stack iniziale: "; Lstackprint(stack1); cout << endl;
	Reverse(stack1);
	cout << "Stack dopo Reverse: "; Lstackprint(stack1); cout << endl;

	return 0;
}

template <typename E>
void Reverse(LStack<E>& S) {
	LStack<Item> stack2;
	LstackTransfer(S, stack2);
	S.clear();
	while (stack2.length() > 0) {
		S.push(stack2.pop());
	}
	
}
