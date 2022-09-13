#include "header.h"

//вроде работает, 1 раз сработало и все отсортировало
int main()
{
    stud a[4];

    cout << endl << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << endl;
        a[i].show();

    }
    

    cout << "predsort flag" << endl;
    sort_kurs(a, 4);

    cout << endl << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << endl;
        a[i].show();

    }

    sort_status(a, 4);

    cout << endl << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << endl;
        a[i].show();

    }
    


    for (int i = 0; i < 4; i++)
    {
        cout << endl;
        a[i].show();

    }
}