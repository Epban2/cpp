#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <time.h>  // Used by timing functions

#include <iostream>
using namespace std;

static int maxKey = 1000;
typedef int Key;

class Item 
  { 
    private:
      float info;
    public:
      Key keyval;
      Item() 
        { keyval = maxKey; } 
	  void setinfo(float f) { info = f; }
	  void setkey(int k) { keyval = k; };
	  float getinfo() const { return info; };
      Key key() const
        { return keyval; }
      int null()
        { return keyval == maxKey; }
      void random_element()
        {
		  keyval =  1000*(1.0*rand()/RAND_MAX);  
          info =  1.0*(1.0*rand()/RAND_MAX); 
	    }  
      int scan(istream& is = cin)
        { 
		  is >> keyval >> info; 
		  return !(cin.fail());
	    }
      void show(ostream& os = cout)
        { os << keyval << " " << info << endl; }
   }; 

inline ostream& operator<<(ostream& os, const Item& x)
  { return os << "(" << x.key() << "," << x.getinfo() << ")"; }

  
#endif