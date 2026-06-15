/*
Esercizio 4: Scrivere un programma che legga il contenuto del file “lotto.txt”.Ciascuna riga del file
contiene il nome di una ruota del Lotto(singola parola) e cinque numeri interi estratti in quella ruota
nel formato :
<nome_ruota> <numero1> <numero2> <numero3> <numero4> <numero5>
Salvare i dati contenuti nel file in un oggetto map di STL, chiamato “lotto”, che contenga come chiave di
ogni elemento il <nome_ruota> e come dato un set di numeri interi :
map<string, set<int> > lotto;
Scrivere una funzione :
bool Find_terno(map<string, set<int> >& lotto, string ruota, int n1, int n2, int n3)
che accetti come argomenti la mappa, il nome di una ruota e tre numeri interi.La funzione Find_terno
deve restituire 1 se i tre numeri passati come argomento costituiscono un “terno” sul nome della ruota
passato come argomento, e 0 altrimenti.Chiamare la funzione Find_terno due volte per verificare se i
tre numeri(11, 12, 13) costituisco un terno sulla ruota di “Firenze” e se i tre numeri(46, 84, 3)
costituiscono un terno sulla ruota di Milano
*/

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>
using namespace std;

bool Find_terno(map<string, set<int> >& lotto, string ruota, int n1, int n2, int n3) {
	set<int> s = lotto[ruota];
	if (s.find(n1) != s.end() && s.find(n2) != s.end() && s.find(n3) != s.end()) return true;

	return false;
}


int main() {
	typedef pair<string, set<int>> obj;

	map<string, set<int>> lotteria;
	ifstream file("lotto.txt");
	if (file.is_open()) {
		string nome;
		int n1, n2, n3, n4, n5;
		while (file >> nome >> n1 >> n2 >> n3 >> n4 >> n5) {
			set<int> numbers;
			numbers.insert(n1); numbers.insert(n2); numbers.insert(n3); numbers.insert(n4); numbers.insert(n5);
			lotteria.insert(obj(nome, numbers));
		}

	}
	file.close();

	for (map<string, set<int>>::iterator mit = lotteria.begin(); mit != lotteria.end(); mit++) {
		cout << (*mit).first << " : ";
		set<int> s = (*mit).second;
		for (set<int>::iterator sit = s.begin(); sit != s.end(); sit++) {
			cout << (*sit) << " ";
		}
		cout << endl;
	}

	cout << "Terno a Milano 46,84,3 : " << (Find_terno(lotteria, "Milano", 46, 84, 3) ? "Trovato" : "Non trovato") << endl;
	cout << "Terno a Bari 1,2,3 : " << (Find_terno(lotteria, "Bari", 1, 2, 3) ? "Trovato" : "Non trovato") << endl;


	return 0;

}