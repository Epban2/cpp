#include <iostream>
using namespace std;

class Line
{
public:
	void setLength(double len);
	double getLength(void);
	Line(double len);  // This is the constructor
	//Line(double len=3) // This is the constructor with a default argument
	// { length = len; }
	~Line();  // This is the destructor: declaration

private:
	double length;
};

//constructor
Line::Line(double len) {
	cout << "Object is being created, length = " << len << endl;
	length = len;
}

Line::~Line(void)
{
	cout << "Object is being deleted" << endl;
}


void Line::setLength(double len) {
	length = len;
}

double Line::getLength(void) {
	return length;
}

int main() {
	Line line(10.0);
	//Line pippo;

	// get initially set length.
	cout << "Length of line : " << line.getLength() << endl;
	// set line length again
	line.setLength(6.0);
	cout << "Length of line : " << line.getLength() << endl;
	return 0;
}