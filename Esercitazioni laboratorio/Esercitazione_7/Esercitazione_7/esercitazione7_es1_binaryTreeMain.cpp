#include <iostream>
using namespace std;
#include <string>

#include "esercitazione7_es1_binaryTree.h"

int main() {
	BinaryTree<Item> tree;
	tree.AddItem(Item("Giamma"));
	tree.AddItem(Item("Mauri"));
	tree.AddItem(Item("Carlo"));
	tree.AddItem(Item("Ramon"));

	tree.traverse();
	cout << "numero elementi: " << tree.count() << endl;
	cout << "altezza alberto: " << tree.height() << endl;
	return 0;
}