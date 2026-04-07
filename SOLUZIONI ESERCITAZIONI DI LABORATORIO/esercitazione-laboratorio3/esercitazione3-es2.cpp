//Scrivere una funzione template: template <typename T> T most_common(T *A, int size)
//che accetti in ingresso un array di elementi di tipo generico T e la sua dimensione “size” 
//e fornisca in uscita l’elemento dell’array ripetuto più volte. 
//Se vi sono due o più elementi con lo stesso numero di ripetizioni massimo la funzione restituisce il primo elemento trovato.

#include "esercitazione3-es2.h"

int main()
{
  int int_array[10]={1,2,3,4,3,6,7,3,9,10};
  string string_array[6] = { "pippo", "topolino", "minni", "paperino", "pippo", "pippo" };
  cout << "most common int_array[10]={1,2,3,4,3,6,7,3,9,10}= " << most_common<int>(int_array,10) << endl;
  cout << "most common string_array[6] = { \"pippo\", \"topolino\", \"minni\", \"paperino\", \"pippo\", \"pippo\" }= " << most_common<string>(string_array, 6) << endl;

}