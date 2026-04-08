//Riscrivere la funzione int equal_queues(LQueue<Item>& Q1, LQueue<Item>& Q2)
//facendola diventare una funzione template
//template <typename E>
//int equal_queues(LQueue<E>& Q1, LQueue<E>& Q2)
//aggiungendo l’operatore != alla classe Item
//bool operator!=(const Item & other) const

#include <iostream>

#include <LQueue.h>
#include <LQueueTest.h>


template <typename E>
int equal_queues(LQueue<E>& Q1, LQueue<E>& Q2);

int main() {
	LQueue<Item> queue1, queue2, queue3, queue4;
	//q1 != q2, q3==q4
	queue1.enqueue(Item(1));queue1.enqueue(Item(3));queue1.enqueue(Item(61));queue1.enqueue(Item(10));
	
	queue2.enqueue(Item(4));queue2.enqueue(Item(2));queue2.enqueue(Item(44));queue2.enqueue(Item(25));

	queue3.enqueue(Item(1)); queue3.enqueue(Item(3));
	queue4.enqueue(Item(1)); queue4.enqueue(Item(3));
	
	cout << "Q1: ";
	Lqueueprint(queue1);
	cout << endl << "Q2: ";
	Lqueueprint(queue2);
	cout << endl << "Q3: ";
	Lqueueprint(queue3);
	cout << endl << "Q4: ";
	Lqueueprint(queue4);
	cout << endl;

	cout << "Q1 equal to Q2 = " << (equal_queues(queue1, queue2) ? "True" : "False") << endl;

	cout << "Q3 equal to Q4 = " << (equal_queues(queue3, queue4) ? "True" : "False") << endl;


	return 0;
}

// Test di uguaglianza tra due code (il test distrugge le due code)
template <typename E>
int equal_queues(LQueue<E>& Q1, LQueue<E>& Q2)
{
	// 0 -> diverse
	// 1 -> uguali
	if (Q1.length() != Q2.length())
		return 0;
	while (Q1.length() > 0)
	{
		E q1 = Q1.dequeue();
		E q2 = Q2.dequeue();
		if (q1 != q2)
			return 0;
	}
	return 1;
}
