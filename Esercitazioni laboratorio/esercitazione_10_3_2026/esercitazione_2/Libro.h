#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <string>
using namespace std;

class Libro
{
public:
	Libro();
	Libro(string, int);
	string getTitolo();
	int getPagine();
	void setTitolo(string titolo);
	void setPagine(int pagine);
	void printLibro();
	//###
	// operator
	void operator+ (Libro l2) {
		this->pagine += l2.pagine;
	};
	//friend così posso usare l.titolo ecc.. altrimenti avrei dovuto usare i getter
	friend ostream& operator<< (ostream& os, const Libro& l); //consente di fare cout<< libro
	//ritorna un oggetto ostream ossia l'uscita video del terminale per stampare

	bool operator== (const Libro l2) const;

private:
	string titolo;
	int pagine;
};

#endif 
