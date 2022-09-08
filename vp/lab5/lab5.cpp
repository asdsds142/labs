#include "header.h"


Matrix::Matrix(int a, int b)
{
    this->i = a;
    this->j = b;
    this->ptr = new int*[this->i];

    for (int c1 = 0; c1 < this->i; c1++)
    {
        this->ptr[c1] = new int[this->j];
        for (int c2 = 0; c2 < this->j; c2++)
        {
            cin >> this->ptr[c1][c2];
        }
    }
}


Matrix::Matrix(int a, int b, int num)
{
    this->i = a;
    this->j = b;
    this->ptr = new int*[this->i];

    for (int c1 = 0; c1 < this->i; c1++)
    {
        this->ptr[i] = new int[this->j];
        for (int c2 = 0; c2 < this->j; c2++)
        {
            this->ptr[c1][c2] = num;
        }
    }
}

//test
void Matrix::show()
{
    for (int c1 = 0; c1 < this->i; c1++)
    {
        for (int c2 = 0; c2 < this->j; c2++)
        {
            if (this->ptr[i][j] != 0) 
                cout << this->ptr[i][j];
        }
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

