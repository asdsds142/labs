#include "boolmatrix.h"

BoolMatrix::BoolMatrix(short a, short b)
{
    cout << "BoolMatrix::BoolMatrix(short a, short b) started" << endl;
    this->i = a;
    this->j = b;

    this->p = new bool *[a];
    
    for (int c1 = 0; c1 < this->i; c1++)
    {
        this->p[c1] = new bool[this->j];
    }

    bool tmp;
    for (int c1 = 0; c1 < this->i; c1++)
    {
        cout << "Введите строку из " << this->j << " bool значений" << endl;
        for (int c2 = 0; c2 < this->j; c2++)
        {
            cin >> tmp;
            this->p[c1][c2] = tmp;
        }
    }
    cout << "BoolMatrix::BoolMatrix(short a, short b) finished" << endl;
}



BoolMatrix::BoolMatrix(short a, short b, int num)
{
    cout << "BoolMatrix::BoolMatrix(short a, short b) started" << endl;
    this->i = a;
    this->j = b;

    this->p = new bool *[a];
    
    for (int c1 = 0; c1 < this->i; c1++)
    {
        this->p[c1] = new bool[this->j];
    }

    for (int c1 = 0; c1 < this->i; c1++)
    {
        for (int c2 = 0; c2 < this->j; c2++)
        {
            this->p[c1][c2] = num;
        }
    }
    cout << "BoolMatrix::BoolMatrix(short a, short b) finished" << endl;
}



void BoolMatrix::to_file(string filename)
{
    cout << "void BoolMatrix::to_file(string filename) started" << endl;
    ofstream fp{filename};

    fp << this->i << " " << this->j;
    for (int c1 = 0; c1 < this->i; c1++)
    {
        fp << endl;
        for (int c2 = 0; c2 < this->j; c2++)
        {
            fp << this->p[c1][c2] << " ";
        }
    }
    cout << "void BoolMatrix::to_file(string filename) finished" << endl;
}


BoolMatrix::BoolMatrix(string filename)
{
    cout << "BoolMatrix::BoolMatrix(string filename) started" << endl;
    ifstream fp{filename};
    
    fp >> this->i >> this->j;


    this->p = new bool *[this->i];
    
    for (int c1 = 0; c1 < this->i; c1++)
    {
        this->p[c1] = new bool[this->j];
    }

    bool a;
    for (int c1 = 0; c1 < this->i; c1++)
    {
        for (int c2 = 0; c2 < this->j; c2++)
        {
            fp >> a;
            this->p[c1][c2] = a;
        }
    }
        cout << "BoolMatrix::BoolMatrix(string filename) finished" << endl;
}


BoolMatrix::BoolMatrix(const BoolMatrix& matrix)
{
    cout << "BoolMatrix::BoolMatrix(const BoolMatrix& matrix) started" << endl;
    this->i = matrix.i;
    this->j = matrix.j;

    this->p = new bool *[this->i];
    
    for (int c1 = 0; c1 < this->i; c1++)
    {
        this->p[c1] = new bool[this->j];
    }

    for (int c1 = 0; c1 < this->i; c1++)
    {
        for (int c2 = 0; c2 < this->j; c2++)
        {
            this->p[c1][c2] = matrix.p[c1][c2];
        }
    }    
    cout << "BoolMatrix::BoolMatrix(const BoolMatrix& matrix) finished" << endl;
}


BoolMatrix::~BoolMatrix()
{
    cout << "BoolMatrix::~BoolMatrix() started" << endl;  
    cout << "BoolMatrix::~BoolMatrix() finished" << endl;    
}


void BoolMatrix::show()
{
    cout << "void BoolMatrix::show() started" << endl;  
    for (int c1 = 0; c1 < this->i; c1++)
    {
        cout << endl;
        for (int c2 = 0; c2 < this->j; c2++)
        {
            cout << this->p[c1][c2] << " ";
        }
    }  
    cout << endl;
    cout << "void BoolMatrix::show() finished" << endl;  
}

