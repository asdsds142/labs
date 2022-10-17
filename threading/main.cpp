#include "matrix.h"
#include "time_check.h"


int main()
{
    time_checker main_checker {"main"};

    Matrix a{521};
    Matrix b{521};
    Matrix c{521};

    c = a*b;

}