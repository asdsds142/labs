#include "boolmatrix.h"

BoolMatrix::BoolMatrix(int64_t a, int64_t b): i(a), j(b), p(new bool *[a])
{

    for (int c1 = 0; c1 < this->i; c1++)
    {
        this->p[c1] = new bool[this->j];
    }

    for (int c1 = 0; c1 < this->i; c1++)
    {
        for (int c2 = 0; c2 < this->j; c2++)
        {
            cin >> this->p[c1][c2];
        }
    }
}



BoolMatrix::BoolMatrix(int64_t a, int64_t b, int64_t num): i(a), j(b), p(new bool *[a])
{
    
    for (size_t c1 = 0; c1 < this->i; c1++)
    {
        this->p[c1] = new bool[this->j];
    }

    for (size_t c1 = 0; c1 < this->i; c1++)
    {
        for (size_t c2 = 0; c2 < this->j; c2++)
        {
            this->p[c1][c2] = num;
        }
    }

}



void BoolMatrix::to_file(ofstream& out)
{


    out << this->i << " " << this->j;
    for (int c1 = 0; c1 < this->i; c1++)
    {
        out << endl;
        for (int c2 = 0; c2 < this->j; c2++)
        {
            out << this->p[c1][c2] << " ";
        }
    }
}


BoolMatrix::BoolMatrix(ifstream& file_stream)
{   
    file_stream >> this->i >> this->j;


    this->p = new bool *[this->i];
    
    for (int c1 = 0; c1 < this->i; c1++)
    {
        this->p[c1] = new bool[this->j];
    }

    for (int c1 = 0; c1 < this->i; c1++)
    {
        for (int c2 = 0; c2 < this->j; c2++)
        {
            file_stream >> this->p[c1][c2];
        }
    }
}


BoolMatrix::BoolMatrix(const BoolMatrix& other): i(other.i), j(other.j), p(new bool *[i])
{   
    for (int c1 = 0; c1 < this->i; c1++)
    {
        this->p[c1] = new bool[this->j];
    }

    for (int c1 = 0; c1 < this->i; c1++)
    {
        for (int c2 = 0; c2 < this->j; c2++)
        {
            this->p[c1][c2] = other.p[c1][c2];
        }
    }    
}


BoolMatrix::~BoolMatrix()
{ 
    for (int c1 = 0; c1 < this->i; c1++)
    {
        delete[] this->p[c1];
    }
    delete[] this->p;    
}


void BoolMatrix::show()
{
    for (int c1 = 0; c1 < this->i; c1++)
    {
        cout << endl;
        for (int c2 = 0; c2 < this->j; c2++)
        {
            cout << this->p[c1][c2] << " ";
        }
    }  
    cout << endl;
}

void BoolMatrix::inverse()
{
    for (int c1 = 0; c1 < this->i; c1++)
    {
        for (int c2 = 0; c2 < this->j; c2++)
        {
            if (this->p[c1][c2] == 0)  
                { this->p[c1][c2] = 1;}


            else { this->p[c1][c2] = 0;}

        }
    }
}


int64_t BoolMatrix::count_ones()
{
    int64_t result = 0;

    for (size_t c1 = 0; c1 < this->i; c1++)
    {
        for (size_t c2 = 0; c2 < this->j; c2++)
        {
            if (this->p[c1][c2] == 1)
                result += 1; 
        }
    } 

    //cout << "int BoolMatrix::count_ones() finished, found " << result << " '1's" << endl;  
    return result; 
}


BoolMatrix& BoolMatrix::operator=(const BoolMatrix& other)
{
    if (this == &other)
    {
        return *this;
    }

    if(this->p)
    {
        for (size_t c1 = 0; c1 < this->i; c1++)
        {
            delete[] this->p[c1];
        }
        delete[] this->p;    
    }

    this->i = other.i;
    this->j = other.j;
    this->p = new bool* [i];

    for (size_t c1 = 0; c1 < this->i; c1++)
    {
        this->p[c1] = new bool[this->j];
    }

    for (size_t c1 = 0; c1 < this->i; c1++)
    {
        for (size_t c2 = 0; c2 < this->j; c2++)
        {
            this->p[c1][c2] = other.p[c1][c2];
        }
    } 

    return *this; 
}


