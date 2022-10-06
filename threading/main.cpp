#include "matrix.h"

int main()
{
    Matrix a{1222};
    Matrix b{1222};
    Matrix c{1222};
    c = a*b;
    c.show();
    
}