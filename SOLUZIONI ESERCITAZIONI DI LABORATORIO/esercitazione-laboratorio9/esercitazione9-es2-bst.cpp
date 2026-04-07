#include <iostream>
#include <fstream>
#include <sstream>  
#include <string>
#include <stdlib.h>
#include "esercitazione9-es2-item.h"
#include "esercitazione9-es2-bst.h"
#include <time.h>  // Used by timing functions

bool isNumber(string s) {
	if (s.size() == 0) return false;
	for (int i = 0; i<s.size(); i++) {
		if ((s[i] >= '0' && s[i] <= '9') == false) {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[])
  { 
	BST<ItemA, KeyA> uffici;
	BST<ItemB, KeyB> telefoni;
	string ufficio, nome, telefono_str;
	KeyB telefono;

	ifstream myfile("telefoni.txt");
	if (myfile.is_open()) {
		while (getline(myfile, ufficio, ',')) {
			getline(myfile, nome, ',');

			getline(myfile, telefono_str);
			istringstream token(telefono_str);
			token >> telefono;

			ItemA vA(ufficio, nome);
			uffici.insert(vA);

			ItemB vB(nome, telefono);
			telefoni.insert(vB);
		}
	}
	myfile.close();

	uffici.balance();
	telefoni.balance();
	cout << "uffici Tree" << endl;
	uffici.show(cout); cout << endl;
	cout << endl << "telefoni Tree" << endl;
	telefoni.show(cout); cout << endl;

	for (int i=0; i< telefoni.tree_size(); i++)
	{
		ItemB itB = telefoni.select(i);
		ItemA itA = uffici.search(itB.getnome());
		cout << itA.getufficio() << " " << itA.key() << " " << itB.key() << endl;
	}

	string stringa;
	while(1)
	{
		cout << endl << "inserire una stringa" << endl;
		getline(cin,stringa);
		if (isNumber(stringa))
		{
			istringstream tk(stringa);
			tk >> telefono;
			ItemB itB = telefoni.search(telefono);
			ItemA itA = uffici.search(itB.getnome());
			if (itB.null())
				cout << "elemento non trovato" << endl;
		    else 
			    cout << itA.getufficio() << " " << itA.key() << " " << itB.key() << endl;

		}
		else 
		{  
			cout << "elenco persone nello stesso ufficio di " << stringa << endl;
			ItemA itA = uffici.search(stringa);
			if (!itA.null())
			 for (int i = 0; i< uffici.tree_size(); i++)
			 {
				ItemA itAi = uffici.select(i);
				if (itA.getufficio() == itAi.getufficio())
				  cout << itAi.key() << endl;
			 }
		}
	}
  }