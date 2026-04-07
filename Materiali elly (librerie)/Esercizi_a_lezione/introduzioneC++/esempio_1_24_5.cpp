#include "esempio_1_24_5_Time.h"

int main()
{
 Time t; // instantiate object t of class Time
 std::cout << "The initial 24H time is ";
 t.print24H();
 std::cout << "\nThe initial standard time is ";
 t.printStandard();
 t.setTime( 13, 27, 6 );
 std::cout << "\n\n24H time after setTime is ";
 t.print24H();
 std::cout << "\nStandard time after setTime is ";
 t.printStandard();
 t.setTime( 99, 99, 99 ); // attempt invalid settings
 std::cout << "\n\nAfter attempting invalid settings:"
 << "\n24H time: ";
 t.print24H();
 std::cout << "\nStandard time: ";
 t.printStandard();
 std::cout << std::endl;
 return 0;
}