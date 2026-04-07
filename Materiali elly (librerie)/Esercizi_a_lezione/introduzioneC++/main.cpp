// file main.cpp 
#include "myfunctions.h" 

int main() { 
int x = 5; // local variable to main 
a(); // a has automatic local x 
b(); // b has static local x 
c(); // c has automatic local x  
b(); // b has static local x 
std::cout << "local x in main is " << x << std::endl; 
return 0; 
} 
