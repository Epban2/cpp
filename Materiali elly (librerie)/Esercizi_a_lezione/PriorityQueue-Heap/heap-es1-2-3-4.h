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
      void insert(Item item)
        { pq[N++] = item; }
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

template <class Item>
bool isHeap(Item arr[], int n)
{
	for (int i = 1; i <= n; i++) 
	{
		// se il figlio sinistro esiste ed e' maggiore del padre esci
		if ((2*i) <= n)
		{
		 if (arr[2 * i] > arr[i])
			return false;
		}

		// se il figlio destro esiste ed ' maggiore del padre esci
		if ((2*i+1) <= n)
		{
		 if (arr[2 * i + 1] > arr[i])
	        return false;
		}
	}
	return true;
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
        { pq[++N] = item;  fixUp(pq, N); 
	  for (int i = 1; i <= N; i++)
		  cout << pq[i] << " ";
	  cout << endl;
	  }

	  void increase_key(int i, Item item)
	    { 
		  cout << "pq[i]=" << pq[i] << endl;
		  if (item < pq[i])
			  cout << "New key must be larger than current key" << endl;
		  else
		  {
			  pq[i] = item;  
			  cout << "pq[i]=" << pq[i] << endl;
			  fixUp(pq, i); 
		  }
		}
      Item getmax()
        { 
          exch(pq[1], pq[N]); 
          fixDown(pq, 1, N-1); 
          return pq[N--]; 
        }
	  Item get_secondbest()
	  {
		  if (N == 2)
			return pq[2];
		  if (pq[2]>pq[3])
		    return pq[2];
		  else
			return pq[3];
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