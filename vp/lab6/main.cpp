#include "header.h"


int main()
{
    stud a[4];

    for (int i = 0; i < 4; i++)
    {
        cout << endl << endl << endl;
        a[i].show();

    }

    sort_kurs(a, 4);


    for (int i = 0; i < 4; i++)
    {
        cout << endl << endl << endl;
        a[i].show();

    }
}