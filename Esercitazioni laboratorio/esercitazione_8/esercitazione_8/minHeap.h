#ifndef MIN_HEAP_H
#define MIN_HEAP_H

template <class Item>
void exch(Item& A, Item& B)
{
	Item t = A; A = B; B = t;
}


template <class Item>
void fixUp(Item a[], int k)
{ //se il padre e' piu' grande, porto su il figlio (e' piu' piccolo del padre)
	while (k > 1 && a[k] < a[k / 2]) //figlio < padre, scambio
	{
		exch(a[k], a[k / 2]); k = k / 2;
	}
}


template <class Item>
void fixDown(Item a[], int k, int N) //a=vettore posizionale , k = indice elemento padre da confrontare con i figli, N = dimensione array
{
	while (2 * k <= N)
	{
		int j = 2 * k; //indice figli
		if (j < N && a[j] > a[j + 1]) j++;//j diventa l'indice del figlio minore (destro o sinistro)
		if (a[k] <= a[j]) break; //se il padre e' minore del figlio piu' piccolo, allora e' gia' ordinato
		//siccome non siamo usciti col break, e' da effettuare lo scambio padre-figlio e memorizzare l'indice del figlio come elemento da controllare (k)
		exch(a[k], a[j]); k = j;
	}
}


// heap based priority queue
template <class Item>
class PQ
{
private:
	Item* pq; //array (vettore posizionale)
	int N;
public:
	PQ(int maxN)
	{
		pq = new Item[maxN + 1]; N = 0;
	}
	~PQ() { delete[] pq; } // Destructor
	int empty() const
	{
		return (N == 0 ? 1 : 0);
	}
	void insert(Item item)
	{
		pq[++N] = item;  fixUp(pq, N); //inserimento in coda e richiamo fixup
	}
	Item getmin()
	{
		exch(pq[1], pq[N]); // porto la radice in ultima posizione
		fixDown(pq, 1, N - 1); //metto a posto l'albero
		return pq[N--]; //ritorno la vecchia radice ossia il valore piu' piccolo dell'heap e poi diminuisco N (tagliando fuori questo elemento)
	}
};



template <class Item>
void PQsort(Item a[], int l, int r)
{
	int k;
	PQ<Item> pq(r - l + 1);
	for (k = l; k <= r; k++) pq.insert(a[k]);
	for (k = r; k >= l; k--) a[k] = pq.getmin();
}


#endif