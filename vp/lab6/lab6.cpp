#include "header.h"



stud::stud()
{
    string first, last, father;

    cout << "\nВведите 'Фамилия, Имя, отчество студента'" << endl;
    cin >> first >> last >> father;

    this->name.append(first);
    this->name.append(" ");
    this->name.append(last);
    this->name.append(" ");
    this->name.append(father);
    this->name.append(" ");

    cout << "Итоговое имя " << this->name << endl;

    cout << "\nВведите курс" << endl;
    while (1)
    {
        int a;
        cout << "looptester" << endl;
        cin >> a;
        if (a < 1 || a > 6) // Допустим 6 курсов на всякий случай, но в случае чего можно быстро заменить циферку и делать от 4
        {
            cout << "Введенный курс неправильного формата, попробуйте еще раз" << endl;
            continue;
        }
        this->kurs = a;
        break;
    }
    cout << "\nВведите количество оценок" << endl; 
    while (1)
    {
        int a;
        cout << "looptester" << endl;
        cin >> a;
        if (a < 1) // Допустим 6 курсов на всякий случай, но в случае чего можно быстро заменить циферку и делать от 4
        {
            cout << "Введенные данные неправильного формата, попробуйте еще раз" << endl;
            cin.clear();
            continue;
        }
        this->scorenumber = a;
        break;
    }
    p = new int[scorenumber];
    cout << "\nВведите оценки" << endl;
    for (int i = 0; i < this->scorenumber; i++)
    {
        int a;
        cin >> a;
        if (a < 1 || a > 10)
        {
            cout << "Введенная оценка неправильного формата, попробуйте еще раз " << endl;
            i -= 1;
            continue;
        }
        this->p[i] = a;

    } // доделать
    cin.clear();
    

    
}


short getstatus(stud s)
{
    short st = 5;
    for (int i = 0; i < s.scorenumber; i++)
    {
        if (s.p[i] == 1 || s.p[i] == 2 || s.p[i] == 3)
        {
            st = 2;
            break;
        }

        if ((s.p[i] == 4 || s.p[i] == 5) && st < 4)
        {
            st = 3;
            continue;
        }

        if ((s.p[i] == 6 || s.p[i] == 7 || s.p[i] == 8) && st < 5)
        {
            st = 4;
            continue;
        }
    }

    s.status = st;
    return st;
}



void sort_kurs(stud a[], int number)
{  
    stud tmp;

    for (int i = 0; i < number; i++)
    {
        int n = 0;
        do
        {
            if (a[i].kurs < a[i+1].kurs)
            {
                tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
                n += 1;
            }
            if (a[i].kurs == a[i+1].kurs && a[i].status < a[i+1].status)
            {
                tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
                n += 1;
            }
        } while (n != 0);   
    }
}




