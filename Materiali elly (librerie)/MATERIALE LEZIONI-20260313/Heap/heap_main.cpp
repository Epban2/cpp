#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "heap.h"

int main(int argc, char** argv) {
   srand(time(NULL));
    
    aPQ<int> priorityq(10);
	//PQ<int> priorityq(10);

	priorityq.insert(5);
	priorityq.insert(50);
	priorityq.insert(12);
	priorityq.insert(27);
	cout << "priorityq max=" << priorityq.getmax() << endl;
	cout << "priorityq max=" << priorityq.getmax() << endl;


	int i, N = atoi(argv[1]), sw = atoi(argv[2]);
    int *a = new int[N];
    if (sw) 
      for (i = 0; i < N; i++) 
        a[i] = 1000*((1.0*rand()/RAND_MAX));
    else 
      { i = 0; 
	    while (i<N) {
			  cin >> a[i];
			  i++;
			  }
	  }

  cout << "PQsort:"<< endl;
  PQsort(a, 0, N-1);

  for (i = 0; i < N; i++) cout << a[i] << " ";
  cout << endl;

  
  return 0;
}