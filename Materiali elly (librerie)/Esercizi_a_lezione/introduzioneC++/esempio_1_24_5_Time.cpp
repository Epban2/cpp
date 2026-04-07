#include "esempio_1_24_5_Time.h"

// Time constructor initializes each data member to zero.
// Ensures all Time objects start in a consistent state.
Time::Time() { hour = minute = second = 0; }

// Set a new Time value using 24H time. Perform validity
// checks on the data values. Set invalid values to zero.
void Time::setTime( int h, int m, int s )
{
hour = ( h >= 0 && h < 24 ) ? h : 0;
minute = ( m >= 0 && m < 60 ) ? m : 0;
second = ( s >= 0 && s < 60 ) ? s : 0;
}

// Print Time in 24H format
void Time::print24H()
{
std::cout << ( hour < 10 ? "0" : "" ) << hour << ":"
<< ( minute < 10 ? "0" : "" ) << minute;
}

// Print Time in standard format
void Time::printStandard()
{
std::cout << ( ( hour == 0 || hour == 12 ) ? 12 : hour % 12 )
<< ":" << ( minute < 10 ? "0" : "" ) << minute
<< ":" << ( second < 10 ? "0" : "" ) << second
<< ( hour < 12 ? " AM" : " PM" );
}

