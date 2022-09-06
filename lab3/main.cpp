#include "header.h"


int main()
{
    long x = 163;
    bool a = x%2;
    x >>= 1;
    cout << x << " " << a << sizeof (long);

}