#define N 5 
#include<iostream>
int RicercaLineare(int V[N], int D) { 
  int trovato=0; 
   for (int i=0; i<N; i++) 
        if (V[i]==D) trovato=1; 
   return trovato; } 

/*
void modifica(int V[N]) {
	V[1] = 100;
}
*/


int main() { 
    int MioVettore[N]={1,6,7,3,21}; 
    int MioElemento; 
    std::cout << "Inserire l'elemento da cercare" << std::endl; 
    std::cin >> MioElemento; 
     if (RicercaLineare(MioVettore,MioElemento)) 
        std::cout << MioElemento << " trovato" << std::endl; 
     else std::cout << MioElemento << " non trovato" << std::endl; 

	 /*modifica(MioVettore);
	 for (int i = 0; i < N; i++)
		 std::cout << MioVettore[i] << " ";
		 */
}
