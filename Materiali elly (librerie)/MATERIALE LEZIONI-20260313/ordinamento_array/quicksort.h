#ifndef QUICKSORT_H
#define QUICKSORT_H

template <class Item>
void quicksort(Item a[], int l, int r)
  {
    if (r <= l) return;
    int i = partition(a, l, r);
    quicksort(a, l, i-1);
    quicksort(a, i+1, r);
  }


template <class Item>
int partition(Item a[], int l, int r)
  { int i = l-1, j = r; Item v = a[r];
    for (;;)
      { 
        while (a[++i] < v) ;
        while (v < a[--j]) if (j == l) break;
        if (i >= j) break;
        exch(a[i], a[j]);
      }
    exch(a[i], a[r]);
    return i;
  }


// Applicazione della funzione partition: mette i k elementi più piccoli in un array (senza ordinarli) nelle prime k posizioni dell'array 
template <class Item>
void select(Item a[], int l, int r, int k)
{
	int i;
	if (r <= l) return;
	i = partition(a, l, r);
	if (i > k) select(a, l, i - 1, k);
	if (i < k) select(a, i + 1, r, k);
}

#endif