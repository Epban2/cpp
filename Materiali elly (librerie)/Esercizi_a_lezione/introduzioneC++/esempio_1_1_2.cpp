#include <iostream> 

int main() 
{ 
 int x= 10;
 int z = 35;
 std::cout << x << std::endl; 
 
 { 
  int x= 20;
  int y = 5;
  std::cout << x << " " << y << " " << z << std::endl; 
 }
 
 std::cout << x << std::endl; 
 //std::cout << y << std::endl;  //errore

 return 0;
}
