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

    //можно было сюда приделать защиту от ввода 4 символов с пробелом но я решил нинада,
    //можно потом сделать через getline для всяких имен больше чем из 3 слов но то не критично

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

            if(char(cin.peek()) == '\n')
                cin.ignore();

            if (cin.fail()) 
            {
                cin.clear(); //Нашел в интернете код который дает защиту от неправильного ввода, пробовал просто писать всякие Cin.clear, считывать оставшееся в строки не работало
                cin.ignore(32767, '\n');
            }
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
        if (a < 1 || a > 35) // больше 35 оценок чтобы случайно не тыкнуть огромную циферку и не погубить программу
        {
            cout << "Введенные данные неправильного формата, попробуйте еще раз" << endl;

            if(char(cin.peek()) == '\n')
                cin.ignore();

            if (cin.fail()) 
            {
                cin.clear();
                cin.ignore(32767, '\n');
            }

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
            if(char(cin.peek()) == '\n')
                cin.ignore();

            if (cin.fail()) 
            {
                cin.clear();
                cin.ignore(32767, '\n');
            }

            continue;
        }
        this->p[i] = a;

    } // доделать

    get_status();
    cin.clear();
    

    
}


short stud::get_status()
{
    short st = 5;
    for (int i = 0; i < this->scorenumber; i++)
    {
        if (this->p[i] == 1 || this->p[i] == 2 || this->p[i] == 3)
        {
            st = 2;
            break;
        }

        if (((this->p[i] == 4 || this->p[i] == 5)) && st > 4)
        {
            st = 3;
            continue;
        }

        if (((this->p[i] == 6 || this->p[i] == 7 || this->p[i] == 8)) && st > 5)
        {
            st = 4;
            continue;
        }
    }

    this->status = st;
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




void stud::show()
{
    cout << "ФИО: " << this->name << endl << this->kurs << " Курс" << endl;
    for (int i = 0; i < this->scorenumber; i++)
    {
        cout << this->p[i] << " ";
    }

    cout << "Суммарный статус: " << this->status << endl << endl;
    cout << endl;
}
