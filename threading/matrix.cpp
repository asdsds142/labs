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

void mstring_mult(Matrix& result, Matrix&& m1, Matrix&& m2, int&& start, int&& finish)
{
    int sizing = m1.i;
    for (int c1 = start; c1 < finish; c1++)
    {
        for (int c3 = 0; c3 < sizing; c3++)
        {
            int sum = 0;
            for (int c2 = 0; c2 < sizing; c2++)
            {
                sum += (m1.body[c1][c2] * m2.body[c2][c3]);
            }
            result.body[c1][c3] = sum;
        }
    }  
}

//для тренировки сюда приделать многопоточность
//покачто тут все супер плохо, изучу тему чуть позже но сейчас тупа сохраню
Matrix Matrix::operator*(Matrix matrix)
{
    cout << "BoolMatrix BoolMatrix::operator*(BoolMatrix matrix) started" << endl;
    Matrix result{this->i};
    int step = this->i / 8;
    int first_max = step;
    int second_max = step * 2;
    int third_max = step * 3;
    int fourth_max = step * 4;
    int fiveth_max = step * 5;
    int sixth_max = step * 6;
    int seventh_max = step * 7;
    int eights_max = this->i;
    thread tr1(mstring_mult, std::ref(result), *this, matrix, 0, first_max);
    thread tr2(mstring_mult, std::ref(result), *this, matrix, first_max, second_max);
    thread tr3(mstring_mult, std::ref(result), *this, matrix, second_max, third_max);
    thread tr4(mstring_mult, std::ref(result), *this, matrix, third_max, fourth_max);
    thread tr5(mstring_mult, std::ref(result), *this, matrix, fourth_max, fiveth_max);
    thread tr6(mstring_mult, std::ref(result), *this, matrix, fiveth_max, sixth_max);
    thread tr7(mstring_mult, std::ref(result), *this, matrix, sixth_max, seventh_max);
    thread tr8(mstring_mult, std::ref(result), *this, matrix, seventh_max, eights_max);


    tr1.join();
    tr2.join();
    tr3.join();
    tr4.join();
    tr5.join();
    tr6.join();
    tr7.join();
    tr8.join();

    cout << "BoolMatrix BoolMatrix::operator*(BoolMatrix matrix) finished" << endl;
    return result;
}