BoolMatrix BoolMatrix::operator&(const BoolMatrix& other)
{
    BoolMatrix result{other};

    if (this->i != other.i || this->j != other.j)
    {
        throw runtime_error("matrix size error");
    }

    for (size_t c1 = 0; c1 < this->i; c1++)
    {
        for (size_t c2 = 0; c2 < this->j; c2++)
        {
            if (this->p[c1][c2] == 1 && other.p[c1][c2] == 1)
            {
                result.p[c1][c2] = 1;
            }

            else
            {
                result.p[c1][c2] = 0;
            }
        }
    }    
    return result;
}


BoolMatrix BoolMatrix::operator|(const BoolMatrix& other)
{
    BoolMatrix result{other};

    if (this->i != other.i || this->j != other.j)
    {
        throw runtime_error("matrix size error");
    }

    for (size_t c1 = 0; c1 < this->i; c1++)
    {
        for (size_t c2 = 0; c2 < this->j; c2++)
        {
            if (this->p[c1][c2] == 1 || other.p[c1][c2] == 1)
            {
                result.p[c1][c2] = 1;
            }

            else
            {
                result.p[c1][c2] = 0;
            }
        }
    }    
    return result;
}


BoolMatrix BoolMatrix::operator/(const BoolMatrix& other)
{
    BoolMatrix result{other};

    if (this->i != other.i || this->j != other.j)
    {
        throw runtime_error("matrix size error");
    }

    for (size_t c1 = 0; c1 < this->i; c1++)
    {
        for (size_t c2 = 0; c2 < this->j; c2++)
        {
            if (this->p[c1][c2] == 0 &&other.p[c1][c2] == 0)
            {
                result.p[c1][c2] = 1;
            }

            else
            {
                result.p[c1][c2] = 0;
            }
        }
    }    
    return result;
}


BoolMatrix BoolMatrix::operator*(const BoolMatrix& other)
{

    BoolMatrix result{this->i, other.j, 0};
  

    if (this->j != other.i)
    {
        throw runtime_error("matrix size error");
    }

    for (size_t c1 = 0; c1 < this->i; c1++)
    {
        for (size_t c3 = 0; c3 < other.j; c3++)
        {
            bool sum = 0;
            for (size_t c2 = 0; c2 < this->j; c2++)
            {
                sum += (this->p[c1][c2] * other.p[c2][c3]);
            }
            result.p[c1][c3] = sum;
        }
    } 
    return result;
}



int64_t BoolMatrix::get_i() { return this->i;}

int64_t BoolMatrix::get_j() { return this->j;}

bool BoolMatrix::get_value(int64_t c1, int64_t c2) { return this->p[c1][c2];}


ostream& operator<<(ostream &out, BoolMatrix other)
{
    out << other.get_i() << " " << other.get_j() << endl;
    for (size_t c1 = 0; c1 < other.get_i(); c1++) 
    {
        for (size_t c2 = 0; c2 < other.get_j(); c2++)
        {
            out << other.get_value(c1, c2) << " ";
        }
        out << endl;
    }
    return out;
}


void BoolMatrix::lexicographic_sort()
{
    int64_t number[this->i] {0};
    for (size_t c1 = 0; c1 < this->i; c1++)
    {
        for (size_t c2 = 0; c2 < this->j; c2++)
        {
            //делаю массив лонгов и пихаю туда единички в виде суммы степеней двойки от последней к первой циферке
            number[c1] += this->p[c1][this->j - 1 - c2] * pow(2, c2);
        }
    }

    for (size_t c1 = 0; c1 < this->i - 1; c1++)
    {
        bool c2 = true;
        while (c2)
        {
            c2 = false;
            //сравниваю мои двоечки и где больше там и больше приоритет у строчки
            if (number[c1] < number[c1+1])
            {
                swap(this->p[c1], this->p[c1+1]);
                swap(number[c1], number[c1+1]);
                c2 = true;
            }
        }
    }
}





