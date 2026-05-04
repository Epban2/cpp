#include <iostream>
using namespace std;
#include <string>

#include "esercitazione7_es3_binaryTree.h"

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
	BinaryTree<Item>* myBT2 = new BinaryTree<Item>;
	Item ita(11);
	myBT2->AddItem(ita);
	Item itb(17);
	myBT2->AddItem(itb);
	Item itc(8);
	myBT2->AddItem(itc);
	Item itd(10);
	myBT2->AddItem(itd);
	Item ite(14);
	myBT2->AddItem(ite);

	//BT2 = new BinaryTree<Item>;
	//Item ita(11);
	//myBT2->AddItem(it1);
	//Item itb(17);
	//myBT2->AddItem(it2);
	//Item itc(8);
	//myBT2->AddItem(it3);
	//Item itd(10);
	//myBT2->AddItem(it4);
	//Item ite(14);
	//myBT2->AddItem(it5);

	cout << endl; cout << endl;
	myBT2->traverse();
	cout << endl; cout << endl;

	int result = myBT->equal_tree(myBT2);
	if (result)
		cout << "trees are equal" << endl;
	else
		cout << "trees are not equal" << endl;

	return 0;
}