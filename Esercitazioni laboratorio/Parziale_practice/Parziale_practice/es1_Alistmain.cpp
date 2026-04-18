#include "es1_Alisttest.h"
#include <fstream>



int main() {
	int  N;
	ifstream file("citta.txt");
	if (file.is_open())
		file >> N;

	// array dinamico di dim. N
	Item* lista_citta = new Item[N];

	if (file.is_open()) {
		string citta; float temperatura;  int umidita;
		int i = 0;
		while (file >> citta >> temperatura >> umidita)
			lista_citta[i++] = Item(citta, temperatura, umidita);

	}
	// Ordinare l'array in ordine crescente di Umidità utilizzando l'algoritmo Selection Sort.
	cout << "Lista non ordinata: " << endl;
	lprint(lista_citta, N);

	selection(lista_citta, N);
	cout << endl << "Lista ordinata: " << endl;
	lprint(lista_citta, N);

	
	int T_min, K;
	cout << endl << "Inserire quante misurazioni ricercare e la temperatura minima:  ";
	cin >> K >> T_min;

	AList<Item> citta_scelte;
	for (int i = 0; i < N && citta_scelte.length() < K; i++)
	{
		if (lista_citta[i].gettemperatura() > T_min)
			citta_scelte.append(lista_citta[i]);
	}

	Lprint(citta_scelte);



	delete[] lista_citta;
	file.close();
	return 0;
}