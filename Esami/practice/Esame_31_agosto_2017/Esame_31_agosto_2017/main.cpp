#include <fstream>
#include <iostream>
#include "Item.h"
#include "llist.h"
#include "listTest.h"
using namespace std;
#include <string>
#include "bst.h"

const string FILENAME = "elenco_studenti.txt";

void bubblesort(List<Item>& L) {
	for (int i = 0; i < (L.length() - 1); i++) {
		for (int j = (L.length() - 1); j > i; j--) {
			L.moveToPos(j);
			Item it_j = L.getValue();
			L.moveToPos(j - 1);
			Item it_jj = L.getValue();
			if (it_jj.getcognome() > it_j.getcognome())
			{
				L.moveToPos(j);
				Item removed = L.remove();
				L.moveToPos(j - 1);
				L.insert(removed);
			}
		}
	}
}

void reversebubblesort(List<Item>& L) {
	for (int i = 0; i < (L.length() - 1); i++) {
		for (int j = (L.length() - 1); j > i; j--) {
			L.moveToPos(j);
			Item it_j = L.getValue();
			L.moveToPos(j - 1);
			Item it_jj = L.getValue();
			if (it_jj.getcognome() <= it_j.getcognome())
			{
				L.moveToPos(j);
				Item removed = L.remove();
				L.moveToPos(j - 1);
				L.insert(removed);
			}
		}
	}
}
void clear() { cout << endl << endl; }

int main()
{
	LList<Item> L1, L2;

	ifstream file(FILENAME);
	if (file.is_open()) {
		string cognome, citta;
		int eta, matricola;
		while (file >> cognome >> matricola >> citta >> eta)
		{
			Item i(matricola, cognome, citta, eta);
			L1.append(i);
			L2.append(i);
		}

	}
	file.close();


	bubblesort(L1);
	reversebubblesort(L2);

	cout << "Q1: stampa lista L1 ordinata per cognome crescente\n";
	lprint(L1);

	cout << endl << "Q1: stampa lista L2 studenti ordinata per cognome decrescente\n";
	lprint(L2);
	clear();




	/*
	 Inserire in un albero binario di ricerca i primi 5 elementi di L1, gli ultimi 5 elementi di L1 e tutti i restanti
	elementi di L1 che hanno sia <città>=Bologna ed (<età>)<23. L’albero non deve contenere
	elementi ripetuti e deve avere come chiave il numero di matricola. Bilanciare l’albero. Stampare a
	video l’albero con visita pre-order. Esempio di output:
	Q2: stampa albero studenti (pre-order)
	(Barbieri,211721,Bologna,21) (Rizzo,167210,Bari,21) (Russo,105456,Modena,20) (Rossi,104234,Bologna,22)
	(Bianchi,123456,Parma,21) (Ferrari,204432,Bologna,20) (Esposito,167345,Bologna,21) (Ricci,234801,Bari,22)
	(Colombo,234800,Roma,27) (Romano,214532,Ferrara,22) (Conti,333874,Palermo,26) (Bruno,333872,Milano,27)
	*/
	BST<Item, int> tree;
	for (L1.moveToStart(); L1.currPos() < L1.length(); L1.next())
	{
		Item i = L1.getValue();
		if (L1.currPos() < 5)
			tree.insert(i);
		else if (L1.currPos() >= L1.length() - 5)
			tree.insert(i);
		else if (i.getcitta() == "Bologna" && i.geteta() < 23)
			tree.insert(i);

	}

	tree.balance();
	cout << endl << "Q2: stampa albero studenti(pre - order)\n";

	tree.show(cout);
	clear();


	/*
	Scrivere un algoritmo per trovare ed eliminare i 3 elementi consecutivi della lista L2 la cui somma dei
	valori di <età> è massima.Stampare a video il contenuto della lista L2
	*/

	int starting_index = 0;
	int max_age_sum = 0;
	int* ages = new int[L2.length()];
	int index = 0; //array con le eta'
	for (L2.moveToStart(); L2.currPos() < L2.length(); L2.next(), index++)
		ages[index] = L2.getValue().geteta();

	max_age_sum = ages[0] + ages[1] + ages[2];
	for (int i = 1; i < L2.length(); i++) {
		int curr_age_sum = ages[i];
		if (i + 2 < L2.length()) {
			curr_age_sum += ages[i + 2];
			curr_age_sum += ages[i + 1];
		}
		else if (i + 1 < L2.length())
			curr_age_sum += ages[i + 1];
		if (curr_age_sum > max_age_sum)
		{
			max_age_sum = curr_age_sum;
			starting_index = i;
		}
	}

	L2.moveToPos(starting_index);
	L2.remove();
	for (int i = 0; i < 2; i++)
	{
		if (L2.currPos() < L2.length())
			L2.remove();
	}

	cout << endl << "Q3: stampa lista L2 studenti ordinata in modo decrescente\n";
	lprint(L2);
	clear();

	/*
	Scrivere una procedura ricorsiva per calcolare il valore della somma delle chiavi(numeri di matricola)
	di tutti i nodi dell’albero creato al punto 2 che sono nodi foglia e figli di “sinistra” di altri nodi
	*/
	cout << endl << "Q4: stampa somma matricole foglie di sinistra: " << tree.returnLeftKeys();

	
	clear();
	return 0;

}