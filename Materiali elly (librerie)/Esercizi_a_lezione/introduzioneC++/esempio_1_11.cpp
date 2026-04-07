#include<iostream> 
void f(const int&, int&);  

int main(){ 
   int a,b; 
   a=100; 
   b=10; 
   f(a,b); 
   std::cout<< " "<<a<<" "<<b; //stampa 100 11
 } 

void f(const int& data, int& datb){ 
   datb++; 
   std::cout<<data<<" "<<datb; //data si può solo leggere
}
