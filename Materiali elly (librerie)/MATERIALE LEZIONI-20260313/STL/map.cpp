#include <iostream>
using namespace std;
#include <map>

int main()
{
 map <int, double> myMap;
 map<int, double>::iterator it;
 // Format: insert(pair<type1,type2>(key, value))

 //pair<int, double> pippo(3, 5.6);
 //myMap.insert(pippo);

 typedef pair<int,double> MyPair;
 myMap.insert(MyPair(1, 4.7));
 myMap.insert(MyPair(3, 8.5));
 myMap.insert(MyPair(4, 9.0));
 myMap[6] = 2.5;
 // Accessing the data using a key
 cout << "myMap[4] = " << myMap[4] << endl;
 // Traversing all elements
 for ( it = myMap.begin(); it != myMap.end(); it++)
 {
  cout << (*it).first << " " << (*it).second << endl;
 }

 it = myMap.find(4);
 if (it != myMap.end())
	 cout << "element with key 4 : "<< (*it).second << endl;
 else
	 cout << "Key not found." << endl;

 /*
 myMap.erase(4);
 // Traversing all elements
 for (it = myMap.begin(); it != myMap.end(); it++)
 {
	 cout << (*it).first << " " << (*it).second << endl;
 }
 */
}