#include <iostream>

typedef struct{
int hour;
int minute;
int second;
} Time;


void print24H( const Time & ); // prototype
void printStandard( const Time & ); // prototype

int main()
{
  Time dinnerTime; // variable of new type Time
  // set members to valid values
  dinnerTime.hour = 18;
  dinnerTime.minute = 30;
  dinnerTime.second = 0;

  std::cout << "Dinner will be held at ";
  print24H( dinnerTime );
  std::cout << " 24H time,\nwhich is ";
  printStandard( dinnerTime );
  std::cout << " standard time.\n";
  //set members to invalid values
  dinnerTime.hour = 29;
  dinnerTime.minute = 73;
  std::cout << "\nTime with invalid values: ";
  print24H( dinnerTime );
  std::cout << std::endl;
  return 0;
}


// Print the time in 24H format
void print24H( const Time &t )
{
 std::cout << ( t.hour < 10 ? "0" : "" ) << t.hour << ":"
 << ( t.minute < 10 ? "0" : "" ) << t.minute;
}

// Print the time in standard format
void printStandard( const Time &t )
{
 std::cout << ( ( t.hour == 0 || t.hour == 12 ) ? 12 : t.hour % 12 )
 << ":" << ( t.minute < 10 ? "0" : "" ) << t.minute
 << ":" << ( t.second < 10 ? "0" : "" ) << t.second
 << ( t.hour < 12 ? " AM" : " PM" );
}