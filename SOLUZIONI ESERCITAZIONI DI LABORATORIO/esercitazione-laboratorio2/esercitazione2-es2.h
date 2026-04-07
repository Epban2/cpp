#ifndef ES2
#define ES2

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
	string getInformation();
	void setcognome(string c) { cognome = c; }
};

#endif

