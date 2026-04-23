#include "list_test1.h"
#include <fstream> //ifstream, is_open()
#include <sstream> //istringstream
#include "llist.h"
#include "link.h"


const char SEPARATORE = ';';

void selectionsort(List<Item>& L) {
	int min_pos;
	Item min_element;
	// se lunghezza <2 non fai nulla
	for (int i = 0; i < L.length() - 1; i++) {
		L.moveToPos(i);
		min_element = L.getValue();
		min_pos = i;
		for (int j = i + 1; j < L.length(); j++) {
			L.moveToPos(j);
			Item it_temp = L.getValue();
			if (it_temp.key().numero < min_element.key().numero)
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

int find(LList<Prodotto>& l, string codice) {
	for (l.moveToStart(); l.currPos() < l.length(); l.next()) {
		if (l.getValue().getCodice() == codice)
			return l.currPos();
	}
	return -1;
}


int main(int argc, char** argv) {
	LList<Prodotto> prodotti;
	LList<Item> ricette;

	//Lettura prodotti
	ifstream file("dispensa.txt");
	if (file.is_open()) {
		string str, codice, nome_prodotto;
		int quantita;

		while (getline(file, codice, SEPARATORE)) {
			getline(file, nome_prodotto, SEPARATORE);

			getline(file, str);
			istringstream token(str);
			token >> quantita;
			Prodotto temp(codice, nome_prodotto, quantita);

			if (prodotti.length() > 0)
			{
				prodotti.moveToPos(prodotti.length() - 1); // per controllo delle quantità, posizionandomi in length()-1 ho l'ultimo elemento inserito e se il codice è identico a quello che voglio aggiungere allora devo modificare la quantità

			}if (prodotti.length() > 0 && temp.getCodice() == prodotti.getValue().getCodice())
			{
				Prodotto toremove = prodotti.getValue();
				prodotti.remove();
				toremove.setQuantita(toremove.getQuantita() + temp.getQuantita());
				prodotti.append(toremove);
			}
			else
				prodotti.append(temp);
		}

		file.close();
	}
	lprint(prodotti);

	//Lettura ricette
	ifstream file_ricette("ricette.txt");
	if (file_ricette.is_open()) {
		string strcodicericetta, nomericetta, codiceprodotto1, strquantitaprodotto1, codiceprodotto2, strquantitaprodotto2;
		int codicericetta, quantitaprodotto1, quantitaprodotto2;

		ricetta r;
		while (getline(file_ricette, strcodicericetta, SEPARATORE)) {
			istringstream c1(strcodicericetta);
			c1 >> r.numero;

			getline(file_ricette, r.descrizione, SEPARATORE);

			getline(file_ricette, r.ingrediente1, SEPARATORE);
			getline(file_ricette, strquantitaprodotto1, SEPARATORE);
			istringstream q1(strquantitaprodotto1);
			q1 >> r.quantita_ingr1;

			getline(file_ricette, r.ingrediente2, SEPARATORE);
			getline(file_ricette, strquantitaprodotto2);
			istringstream q2(strquantitaprodotto2);
			q2 >> r.quantita_ingr2;

			Item temp(r);
			ricette.append(temp);
		}

		file_ricette.close();
	}

	selectionsort(ricette);
	lprint(ricette);


	//3. Dopo aver richiesto al cuoco il numero di un piatto controllare se sono disponibili tutti gli ingredienti
	//	necessari e comunicarlo al cuoco.Se entrambe le quantità degli ingredienti sono sufficienti il cuoco
	//	decide di cucinare tale piatto.Decrementare le relative quantità di prodotti presenti in dispensa.
	while (true) {
		int piattorichiesto;
		cout << endl << "Numero del piatto da ordinare: ";
		cin >> piattorichiesto;

		//Controllo ingredienti richiesti
		ricette.moveToPos(piattorichiesto - 1);
		Item ricetta = ricette.getValue();

		string cod1 = ricetta.key().ingrediente1;
		string cod2 = ricetta.key().ingrediente2;
		int quantitarichiesta1 = ricetta.key().quantita_ingr1;
		int quantitarichiesta2 = ricetta.key().quantita_ingr2;

		int index1 = find(prodotti, cod1);
		int index2 = find(prodotti, cod2);
		if (index1 != -1 && index2 != -1) { //significa che i due sono gli indici dei prodotti nella lista
			prodotti.moveToPos(index1);
			Prodotto p1 = prodotti.getValue();
			prodotti.moveToPos(index2);
			Prodotto p2 = prodotti.getValue();
			if (p1.getQuantita() >= quantitarichiesta1 && p2.getQuantita() >= quantitarichiesta2) { //significa che ne abbiamo abbastanza e dobbiamo decrementarle
				cout << endl << "In preparazione: " << ricetta << endl;
				prodotti.moveToPos(index1);
				p1 = prodotti.remove();
				p1.setQuantita(p1.getQuantita() - 1);
				prodotti.insert(p1);

				prodotti.moveToPos(index2);
				p2 = prodotti.remove();
				p2.setQuantita(p2.getQuantita() - 1);
				prodotti.insert(p2);

			}
			else {
				cout << endl << "Ingredienti non sufficienti!" << endl;
			}

		}
	}
	return 0;
}