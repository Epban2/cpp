#include<iostream> 
void f(const int*, const int); 

int main(){ 
 int array[]={0,1,2,3,4,5,6,7,8,9}; 
 f(array,10); 
} 

void f(const int* array, const int dim){ 
   for(int i=0;i<dim;i++){ 
        std::cout<< array[i]; 
 }
   // dim=5; !!ERRORE DI COMPILAZIONE dim è una variabile const
}
