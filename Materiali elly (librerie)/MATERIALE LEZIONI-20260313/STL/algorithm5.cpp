#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
 vector< char > chars( 10 );
 
 fill( chars.begin(), chars.end(),'5' );
 cout << "Il vettore chars dopo fill() con 5:\n";
 for (vector< char >::iterator it = chars.begin(); it != chars.end(); it++) { cout << *it << " ";}
 cout << endl;

 fill_n( chars.begin(), 5, 'A' );
 cout << "Il vettore chars dopo fill_n() di cinque elementi uguali ad A:\n";
 for (vector< char >::iterator it = chars.begin(); it != chars.end(); it++) { cout << *it << " "; }
 cout << endl;

 return 0;
}
