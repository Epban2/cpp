#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
using namespace std;

#include "lstack.h"
#include "binary_tree-listTest.h"
#include "lqueue.h"

// Singly linked list node
template <typename E> class Node {
public:
  E data;      // Value for this node
  Node* lChildptr;
  Node* rChildptr;
  // Constructors
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

    void Insert(T newData, Node<T>* &theRoot)
        {
            if(theRoot == NULL)
            {
                theRoot = new Node<T>(newData);
                return;
            }

            if(newData < theRoot->data)
                Insert(newData, theRoot->lChildptr);
            else
                Insert(newData, theRoot->rChildptr);
        }

    void traverse(Node<T>* theRoot)
        {
            if(theRoot != NULL)
            {
                traverse(theRoot->lChildptr);
                traverse(theRoot->rChildptr);
				cout<< theRoot->data<<" ";
            }
        }

	void traverse_preorder_NR(Node<T>* theRoot)
     { 
	  LStack<Node<T>*> s;
      s.push(theRoot);
      while (s.length()!=0)
      {
        theRoot = s.pop();
		cout<< theRoot->data<<" ";
        if (theRoot->rChildptr != NULL) s.push(theRoot->rChildptr);
        if (theRoot->lChildptr != NULL) s.push(theRoot->lChildptr);
      }
     }

	void traverse_levelorder_NR(Node<T>* theRoot)
     { 
      LQueue<Node<T>*> q;
      q.enqueue(theRoot);
      while (q.length()!=0)
      {
        theRoot = q.dequeue();
		cout<< theRoot->data<<" ";
        if (theRoot->lChildptr != NULL) q.enqueue(theRoot->lChildptr);
        if (theRoot->rChildptr != NULL) q.enqueue(theRoot->rChildptr);
      }
     }

     int count_elements(Node<T>* h)
        {
          if (h == NULL) return 0;
          return count_elements(h->lChildptr) + count_elements(h->rChildptr) + 1;
        }

	 int tree_height(Node<T>* h)
        {
         if (h == NULL) return -1;
         int u = tree_height(h->lChildptr), v = tree_height(h->rChildptr);
         if (u > v) return u+1; else return v+1;
        }

	 Node<T>* max(T a[], int l, int r)
		{
		 int m = (l+r)/2;
         Node<T>* x = new Node<T>(a[m]);
         if (l == r) return x;
         x->lChildptr = max(a, l, m);
         x->rChildptr = max(a, m+1, r);
         int u = x->lChildptr->data.key(), v = x->rChildptr->data.key();
         if (u > v)
           x->data = u; else x->data = v;
         return x;
		}
		
		int equal_structure(Node<T>* theRootA, Node<T>* theRootB)
		{
			if (theRootA == NULL)
			{
				if (theRootB != NULL) return 0;
			}
			else
			{
				if (theRootB == NULL) return 0;
				int result;
				result = equal_structure(theRootA->lChildptr, theRootB->lChildptr);
				if (result == 0)
					return 0;
				result = equal_structure(theRootA->rChildptr, theRootB->rChildptr);
				if (result == 0)
					return 0;
			}
		    return 1;
		}

    public:
		Node<T>* root;

        BinaryTree()
        {
            root = NULL;
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

		int equal_tree_structure(Node<T>* theRootB)
		{
			int result = equal_structure(root,theRootB);
			return result;
		}
  };

#endif