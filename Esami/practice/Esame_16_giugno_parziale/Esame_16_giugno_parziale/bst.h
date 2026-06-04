#ifndef BST_H
#define BST_H

//#include "symbol_table_item.h"

#include <iostream>
using namespace std;

#include <stdlib.h>

// classe template per la realizzazione di un albero binario di ricerca
template <class Item, class Key>
class BST
{
private:
	// definizione di una struttura dati per rappresentare i nodi dell'albero
	struct node
	{
		Item item; node* l, * r;
		node(Item x)
		{
			item = x; l = 0; r = 0;
		}
	};
	typedef node* link;
	link head;
	Item nullItem;

	// ricerca di un elemento data una chiave in ingresso
	// restituisce, se presente, il primo elemento trovato nell'albero con la chiave cercata
	Item searchR(link h, Key v)
	{
		if (h == 0) return nullItem;
		Key t = h->item.key();
		if (v == t) return h->item;
		if (v < t) return searchR(h->l, v);
		else return searchR(h->r, v);
	}

	// inserimento di un elemento nell'albero binario di ricerca
	void insertR(link& h, Item x)
	{
		if (h == 0) { h = new node(x); return; }
		if (x.key() < h->item.key())
			insertR(h->l, x);
		else insertR(h->r, x);
	}

	void showR(link h, ostream& os)
	{
		if (h == 0) return;

		h->item.show(os);
		showR(h->l, os);
		showR(h->r, os);
	}

	void rotR(link& h)
	{
		link x = h->l; h->l = x->r; x->r = h; h = x;
	}
	void rotL(link& h)
	{
		link x = h->r; h->r = x->l; x->l = h; h = x;
	}

	// inserimento in radice
	void insert_rootR(link& h, Item x)
	{
		if (h == 0) { h = new node(x); return; }
		if (x.key() < h->item.key())  // se è minore inserisce e poi ruota a dx
		{
			insert_rootR(h->l, x); rotR(h);
		}
		else { insert_rootR(h->r, x); rotL(h); } // altrimenti inserisce a destra e ruota a sinistra
	}

	// restituisce il k-mo elemento con chiave minore dell'albero
	Item selectR(link h, int k)
	{
		if (h == 0) return nullItem;
		int t = tree_size(h->l);
		if (t > k) return selectR(h->l, k);
		if (t < k) return selectR(h->r, k - t - 1);
		return h->item;
	}

	// partizionamento: porta in radice il k-mo elemento con chiave minore
	void partR(link& h, int k)
	{
		int t = tree_size(h->l);
		if (t > k)
		{
			partR(h->l, k); rotR(h);
		}
		if (t < k)
		{
			partR(h->r, k - t - 1); rotL(h);
		}
	}

	// fonde due alberi binari di ricerca in cui il secondo (b) contiene elementi con chiavi maggiori delle chiavi del primo albero (a)
	// restituisce il nodo radice dell'albero risultante dalla fusione di a e b
	link joinLR(link a, link b)
	{
		if (b == 0) return a;
		partR(b, 0); b->l = a;
		return b;
	}

	// elimina, se presente, il primo elemento nell'albero con chiave v
	void removeR(link& h, Key v)
	{
		if (h == 0) return;
		Key w = h->item.key();
		if (v < w) removeR(h->l, v);
		if (w < v) removeR(h->r, v);
		if (v == w)
		{
			link t = h;
			h = joinLR(h->l, h->r); delete t;
		}
	}

	// fonde due alberi binari di ricerca generici
	link joinR(link a, link b)
	{
		if (b == 0) return a;
		if (a == 0) return b;
		insert_rootR(b, a->item);
		b->l = joinR(a->l, b->l);
		b->r = joinR(a->r, b->r);
		delete a; return b;
	}

	void rand_insertR(link& h, Item x)
	{
		if (h == 0) { h = new node(x); return; }
		if (rand() < RAND_MAX / (1 + tree_size(h)))
		{
			insert_rootR(h, x); return;
		}
		if (x.key() < h->item.key())
			rand_insertR(h->l, x);
		else rand_insertR(h->r, x);
	}

