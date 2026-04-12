//Scrivere un programma che inizializzi due liste non ordinate L1 ed L2 di N numeri interi
//(oppure di oggetti Item contenenti un numero intero) casuali compresi tra MINVAL e MAXVAL.Il
//programma deve inserire tutti gli elementi di L2 in L1 e, successivamente, ordinare in modo crescente la
//lista L1 e stamparla a video.Utilizzare uno qualsiasi degli algoritmi di ordinamento per liste

#include <iostream>
#include <ctime>

#include <llist.h>
#include <link.h>
#include <listTest.h>

const int MINVAL = 20;
const int MAXVAL = 80;
const int N = 5;
using namespace std;

void selectionsort(LList<Item>& L);

int main() {
	LList<Item> L1, L2;

	//popolazione list2
	for (int i = 0; i < N; i++) {
		L1.append(Item((rand() % (MAXVAL - MINVAL + 1)) + MINVAL));
		L2.append(Item((rand() % (MAXVAL - MINVAL + 1)) + MINVAL));
	}
	lprint(L1);
	lprint(L2);

	//sort
	L1.moveToStart();
	for (int i = 0; i < L2.length(); i++) {
		L2.moveToPos(i);
		L1.insert(L2.getValue()); //aggiungo all'inizio di lista 1 tutta la lista 2
	}

	lprint(L1);

	cout << endl;
	selectionsort(L1);

	cout << "L1: "; lprint(L1);


	return 0;
}//Fine main


void selectionsort(LList<Item>& L)
{
	int min_pos;								// 1) inizializzo il valore minore e il suo indice
	Item min_element;
	// se lunghezza <2 non fai nulla
	for (int i = 0; i < L.length() - 1; i++) {  //2) ciclo esterno, ripetera' fino a maxLunghezza - 1 (altrimenti out of range)
		L.moveToPos(i);							//3) 
		min_element = L.getValue();				//4) prende l'elemento corrente e l'indice memorizzandoli come min (poiche' la lista e' rimpicciolita in avanti)
		min_pos = i;						
		for (int j = i; j < L.length(); j++) {  //5) scorre tutti i numeri da < .. i| in avanti> cercando se ne trova uno piu' piccolo
			L.moveToPos(j);
			Item temp_item = L.getValue();		//6) memorizza l'elemento
			if (temp_item.key() < min_element.key()) { //7) se questo e' minore del minimo, salvo valore e posizione
				min_pos = L.currPos();
				min_element = temp_item;
			}
			}									//8) ho cosi' trovato il minore nella sottolista <i...end>
		L.moveToPos(min_pos);					//9) vado nell'indice del piu' piccolo trovato in precedenza
		Item it_temp = L.remove();				//10) lo tolgo e posiziono nell'indice iniziale (inizio sottolista)
		L.moveToPos(i);
		L.insert(it_temp);
	}											//11) cosi' si mette sempre il piu' piccolo tutto a sinistra
}