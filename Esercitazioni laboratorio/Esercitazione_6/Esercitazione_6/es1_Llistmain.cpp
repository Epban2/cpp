/*
Scrivere un programma che inizializzi due liste non ordinate L1 ed L2 di N numeri interi
(oppure di oggetti Item contenenti un numero intero) casuali compresi tra MINVAL e MAXVAL.Il
programma deve inserire tutti gli elementi di L2 in L1 e, successivamente, ordinare in modo crescente la
lista L1 e stamparla a video.Utilizzare uno qualsiasi degli algoritmi di ordinamento per liste.
*/

#include <iostream>
#include <cstdlib>
//#include <stdlib.h> // rand

using namespace std;
#include <llist.h>
#include <listTest.h>

int N = 10;
int MINVAL = 0;
int MAXVAL = 80;

void bubble(LList<Item>& l)
{
	for (int i = 0; i < l.length(); i++)
		for (int j = l.length() - 1; j > i; j--) {
			l.moveToPos(j - 1);
			Item low = l.getValue(); // l[j-1]
			l.next();
			Item up = l.getValue();  // l[j]
			if (up.key() < low.key()) {
				l.moveToPos(j - 1);
				l.remove(); l.remove();
				l.insert(low);
				l.insert(up);
			}
		}
}

int main() {
	srand(time(NULL));
	LList<Item> l1, l2;
	while (l1.length() < N) {
		l1.append(rand() % (MAXVAL - MINVAL + 1) + MINVAL);
		l2.append(rand() % (MAXVAL - MINVAL + 1) + MINVAL);

	}

	l2.moveToStart();
	while (l2.length() > 0)
		l1.append(l2.remove());
	l2.clear();

	cout << "Lista non ordinata: " << endl;
	lprint(l1);

	bubble(l1);
	cout << endl << "Lista ordinata in ordine crescente: " << endl;
	lprint(l1);

	return 0;

}