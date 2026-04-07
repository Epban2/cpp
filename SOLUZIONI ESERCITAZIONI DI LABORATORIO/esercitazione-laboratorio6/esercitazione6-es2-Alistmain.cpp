// Array-based list class test program

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <time.h>  // Used by timing functions
#include <sstream> 


using namespace std;

// Include the array-based list template code
#include "alist.h"

// Generic list test commands
#include "esercitazione6-es2-listTest.h"

int data_minore(Item el1, Item el2)
{
	if ((el1.getanno()<el2.getanno()) || (el1.getanno() == el2.getanno() && el1.getmese()<el2.getmese()) || (el1.getanno() == el2.getanno() && el1.getmese() == el2.getmese() && el1.getgiorno()<el2.getgiorno()))
		return 1;
	else
		return 0;
}

void selectionsort(List<Item>& L) {
	int min_pos;
	Item min_element;
	// se lunghezza <2 non fai nulla
	for (int i = 0; i<(L.length() - 1); i++) {
		L.moveToPos(i);
		min_element = L.getValue();
		min_pos = i;
		for (int j = i + 1; j<L.length(); j++) {
			L.moveToPos(j);
			Item it_temp = L.getValue();
			if (
				(it_temp.getcognome()<min_element.getcognome()) ||
				((it_temp.getcognome() == min_element.getcognome()) && (it_temp.getnome()<min_element.getnome())) ||
				((it_temp.getcognome() == min_element.getcognome()) && (it_temp.getnome() == min_element.getnome()) && (data_minore(it_temp, min_element))))
			{
				min_pos = L.currPos();
				min_element = it_temp;
			}
		}
		L.moveToPos(min_pos);
		Item it_temp = L.remove();
		L.moveToPos(i);
		L.insert(it_temp);
	}
}



// Main routine for array-based list driver class
int main(int argc, char** argv) {

	AList<Item> agenda(100);
	string nome;
	string cognome;
	int giorno;
	int mese;
	int anno;
	string s,stemp;

	ifstream myfile("agenda.txt");
	if (myfile.is_open()) {
		while (myfile >> nome >> cognome >> s) {
			stemp = s.substr(0, 2);
			istringstream convert(stemp);
			convert >> giorno;

			stemp = s.substr(3, 2);
			istringstream convert2(stemp);
			convert2 >> mese;

			stemp = s.substr(6, 4);
			istringstream convert3(stemp);
			convert3 >> anno;
			
			Item item_tmp(nome,cognome,giorno,mese,anno);
			cout << item_tmp << endl;
			agenda.insert(item_tmp);
		}
		myfile.close();
	}

	cout << "agenda: "; lprint(agenda);
	selectionsort(agenda);
	cout << endl << "agenda sorted: "; lprint(agenda);

	cout << "That is all.\n";

	return 0;
}