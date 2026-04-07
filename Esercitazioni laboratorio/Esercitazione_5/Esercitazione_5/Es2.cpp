#include <iostream>
#include <lqueue.h>
#include <LQueueTest.h>
#include <lstack.h>


int main() {
	/*
	Scrivere una funzione membro void reverse() della classe LQueue per invertire una coda che utilizzi
	internamente uno stack (aggiungere #include "lstack.h" nel file “lqueue.h”)
	*/
	LQueue<Item> queue;
	queue.enqueue(Item(1));
	queue.enqueue(Item(2));
	queue.enqueue(Item(3));

	cout << "Coda Prima reverse : ";	Lqueueprint(queue);
	cout << endl << "Coda Dopo reverse: ";	queue.reverse(); Lqueueprint(queue);


	return 0;
}