#ifndef ES4
#define ES4

#include <string>
#include <iostream>

using namespace std;

class Persona {

  private:
    string nome, cognome;
    int anni;
  public:
	 Persona(string n = "", string c = "", int a = 0) {
		  nome = n;
		  cognome = c;
		  anni = a;
	  }
	bool operator != (Persona p2) { 
		if ((nome == p2.nome) && (cognome == p2.cognome) && (anni==p2.anni))
			return 0;
		else
			return 1;
		}
	string getInformation();
	void setcognome(string c) { cognome = c; }
};

#endif

