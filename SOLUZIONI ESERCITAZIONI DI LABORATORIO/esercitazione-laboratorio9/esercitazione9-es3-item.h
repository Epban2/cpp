#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <time.h>  // Used by timing functions

#include <iostream>
#include <string>
using namespace std;

static int maxKey = 1000;
typedef int Key;

class Item 
  { 
    private:
      string nome;
	  int voto;
	  string email;
	  Key keyval;
    public:
      Item(string n="", int v=0, string e="", Key k=maxKey) 
        { 
		  nome = n;
		  voto = v;
		  email = e;
		  keyval = k; 
	  } 
      Key key() const
        { return keyval; }
      int null()
        { return keyval == maxKey; } 
	  string getnome()
	  {
		  return nome;
	  }
	  int getvoto()
	  {
		  return voto;
	  }
      void setvalues(string n, int v, string e)
	  {
		  nome = n;
		  voto = v;
		  email = e;
	  }
      void show(ostream& os = cout)
        { os << keyval  << endl; }
   };

inline ostream& operator<<(ostream& os, const Item& x)
  { return os << x.key(); }

  
#endif