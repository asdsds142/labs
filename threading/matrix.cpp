#include "matrix.h"

Matrix::Matrix(int size)
{
    this->i = size;

    this->body = new int*[i];

    for (int c1 = 0; c1 < this->i; c1++)
    {
        this->body[c1] = new int[i];
    }

    for (int c1 = 0; c1 < this->i; c1++)
    {
        for (int c2 = 0; c2 < this->i; c2++)
        {
            this->body[c1][c2] = (rand()%26)-13;
        }
    }
}

void Matrix::show()
{
    for (int c1 = 0; c1 < this->i; c1++)
    {
        for (int c2 = 0; c2 < this->i; c2++)
        {
            cout << this->body[c1][c2] << ' ';
        }
        cout << '\n';
    }
}

void foo(Matrix& result, Matrix m1, Matrix m2, int c1, int c3)
{
    int sum = 0;
            
    for (int c2 = 0; c2 < m1.i; c2++)
    {
        int a, b;

        a = m1.body[c1][c2];
        b = m2.body[c2][c3];

        sum += (a * b);
    }
    result.body[c1][c3] = sum;
}

//для тренировки сюда приделать многопоточность
//покачто тут все супер плохо, изучу тему чуть позже но сейчас тупа сохраню
Matrix Matrix::operator*(Matrix matrix)
{
    cout << "BoolMatrix BoolMatrix::operator*(BoolMatrix matrix) started" << endl;
    Matrix result{this->i};
    vector<thread> v;

    for (int c1 = 0; c1 < this->i; c1++)
    {

        for (int c3 = 0; c3 < this->i; c3++)
        {
            thread tr(foo);
            v.push_back(tr);
            tr.detach();
        }
    }  

    for (size_t i = 0; i < v.size(); i++)
    {
        v[i].join();
    }
    
    cout << "BoolMatrix BoolMatrix::operator*(BoolMatrix matrix) finished" << endl;
    return result;
}


