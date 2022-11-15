#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include "../tools/tools.h"



using namespace std;


class BoolMatrix
{
private:
	int64_t i, j;
    bool **p;


public:
	BoolMatrix(int64_t, int64_t);
	BoolMatrix(ifstream&);														
    BoolMatrix(const BoolMatrix&);
    BoolMatrix(int64_t, int64_t, int64_t);
    explicit BoolMatrix(int64_t);

	~BoolMatrix();
	void to_file(ofstream&);
	void show();
	void inverse();
    int64_t count_ones();
    void lexicographic_sort();
    int64_t get_i();
    int64_t get_j();
    bool get_value(int64_t, int64_t);

	BoolMatrix operator*(const BoolMatrix&);
    BoolMatrix operator&(const BoolMatrix&);
    BoolMatrix operator|(const BoolMatrix&);
    BoolMatrix operator/(const BoolMatrix&);
    BoolMatrix& operator=(const BoolMatrix&);
    friend ostream& operator<<(ostream&, BoolMatrix);
    friend istream& operator>>(istream&, BoolMatrix);
	
};




