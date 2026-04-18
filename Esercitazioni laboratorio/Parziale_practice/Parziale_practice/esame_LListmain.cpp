/*
Creare una lista singolarmente concatenata che rappresenti l’elenco di tutti i biglietti venduti.Ciascun
elemento “Item” contiene tre campi : il numero del biglietto(int), il cognome(string) e il nome(string)
della persona che lo ha acquistato.Leggere dal file "biglietti.txt" l’elenco dei biglietti venduti salvando
le informazioni contenute in ogni riga(nel formato : <numero biglietto> <nome> <cognome>) in un
elemento della lista.Ogni persona può avere acquistato più di un biglietto.
Ordinare la lista per numero di biglietto decrescente utilizzando BubbleSort e stamparla a video.
*/
#include "esame_LListtest.h"
#include <fstream>
#include <cstdlib>

int main() {
//1)
	ifstream file_biglietti("biglietti.txt");

	LList<Item> biglietti;
	if (file_biglietti.is_open()) {
		string cognome, nome; int num_biglietto;
		while (file_biglietti >> num_biglietto >> nome >> cognome)
			biglietti.append(Item(cognome, nome, num_biglietto));
	}
	file_biglietti.close();
	bubble(biglietti);
	Lprint(biglietti);


// 2)
	int K;
	cout << endl << "Inserire il numero di premi (<=7):  ";
	cin >> K;
	if (K > 7)
		return 1;

	Premio* premi = new Premio[K];//array dinamico dimensione K

	ifstream premi_file("premi.txt");
	if (premi_file.is_open()) {
		string nome; float valore;

		for (int i = 0; i < K; i++) {
			premi_file >> nome >> valore;
			premi[i] = Premio(nome, float(valore / 100));
		}
	}
	premi_file.close();

	cout << endl;
	lprint(premi, K);


// 3)

	Premio primo = premi[0], ultimo = premi[K - 1];
	premi[0] = ultimo; premi[K - 1] = primo;

	LStack<Premio> stack_premi;
	float valore_totale = 0;
	for (int i = K - 1; i >= 0; i--) {
		valore_totale += premi[i].getvalore();
		stack_premi.push(premi[i]);
	}
	delete[] premi;

	cout << endl << "Premi nello stack: " << endl;
	Lstackprint(stack_premi);
	cout << "Valore totale premi: " << valore_totale << endl;



// 4) 
	srand(time(NULL));
	Item* vincitori = new Item[K]; // array con i vincitori
	int estratti_counter = 0;

	for (int i = 0; i < K; i++) {
		bool valido = false; //per riestrarre nel caso sia gia' uscito
		Item vincitore_estratto;

		while (!valido) { //finche' non trova un vincitore valido
			// valore random a caso nella lista dei biglietti
			int random_winner = rand() % biglietti.length();
			biglietti.moveToPos(random_winner);
			vincitore_estratto = biglietti.getValue();

			// controlla se è già nell'array dei vincitori
			bool gia_vinto = false;
			for (int j = 0; j < estratti_counter; j++) {
				if (vincitori[j] == vincitore_estratto) { //operatore di item, controlla che nome e cognome siano diversi
					gia_vinto = true;
					break; // se trovato, inutile controllare gli altri
				}
			}

			// Valuta il risultato
			if (!gia_vinto) {
				valido = true; // Ottimo! Rompe il ciclo while.
			}
		}

		// Salva il vincitore valido
		vincitori[i] = vincitore_estratto;
		estratti_counter++;
	}

	cout << endl << "Vincitori: " << endl;
	for (int i = 0; i < K; i++) {
		Premio estratto = stack_premi.pop();
		cout << "Il premio " << estratto.getnome() << " viene attribuito a " << vincitori[i].getnome() << " " << vincitori[i].getcognome() << endl;
	}
	delete[] vincitori;

	return  0;
}