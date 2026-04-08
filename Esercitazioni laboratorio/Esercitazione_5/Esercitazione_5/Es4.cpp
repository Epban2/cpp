//Scrivere un programma per il calcolo della sequenza dei primi N numeri della sequenza di Fibonacci: 
//(1 1 2 3 5 8 13 21 34 55 89 144, …) che utilizzi uno stack per generare la sequenza e per memorizzarla.
//Successivamente creare una lista singolarmente concatenata, estrarre tutti gli elementi dallo stack e
//inserirli nella lista, con inserimento in testa.Visualizzare la lista

#include <iostream>
#include <lstack.h>
#include <LStackTest.h>
#include <alist.h>

using namespace std;
int N = 11;


template <typename E>
void lprint(List<E>& L);

int main() {
	LStack <Item> stack;
	//cout << "Inserire N: ";
	//cin >> N;
	stack.push(Item(1));
	stack.push(Item(1));
	while (stack.length() <= N) {
		int pop1 = stack.pop().key();
		int pop2 = stack.pop().key();

		stack.push(Item(pop2));
		stack.push(Item(pop1));
		
		stack.push(Item(pop1 + pop2));

	}
	AList<Item> list;
	while (stack.length() > 0)
		list.append(Item(stack.pop().key()));

	cout << "Sequenza di Fibonacci: ";
	lprint<Item>(list);

	return 0;

}
//
template <typename E>
void lprint(List<E>& L) {
	int currpos = L.currPos();

	L.moveToStart();

	cout << "< ";
	int i;
	for (i = 0; i < currpos; i++) {
		cout << L.getValue() << " ";
		L.next();
	}
	cout << "| ";
	while (L.currPos() < L.length()) {
		cout << L.getValue() << " ";
		L.next();
	}
	cout << ">\n";
	L.moveToPos(currpos); // Reset the fence to its original position
}
