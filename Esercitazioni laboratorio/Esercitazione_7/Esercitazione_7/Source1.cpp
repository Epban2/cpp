#include <iostream>
#include "binary_tree.h"
#include "bstTest1.h"

using namespace std;

int main() {
	BinaryTree bt;
	BST<myItem, Key> bst;
	myItem i1("Piero"), i2("Franco"), i3("Luigi"), i4("Toto");
	bst.insert(i1);	bst.insert(i2); bst.insert(i3); bst.insert(i4);
	bst.show()
	return 0;
}