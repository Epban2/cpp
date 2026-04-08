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
using namespace std;

int main() {

	cout << "Ciao";
}