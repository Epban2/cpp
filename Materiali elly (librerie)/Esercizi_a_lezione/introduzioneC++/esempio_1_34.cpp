#include "esempio_1_34.h"

void main() {
	int a = 7;
	char b = 'F';
	myfunc(a, "prova");
	myfunc<float,char>(10.2, b);
}