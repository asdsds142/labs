#include "header.h"


int main()
{

    
    int *a = new int[7];
    int *p =  new int[7];
    a[0] = 5;
    a[1] = 7;
    p = a;
    p[0] = 15;
    cout << a[0];
}