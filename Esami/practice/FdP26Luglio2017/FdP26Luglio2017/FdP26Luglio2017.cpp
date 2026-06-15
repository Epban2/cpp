#include <fstream>
#include <sstream>

#include <iostream>
#include "Libro.h"
#include <string>
#include "llist.h"
#include "bst.h"
#include "listTest.h"

#include <map> //map per gestire gli editori
using namespace std;

const string NOMEFILE = "elenco_libri.txt";
const char SEPARATORE = '/';

void clear() { cout << endl << endl; }

/*
Ordinare la lista per <nome libro> decrescente e, a parità di <nome libro>,
per <codice libro> decrescente utilizzando un qualunque algoritmo di ordinamento.
*/
void bubblesort(List<Libro>& L) {
	for (int i = 0; i < (L.length() - 1); i++) {
		for (int j = (L.length() - 1); j > i; j--) {
			L.moveToPos(j);
			Libro it_j = L.getValue();
			L.moveToPos(j - 1);
			Libro it_jj = L.getValue();
			if (it_jj.getnome() < it_j.getnome())
			{
				L.moveToPos(j);
				Libro removed = L.remove();
				L.moveToPos(j - 1);
				L.insert(removed);
			}
			else if (it_jj.getnome() == it_j.getnome()) {
				if (it_jj.getcodice() < it_j.getcodice()) {
					L.moveToPos(j);
					Libro removed = L.remove();
					L.moveToPos(j - 1);
					L.insert(removed);
				}
			}
		}
	}
}

int main()
{
	LList<Libro> libri;
	BST<Libro, int> tree;

	ifstream file(NOMEFILE);
	if (file.is_open()) {
		string nome, editore, prezzostr, codicestr;
		int prezzo, codice;

		while (getline(file, nome, SEPARATORE)) {
			getline(file, codicestr, SEPARATORE);
			getline(file, editore, SEPARATORE);
			getline(file, prezzostr);

			istringstream tokenprezzo(prezzostr);
			tokenprezzo >> prezzo;
			istringstream tokencodice(codicestr);
			tokencodice >> codice;

			Libro l(nome, editore, prezzo, codice);
			if (nome != "non valido") // 2)
				libri.append(l);
			else
				tree.insert(l);
		}
	}
	file.close();


	bubblesort(libri);
	lprint(libri);
	clear();

	/*
	2) Durante la lettura del file salvare tutti i libri il cui <nome libro> è uguale alla stringa "non valido" in un
	albero binario di ricerca (BST1) avente come chiave il <prezzo>. Bilanciare l’albero. Stampare a
	video l’albero con visita In-order. Esempio di output:
	Q2: (non valido,19,ed3,8) (non valido,88,ed4,12) (non valido,987,ed3,21) (non valido,651,ed5,29)
	(non valido,25,ed4,37) (non valido,652,ed1,62)
	*/
	tree.balance();
	tree.show(cout);
	clear();

	/*
	Scrivere un algoritmo che modifichi la lista creata al punto 1 in modo che tra tutti gli elementi con lo
	stesso <nome editore> venga mantenuto soltanto l’ultimo(partendo dalla fine della lista).E’ possibile
	utilizzare strutture dati aggiuntive.Stampare a video il contenuto della lista.Esempio di output :
	Q3: < | (libro3, 71, ed1, 100) (libro1, 1786, ed12, 155) (libro1, 500, ed3, 49) (libro1, 285, ed2, 66)
	(libro0, 1000, ed4, 711) >
	*/
	typedef pair<string, Libro> obj; //la chiave è quindi una stringa es. ed4
	map <string, Libro> mapEditori;

	libri.moveToEnd();
	libri.prev();

	while (libri.currPos() >= 0)
	{
		Libro l = libri.getValue();
		if (mapEditori.find(l.geteditore()) == mapEditori.end()) {// se non è stato trovato
			mapEditori.insert(obj(l.geteditore(), l));
			if (libri.currPos() == 0)
				break; //se era il primo (ultima iterazione) allora è finito e non decremento
			libri.prev();
		}
		else // e' stato trovato -> devo eliminarlo
		{
			int pos = libri.currPos();

			libri.remove();
			if (pos == 0) //se ho rimosso il primo non devo tornare indietro
				break;

			libri.prev();
		}
	}
	lprint(libri);
	clear();

	/*
	Creare un secondo albero binario di ricerca BST2. Scrivere una procedura ricorsiva che per ogni
	nodo di BST1 crei un nuovo nodo il cui prezzo sia pari alla somma del prezzo del nodo stesso con i
	prezzi di tutti i nodi di BST1 con prezzo maggiore e inserisca il nuovo nodo creato in BST2. Il
	contenuto di BST1 non va modificato. Non è consentito utilizzare la funzione “select”. Si supponga
	che tutti gli elementi abbiano un prezzo diverso. Stampare a video il contenuto di BST2 con visita Inorder. Esempio di output:
	Q4: (non valido,652,ed1,62) (non valido,25,ed4,99) (non valido,651,ed5,128) (non valido,987,ed3,149)
	(non valido,
	*/
	BST<Libro, int> tree2;
	tree.sommamaggiore(tree2);

	tree2.balance();
	tree2.show(cout);
	clear();
	return 0;
}
