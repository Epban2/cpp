#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "recursion.h"

int main(int argc, char** argv) {
 
  int result;
  int n=12;
  int m=4;
  int i=0;
  int n1 = 12;
  int n2 = 4;
  string s1;

  srand(time(NULL));

  result = factorial(n);
  cout << "fattoriale(" << n << ")="<< result << endl;

  result = gcd(n1,n2);
  cout << "gcd(" << n1 << "," << n2 << ")="<< result << endl;

  s1 = "* + 7 * * 4 6 + 8 9 5";
  result = eval(s1,i);
  cout << "eval(" << s1 << ")="<< result << endl;

  i=0;
  s1 = "+ * 3 4 2";
  result = eval(s1,i);
  cout << "eval(" << s1 << ")="<< result << endl;

  cout << "Fibonacci: ";
  for (i=0; i<45; i++)
	  {
       result = Fibonacci(i);
	   cout << result << " ";
	  }
  cout << endl;

  cout << "Fibonacci_opt: ";
  for (i=0; i<45; i++)
	  {
       result = Fibonacci_opt(i);
	   cout << result << " ";
	  }
  cout << endl;

  cout << "ackermann: ";
  cout << ackermann(3,4) << endl;

  cout << "7 e' pari? :";
  cout << is_even(7) << endl;

  cout << "8 e' pari? :";
  cout << is_even(8) << endl;

  const int Item_array_size=16;
  Item a[Item_array_size];

  for (i=0; i<Item_array_size; i++)
	 {
	  a[i].setkey((int) 1000*((1.0*rand()/RAND_MAX)));
	  cout << a[i] << " ";
     }
   cout << endl;

  Item Item_res= max(a, 0, Item_array_size-1);
  cout << "max=" << Item_res.key() << endl;

  result = esponente(n, m);
  cout << "esponente=" <<  result << endl;
  return 0;
}