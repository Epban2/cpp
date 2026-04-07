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
	Item i1(1), i2(2), i3(3), i4(4), i5(5), i6(6);
	stack1.push(i1); stack1.push(i2); stack1.push(i3); stack1.push(i4); stack1.push(i5); stack1.push(i6);

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
