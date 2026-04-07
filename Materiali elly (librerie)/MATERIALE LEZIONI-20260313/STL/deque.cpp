#include <iostream>
#include <deque>

using namespace std;

int main()
{
 deque< double > values;

 values.push_front( 2.2 );
 values.push_front( 3.5 );
 values.push_back( 1.1 );
 
 cout << "values contiene: ";
 for ( int i = 0; i < values.size(); ++i )
  cout << values[ i ] << ' ';
 
 values.pop_front();
 cout << "\nDopo pop_front() values contiene: ";
 for (int i = 0; i < values.size(); ++i)
	 cout << values[i] << ' ';

 values[ 1 ] = 5.4;
 cout << "\nDopo values[ 1 ] = 5.4, values contiene: ";
 for (int i = 0; i < values.size(); ++i)
	 cout << values[i] << ' ';
 cout << endl;
 return 0;
}