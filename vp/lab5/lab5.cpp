#include "header.h"


Matrix::Matrix(int a)
{
    this->i = a;
    this->ptr = new stroka*[i];
    this->pointer = new stroka[i];


    for (int c1 = 0; c1 < this->i; c1++)
    {
        /*stroka a{};
        cout << "flag matrix" << endl;
        this->pointer[c1] = a;
        cout << "flag2 matrix" << endl;*/
        this->ptr[c1] = &this->pointer[c1]; 
    }


    
}

Matrix::stroka::stroka()
{
    cout << "Введите число оценок" << endl;
    int a;
    while (1)
    {
        //cout << "looptester" << endl;
        cin >> a;
        if (a < 0 || a > 25)
        {
            cout << "Введенные данные неверного формата, попробуйте снова" << endl;
            if(char(cin.peek()) == '\n')
                cin.ignore();

            if (cin.fail()) 
            {
                cin.clear(); //Нашел в интернете код который дает защиту от неправильного ввода, пробовал просто писать всякие Cin.clear, считывать оставшееся в строки не работало
                cin.ignore(32767, '\n');
            }
            continue;
        }
        //cout << "a =" << a;
        this->numbersnumber = a;
        //cout << "this numnum = " << this->numbersnumber << endl;
        break;
    }
    p = new int[numbersnumber];

    cout << "Введите оценки" << endl;
    for (int c1 = 0; c1 < numbersnumber; c1++)
    {
        cin >> a;
        if (a < 1 || a > 10)
        {
            cout << "Введенные данные неверного формата попробуйте снова" << endl;
            c1 -= 1;
            if(char(cin.peek()) == '\n')
                cin.ignore();

            if (cin.fail()) 
            {
                cin.clear(); //Нашел в интернете код который дает защиту от неправильного ввода, пробовал просто писать всякие Cin.clear, считывать оставшееся в строки не работало
                cin.ignore(32767, '\n');
            }
            continue;
        }
        this->p[c1] = a;
    }

    calculate_is_bad();
    calculate_string_average();
    
}

//test
void Matrix::show()
{
    cout << endl << endl;
    for (int c1 = 0; c1 < this->i; c1++)
    {
        for (int c2 = 0; c2 < this->ptr[c1]->numbersnumber; c2++)
        {
            cout << this->ptr[c1]->p[c2] << " ";
        }
        cout << "average: " << this->ptr[c1]->average << "    ";
        cout << "Двоечник? " << this->ptr[c1]->is_bad;
        cout << endl;
    }
}

//test
void Matrix::replace_a1_a2(int a1, int a2)
{
    //cout << "replace flag" << a1 << a2 << endl;
    //cout << "replace a1, b1 = " << a1 << " " << a2 << endl;

    stroka *tmp;
    tmp = this->ptr[a1];
    //cout <<"replace bigflag" << tmp << " " << this->ptr[a1] << " " << this->ptr[a2] << endl;
    this->ptr[a1] = this->ptr[a2];
    this->ptr[a2] = tmp;



}


/*double Matrix::calculate_string_average(int index)
{
    cout << "csa start\n";
    double sum = 0;

    for (int c1 = 0; c1 < this->j; c1++)
    {
        sum += this->ptr[index][c1];
    }

    double result = sum/this->numbersnumber[index];

    return result;
}*/

/*
void Matrix::sort()
{
    int d[this->i];
    int cntr = 0;
    cout << "sort flag1" << endl;

    
    for(int c1 = 0; c1 < this->i; c1++)
    {
        if (this->ptr[c1]->is_bad == 0)
        {
            d[cntr] = c1;   //засовываем в массив индексы хороших студентов чтобы сортировать только хороших
            cntr++;
        }
    }

    cout << "sort flag2" << endl;


    int icount = 1;
    while (icount)
    {
        show();
        cout << "sort flag3" << endl;
        icount = 0;
        for (int c1 = 0; c1 < cntr; c1++)
        {
            if (this->ptr[d[c1]]->average < this->ptr[d[c1+1]]->average)
            {
                show();
                cout <<" d[c1], d[c2] = " << d[c1] << d[c1+1];
                int a = d[c1];
                int b = d[c1+1];
                replace_a1_a2(a, b);
                icount += 1;
            }
        }
    }
}*/



void Matrix::sort()
{
    int cntr = 0;
    //cout << "sort flag1" << endl;

    
    for(int c1 = 0; c1 < this->i; c1++)
    {
        if (this->ptr[c1]->is_bad == 0)
        {
            cntr++;
        }
    }

    int d[cntr];
    cntr = 0;
    for(int c1 = 0; c1 < this->i; c1++)
    {
        if (this->ptr[c1]->is_bad == 0)
        {
            d[cntr] = c1;
            cntr++;
        }
    }


    for (int c1 = 0; c1 < cntr-1; c1++)
    {
        int max_index = c1;
        for (int c2 = c1+1; c2 < cntr; c2++)
        {
            if (this->ptr[d[c2]]->average > this->ptr[d[max_index]]->average)
            {
                max_index = c2;
            }
        }
        if (max_index != c1)
        {
            replace_a1_a2(d[c1], d[max_index]);
        }
    }

    //cout << "sort flag2" << endl;

}




double Matrix::stroka::calculate_string_average()
{
    double sum = 0;
    double result = 0;

    for (int i = 0; i < this->numbersnumber; i++)
    {
        sum += this->p[i];
    }
    result = sum/this->numbersnumber;

    this->average = result;
    //cout << "average = " << result << endl;
    return result;
}


bool Matrix::stroka::calculate_is_bad()
{
    bool result = 0;
    for (int i = 0; i < this->numbersnumber; i++)
    {
        int a = this->p[i];
        if (a == 1 || a == 2 || a == 3)
        {
            result = 1;
            break;
        }
    }

    this->is_bad = result;
    //cout << "is_bad = " << result << endl;
    return result;
}



Matrix::~Matrix()
{
    delete this->ptr;
}