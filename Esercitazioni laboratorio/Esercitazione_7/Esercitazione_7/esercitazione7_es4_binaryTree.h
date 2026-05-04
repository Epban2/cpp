/*
Esercizio 4: Scrivere il distruttore della classe BinaryTree
*/

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
using namespace std;

#include "lstack.h"
#include "esercitazione7_es2_listTest.h"
#include "lqueue.h"

// class Node
template <typename E> class Node {
public:
	E data;      // Value for this node
	Node* lChildptr;
	Node* rChildptr;
	// Constructors<
	Node(E dataNew)
	{
		data = dataNew;
		lChildptr = NULL;
		rChildptr = NULL;
	}
};


template<class T>
class BinaryTree
{

private:
	Node<T>* root;

	// inserimento di un elemento nell'albero binario
	void Insert(T newData, Node<T>*& theRoot)
	{
		if (theRoot == NULL) //Se la radice è nulla
		{
			theRoot = new Node<T>(newData); //devo allocare un nuovo nodo che diventa la radice
			return;
		}

		if (newData < theRoot->data)
			Insert(newData, theRoot->lChildptr);
		else\
			Insert(newData, theRoot->rChildptr);
	}

	// attraversamento con stampa dell'albero 
	// permutando le righe si ottengono attraversamenti pre-order, post-order, in-order
	void traverse(Node<T>* theRoot)
	{
		if (theRoot != NULL)
		{
			traverse(theRoot->lChildptr);
			traverse(theRoot->rChildptr);
			cout << theRoot->data << " ";
		}
	}

	// attraversamento pre-order non ricorsivo
	void traverse_preorder_NR(Node<T>* theRoot) //Versione non ricorsiva, deve però utilizzare uno stack
	{
		LStack<Node<T>*> s;
		s.push(theRoot);
		while (s.length() != 0)
		{
			theRoot = s.pop();
			cout << theRoot->data << " ";
			if (theRoot->rChildptr != NULL) s.push(theRoot->rChildptr);
			if (theRoot->lChildptr != NULL) s.push(theRoot->lChildptr);
		}
	}

	// attraversamento level-order (chiamato anche in ampiezza)
	void traverse_levelorder_NR(Node<T>* theRoot)
	{
		LQueue<Node<T>*> q;
		q.enqueue(theRoot);
		while (q.length() != 0)
		{
			theRoot = q.dequeue();
			cout << theRoot->data << " ";
			if (theRoot->lChildptr != NULL) q.enqueue(theRoot->lChildptr);
			if (theRoot->rChildptr != NULL) q.enqueue(theRoot->rChildptr);
		}
	}

	// conta il numero di elementi nell'albero binario
	int count_elements(Node<T>* h)
	{
		if (h == NULL) return 0;
		return count_elements(h->lChildptr) + count_elements(h->rChildptr) + 1;
	}

	// restituisce l'altezza dell'albero
	int tree_height(Node<T>* h)
	{
		if (h == NULL) return -1;
		int u = tree_height(h->lChildptr), v = tree_height(h->rChildptr);
		if (u > v) return u + 1; else return v + 1;
	}

	// divide et impera
	Node<T>* max(T a[], int l, int r)
	{
		int m = (l + r) / 2;
		Node<T>* x = new Node<T>(a[m]);
		if (l == r) return x;
		x->lChildptr = max(a, l, m);
		x->rChildptr = max(a, m + 1, r);
		int u = x->lChildptr->data.key(), v = x->rChildptr->data.key();
		if (u > v)
			x->data = u; else x->data = v;
		return x;
	}



	int equal_structure(Node<T>* theRootA, Node<T>* theRootB)
	{
		if (theRootA == NULL && theRootB == NULL) return 1; //albero vuoto
		if (theRootA == NULL || theRootB == NULL) return 0; //se la condizione e' verificata, significa che solo uno dei due e' null (altrimenti avrebbe ritornato 1)

		//serie di iterazioni, se un nodo dei due (destro/sinistro) e' diverso da quelli del B, allora il ritorno sara' l'ultimo ossia 0 (falso)
		return (equal_structure(theRootA->rChildptr, theRootB->rChildptr) && equal_structure(theRootA->lChildptr, theRootB->lChildptr));
	}

	int equal(Node<T>* theRootA, Node<T>* theRootB)
	{
		if ((theRootA == NULL && theRootB == NULL))	return 1; //albero vuoto
		if (theRootA == NULL || theRootB == NULL) return 0; //se la condizione e' verificata, significa che solo uno dei due e' null (altrimenti avrebbe ritornato 1)

		//verificati i due passi base
		//se le radici sono identiche, allora posso andare piu' in profondita'
		if (theRootA->data.key() == theRootB->data.key())
			return (equal(theRootA->rChildptr, theRootB->rChildptr) && equal(theRootA->lChildptr, theRootB->lChildptr));
		else return 0;
	}


public:

	BinaryTree()
	{
		root = NULL;
	}

	~BinaryTree() {
		//devo andare in prodontira' ed eliminare la radice
		destruct(root);
		cout << "Destructor: Memory deallocated" << endl;
	}

	void destruct(Node<T>* treeRoot) {
		if (treeRoot == NULL) return;
		destruct(treeRoot->lChildptr);
		destruct(treeRoot->rChildptr);
		delete treeRoot;

	}

	void AddItem(T newData)
	{
		Insert(newData, root);
	}

	void traverse()
	{
		traverse(root);
		//traverse_preorder_NR(root);
		//traverse_levelorder_NR(root);
	}

	int count()
	{
		return count_elements(root);
	}


	int height()
	{
		return tree_height(root);
	}


	void createTournament(T a[], int l, int r)
	{
		root = max(a, l, r);
	}

	//
	int equal_tree_structure(Node<T>* theRootB) {
		return equal_structure(root, theRootB);
	}

	//Due	alberi A e B sono uguali se hanno la stessa struttura e se tutte le coppie di nodi corrispondenti di A e di B hanno lo stesso valore).
	int equal_tree(BinaryTree<T>* treeB) {
		return equal(root, treeB->root);
	}

};



#endif