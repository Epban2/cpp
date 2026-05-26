/*
Esercizio 4: Scrivere un programma che legga il contenuto del file “lotto.txt”. Ciascuna riga del file
contiene il nome di una ruota del Lotto (singola parola) e cinque numeri interi estratti in quella ruota
nel formato:
<nome_ruota> <numero1> <numero2> <numero3> <numero4> <numero5>
Salvare i dati contenuti nel file in un oggetto map di STL, chiamato “lotto”,che contenga come chiave di
ogni elemento il <nome_ruota> e come dato un set di numeri interi:
map<string, set<int> > lotto;
Scrivere una funzione:
bool Find_terno(map<string, set<int> >& lotto, string ruota, int n1, int n2, int n3)
che accetti come argomenti la mappa, il nome di una ruota e tre numeri interi. La funzione Find_terno
deve restituire 1 se i tre numeri passati come argomento costituiscono un “terno” sul nome della ruota
passato come argomento, e 0 altrimenti. Chiamare la funzione Find_terno due volte per verificare se i
tre numeri (11,12,13) costituisco un terno sulla ruota di “Firenze” e se i tre numeri (46,84,3)
costituiscono un terno sulla ruota di Milano.
*/


#include <iostream>
#include <string>
using namespace std;
#include <map>
#include <set>

#include <fstream>

const string FILENAME = "lotto.txt";

/*
che accetti come argomenti la mappa, il nome di una ruota e tre numeri interi. La funzione Find_terno
deve restituire 1 se i tre numeri passati come argomento costituiscono un “terno” sul nome della ruota
passato come argomento, e 0 altrimenti.
*/
bool Find_terno(map<string, set<int> >& lotto, string ruota, int n1, int n2, int n3) {
	map<string, set<int> >::iterator it = lotto.find(ruota); //it è un iteratore alla map ricercata, se dereferenziato il tipo è pair, pertanto c'è .first e .second che ritornano stringa o set<int> (con in numeri della ruota).
	if (it == lotto.end())
			return 0; //Non è stato trovato il nome
	set<int> set_numeri = (*it).second;

	if (set_numeri.find(n1) != set_numeri.end() && set_numeri.find(n2) != set_numeri.end() && set_numeri.find(n3) != set_numeri.end())
		return 1;
	return 0;
}

int main() {
	typedef pair<string, set<int>> MyPair;

	map<string, set<int> > lotto;


	ifstream file(FILENAME);

	if (file.is_open())
	{
		set<int> numbers;
		string nome; int n1, n2, n3, n4, n5;
		while (file >> nome >> n1 >> n2 >> n3 >> n4 >> n5) {
			numbers.insert(n1);
			numbers.insert(n2);
			numbers.insert(n3);
			numbers.insert(n4);
			numbers.insert(n5);

			lotto.insert(MyPair(nome, numbers));
		}

	}
	file.close();

	/* Chiamare la funzione Find_terno due volte per verificare se i
	tre numeri (11,12,13) costituisco un terno sulla ruota di “Firenze” e se i tre numeri (46,84,3)
	costituiscono un terno sulla ruota di Milano.
	*/

	string citta1 = "Firenze", citta2 = "Milano";
	cout << "Terno a " << citta1 << ": " << (Find_terno(lotto, citta1, 11, 12, 13) ? "Trovato" : "Non trovato") << endl;
	cout << "Terno a " << citta2 << ": " << (Find_terno(lotto, citta2, 46, 84, 3) ? "Trovato" : "Non trovato") << endl;

	return 0;
}