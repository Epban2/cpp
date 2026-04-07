#include <iostream>

int MinimoInteri(int i, int j); // prototipo della funzione

int main() 
{ int M; 
  int A=5, B=6; 
  M=MinimoInteri(A,MinimoInteri(B,3)); 
  std::cout << "M=" << M << std::endl; 
} 

int MinimoInteri(int i, int j) { 
  if (i<j) return i; else return j; 
}
