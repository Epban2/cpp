#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

//template < class T > void printList( list< T > &listRef );
void printList(list< int >& listRef);

int main()
{
 list< int > values, otherValues;
 
 values.push_front( 1 );
 values.push_front( 2 );
 values.push_back( 4 );
 values.push_back( 3 );

 cout << "values contiene: ";
 printList( values );
 values.sort();
 cout << "\nvalues dopo sort() contiene: ";
 printList( values );

 otherValues.insert( otherValues.begin(), values.begin(), values.end() );
 cout << "\notherValues contiene: ";
 printList( otherValues );

 values.merge( otherValues );
 cout << "\nDopo merge():\n values contiene: ";
 printList( values );
 cout << "\n otherValues contiene: ";
 printList( otherValues );

 values.pop_front();
 values.pop_back(); // per tutti i container sequenziali
 cout << "\nDopo pop_front() e pop_back() values contiene:\n";
 printList( values );

 values.unique();
 cout << "\nDopo unique() values contiene: ";
 printList( values );

 // il metodo swap() e' disponibile in tutti i container
 values.swap( otherValues );
 cout << "\nDopo swap:\n values contiene: ";
 printList( values );
 cout << "\n otherValues contiene: ";
 printList( otherValues );

 //values.push_back(17);
 values.assign( otherValues.begin(), otherValues.end() );
 cout << "\nDopo assign() values contiene: ";
 printList( values );

 values.merge( otherValues );
 cout << "\nvalues contiene: ";
 printList( values );
 values.remove( 4 );
 cout << "\nDopo remove( 4 ) values contiene: ";
 printList( values );
 cout << endl;

 list<int>::iterator it= values.begin();
 it++;
 //it=values.insert(it, 10);
 values.insert(it, 10);
 values.insert(it, 6);
 cout << "values contiene: ";
 printList(values);

 /* cancellazione elementi lista uno dopo l'altro con erase */
 list<int>::iterator it_values = values.begin();
 while ( it_values != values.end()) 
 {
	 it_values = values.erase(it_values);
	 //values.erase(it_values); // ! errore it_values dopo erase è invalidato 
 }
 cout << endl << "values contiene: ";
 printList(values);


 return 0;
}

/*
template < class T >
void printList( list< T > &listRef )
{
 if ( listRef.empty() )
  cout << "La list e' vuota";
 else {
	 // typename obbligatorio (almeno nelle versioni più avanzate dello standard) ogni volta che un tipo (in questo caso l'iteratore) dipende da un parametro di template
	 for (typename list<T>::iterator it = listRef.begin(); it != listRef.end(); it++) {
		 cout << *it << " ";
	 }
 }
}
*/

void printList(list<int>& listRef)
{
	if (listRef.empty())
		cout << "La list e' vuota";
	else {
		for (list<int>::iterator it = listRef.begin(); it != listRef.end(); it++) {
			cout << *it << " ";
		}
	}
}

