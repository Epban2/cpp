#include "recursion.h"

//Esempi di funzioni ricorsive

// Let us print out Items easily
ostream& operator<<(ostream& s, const Item& i)
  { return s << i.key(); }

// calcolo del fattoriale di un numero intero
int factorial(int N)
  {
    if (N == 0) return 1;
    return N*factorial(N-1);
  }  

// calcolo del massimo comun divisore tra due numeri interi m e n con m>=n
int gcd(int m, int n)
  {
    if (n == 0) return m;
    return gcd(n, m % n);
  }  

// valutazione di espressioni in notazione prefissa
int eval(string s, int &i)
  { int x = 0;
    while (s[i] == ' ') i++;
    if (s[i] == '+')
      { i++; return eval(s,i) + eval(s,i); }
    if (s[i] == '*')
      { i++; return eval(s,i) * eval(s,i); }
    while ((s[i] >= '0') && (s[i] <= '9')) 
      x = 10*x + (s[i++]-'0'); 
    return x;
  }

// calcolo dei numeri della sequenza di Fibonacci
int Fibonacci(int i)
  { 
    if (i < 1) return 0;
    if (i == 1) return 1;
    return Fibonacci(i-1) + Fibonacci(i-2);
  }


//versione più efficiente che memorizza risultati calcolati in precedenza
int Fibonacci_opt(int i)
{ static int knownF[100]; //in C++ valori automaticamente inizializzati a 0
  if (knownF[i] != 0) return knownF[i];
  int t = i;
  if (i < 0) return 0;
  if (i > 1) t = Fibonacci_opt(i-1) + Fibonacci_opt(i-2);
  return knownF[i] = t;
}

// calcolo dei numeri della sequenza di ackermann
// A(m,n) = -1        se m<0 oppure n <0
// A(m,n) = n+1       se m=0
// A(m,n) = A(m-1,1)  se n=0
// A(m,n) = A(m-1, A(m,n-1)) altrimenti
int ackermann(int m, int n)
{
	if (m < 0 || n < 0) return -1; /* ack non e' definita per interi negativi! */

	if (m == 0) return n + 1;
	else if (n == 0) return ackermann(m - 1, 1);
	else return ackermann(m - 1, ackermann(m, n - 1));
}

// funzione per determinare se un numero è pari
int is_even(unsigned int n)
{
	if (n == 0) return 1;
	 else return(is_odd(n-1));
}

// funzione per determinare se un numero è dispari
int is_odd(unsigned int n)
{
	return (!is_even(n));
}

// funzione per calcolare il massimo in un array
Item max(Item a[], int l, int r)
  {
    if (l == r) return a[l];
    int m = (l+r)/2; 
    Item u = max(a, l, m);
    Item v = max(a, m+1, r);
    if (u.key() > v.key()) return u; else return v;
  }

int somma(int x, int y)
  /* Calcola la somma tra due interi sfruttandone la definizione induttiva. */
	//  somma(x,y) = x                  se y=0
	//  somma(x,y) = 1 + somma(x, y-1)  se y>0
{
  int prec;

  if (y == 0)
    return x;
  else {
    prec = somma(x, --y);
    return ++prec;
  }
}  /* somma */


int prodotto(int x, int y)
  /* Calcola il prodotto tra due interi sfruttandone la definizione induttiva.
   */
	//  prodotto(x,y) = 0                          se y=0
	//  prodotto(x,y) = somma(x, prodotto(x,y-1))  se y>0     
{
  if (y == 0)
    return 0;
  else
    return (somma(x, prodotto(x, --y)));
}  /* prodotto */


int esponente(int x, int y)
//  esponente(x,y) = 1                               se y=0
//  esponente(x,y) = prodotto(x, esponente(x,y-1))   se y>0     x^y = x * x^(y-1) 
{
  /* Calcola l'elevamento a potenza tra due interi sfruttandone la definizione
     induttiva. */
  if (y == 0)
    return 1;
  else
    return (prodotto(x, esponente(x, --y)));
}  /* esponente */


