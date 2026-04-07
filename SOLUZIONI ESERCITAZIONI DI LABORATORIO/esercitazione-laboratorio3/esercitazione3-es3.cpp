//Scrivere una classe template template<class T> class Pair i cui oggetti rappresentino coppie di elementi dello stesso tipo generico T (“first” e “second”). La classe deve contenere i seguenti metodi pubblici:
//•	void set_element(int position, T value); // imposta value in posizione 1 o 2
//•	T get_element(int position) const; // restituisce l’elemento in posizione 1 o 2
//•	void add_up(const Pair<T>& the_pair); // somma gli elementi corrispondenti di un oggetto Pair con quelli contenuti nell’argomento the_pair 


#include "esercitazione3-es3.h"


int main()
{
	Pair<int> coppia_int(20, 40);
	Pair<int> coppia_int2(10, 12);
	Pair<float> coppia_float;
	coppia_float.set_element(1, 30.5);
	coppia_float.set_element(2, 50.1);
	cout << "coppia_int 1: " << coppia_int.get_element(1) << "  2: " << coppia_int.get_element(2) << endl;
	cout << "coppia_float 1: " << coppia_float.get_element(1) << "  2: " << coppia_float.get_element(2) << endl;
	coppia_int.add_up(coppia_int2);
	cout << "coppia_int 1: " << coppia_int.get_element(1) << "  2: " << coppia_int.get_element(2) << endl;
}