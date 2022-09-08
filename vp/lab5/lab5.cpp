#include "header.h"


Matrix::Matrix(int a, int b)
{
    this->i = a;
    this->j = b;
    this->ptr = new int*[this->i];
    this->numbersnumber = new int[i];
    this->is_bad = new bool[i];
    this->average = new double[i];


    cout << "Введите матрицу:" << endl;
    for (int c1 = 0; c1 < this->i; c1++)
    {
        cout << "Введите " << c1+1 << " строку матрицы" << endl;
        this->ptr[c1] = new int[this->j];
        for (int c2 = 0; c2 < this->j; c2++)
        {
            cin >> this->ptr[c1][c2];
            if (this->ptr[c1][c2] != 0)
                this->numbersnumber[c1] += 1;
            if (this->ptr[c1][c2] == 1 || this->ptr[c1][c2] == 2 || this->ptr[c1][c2] == 3)
                this->is_bad[c1] = 1;
        }
        
        this->average[c1] = calculate_string_average(c1);
    }
    cout << "input finished\n";
}



//test
void Matrix::show()
{
    for (int c1 = 0; c1 < this->i; c1++)
    {
        for (int c2 = 0; c2 < this->j; c2++)
        {
            if (this->ptr[c1][c2] != 0) 
                cout << this->ptr[c1][c2] << " ";
        }
        cout << "average: " << this->average[c1] << "    ";
        cout << "Двоечник? " << this->is_bad[c1];
        cout << endl;
    }
}

//test
void Matrix::replace_a1_a2(int a1, int a2)
{
    int *tmp;
    tmp = this->ptr[a1];
    this->ptr[a1] = this->ptr[a2];
    this->ptr[a2] = tmp;
}


double Matrix::calculate_string_average(int index)
{
    cout << "csa start\n";
    double sum = 0;

    for (int c1 = 0; c1 < this->j; c1++)
    {
        sum += this->ptr[index][c1];
    }

    double result = sum/this->numbersnumber[index];

    return result;
}


void Matrix::sort()
{
    int d[this->j];
    int cntr = 0;
    
    for(int c1 = 0; c1 < this->i; c1++)
    {
        if (this->is_bad[c1] == 0)
        {
            d[cntr] = c1;   //засовываем в массив индексы хороших студентов чтобы сортировать только хороших
            cntr++;
        }
    }


    int icount = 1;
    while (icount)
    {
        for (int c1 = 0; c1 < cntr; c1++)
        {
            if (this->average[d[c1]] < this->average[d[c1+1]])
            {
                replace_a1_a2(d[c1], d[c1+1]);
            }
        }
    }


}