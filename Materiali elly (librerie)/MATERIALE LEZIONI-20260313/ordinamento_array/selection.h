#ifndef SELECTION_H
#define SELECTION_H

template <class Item>
void selection(Item a[], int l, int r)
  { for (int i = l; i < r; i++) //Avanzamento esterno
      { int min = i;
        for (int j = i+1; j <= r; j++) //Avanzamento interno, cerca il numero minore della sottosequenza
            if (a[j] < a[min]) min = j;
        exch(a[i], a[min]); //funzione di comp.h
      } 
  }

#endif