	// bilanciamento di un albero binario di ricerca
	void balanceR(link& h)
	{
		int size;
		size = tree_size(h);

		if (size < 2) return;
		partR(h, size / 2);
		balanceR(h->l);
		balanceR(h->r);
	}

	/*
	int height(link h)
	{
		if (h == 0) return -1;
		int u = height(h->l), v = height(h->r);
		if (u > v) return u + 1; else return v + 1;
	}
	*/

	int stampaeCalcolaR(link h, string citta)
	{
		if (h == 0) return 0;

		cout << h->item;
		int sum = 0;
		if (h->item.getCitta() == citta)
			sum++;
		return stampaeCalcolaR(h->l, citta) + stampaeCalcolaR(h->r, citta) + sum;
	}

	/*
	Scrivere un metodo ricorsivo della classe BST per stampare il nome, se esiste, del nodo padre di un
	nodo la cui chiave viene passata come argomento.Eseguire il metodo due volte con i nomi
	“Giuseppe Longo” e “Marina Castelli”.Esempio di output :
	padre di Giuseppe Longo : Giulio Rossi(Mantova)
	nessun nodo padre di Marina Castelli
	*/
	void stampaPadreR(link h, string chiave) {
		if (h == 0) { // se siamo arrivati fino alla fine significa che non e' stato trovato alcun padre
			cout << "nessun nodo padre di " << chiave;
			return;
		}
		if (chiave == head->item.key()) // la radice non ha padre
		{
			cout << "nessun nodo padre di " << chiave;
			return;
		}
		link left = h->l; //non faccio andare a figli non esistenti
		link right = h->r;
		if (left != 0) {
			if (left->item.key() == chiave)
			{
				cout << "padre di " << chiave << " : " << h->item;
				return;
			}
			stampaPadreR(left, chiave);

		}
		if (right != 0) {
			if (right->item.key() == chiave)
			{
				cout << "padre di " << chiave << " : " << h->item;
				return;
			}
			stampaPadreR(right, chiave);
		}
	}


public:
	BST()
	{
		head = 0;
	}

	int tree_size(link tree) {
		if (!tree) return 0;
		return 1 + tree_size(tree->r) + tree_size(tree->l);
	}

	Item search(Key v)
	{
		return searchR(head, v);
	}
	void insert(Item x)
	{
		insertR(head, x);
	}
	void show(ostream& os)
	{
		showR(head, os);
	}
	void insert_root(Item item)
	{
		insert_rootR(head, item);
	}
	Item select(int k)
	{
		return selectR(head, k);
	}
	void remove(Item x)
	{
		removeR(head, x.key());
	}
	void join(BST<Item, Key>& b)
	{
		head = joinR(head, b.head);
	}
	void rand_insert(Item x)
	{
		rand_insertR(head, x);
	}
	void balance()
	{
		balanceR(head);
	}

	/*int tree_height()
	{
		return height(head);
	}*/


	/*
	Bilanciare l’albero binario di ricerca.Aggiungere un metodo alla classe BST che stampi a video tutti
	gli elementi secondo una visita pre - order e che calcoli il numero di persone non ammesse al concerto
	provenienti da una città passata come argomento.Stampare il risultato quando il metodo viene
	chiamato con la città “Parma” come argomento.Esempio di output :
	stampa contenuto albero delle persone non ammesse(pre - order)
	Marina Castelli(Firenze) Giulio Rossi(Mantova) Elena Giannini(Parma) Elena Ferrari(Genova)
	Giuseppe Longo(Parma) Paola Russo(Bari) Matteo Gentile(Parma) Renzo Valloni(Padova)
	numero persone di Parma escluse dal concerto : 3
	*/
	int stampaeCalcola(string citta) { return stampaeCalcolaR(head, citta); }

	void stampaPadre(string chiave) {
		stampaPadreR(head, chiave);
	}




};

#endif