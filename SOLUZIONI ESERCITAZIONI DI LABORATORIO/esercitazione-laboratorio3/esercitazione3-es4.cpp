//Scrivere una classe template template <class T> class Matrix2x2 per rappresentare array a due dimensioni generici di dimensione 2x2 (matrici). La classe oltre ai costruttori deve contenere un metodo pubblico per sommare ad un oggetto Matrix2x2 una matrice passata come argomento 
//Matrix2x2<T> Add(Matrix2x2 x);
// (la somma di due matrici è la matrice i cui elementi sono la somma di elementi in posizione corrispondente)

#include "esercitazione3-es4.h"

int main()
{
	Matrix2x2<int> X(1, 2, 3, 4);
    Matrix2x2<int> Y(5, 6, 7, 8);
	Matrix2x2<int> A = X.Add(Y);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			cout << A.m[i][j] << " ";
		cout << endl;
	}
}