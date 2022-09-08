#include "header.h"


int main()
{

    
    Vector v{};
    v.push_back(6);
    v.push_back(4);
    v.show();

    int a[16] = {15, 1, 6, 3 , 8, 3, 7, 8, 9, 1};

    v.push_back(a, sizeof(a)/sizeof(int));
    v.show();
    v.find_kmax(1);
    v.find_kmax(2);
    v.find_kmax(3);
    v.find_kmax(4);
    v.find_kmax(5);
    v.find_kmax(6);
    v.show();
}