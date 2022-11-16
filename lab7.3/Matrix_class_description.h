//Matrix_class_description.h
/*Сначала реализовывал на векторах но вектора как то по тупому работают,
  двумерный вектор плохо копируется вызывая сегфолты да и много других проблем
  поетому я все же реализую на классическом двойном указателе динамическом массиве
  а потом как изучу умные указатели возможно чуть докручу*/
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include "../tools/tools.h"



using namespace std;

//базовый класс для матрицы, потом подкручу наследование чтобы наследовать кастомние
template<class T = double>
class Matrix
{
private:
    static constexpr uint64_t DEFAULT_SIZE = 50;
    static uint64_t matrix_id_;

    string name_;
	uint64_t string_number_ = DEFAULT_SIZE;
    uint64_t column_number_ = DEFAULT_SIZE;
    T** body_ = nullptr;


public:

	explicit Matrix(uint64_t = DEFAULT_SIZE, uint64_t = DEFAULT_SIZE, T = 0);//													
    explicit Matrix(istream&); //

    Matrix(const Matrix<T>&); //
    ~Matrix(); //
    Matrix<T>& operator=(const Matrix<T>&); //

	void to_file(ofstream&); //
	void show() const; //

    uint64_t get_i() const {return this->string_number_;} //   
    uint64_t get_j() const {return this->column_number_;} //
    T get_value(uint64_t, uint64_t) const; //

    T string_sum(uint64_t); // 
    T column_sum(uint64_t); //
    T min(); //
    T max(); //
    vector<T> get_min_vector(); //


    Matrix<T> operator-() const; //
    Matrix<T>& operator*=(const Matrix<T>&); //
	Matrix<T> operator*(const Matrix<T>&) const; //
    Matrix<T>& operator+=(const Matrix<T>&); //
    Matrix<T> operator+(const Matrix<T>&) const; //
    Matrix<T>& operator-=(const Matrix<T>&); //
    Matrix<T> operator-(const Matrix<T>&) const; //

    Matrix<T> operator^(uint64_t) const; //

    bool operator==(const Matrix<T>&) const; //

    Matrix<T>& operator*=(T); //
    Matrix<T> operator*(T const); //
    Matrix<T>& operator/=(T); //
    Matrix<T> operator/(T) const; //


    template<class P>
    friend ostream& operator<<(ostream&, const Matrix<P>&); //
    template<class P>
    friend istream& operator>>(istream&, Matrix<P>&); //
	
};
