#include <iostream>

using namespace std;

class Base
{
 public:
	 int i1;
 protected:
	 int i2;
 private:
	 int i3;
};

class D1: private Base
{
 void f() {
	 i1 = 0;
	 i2 = 0;
	 // i3 = 0; // errore
 }
};

class D2 : protected Base
{
	void g() {
		i1 = 0;
		i2 = 0;
		//i3 = 0; // errore
	}
};

class D3 : public Base
{
	void g() {
		i1 = 0;
		i2 = 0;
		//i3 = 0; // errore
	}
};

int main(void)
{
	Base b;
	b.i1 = 1;   
	//b.i2 = 1; //errore
	//b.i3 = 1; //errore

	D1 d1;
	//d1.i1 = 1; //errore
	//d1.i2 = 1; //errore
	//d1.i3 = 1; //errore

	D2 d2;
	//d2.i1 = 1; //errore
	//d2.i2 = 1; //errore
	//d2.i3 = 1; //errore

	D3 d3;
	d3.i1 = 1; 
	//d3.i2 = 1; //errore
	//d3.i3 = 1; //errore

	return 0;
}