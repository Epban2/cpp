#include <iostream>
#include <string>
using namespace std;

#include <alist.h>

//Ogni nominativo(classe Item) è composto da
//una struttura dati contenente : Nome(string in caratteri minuscoli), Cognome(string in caratteri
//minuscoli) e data di nascita(tre campi “giorno”, “mese”, “anno” in valori interi positivi

class Item {
private:
	string nome, cognome;
	int giorno, mese, anno;

public:
	Item(string nome = "", string cognome = "", int giorno = 0, int mese = 0, int anno = 0) {
		this->nome = nome;
		this->cognome = cognome;
		this->giorno = giorno;
		this->mese = mese;
		this->anno = anno;
	}

	string getnome() const { return this->nome; }
	string getcognome() const { return this->cognome; }
	int getgiorno() const { return this->giorno; }
	int getmese() const { return this->mese; }
	int getanno()  const { return this->anno; }

};

inline ostream& operator<<(ostream& s, const Item& i)
{
	return s << i.getnome() << " " << i.getcognome() << " " << i.getgiorno() << "." << i.getmese() << "." << i.getanno() << endl;
}

// Assert: If "val" is false, print a message and terminate
// the program
inline void Assert(bool val, string s) {
	if (!val) { // Assertion failed -- close the program
		cout << "Assertion Failed: " << s << endl;
		exit(-1);
	}
}

// Print out the list (including showing position for the fence)
// Print list contents
void lprint(List<Item>& L) {
	int currpos = L.currPos();

	L.moveToStart();

	cout << "< ";
	int i;
	for (i = 0; i < currpos; i++) {
		cout << L.getValue() << " ";
		L.next();
	}
	cout << "| ";
	while (L.currPos() < L.length()) {
		cout << L.getValue() << " ";
		L.next();
	}
	cout << ">\n";
	L.moveToPos(currpos); // Reset the fence to its original position
}

inline bool operator<(Item& i1, Item& i2) {
	if (i1.getcognome() != i2.getcognome())
		return i1.getcognome() < i2.getcognome();

	if (i1.getnome() != i2.getnome())
		return i1.getnome() < i2.getnome();

	// opzionale: confronto per data
	if (i1.getanno() != i2.getanno())
		return i1.getanno() < i2.getanno();
	if (i1.getmese() != i2.getmese())
		return i1.getmese() < i2.getmese();
	return i1.getgiorno() < i2.getgiorno();
}

void bubble(AList<Item>& l) {
	for (int i = 0; i < l.length(); i++)
		for (int j = l.length() - 1; j > i; j--)
		{
			l.moveToPos(j - 1);
			Item i1 = l.getValue();
			l.next();
			Item i2 = l.getValue();
			if (i2 < i1) {
				l.moveToPos(j - 1);
				l.remove(); 
				l.next();
				l.insert(i1);
			}
		}
}

