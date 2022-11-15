#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <vector>
#include <cmath>
#include "../tools/tools.h"



using namespace std;


template<class T>
class Matrix
{
private:
    static constexpr uint64_t default_size_ = 3;

	uint64_t string_number_;
    uint64_t column_number_;
    vector<vector<T>> body_;


public:

	Matrix(uint64_t = default_size_, uint64_t = default_size_, T = 0);													
    Matrix(const Matrix&) = default;
    explicit Matrix(istream&);
    explicit Matrix(T); //тут будет диагональная матрица


	void to_file(ofstream&);
	void show();
    int64_t get_i() {return this->string_number_;}
    int64_t get_j() {return this->column_number_;}
    T get_value(uint64_t, uint64_t);

	Matrix operator*(const Matrix<T>&);
    Matrix& operator+=(const Matrix<T>&);
    Matrix operator+(const Matrix<T>&);

    friend ostream& operator<<(ostream&, Matrix);
    friend istream& operator>>(istream&, Matrix);
	
};
