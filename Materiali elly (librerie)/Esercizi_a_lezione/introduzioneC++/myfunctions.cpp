// file myfunctions.cpp 
#include "myfunctions.h" 

void a( void ) { 
 int x = 25; ++x; } 

void b( void ) { 
	static int x = 50;
	x++;
	std::cout << "local x in b is " << x << std::endl;
}

void c(void) {
	int x = 1;
	x *= 10;
}
