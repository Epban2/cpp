/*
Esercizio 1: Scrivere un programma che inizializzi due liste non ordinate L1 ed L2 di N numeri interi
(oppure di oggetti Item contenenti un numero intero) casuali compresi tra MINVAL e MAXVAL.Il
programma deve inserire tutti gli elementi di L2 in L1 e, successivamente, ordinare in modo crescente la
lista L1 e stamparla a video.Utilizzare uno qualsiasi degli algoritmi di ordinamento per liste.
*/

#include <iostream>
#include <cstdlib>	//random
using namespace std;
#include <llist.h>
#include <listTest.h>

const int MINVAL = 10, MAXVAL = 50, N = 5;

void bubble(LList<Item>& a)
{
	for (int i = 0; i < a.length(); i++)
		for (int j = a.length() - 1; j > i; j--)
		{
			a.moveToPos(j-1);
			Item i1 = a.getValue();
			a.next();
			Item i2 = a.getValue();
			if (i1.key() > i2.key()) {
				a.moveToPos(j - 1);
				a.remove();a.remove();
				a.insert(i1);
				a.insert(i2);
			}
		}
}


int main() {
	srand(time(NULL));
	LList<Item> l1, l2;
	while (l1.length() < N && l2.length() < N) {
		l1.append(Item(rand() % (MAXVAL - MINVAL + 1) + MINVAL));
		l2.append(Item(rand() % (MAXVAL - MINVAL + 1) + MINVAL));

	}

	l1.moveToStart();
	while (l1.length() > 0) l2.append(l1.remove());


	lprint(l2);

	cout << endl << "Dopo ordinamento: " << endl;
	bubble(l2);
	lprint(l2);



	return 0;
}