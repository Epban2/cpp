#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "heap-es5.h"

// Let us print out Items easily
ostream& operator<<(ostream& s, const Item& i)
{
	return s << i.key();
}

int main(int argc, char** argv) {
    srand(time(NULL));
    
    PQ<Item> pq(1000);
	int cur_time_to_complete = -1;
	int cur_max_priority = -1;

	for (int time=0;time<1000;time++)
	{
		if (cur_time_to_complete == 0)
		{
			Item completed = pq.getmax();
			cur_max_priority = 0;
			cur_time_to_complete = -1;
			cout << "time=" << time << " completed task: " << completed << endl;
			if (!pq.empty())
			{
				Item max = pq.getmax();
				cur_time_to_complete = max.tempo;
				cur_max_priority = max.key();
				pq.insert(max);
				cout << "time=" << time << " new task with highest priority: " << max << "    time_left_to_complete (previous task)=" << cur_time_to_complete << endl;
			}
		}

	  if (rand()%100<30)
	  {
		  int priority = (int) rand() % 100+1;
		  int total_time = (int) rand() % 10+1;
		  Item newitem(priority,total_time);
		  if (priority>cur_max_priority)
		  {
			  if (!pq.empty())
			  {
			   Item max = pq.getmax();
			   max.tempo = cur_time_to_complete;
			   cout << "time=" << time << " new task with highest priority: " << newitem << "    time_left_to_complete (previous task)=" << cur_time_to_complete << endl;
			   pq.insert(max);
			  }
			  cur_time_to_complete = total_time;
			  cur_max_priority = priority;
		  }
		  cout << "time=" << time << " new task: " << newitem << " time_to_complete=" << total_time << endl;
		  pq.insert(newitem);
	  }
	
	  if (cur_time_to_complete>=1)
	   cur_time_to_complete--;
	  
	}
	
    return 0;
}