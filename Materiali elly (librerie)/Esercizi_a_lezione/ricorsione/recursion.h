#ifndef RECURSION_H
#define RECURSION_H

#include <iostream>
#include <string>
using namespace std;


// Your basic int type as an object.
class Item {
private:
  int val;
public:
  Item(int input=0) { val = input; }
  // The following is for those times when we actually
  //   need to get a value, rather than compare objects.
  int key() const { return val; }
  void setkey(int n) { val =n; }
};

// Let us print out Items easily
ostream& operator<<(ostream& s, const Item& i);

int factorial(int N);

int gcd(int m, int n);

int eval(string s, int &i);

int Fibonacci(int i);

int Fibonacci_opt(int i);

Item max(Item a[], int l, int r);

int esponente(int x, int y);

int ackermann(int m, int n);

int is_even(unsigned int n);

int is_odd(unsigned int n);

#endif