#ifndef HEAP_H
#define HEAP_H

template <class Item>
void exch(Item &A, Item &B)
{
	Item t = A; A = B; B = t;
}

// array based priority queue
template <class Item>
class aPQ 
  {
    private:
      Item *pq; 
      int N;
    public:
      aPQ(int maxN)
        { pq = new Item[maxN]; N = 0; }
	  ~aPQ() { delete[] pq; } // Destructor
      int empty() const
        { return N == 0; }
	  // inserisce un elemento
      void insert(Item item)
        { pq[N++] = item; }
	  // estrae l'elemento con priorità massima
      Item getmax()
        { int max = 0;
          for (int j = 1; j < N; j++)
            if (pq[max] < pq[j]) max = j;
          exch(pq[max], pq[N-1]);  
          return pq[--N];
        }
  };


template <class Item>
void fixUp(Item a[], int k)
  {
    while (k > 1 && a[k/2] < a[k])
      { exch(a[k], a[k/2]); k = k/2; }
  }


template <class Item>
void fixDown(Item a[], int k, int N)
  {
    while (2*k <= N)
      { int j = 2*k;
        if (j < N && a[j] < a[j+1]) j++;
        if (!(a[k] < a[j])) break;
        exch(a[k], a[j]); k = j;
      }
  }


// heap based priority queue
template <class Item>
class PQ 
  {
    private:
      Item *pq; 
      int N;
    public:
      PQ(int maxN)
        { pq = new Item[maxN+1]; N = 0; }
	  ~PQ() { delete[] pq; } // Destructor
      int empty() const
        { return N == 0; }
      void insert(Item item)
        { pq[++N] = item;  fixUp(pq, N); }
      Item getmax()
        { 
          exch(pq[1], pq[N]); 
          fixDown(pq, 1, N-1); 
          return pq[N--]; 
        }
  };



template <class Item>
void PQsort(Item a[], int l, int r)
  { int k;
    PQ<Item> pq(r-l+1);
    for (k = l; k <= r; k++) pq.insert(a[k]);
    for (k = r; k >= l; k--) a[k] = pq.getmax();
  }


#endif