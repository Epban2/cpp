#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <time.h>  // Used by timing functions

#include <iostream>
using namespace std;


static string maxKey = "";

class Item {
private:
	string name;
	string city;
	int priority;
public:
	Item(string n, string c, int p) { name = n; city = c; priority = p; }
	Item() { name = maxKey; }
	// The following is for those times when we actually
	//   need to get a value, rather than compare objects.
	int null()
	{
		return name == maxKey;
	}
	string key() const { return name; }
	string getcity()  const { return city; }
	int getpriority()  const { return priority; }
	bool operator<(const Item &other) const {
		if (priority < other.getpriority()) return true;
		else return false;
	}
	void show(ostream& os = cout)
	{
		os << name << " " << "("<< city <<")  ";
	}
};
 
// Let us print out Items easily
inline ostream& operator<<(ostream& s, const Item& i)
{
	return s << i.key() << " " << "(" << i.getcity() << ")";
}
#endif