#include <iostream>
using namespace std;

class Complex
{
 public:
	 Complex(float r = 0.0, float i = 0.0) { re = r; im = i; };
     float getRe() const { return re; };
	 float getIm() const { return im; };
     void SetRe(float r) { re=r; };
     void SetIm(float i) { im=i; };
     void show();
	 Complex operator+(Complex op2); // esempio di operatore binario come funzione membro
	 Complex operator++(); // esempio di operatore unario prefisso come funzione membro
 private:
	 float re;
	 float im;
};


void Complex::show() {
	cout << endl << "re: " << re << " im: " << im;
}

Complex Complex::operator+(Complex op2) {
	Complex tmp;
	tmp.re = re + op2.re;
	tmp.im = im + op2.im;
	return tmp;
}

Complex Complex::operator++() {
	re++;
	im++;
	return *this;
}

// esempio di operatore "-" come funzione non-membro
Complex operator-(Complex op1, Complex op2) {
	Complex tmp;
	tmp.SetRe(op1.getRe() - op2.getRe());
	tmp.SetIm(op1.getIm() - op2.getIm());
	return tmp;
}

// esempio di operatore "<<" come funzione non-membro
ostream& operator<<(ostream& os, Complex op)
{
	os << op.getRe();
	if (op.getIm() > 0)
		os << " + ";

	os << op.getIm()<< "i";

	return os;
}

int main() {
	Complex c1, c2(1, 1), c3(4, 5);

	c1.show(); 
	c2.show(); cout << "  " << c2;
	c3.show();

	c1 = c2 + c3;
	c1.show();
	c1 = c2 - c3;
	c1.show();

	++c1;
	c1.show();
	c2 = ++c1;
	c2.show();

	return 0;
}