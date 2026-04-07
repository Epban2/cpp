#include <iostream>
#include <string>
using namespace std;
class Item {
public:
	string abbreviazione;
	string parola;
	Item() {
		abbreviazione = "";
		parola = "";
	};
	Item(string abb, string par) {
		this->abbreviazione = abb;
		this->parola = par;
	}
};

int cerca(Item* lista, string abbreviazione, string parola, int size);
int main()
{

	Item* items = new Item[20];
	items[0] = Item("TO", "TORINO");
	items[10] = Item("TO", "TORONTO");

	items[1] = Item("MI", "MILANO");
	items[2] = Item("RM", "ROMA");
	items[3] = Item("NA", "NAPOLI");
	items[4] = Item("FI", "FIRENZE");
	items[5] = Item("VE", "VENEZIA");
	items[6] = Item("BO", "BOLOGNA");
	items[7] = Item("PA", "PALERMO");
	items[8] = Item("GE", "GENOVA");
	items[9] = Item("BA", "BARI");
	int size = 10;

	//prove
	int res = cerca(items, "XX", "Parma", size);
	cout << res << endl;
	if (res == 1) size++;

	cout << cerca(items, "TO", "TORINO", size) << endl;
	cout << cerca(items, "BA", "BARCELLONA", size) << endl;

	cout << items[9].parola << endl;
	cout << items[11].abbreviazione << ", " << items[11].parola;


	return 0;
}


int cerca(Item* lista, string abbreviazione, string parola, int size) {
	bool presente = false;
	int index;
	for (int i = 0; i < 20; i++) {
		if (lista[i].abbreviazione == abbreviazione && lista[i].parola == parola)
			return 0;
		else if (lista[i].abbreviazione == abbreviazione) {
			presente = true; //solamente l'abbreviazione è presente ma la parola è diversa
			index = i;
		}
	}

	if (presente) {
		lista[index].parola = parola;
		return 2;
	}

	lista[11] = Item(abbreviazione, parola);
	return 1;
}
