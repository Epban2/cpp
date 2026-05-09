#ifndef MINHEAP_H
#define MINHEAP_H

class Item {
private:
	int val;
public:
	int array_id;
	int next_element;
	Item(int v = 0, int a = 0, int n = 0) { val = v; array_id = a; next_element = n; }
	// The following is for those times when we actually
	//   need to get a value, rather than compare objects.
	int key() const { return val; }
	bool operator>(const Item& other) const {
		if (val > other.key()) return true;
		else return false;
	}
};



template <class Item>
void exch(Item &A, Item &B)
{ Item t = A; A = B; B = t; }

template <class Item>
void MinHeapfixUp(Item a[], int k)
  {
    while (k > 1 && a[k/2] > a[k])
      { exch(a[k], a[k/2]); k = k/2; }
  }


template <class Item>
void MinHeapfixDown(Item a[], int k, int N)
  {
    while (2*k <= N)
      { int j = 2*k;
        if (j < N && a[j] > a[j+1]) j++;
        if (!(a[k] > a[j])) break;
        exch(a[k], a[j]); k = j;
      }
  }


// heap based priority queue
template <class Item>
class MinHeapPQ
  {
    private:
      Item *pq; 
      int N;
    public:
		MinHeapPQ(int maxN)
        { pq = new Item[maxN+1]; N = 0; }
	  ~MinHeapPQ() { delete[] pq; } // Destructor
      int empty() const
        { return N == 0; }
      void insert(Item item)
        { pq[++N] = item;  MinHeapfixUp(pq, N); }
	  void stampa()
        { for(int i=1;i<=N;i++)
	       cout << pq[i] << " padre: " << pq[i/2] << endl;}
      Item getmin()
        { 
          exch(pq[1], pq[N]); 
		  MinHeapfixDown(pq, 1, N-1);
          return pq[N--]; 
        }
  };


#endif