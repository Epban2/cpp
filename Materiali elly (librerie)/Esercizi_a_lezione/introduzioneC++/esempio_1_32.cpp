#include "esempio_1_32.h"

int main()
{
double darray[3] = { 1.0, 2.2, 3.2 };
double dsum = sumVector(darray, 3);
cout << "dsum=" << dsum << endl;

int iarray[5] = { 1,5,6,2,8 };
int isum = sumVector(iarray, 5);
cout << "isum=" << isum << endl;
return 0;
}