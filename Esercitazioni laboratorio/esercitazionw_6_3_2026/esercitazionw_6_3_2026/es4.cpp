#include <iostream>
#include <ctime>
#include <string>

using namespace std;

struct Tipolibro {
	string titolo;
	string autore;
	int anno_edizione;
	float prezzo;

};
const int N = 3;


int main() {
	Tipolibro libri[3];

	int anno;
	int prezzo;
	string titolo, autore,anno_str;
	float sum = 0;
	int older = 10000, older_index, expensive = 0, expensive_index;
	for (int i = 0; i < 3; i++)
	{
		cout << "titolo autore anno: ";
		cin >> titolo >> autore >> anno_str;
		anno = stoi(anno_str);
		prezzo = rand() % 200;
		libri[i].titolo = titolo;
		libri[i].autore= autore;
		libri[i].anno_edizione= anno;
		libri[i].prezzo = prezzo;
		sum += prezzo;
		if (anno < older) {
			older = anno;
			older_index =i; 
		}
		if (prezzo> expensive) 
		{
			expensive_index= i;
			expensive = prezzo;
		}
	}

	//prezzo medio

	for (int i = 0; i < N; i++) {
		cout << libri[i].titolo << ", " << libri[i].autore << ", " << libri[i].anno_edizione << ", " << libri[i].prezzo << "$" << endl;
	}

	cout << "prezzo medio: " << (sum / N)<<endl;
	cout << "libro piu' vecchio: " << libri[older_index].titolo<<endl;
	cout << "libro piu' costoso: " << libri[expensive_index].titolo;;
	
	return 0;
}