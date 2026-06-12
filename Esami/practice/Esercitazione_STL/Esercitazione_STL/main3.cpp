/*
Esercizio 3: Creare una lista della classe STL list, chiamata “lista_di_code”, i cui elementi siano costituiti
da code di numeri interi della classe STL queue. Inserire nella “lista_di_code” 4 code inizializzate con i
seguenti valori: coda1: (30,12,1,203,10); coda2: (7); coda3: (14,29,45,100); coda4: (2,13,8)
Scrivere un algoritmo che per ciascuna coda della “lista_di_code”, partendo dalla prima coda fino alla
penultima, estragga un elemento dalla coda e lo inserisca nella coda di indice successivo della
“lista_di_code”. Stampare il contenuto di tutte le code nella “lista_di_code”.
*/


#include <iostream>
#include <queue>
#include <list>
using namespace std;

int main() {
	queue<int> q1, q2, q3, q4;
	q1.push(30); q1.push(12); q1.push(1); q1.push(203); q1.push(10);
	q2.push(7);
	q3.push(14); q3.push(29); q3.push(45); q3.push(100);
	q4.push(2); q4.push(13); q4.push(8);

	list<queue<int>> lista_di_code;
	lista_di_code.push_back(q1); lista_di_code.push_back(q2);
	lista_di_code.push_back(q3); lista_di_code.push_back(q4);

	list<queue<int>>::iterator it = lista_di_code.begin();
	for (int i = 0; i < lista_di_code.size() - 1; i++)
	{
		int num = (*it).front();
		(*it).pop();
		it++;
		(*it).push(num);

	}


	for (it = lista_di_code.begin(); it != lista_di_code.end(); it++) {
		while (!(*it).empty()) {
			cout << (*it).front() << " ";
			(*it).pop();


		}
		cout << endl;
	}
	return 0;
}