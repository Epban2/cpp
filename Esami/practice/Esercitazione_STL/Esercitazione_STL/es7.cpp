#include <iostream>
#include <string>
#include <list>
#include <queue>
using namespace std;

int main() {

	list<queue<char>> lista_di_code;

	queue<char> q1, q2, q3;
	q1.push('X'); q1.push('Y'); q1.push('Z');
	q2.push('K'); q2.push('W');
	q3.push('H'); q3.push('J'); q3.push('I');
	lista_di_code.push_back(q1);
	lista_di_code.push_back(q2);
	lista_di_code.push_back(q3);

	list<queue<char>>::reverse_iterator reverse_iterator = lista_di_code.rbegin();


	for (size_t i = 0; i < (lista_di_code.size() - 1); i++) {
		// (andando all'indietro, il "successivo" per il reverse_iterator è la coda precedente!)
		list<queue<char>>::reverse_iterator prev_rit = reverse_iterator;
		prev_rit++;

		char extract = reverse_iterator->front();
		reverse_iterator->pop();

		// Inseriamo nella coda precedente (es. q2 al primo giro)
		prev_rit->push(extract);

		// Avanziamo l'iteratore principale verso l'inizio della lista
		reverse_iterator++;


	}

	for (list<queue<char>>::iterator it = lista_di_code.begin(); it != lista_di_code.end(); it++) {

		while (!it->empty()) {
			cout << it->front() << ", ";
			it->pop();
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}