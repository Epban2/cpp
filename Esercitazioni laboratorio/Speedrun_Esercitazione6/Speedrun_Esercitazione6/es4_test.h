#include <iostream>
#include <string>
using namespace std;
#include <alist.h>


class Item {
private:
	int eta;
	string cognome;
	float media;

public:
	Item(string cognome = "", int eta = 0, float media = 0) {
		this->cognome = cognome;
		this->eta = eta;
		this->media = media;
	}
	string getCognome() const { return this->cognome; }
	int getEta() const { return this->eta; }
	float getMedia() const { return this->media; }

};

inline ostream& operator <<(ostream& s, const Item& i) {
	return s << i.getCognome() << " " << i.getEta() << " " << i.getMedia() << endl;
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
void lprint(Item L[], int dim) {
	for (int i = 0; i < dim; i++)
		cout << L[i];

}

void bubble(Item a[], int dim) {
	for (int i = 0; i < dim; i++) {
		for (int j = dim - 1; j > 0; j--) {
			if (a[j - 1].getMedia() < a[j].getMedia()) {
				Item low = a[j - 1];
				a[j - 1] = a[j];
				a[j] = low;
			}
		}
	}

}



// Print out the list (including showing position for the fence)
// Print list contents
void listPrint(List<Item>& L) {
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
