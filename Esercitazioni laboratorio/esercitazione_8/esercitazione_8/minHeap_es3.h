#ifndef MIN_HEAP_H
#define MIN_HEAP_H

class Item {
public:
	int valore;
	int indiceArrayProvenienza;
	int indiceSuccessivo;

	Item(int v = 0, int p = 0, int s = 0) { valore = v; indiceArrayProvenienza = p; indiceSuccessivo = s; }

};


template <class Item>
void exch(Item& A, Item& B)
{
	Item t = A; A = B; B = t;
}


void fixUp(Item a[], int k)
{ //se il padre e' piu' grande, porto su il figlio (e' piu' piccolo del padre)
	while (k > 1 && a[k].valore < a[k / 2].valore) //figlio < padre, scambio
	{
		exch(a[k], a[k / 2]); k = k / 2;
	}
}


void fixDown(Item a[], int k, int N) //a=vettore posizionale , k = indice elemento padre da confrontare con i figli, N = dimensione array
{
	while (2 * k <= N)
	{
		int j = 2 * k; //indice figli
		if (j < N && a[j].valore > a[j + 1].valore) j++;//j diventa l'indice del figlio minore (destro o sinistro)
		if (a[k].valore <= a[j].valore) break; //se il padre e' minore del figlio piu' piccolo, allora e' gia' ordinato
		//siccome non siamo usciti col break, e' da effettuare lo scambio padre-figlio e memorizzare l'indice del figlio come elemento da controllare (k)
		exch(a[k], a[j]); k = j;
	}
}

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

#endif