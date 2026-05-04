#include <iostream>
using namespace std;
#include <string>

#include "esercitazione7_es2_binaryTree.h"

int main() {

	BinaryTree<Item>* myBT = new BinaryTree<Item>;
	Item it1(25);
	myBT->AddItem(it1);
	Item it2(19);
	myBT->AddItem(it2);
	Item it3(32);
	myBT->AddItem(it3);
	Item it4(22);
	myBT->AddItem(it4);
	Item it5(30);
	myBT->AddItem(it5);
	myBT->traverse();

	//bilanciata
	//BinaryTree<Item>* myBT2 = new BinaryTree<Item>;
	//Item ita(11);
	//myBT2->AddItem(ita);
	//Item itb(17);
	//myBT2->AddItem(itb);
	//Item itc(8);
	//myBT2->AddItem(itc);
	//Item itd(10);
	//myBT2->AddItem(itd);
	//Item ite(14);
	//myBT2->AddItem(ite);

	//sbilanciata
	BinaryTree<Item>* myBT2 = new BinaryTree<Item>;
	Item ita(25);
	myBT2->AddItem(ita);
	Item itb(19);
	myBT2->AddItem(itb);
	Item itc(32);
	myBT2->AddItem(itc);
	Item itd(10);
	myBT2->AddItem(itd);
	Item ite(30);
	myBT2->AddItem(ite);

	cout << endl; cout << endl;
	myBT2->traverse();
	cout << endl; cout << endl;

	int result = myBT->equal_tree_structure(myBT2->root);
	if (result)
		cout << "trees have the same structure" << endl;
	else
		cout << "trees do not have the same structure" << endl;

	return 0;
}