#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

// Your basic int type as an object.
class Item {
private:
	int val;
public:
	Item(int input = 0) { val = input; }
	// The following is for those times when we actually
	//   need to get a value, rather than compare objects.
	int key() const { return val; }
	void setkey(int input) { val = input;}
	int operator< (Item input) 
			{ if (val < input.key()) return 1; 
			  else return 0;
	        }
	int operator> (Item input)
	{
		if (val > input.key()) return 1;
		else return 0;
	}
};

// Let us print out Items easily
ostream& operator<<(ostream& s, const Item& i)
{
	return s << i.key();
}


#include "comp.h"
//#include "selection.h"
//#include "insertion.h"
//#include "bubble.h"
//#include "quicksort.h"
#include "mergesort.h"

int main(int argc, char *argv[])
  { 
	// inizializzazione dell'algoritmo di generazione di numeri casuali, srand va chiamata una sola volta prima della funzione rand()
    srand(time(NULL));
	if (argc < 2)
	 {
		cout << "argomenti: numero elementi, [0/1] inserimento manuale o casuale" << endl;
		exit(-1);
	 }
	int i, N = atoi(argv[1]), sw = atoi(argv[2]);
	//int *a = new int[N];
	//float *a = new float[N];
    Item *a = new Item[N];
	if (sw)
		for (i = 0; i < N; i++)
		{
		 a[i].setkey(1 + rand() % 1000);
		 //a[i] = 1 + rand() % 1000; // se si usa array di tipi di dato elementari, es: int
		}
	     // rand() ritorna un valore intero casuale in [0, RAND_MAX]
	     // quindi 1 + rand()%1000 è un numero intero casuale tra 1 e 1000
	     // in generale la formula 1 + rand()%N genera un intero casuale tra 1 e N
	     // generazione di un numero casuale tra min e max  r= min + rand()%(max-min+1)
	     // per numeri float ((float)rand()/RAND_MAX)*1000;
    else 
      { i = 0; 
	    while (i<N) {
			  int value;
			  cin >> value;
			  a[i].setkey(value);
			  //a[i] = value; // se si usa array di tipi di dato elementari, es: int
			  i++;
			  }
	  }
    
	//selection(a, 0, N-1);
	//insertion(a, 0, N-1);
	//bubble(a, 0, N-1);
	//shellsort(a, 0, N-1);
    //quicksort(a, 0, N-1);
	mergesort<Item>(a, 0, N-1);
	//select(a, 0, N - 1, 7);
	for (i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;
  }