#ifndef COMP_H
#define COMP_H

template <class E> 
  void exch(E &A, E &B) 
    { E t = A; A = B; B = t; } 

template <class E>
  int comp(E &A, E &B)
  {
	  if (B < A) return 1;
	  else
		  return 0;
  }

template <class E> 
  void compexch(E &A, E &B) 
    { if (B > A) exch(A, B); }
	
#endif