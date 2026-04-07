#include <cstdlib>
#include <iostream>
#include <ctime>
int main() {
	srand(std::time(nullptr)); 
	int random_variable = rand();
	std::cout << "RAND_MAX=" << RAND_MAX << std::endl;
	std::cout << "numero casuale tra 0 e RAND_MAX: " << random_variable << std::endl;
	int n = 10;
	std::cout << "numero casuale tra 0 e (n-1): " << rand()%n << std::endl;
	int a = 10;
	int b = 30;
	std::cout << "numero casuale tra a e b: " << a+rand()%(b-a+1) << std::endl;
}