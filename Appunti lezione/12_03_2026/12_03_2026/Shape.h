#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <string>
using namespace std;


class Shape { //Classe astratta, poiché contiene un metodo virtual <type> <name>() =0;
protected:
	int width, height; //passa come campi privati alle classi figlie
public: 
	Shape(int a = 0, int b = 0) {
	width = a; height = b;
}
	  virtual int area() const { //Virtual--> implementazione di base, PUò essere sovrascritto dai figli (override)
		  cout << endl << "Parent class area :";
		  return 0;
	  }
	  // !!!!
	  virtual string name() const  = 0 ; // metodo virtuale "puro" (astratto), non ha implementazione (=0) RICHIEDE implementazione nei figli!
	  // SE TALE METODO NON VIENE IMPLEMENTATO NELLA FIGLIA, ANCH'ESSA DIVENTA ASTRATTA (non può quindi essere utilizzata nel main)!
//!!!!
//Nel momento in cui una classe contiene un metodo astratto come questo (anche uno solo), allora 
//essa diventa una classe astratta

};

//FIGLIO DI SHAPE, non serve mettere gli attributi già esistenti
class Rectangle : public Shape {
public: 
	Rectangle(int a = 0, int b = 0) :Shape(a, b) {} //dichiarato il costruttore uguale
	  int area() const override {
		  cout << "class area :";
		  return (width * height);
	  }

	  string name() const override {
		  return "Rectangle";
	  }

};

//FIGLIO DI SHAPE,
class Triangle : public Shape {
public: Triangle(int a = 0, int b = 0) :Shape(a, b) {}
	  int area() const override {
		  cout << "class area :";
		  return (width * height / 2);
	  }

	  string name()  const override {
		  return "Triangle";
	  }
};

inline ostream& operator<< (ostream& os, const Shape& s) {
	os << s.name() << ", " << s.area()<< endl;
	return os;
}
#endif