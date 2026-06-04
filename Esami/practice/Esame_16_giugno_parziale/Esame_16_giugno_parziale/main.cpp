
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Item.h"
#include "heap.h"
#include "bst.h"
using namespace std;

const string FILENAME = "spettatori.txt";
const char SEPARATORE = ';';

int main()
{
	ifstream file(FILENAME);

	PQ<Item> code[3];
	BST<Item, string> non_ammessi;

	if (file.is_open()) {
		string nome, priorita, citta, value_str;
		int value;
		while (getline(file, nome, SEPARATORE)) {
			getline(file, priorita, SEPARATORE);
			getline(file, citta, SEPARATORE);
			getline(file, value_str);
			istringstream token(value_str);
			token >> value;

			Item i(nome, citta, value);
			int index = 0;
			if (priorita == "M")
				index++;
			else if (priorita == "L")
				index += 2;

			code[index].insert(i);
		}
	}
	file.close();

	/*
	L’ammissione al concerto avviene in K = 2 iterazioni.In ogni iterazione vengono estratti dalle code e
	ammessi, se presenti, i 3 spettatori con priorità più elevata dalla coda “H”, i 2 spettatori con priorità
	più elevata dalla coda “M”, lo spettatore con priorità più elevata dalla coda “L”.Stampare a video i
	nomi di tutti gli spettatori ammessi al concerto.Salvare tutti i rimanenti spettatori nelle tre code, non
	ammessi al concerto, in un albero binario di ricerca(BST) di oggetti Item avente il nome come chiave.
	*/
	for (int c = 0; c < 2; c++) {
		int index = 0;
		Item estratto;
		for (int j = 0; j < 3 && !code[index].empty(); j++) {
			estratto = code[index].getmax();
			cout << estratto;
		}
		index++;
		for (int j = 0; j < 2 && !code[index].empty(); j++) {
			estratto = code[index].getmax();
			cout << estratto;
		}
		index++;
		if (!code[index].empty()) {
			estratto = code[index].getmax();
			cout << estratto;
		}

		cout << endl;

	}

	for (int i = 0; i < 3; i++)
	{
		while (!code[i].empty())
			non_ammessi.insert(code[i].getmax());
	}

	non_ammessi.balance();
	cout << endl;
	int esclusi_parma = non_ammessi.stampaeCalcola("Parma");
	cout << "\nnumero persone di Parma escluse dal concerto: " << esclusi_parma << endl;

	//4)
	cout << endl;
	non_ammessi.stampaPadre("Marina Castelli");
	cout << endl;

	non_ammessi.stampaPadre("Giuseppe Longo");

	cout << endl;
	non_ammessi.stampaPadre("Maurizio Mercuri");

	cout << endl;
	return 0;
}