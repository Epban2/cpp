#include <iostream> 
int f(int &); 
void main(){ 
int dato=2; 
std::cout<<f(dato)<<std::endl; //stampa 9 
std::cout<<dato<<std::endl; //stampa 3 
} 

int f(int & num){ 
   num=num+1; 
   return num*num;
}
