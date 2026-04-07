#include <set>
#include <iostream>

using namespace std;

int main()
{
 set <int> mySet;
 set<int>::iterator it;
 mySet.insert(4);
 mySet.insert(2);
 mySet.insert(4);
 mySet.insert(1);
 mySet.insert(4);
 for ( it = mySet.begin(); it != mySet.end(); it++ )
 {
  cout << *it << endl;
 }

 cout << "s.count(5)=" <<  mySet.count(5) << endl; // number of elements == 5
 
 std::set<int>::iterator itlow, itup;
 mySet.clear();
 for (int i = 1; i<10; i++) mySet.insert(i * 10); // 10 20 30 40 50 60 70 80 90
 itlow = mySet.lower_bound(30);                   //       ^
 itup = mySet.upper_bound(60);                    //                   ^
 std::cout << "itlow= " << *itlow << " itup= " << *itup << std::endl;
 mySet.erase(itlow, itup);                     // 10 20 70 80 90

 it = mySet.find(20);
 mySet.erase(it);
 mySet.erase(mySet.find(80));

 std::cout << "mySet contains:";
 for (std::set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it)
	 std::cout << ' ' << *it;
 std::cout << '\n';
 return 0;
}

