#include "matrix.h"
#include "time_check.h"


int main()
{
    time_checker main_checker {"main"};

    Matrix a{3521};
    Matrix b{3521};
    Matrix c{3521};

    c = a*b;

}