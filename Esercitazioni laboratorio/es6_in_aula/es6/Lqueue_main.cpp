#include "Lqueue_test.h"
#include <ctime>	//time()
#include <cstdlib>	//rand(), srand() 

const int N_UTENTI = 10;
const int N_MAX_PAGINE = 20;


int main() {
	srand(time(NULL));

	int documenti_utente[N_UTENTI + 1] = { 0 };
	int pagine_utente[N_UTENTI + 1] = { 0 };

	LQueue<Job> joblist;
	int job_counter = 1; //richiesto dal programma
	int printing_pages = 0;
	int totale_pagine_stampate = 0;

	for (int timestamp = 0; timestamp < 60 * 60 * 8; timestamp++) {

		if (printing_pages == 0 && joblist.length() > 0)
		{
			printing_pages = joblist.frontValue().getPagine();
		}

		if (joblist.length() > 0 && joblist.frontValue().getPagine() == printing_pages) {
			cout << joblist.frontValue() << ", job in coda: " << (joblist.length() - 1) << endl;
			documenti_utente[joblist.frontValue().getUtenteId()]++;
		}


		if (printing_pages > 0) {
			printing_pages--;
			totale_pagine_stampate++;
			pagine_utente[joblist.frontValue().getUtenteId()]++; // aumento le pagine stampate dall'utente
			if (printing_pages == 0)
				joblist.dequeue();
			else cout << "Pagine da stampare: " << printing_pages << endl;
		}


		if (rand() % 180 == 0) {
			int id_utente = (rand() % N_UTENTI) + 1;
			int n_pagine = (rand() % N_MAX_PAGINE) + 1;
			Job j = Job(id_utente, n_pagine, timestamp, job_counter++);
			joblist.enqueue(j);
		}

	}
	cout << endl << "Totale pagine stampate: " << totale_pagine_stampate << endl;
	for (int i = 1; i <= N_UTENTI; i++)
		cout << "Utente: " << i << ", n.Documenti: " << documenti_utente[i] << ", n.pagine stampate: " << pagine_utente[i] << endl;


	return 0;
}