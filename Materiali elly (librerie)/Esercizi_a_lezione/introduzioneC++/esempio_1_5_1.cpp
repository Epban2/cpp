#include <iostream>
void a( void ); // function prototype 
void b( void ); // function prototype 
void c( void ); // function prototype 

int main() { 
 int x = 5; // local variable to main 
 a(); // a has automatic local x 
 b(); // b has static local x 
 c(); // c has automatic local x 
 b(); // b has static local x 
 std::cout << "local x in main is " << x << std::endl; 
return 0; } 

void a( void ) { 
 int x = 25; // initialized each time a is called 
 ++x; } 

void b( void ) {
 static int x = 50;  
 x++;
 std::cout << "local x in b is " << x << std::endl;
}
 
void c( void ) {
 int x = 1;
 x *= 10; }
