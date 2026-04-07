// es conversione da notazione infissa a polacca inversa

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "lstack.h"
#include "lqueue.h"
#include "es2_LStackTest.h"


// Main routine
int main(int argc, char** argv) {
 
  LStack<Item> S;
  Item temp;
  LQueue<Item> Q;

  //string infissa = "(3+4)*(2-3)/(1+5)";
  string infissa = "3+(4-3*(2/5))";
  
  for (int i=0; i<infissa.length(); i++)
  {
	  if (isdigit(infissa[i]))
	  {
		  Item el(infissa[i]);
		  Q.enqueue(el);
		  cout << "queue:";
		  Lqueueprint(Q);
		  cout << endl;
	  }
	  else if ((infissa[i] == '+') || (infissa[i] == '-') || (infissa[i] == '/') || (infissa[i] == '*') || (infissa[i] == '('))
	  {
		  Item el(infissa[i]);
		  S.push(el);
		  cout << "stack:";
		  Lstackprint(S);
		  cout << endl;
	  }
	  else if (infissa[i] == ')')
	  {
		  do {
			  temp = S.pop();
			  if (temp.key() != '(') Q.enqueue(temp);
		  } while (temp.key() != '(');
		  cout << endl;
		  cout << "queue:";
		  Lqueueprint(Q);
		  cout << endl;
		  cout << "stack:";
		  Lstackprint(S);
		  cout << endl;
	  }
  }

  while (S.length()>0)
  {
	  temp = S.pop();
	  Q.enqueue(temp);
  }

  cout << endl;
  Lqueueprint(Q);
 
  cout << endl << "That is all.\n\n";
  return 0;
}