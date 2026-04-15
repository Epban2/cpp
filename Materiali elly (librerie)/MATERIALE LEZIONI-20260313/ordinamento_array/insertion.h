#ifndef INSERTION_H
#define INSERTION_H
//VEDI NEL FILE comp.h PER LE IMPLEMENTAZIONI DEI METODI DI CONFRONTO/SCAMBIO

template <class E>
void insertion(E a[], int l, int r)
{
	for (int i = l + 1; i <= r; i++)
		for (int j = i; ((j > l) && comp(a[j - 1], a[j])); j--)
			exch(a[j - 1], a[j]);
}

#endif