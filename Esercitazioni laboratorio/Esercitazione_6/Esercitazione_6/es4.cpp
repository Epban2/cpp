#include "es4test.h"
#include <fstream>


int main()
{
	int n_scelti, eta_scelta; //per la selezione di studenti 
	cout << "Inserire n.studenti e eta' max:  ";
	cin >> n_scelti >> eta_scelta;
	ifstream file("studenti.txt");

	int n_studenti;

	if (file.is_open())
		file >> n_studenti;

	Studente* lista_studenti = new Studente[n_studenti];

	if (file.is_open())
	{
		string cognome; int eta; float media;
		int i = 0;
		while (file >> cognome >> eta >> media)
			lista_studenti[i++] = Studente(cognome, eta, media);

	}

	cout << "Lista non ordinata: " << endl;
	lprint(lista_studenti, n_studenti);


	insertion(lista_studenti, n_studenti);
	cout << endl << "Lista ordinata: " << endl;
	lprint(lista_studenti, n_studenti);

	LList<Studente> studenti_scelti;
	for (int i = 0; i < n_studenti && studenti_scelti.length() < n_scelti; i++)
	{
		if (lista_studenti[i].geteta() < eta_scelta)
			studenti_scelti.append(lista_studenti[i]);
	}

	cout << endl << "Studenti scelti: " << endl;
	Lprint(studenti_scelti);

	delete[] lista_studenti;
	file.close();
	return 0;
}