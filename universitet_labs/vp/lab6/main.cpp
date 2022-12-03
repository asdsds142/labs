#include "header.h"

//вроде работает, 1 раз сработало и все отсортировало
int main()
{
    int a = 0;

    cout << "Введите число студентов " << endl;
    cin >> a;

    stud *ptr;
    ptr = new stud[a];
    
    
    cout << endl << endl;
    for (int i = 0; i < a; i++)
    {
        cout << endl;
        ptr[i].show();

    }
    

    cout << "predsort flag" << endl;
    sort_kurs(ptr, a);

    cout << endl << endl;
    for (int i = 0; i < a; i++)
    {
        cout << endl;
        ptr[i].show();

    }

    sort_status(ptr, a);
    cout << "sortstatusflag" << endl;


    cout << endl << endl;
    for (int i = 0; i < a; i++)
    {
        cout << endl;
        ptr[i].show();

    }

    cout << "deleteflag" << endl;
}