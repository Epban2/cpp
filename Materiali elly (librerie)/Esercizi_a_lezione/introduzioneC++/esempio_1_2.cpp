#include <iostream>
int main() {
    bool a = true;
    bool b = false;
    bool c = 1;
   
    if (a || b) std::cout << " OK";
    if (a && b) std::cout << " Impossibile";
    if (a == b) std::cout << " Impossibile";
    if (a != b) std::cout << " OK";
    if (a == true) std::cout << " OK";
    if (a) std::cout << " OK";
	if (!((a || b) && c)) std::cout << " Impossibile";
	return 0;
}
