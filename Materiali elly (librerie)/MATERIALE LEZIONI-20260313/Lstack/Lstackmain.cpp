// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for the linked stack class

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "lstack.h"

#include "LStackTest.h"

// Funzione per la valutazione di espressioni in notazione polacca postfissa 
// Esempio: espressione  5*( ( ( 9 + 8) * (4 * 6) ) + 7 )             = 2075
// notazione postfissa:  5 9 8 + 4 6 * * 7 + *
// soluzione per espressioni che contengono esclusivamente operazioni di somma e moltiplicazione tra interi.
// Si procede valutando l'espressione da sinistra verso destra:
// •	Quando si incontra un operando si esegue una operazione di push nella pila
// •	Quando si incontra un operatore si eseguono due operazioni di pop per estrarre gli operandi, si esegue l’operazione tra i due operandi e poi si esegue una push del risultato intermedio sulla pila
int PostFixEvaluation(string s)
{
	LStack<int> Stemp;
	int eval = 0;
	for (int i=0; i<s.length();i++)
	{
		if (s[i] == '+')
			Stemp.push(Stemp.pop() + Stemp.pop());
		if (s[i] == '*')
			Stemp.push(Stemp.pop() * Stemp.pop());
		if ((s[i] >= '0') && (s[i] <= '9'))
			Stemp.push(0);
		while ((s[i] >= '0') && (s[i] <= '9'))
			Stemp.push(10*Stemp.pop() + (s[i++]-'0'));
	}
	eval = Stemp.pop();
	return eval;
}

// Driver class for list implementations

// Main routine for array-based list driver class
int main(int argc, char** argv) {
  // Declare some sample lists
  LStack<Item> S1,S2;
 
  Item temp;

  // Test a bunch of stack operations
  if (S1.length() > 0) {
    temp = S1.pop();
    cout << "Top is " << temp << endl;
  }
  else cout << "Nothing in stack\n";
  Item temp1(10);
  S1.push(temp1);
  cout << "Pushed " << temp1 << endl;
  Item temp2(20);
  S1.push(temp2);
  cout << "Pushed " << temp2 << endl;
  Item temp3(15);
  S1.push(temp3);
  cout << "Pushed " << temp3 << endl;
  cout << "Size is " << S1.length() << endl;

  Lstackprint<Item>(S1);
  cout << endl;

  if (S1.length() > 0) {
    temp = S1.pop();
    cout << "Popped " << temp << endl;
  }
  else cout << "Nothing in stack\n";
  cout << "Popping elements" << endl;
  while(S1.length() > 0) {
    temp = S1.pop();
    cout << temp << " ";
  }
  cout << endl;
  if (S1.length() > 0) {
    temp = S1.pop();
    cout << "Top is " << temp << endl;
  }
  else cout << "Nothing in stack\n";
  cout << "Size is " << S1.length() << endl;
  S1.clear();
  cout << "Size is " << S1.length() << endl;

  S1.push(Item(1));
  S1.push(Item(2));
  S1.push(Item(3));
  cout << "S1: ";
  Lstackprint<Item>(S1);
  cout << endl;

  S2.push(Item(10));
  S2.push(Item(11));
  S2.push(Item(12));
  S2.push(Item(13));
  cout << "S2: ";
  Lstackprint<Item>(S2);
  cout << endl;

  LstackTransfer<Item>(S1, S2);
  cout << "S2: ";
  Lstackprint<Item>(S2);
  cout << endl;

  string postfix = "5 9 8 + 4 6 * * 7 + *";
  //string postfix = "2 20 + 4 3 * * 1 +";
  cout << "Postfix evaluation of " << postfix << " is " << PostFixEvaluation(postfix) << endl;

  cout << "That is all.\n\n";
  return 0;
}