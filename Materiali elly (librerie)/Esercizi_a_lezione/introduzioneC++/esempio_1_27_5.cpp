#include <iostream>

using namespace std;
int main()
{
	int n1 = 5;
	int n2 = 1; 
	float res;
	float e=0.0;
	try
	{
		if (n2 == 0)
			throw 'a';
		    //throw n2;  
		else if (n2 == 1)
			throw e;
		else
		{
			res = (float) n1/n2;
			cout << "res = " << res << endl;
		}
	}
	catch (int a)
	{
		cout
			<< "Exception caught: Division by zero: " << a;
	}
	catch (float d)
	{
		cout
			<< "Exception caught: n2=" << n2;
	}
	catch (...)
	{
		cout << "Generic exception caught";
	}
}