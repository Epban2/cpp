#ifndef ES1
#define ES1

#include <iostream>
#include <string>

using namespace std;

class Libro {

private:
	string titolo;
	int pagine;
public:
	Libro(string t = "", int p = 0) {
		titolo = t;
		pagine = p;
	}
	string gettitolo() const { return titolo; }
	int getpagine() const { return pagine; }
	void settitolo(string t) { titolo = t; }
	void setpagine(int p) { pagine = p; }
};

#endif