void BoolMatrix::inverse()
{
    cout << "void BoolMatrix::inverse() started" << endl;  
    for (int c1 = 0; c1 < this->i; c1++)
    {
        for (int c2 = 0; c2 < this->j; c2++)
        {
            if (this->p[c1][c2] == 0)  
                { this->p[c1][c2] = 1;}


            else { this->p[c1][c2] = 0;}

        }
    }  
    cout << "void BoolMatrix::inverse() finished" << endl;  
}


int BoolMatrix::count_ones()
{
    cout << "int BoolMatrix::count_ones() started" << endl;
    int result = 0;

    for (int c1 = 0; c1 < this->i; c1++)
    {
        for (int c2 = 0; c2 < this->j; c2++)
        {
            if (this->p[c1][c2] == 1)
                result += 1; 
        }
    } 

    cout << "int BoolMatrix::count_ones() finished, found " << result << " '1's" << endl;  
    return result; 
}


void BoolMatrix::operator=(BoolMatrix matrix)
{
    cout << "void BoolMatrix::operator=(BoolMatrix matrix) started" << endl;
    this->i = matrix.i;
    this->j = matrix.j;

    for (int c1 = 0; c1 < this->i; c1++)
    {
        delete this->p[c1]; //воттута с делитами может организовать напрягу, если что надобно удалить делиты и пусть будет некрависо
    }                       //алсо тут нет проверки на пустую этусамую матрицу но пустой у меня по условию не будет как минимум какая то да инициализируется

    delete this->p;

    this->p = new bool *[this->i];
    
    for (int c1 = 0; c1 < this->i; c1++)
    {
        this->p[c1] = new bool[this->j];
    }

    for (int c1 = 0; c1 < this->i; c1++)
    {
        for (int c2 = 0; c2 < this->j; c2++)
        {
            this->p[c1][c2] = matrix.p[c1][c2];
        }
    }    
    cout << "void BoolMatrix::operator=(BoolMatrix matrix) finished" << endl;
}


BoolMatrix BoolMatrix::operator&(BoolMatrix matrix)
{
    cout << "BoolMatrix BoolMatrix::operator&(BoolMatrix matrix) started" << endl;
    BoolMatrix result{matrix};
    //по хорошему я не особа должен конкретно тут обрабатывать выбросы всякие троу кетчи потому что я их не знаю но маленькую защиту все же приделаю сиаутом

    if (this->i != matrix.i || this->j != matrix.j)
    {
        cout << "варнинг, аларм BoolMatrix BoolMatrix::operator&(BoolMatrix matrix) значения i, j не равны между собой сравнение невозможно" << endl;
        return matrix;
    }

    for (int c1 = 0; c1 < this->i; c1++)
    {
        for (int c2 = 0; c2 < this->j; c2++)
        {
            if (this->p[c1][c2] == 1 && matrix.p[c1][c2] == 1)
            {
                result.p[c1][c2] = 1;
            }

            else
            {
                result.p[c1][c2] = 0;
            }
        }
    }    
    cout << "BoolMatrix BoolMatrix::operator&(BoolMatrix matrix) finished" << endl;
    return result;
}


BoolMatrix BoolMatrix::operator|(BoolMatrix matrix)
{
    cout << "BoolMatrix BoolMatrix::operator|(BoolMatrix matrix) started" << endl;
    BoolMatrix result{matrix};
    //по хорошему я не особа должен конкретно тут обрабатывать выбросы всякие троу кетчи потому что я их не знаю но маленькую защиту все же приделаю сиаутом

    if (this->i != matrix.i || this->j != matrix.j)
    {
        cout << "варнинг, аларм BoolMatrix BoolMatrix::operator|(BoolMatrix matrix) значения i, j не равны между собой сравнение невозможно" << endl;
        return matrix;
    }

    for (int c1 = 0; c1 < this->i; c1++)
    {
        for (int c2 = 0; c2 < this->j; c2++)
        {
            if (this->p[c1][c2] == 1 || matrix.p[c1][c2] == 1)
            {
                result.p[c1][c2] = 1;
            }

            else
            {
                result.p[c1][c2] = 0;
            }
        }
    }    
    cout << "BoolMatrix BoolMatrix::operator|(BoolMatrix matrix) finished" << endl;\
    return result;
}


