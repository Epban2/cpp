/*
Scrivere una funzione di ordinamento decrescente per liste utilizzando l’algoritmo “insertion
sort” void insertionsort(List<Item>& L)
*/
#include <iostream>
#include <alist.h>

using namespace std;

//item
class Item {
private:
	int val;
public:
	Item(int input = 0) { val = input; }
	// The following is for those times when we actually
	//   need to get a value, rather than compare objects.
	int key() const { return val; }
};

inline ostream& operator<<(ostream& s, const Item& i)
{
	return s << i.key();
}

// Assert: If "val" is false, print a message and terminate
// the program
inline void Assert(bool val, string s) {
	if (!val) { // Assertion failed -- close the program
		std::cout << "Assertion Failed: " << s << endl;
		exit(-1);
	}
}


//lprint
template <typename E>
void lprint(List<E>& L) {
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

/*
Funzione generica che confronta due elementi e ritorna true se il secondo è minore del primo (effettuare quindi scambio)
*/
int comp(int& A, int& B)
{
	if (B < A) return 1;
	else
		return 0;
}


//insertion
void insertion(List<Item>& L)
{
	for (int i = 1; i < L.length(); i++)
	{
		for (int j = i; j > 0; j--) {

			L.moveToPos(j - 1);
			int a = L.getValue().key(); //low

			L.next();
			int b = L.getValue().key(); // up

			if (comp(b, a)) {
				L.moveToPos(j - 1);
				L.remove(); L.remove();
				L.insert(a);
				L.insert(b);

			}
			else break;
		}
	}
}

