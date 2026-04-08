//Scrivere un programma che chieda all’utente un numero intero N di valori di tipo “float” da inserire.A
//questo punto il programma deve chiedere all’utente di inserire gli N valori.Il programma deve
//memorizzare i valori in una coda.Successivamente il programma deve iterativamente dimezzare la
//dimensione del numero di elementi della coda(arrotondando per eccesso) producendo una coda che
//sostituisca i valori con, alternativamente, la somma, sottrazione, moltiplicazione e divisione di coppie di
//elementi consecutivi.L’iterazione si arresta quando rimane un solo elemento nella coda.Esempio:
//l’utente inserisce N = 9 e quindi inserisce i seguenti valori interi : 4 8 ‐2 17 ‐3 2 3 21 ‐9
//Dopo la prima iterazione la coda deve contenere i seguenti 5 (9 / 2 arrotondato per eccesso) valori :
//12 (4 + 8, inizio con la somma) 15 (‐2 + 17) ‐1(‐3 + 2) 24 (3 + 21) ‐9
//Dopo la seconda iterazione la coda deve contenere i seguenti 3 (5 / 2 arrotondato per eccesso) valori :
//‐3(12‐15, questa volta tocca alla sottrazione) ‐25(‐1‐24) ‐9
//Dopo la terza iterazione la coda deve contenere i 2 valori(3 / 2 arrotondato per eccesso) seguenti :
//75 (‐3 * (‐25), tocca alla moltiplicazione) ‐9
//Dopo la quarta e ultima iterazione rimane un solo valore che è 75 / (‐9) = -8.3333

#include <iostream> 
#include <lqueue.h>
#include <LQueueTest.h>

using namespace std;
int N = 9; //dimensione dela coda globale, inizializzo ad un valore manuale per input hardcoded

//Funzione automatica con le operazioni
template <typename E>
void dimezza(LQueue<E>& newQueue, LQueue<E>& oldQueue, char operation);


int main() {
	//cout << "Quanti valori inserire? ";
	//cin >> N;
	LQueue<float> queue1, queue2;
	//while (queue1.length() < N) {
	//	float input;
	//	cin >> input;
	//	queue1.enqueue(input);
	//}
	cout << "Coda iniziale: ";
	queue1.enqueue(float(4)); queue1.enqueue(float(8)); queue1.enqueue(float(-2)); queue1.enqueue(float(17)); queue1.enqueue(float(-3)); queue1.enqueue(float(2)); queue1.enqueue(float(3)); queue1.enqueue(float(21)); queue1.enqueue(float(-9));
	Lqueueprint(queue1);
	std::cout << endl;

	//una si riempie e l'altra si svuota e così via
	dimezza(queue2, queue1, 's');
	dimezza(queue1, queue2, 'm');
	dimezza(queue2, queue1, 'p');
	dimezza(queue1, queue2, 'd');

	return 0;
}

//Implementazione metodo
template <typename E>
void dimezza(LQueue<E>& newQueue, LQueue<E>& oldQueue, char operation) {
	int length = (oldQueue.length() + 1) / 2; //sommo 1 perchè in cpp: (10 + 1 ) / = 5,  (9 + 1) / 2 = 5, pertanto arrotondando per eccesso fuziona solo con i valori dispari (come vogliamo) e quelli pari rimangono tali

	if (oldQueue.length() == 1) {
		newQueue.enqueue(oldQueue.dequeue()); //se c'è un solo elemento lo metto dentro e basta
		return;
	}

	while (newQueue.length() < length) {

		if (oldQueue.length() == 1)
			newQueue.enqueue(oldQueue.dequeue()); //se c'è un solo elemento lo metto dentro e basta
		else {
			E operationResult;

			switch (operation) { // a seconda dell'operazione passata, la svolgo
			case 's':
				operationResult = oldQueue.dequeue() + oldQueue.dequeue();
				break;
			case 'm':
				operationResult = oldQueue.dequeue() - oldQueue.dequeue();
				break;
			case 'p':
				operationResult = oldQueue.dequeue() * oldQueue.dequeue();
				break;
			case 'd':
				operationResult = oldQueue.dequeue() / oldQueue.dequeue();
				break;
			}
			newQueue.enqueue(operationResult);
		}
	}
	cout << operation << ": ";
	Lqueueprint(newQueue);
	cout << endl;
}