BoolMatrix BoolMatrix::operator/(BoolMatrix matrix)
{
    cout << "BoolMatrix BoolMatrix::operator/(BoolMatrix matrix) started" << endl;
    BoolMatrix result{matrix};
    //по хорошему я не особа должен конкретно тут обрабатывать выбросы всякие троу кетчи потому что я их не знаю но маленькую защиту все же приделаю сиаутом

    if (this->i != matrix.i || this->j != matrix.j)
    {
        cout << "варнинг, аларм BoolMatrix BoolMatrix::operator/(BoolMatrix matrix) значения i, j не равны между собой сравнение невозможно" << endl;
        return matrix;
    }

    for (int c1 = 0; c1 < this->i; c1++)
    {
        for (int c2 = 0; c2 < this->j; c2++)
        {
            if (this->p[c1][c2] == 0 && matrix.p[c1][c2] == 0)
            {
                result.p[c1][c2] = 1;
            }

            else
            {
                result.p[c1][c2] = 0;
            }
        }
    }    
    cout << "BoolMatrix BoolMatrix::operator/(BoolMatrix matrix) finished" << endl;
    return result;
}


BoolMatrix BoolMatrix::operator*(BoolMatrix matrix)
{
    cout << "BoolMatrix BoolMatrix::operator*(BoolMatrix matrix) started" << endl;
    BoolMatrix result{this->i, matrix.j, 0};
    //по хорошему я не особа должен конкретно тут обрабатывать выбросы всякие троу кетчи потому что я их не знаю но маленькую защиту все же приделаю сиаутом

    if (this->j != matrix.i)
    {
        cout << "варнинг, аларм BoolMatrix BoolMatrix::operator*(BoolMatrix matrix) значения j1, i2 не равны между собой сравнение невозможно" << endl;
        return matrix;
    }

    for (int c1 = 0; c1 < this->i; c1++)
    {
        for (int c3 = 0; c3 < matrix.j; c3++)
        {
            bool sum = 0;
            for (int c2 = 0; c2 < this->j; c2++)
            {
                sum += (this->p[c1][c2] * matrix.p[c2][c3]);
            }
            result.p[c1][c3] = sum;
        }
    }  
    cout << "BoolMatrix BoolMatrix::operator*(BoolMatrix matrix) finished" << endl;
    return result;
}



short BoolMatrix::get_i() { return this->i;}

short BoolMatrix::get_j() { return this->j;}

bool BoolMatrix::get_value(short c1, short c2) { return this->p[c1][c2];}


ostream& operator<<(ostream &out, BoolMatrix matrix)
{
    cout << "operator << (boolmatrix) started" << endl;
    out << matrix.get_i() << " " << matrix.get_j() << endl;
    for (int c1 = 0; c1 < matrix.get_i(); c1++) //протестировать но вроде должно работать
    {
        for (int c2 = 0; c2 < matrix.get_j(); c2++)
        {
            out << matrix.get_value(c1, c2) << " ";
        }
        out << endl;
    }
    cout << "operator << (boolmatrix) finished" << endl;
    return out;
}

//Должно работать но я не тестил еще
void BoolMatrix::lexicographic_sort()
{
    cout << "void BoolMatrix::lexicographic_sort() started" << endl;
    long number[this->i] {0};
    for (int c1 = 0; c1 < this->i; c1++)
    {
        for (int c2 = 0; c2 < this->j; c2++)
        {
            //делаю массив лонгов и пихаю туда единички в виде суммы степеней двойки от последней к первой циферке
            number[c1] += this->p[c1][this->j - 1 - c2] * pow(2, c2);
        }
    }

    for (int c1 = 0; c1 < this->i; c1++)
    {
        int c2 = 0;
        while (!c2)
        {
            c2 = 0;
            //сравниваю мои двоечки и где больше там и больше приоритет у строчки
            if (number[c1] < number[c1+1])
            {
                swap(this->p[c1], this->p[c1+1]);
                c2 += 1;
            }
        }
    }
    cout << "void BoolMatrix::lexicographic_sort() finished" << endl;
}


//todo затестировать


