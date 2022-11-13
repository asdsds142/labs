#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>



using namespace std;


class BoolMatrix
{
private:
	short i, j;
    bool **p;


public:
	BoolMatrix(short, short);
	BoolMatrix(string);														
    BoolMatrix(const BoolMatrix&);
    BoolMatrix(short, short, int);

	~BoolMatrix();
	void to_file(string);
	void show();
	void inverse();
    int count_ones();
    void lexicographic_sort();
    short get_i();
    short get_j();
    bool get_value(short, short);

	BoolMatrix operator*(BoolMatrix);
    BoolMatrix operator&(BoolMatrix);
    BoolMatrix operator|(BoolMatrix);
    BoolMatrix operator/(BoolMatrix);
    void operator=(BoolMatrix);
    friend ostream& operator<<(ostream&, BoolMatrix);
	
};


//может тут както френд надо юзать но я еще не знаю френды



