#include "matrix.h"
#include "time_check.h"

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
    time_checker checker{"operator*"};

    Matrix result{this->i};
    int step = this->i / 4;
    int first_max = step;
    int second_max = step * 2;
    int third_max = step * 3;
    int fourth_max = this->i;

    thread tr1(mstring_mult, std::ref(result), *this, matrix, 0, first_max);
    thread tr2(mstring_mult, std::ref(result), *this, matrix, first_max, second_max);
    thread tr3(mstring_mult, std::ref(result), *this, matrix, second_max, third_max);
    thread tr4(mstring_mult, std::ref(result), *this, matrix, third_max, fourth_max);
    //можно сделать и больше потоков но эффективность снижается из-за доступа к памяти 
    //по крайней мере на моем ноутбуке разницы между 4 и 8 потоками немного для 8 ядер
    //(0.90 время выполнения в 4 потоках, 0.75 в 8 условно) про память в книжке услышал 

    tr1.join();
    tr2.join();
    tr3.join();
    tr4.join();
    


    return result;
}


