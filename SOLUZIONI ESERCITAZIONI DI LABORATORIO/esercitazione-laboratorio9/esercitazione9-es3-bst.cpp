#include <iostream>
#include <fstream>
#include <sstream>  
#include <string>
#include <stdlib.h>
#include "esercitazione9-es3-item.h"
#include "esercitazione9-es3-bst.h"
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
	BST<Item, Key> parteA;
	BST<Item, Key> parteB;
	string str,nome,email,voto_str;
	int voto; int matricola;

	ifstream myfile("parteA.txt");
	if (myfile.is_open()) {
		while (getline(myfile, str, ',')) {
			istringstream token(str);
			token >> matricola;

			getline(myfile, nome, ',');

			getline(myfile, voto_str, ',');
			if (!isNumber(voto_str))
				voto = 0;
			else
			{
			 istringstream token2(voto_str);
			 token2 >> voto;
		    }

			myfile >> email;
			
			Item v(nome, voto, email, matricola);
			parteA.insert(v);
		}
	}
	myfile.close();

	myfile.open("parteB.txt");
	if (myfile.is_open()) {
		while (getline(myfile, str, ',')) {
			istringstream token(str);
			token >> matricola;

			getline(myfile, nome, ',');

			getline(myfile, voto_str, ',');
			if (!isNumber(voto_str))
				voto = 0;
			else
			{
				istringstream token2(voto_str);
				token2 >> voto;
			}

			myfile >> email;

			Item v(nome, voto, email, matricola);
			parteB.insert(v);
		}
	}
	myfile.close();

	parteA.balance();
	parteB.balance();
	cout << "parteA Tree" << endl;
	parteA.show(cout); cout << endl;
	cout << endl << "parteB Tree" << endl;
	parteB.show(cout); cout << endl;

	parteA.stampa_risultati(parteB);
  }