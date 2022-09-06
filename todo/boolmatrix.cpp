#include "boolmatrix.h"


BoolMatrix::BoolMatrix(int a, int b)
{   
    this->i = a;
    this->j = b;
    this->p.reserve(a);
    for (int c1 = 0; c1 < a; c1++)
    {
        long n = 0;

        for (int c2 = 0; c2 < b; c2++)
        {
            short a;
            cin >> a;

            if (a)
                n += pow(2, c2);
        }

        p[c1] = n;
    }
}


BoolMatrix::BoolMatrix(string filename)
{
	ifstream ptr{filename};
	ptr >> i >> j;
	this->p.reserve(i);


	for (int c1 = 0; c1 < this->i; c1++)
		ptr >> this->p[c1];
}



BoolMatrix::BoolMatrix(const BoolMatrix& A)
{
	this->i = A.i;
    this->j = A.j;
	this->p.reserve(this->i);


	for (int c1 = 0; c1 < this->i; c1++)
		this->p[c1] = A.p[c1];
}



void BoolMatrix::to_file(string textfile)
{
	ofstream d{textfile};
	d << this->i << " " <<  this->j << " ";

	for (int a = 0; a < this->i; a++)
		d << this->p[a] << " ";

    d << endl;
}




void BoolMatrix::show()
{
    cout << "Матрица напоказ:"  << endl;
    for (int c1 = 0; c1 < this->i; c1++)
    {
        for(int c2 = 0; c2 < this->j; c2++)
        {
            cout << (this->p[c1]>>c2)%2 << " ";

        }
        cout << endl;
    }
}


void BoolMatrix::inverse()
{
    for (int c1 = 0; c1 < this->i; c1++)
    {
        long a = 0;
        for (int c2 = 0; c2 < this->j; c2++)
        {
            
            short b = (this->p[c1]>>c2)%2;
            if (!b)
            {
                a += pow(2, c2);
            }
            
        }
        this->p[c1] = a;
    }
}


BoolMatrix BoolMatrix::operator&(BoolMatrix M)
{
    
    BoolMatrix A{M};
    for (int c1 = 0; c1 < this->i; c1++)
    {
        long a = 0;
        for (int c2 = 0; c2 < this->j; c2++)
        {
            
            short b = (this->p[c1]>>c2)%2;
            if ((this->p[c1]>>c2)%2 && (M.p[c1]>>c2)%2)
            {
                a += pow(2, c2);
            }
            
        }
        A.p[c1] = a;
    }
    return A;
}


BoolMatrix BoolMatrix::operator|(BoolMatrix M)
{
    
    BoolMatrix A{M};
    for (int c1 = 0; c1 < this->i; c1++)
    {
        long a = 0;
        for (int c2 = 0; c2 < this->j; c2++)
        {
            
            short b = (this->p[c1]>>c2)%2;
            if ((this->p[c1]>>c2)%2 || (M.p[c1]>>c2)%2)
            {
                a += pow(2, c2);
            }
            
        }
        A.p[c1] = a;
    }
    return A;
}



BoolMatrix BoolMatrix::operator/(BoolMatrix M)
{
    
    BoolMatrix A{M};
    for (int c1 = 0; c1 < this->i; c1++)
    {
        long a = 0;
        for (int c2 = 0; c2 < this->j; c2++)
        {
            
            short b = (this->p[c1]>>c2)%2;
            if (!(this->p[c1]>>c2)%2 && !(M.p[c1]>>c2)%2)
            {
                a += pow(2, c2);
            }
        }
        A.p[c1] = a;
    }
    return A;
}



void BoolMatrix::operator=(BoolMatrix A)
{
    this->i = A.i;
    this->j = A.j;
	this->p.reserve(this->i);


	for (int c1 = 0; c1 < this->i; c1++)
		this->p[c1] = A.p[c1];

    

}





BoolMatrix::~BoolMatrix()
{

}
