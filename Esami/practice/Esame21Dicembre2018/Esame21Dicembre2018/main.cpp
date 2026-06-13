# include <iostream>
#include <string>
using namespace std;

#include "bst.h"
#include "llist.h"
#include "listTest.h"
#include "Item.h"
#include <fstream>
const string FILENAME = "navi.txt";

void clear() { cout << endl << endl; }

typedef Nave Item;
void bubblesort(List<Item>& L) {
	for (int i = 0; i < (L.length() - 1); i++) {
		for (int j = (L.length() - 1); j > i; j--) {
			L.moveToPos(j);
			Item it_j = L.getValue();
			L.moveToPos(j - 1);
			Item it_jj = L.getValue();
			if (it_jj.getpasseggeri() < it_j.getpasseggeri())
			{
				L.moveToPos(j);
				Item removed = L.remove();
				L.moveToPos(j - 1);
				L.insert(removed);
			}
		}
	}
}



int main()
{
	ifstream file(FILENAME);
	LList<Nave> L1;
	BST<Nave, string> Anavi;

	if (file.is_open()) {
		string nome, compagnia;
		int passeggeri;
		float velocita;
		while (file >> nome >> passeggeri >> velocita >> compagnia) {
			Nave n(nome, passeggeri, velocita, compagnia);
			Anavi.insert(n);
			L1.append(n);

		}
	}
	file.close();

	Anavi.balance();


	cout << "Q1: stampa lista L1 ";
	lprint(L1);
	cout << endl;

	cout << "Q1 : stampa albero Anavi(in - order) ";
	Anavi.show(cout);


	clear();

	//2) Scrivere un algoritmo ricorsivo che visiti tutti gli elementi di Anodi e decrementi di 0.5 tutti i valori di
	//<velocità>.Stampare Anavi(con visita in - order).
	Anavi.decrementa();
	cout << "Q2: stampa albero Anavi(in - order)\n";
	Anavi.show(cout);
	clear();

	/*
	Creare una lista L2 di elementi “nave” che contenga un elemento per ogni valore distinto di
	<compagnia> presente in L1; nel campo <passeggeri> la somma dei valori dei campi
	<passeggeri> di tutte le navi di L1 della stessa compagnia; nel campo < nome> "---"; nel campo
	< velocità> "-1".
	Ordinare L2 per valore di <passeggeri> decrescente(algoritmo a scelta).Stampare
	L2.
	*/
	LList<Nave> L2;
	for (L1.moveToStart(); L1.currPos() < L1.length(); L1.next()) {
		Nave n = L1.getValue();
		bool found = false; // L1 contiene tutte le navi e L2 solamente una per compagnia
		for (L2.moveToStart(); L2.currPos() < L2.length(); L2.next()) {
			if (L2.getValue().key() == n.key()) {
				found = true;
				Nave toremove = L2.remove();
				toremove.setPasseggeri(n.getpasseggeri() + toremove.getpasseggeri()); //somma dei passeggeri e riaggungo alla lista
				L2.insert(toremove);
				break; //termino perche' tanto non ce ne saranno altre siccome una sola per compagnia
			}
		}
		if (!found) {
			n.setNome("---");
			n.setVelocita(-1);
			L2.append(n);
		}
	}

	bubblesort(L2);
	cout << "Q3: stampa lista L2 ";
	lprint(L2);
	clear();

	//4) Eliminare da Anavi tutti gli elementi che appartengono alla compagnia che ha il numero maggiore di
	//passeggeri in L2.Stampare Anavi(con visita in - order).
	int max_passeggeri = 0;
	string compagnia_max = "";
	for (L2.moveToStart(); L2.currPos() < L2.length(); L2.next()) {
		Nave n = L2.getValue();
		if (n.getpasseggeri() > max_passeggeri) {
			max_passeggeri = n.getpasseggeri();
			compagnia_max = n.key();
		}
	}

	//ora elimino dall'albero tutte le navi della stessa compagnia compagnia_max
	cout << "Q4: stampa albero Anavi(in - order)\n";
	Anavi.deleteCompagnia(compagnia_max);
	Anavi.show(cout);

	clear();

	return 0;

}
