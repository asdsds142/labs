//Matrix_class_description.h
/*Сначала реализовывал на векторах но вектора как то по тупому работают,
  двумерный вектор плохо копируется вызывая сегфолты да и много других проблем
  поетому я все же реализую на классическом двойном указателе динамическом массиве
  а потом как изучу умные указатели возможно чуть докручу*/

/*Разработать шаблонный класс «матрица»
Обеспечить представление матрицы произвольного размера (по умолчанию  50x50) и типа (по умолчанию double)  с помощью шаблона класса. 
Выполнить перегрузку арифметических операций, операций присваивания, ввода с клавиатуры, вывода на экран, индексирования[]. 
Реализовать в конструкторе автоматическое генерирование имени матрицы («матрица 1», «матрица 2» и т.д.), используя для этого статическое поле – счетчик объектов класса. Реализовать метод вывода матрицы на экран с одновременным выводом ее имени. В основном модуле программы (файл main.cpp) определить массив указателей (проинициализировав его адресами объявленных матриц-объектов, требуемых по условию задания) и функцию Show(), которой передаются данный массив и количество матриц (для вывода на экран перечня всех матриц с их значениями).

Реализовать следующие операции над матрицами:
    • сложения, вычитания;
    • умножения и деления на число;
    • присваивания (+=, -=, *=, /=);
    • сравнения на равенство/неравенство;
    • вычисления суммы элементов, расположенных в заданном столбце; 
    • нахождения наименьшего/наибольшего элемента матрицы;
    • вычисления суммы элементов, расположенных в заданном столбце/строке;
    • получения вектора из минимальных значений элементов столбцов матрицы;
    • ввода/вывода в стандартные потоки подматрицы любого размера и всей матрицы; 
    • умножения матриц;
    • возведения в степень;
При необходимости добавить в класс другие методы.

Создать две матрицы и найти для каждой из них сумму элементов, расположенных в последней строке.
*/
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

    string name_ = "undefined";
	uint64_t string_number_ = DEFAULT_SIZE;
    uint64_t column_number_ = DEFAULT_SIZE;
    T** body_ = nullptr;

public:

	explicit Matrix(uint64_t = DEFAULT_SIZE, uint64_t = DEFAULT_SIZE, T = 0);//													
    explicit Matrix(istream&); //

    Matrix(const Matrix<T>&); //
    virtual ~Matrix(); //
    virtual Matrix<T>& operator=(const Matrix<T>&); //

	virtual void show() const; //

    virtual uint64_t get_i() const {return this->string_number_;} //   
    virtual uint64_t get_j() const {return this->column_number_;} //
    virtual T get_value(uint64_t, uint64_t) const; //

    virtual T string_sum(uint64_t); // 
    virtual T column_sum(uint64_t); //
    virtual T min(); //
    virtual T max(); //
    virtual vector<T> get_min_vector(); //

    virtual Matrix<T> operator-() const; //
    virtual Matrix<T>& operator*=(const Matrix<T>&); //
	virtual Matrix<T> operator*(const Matrix<T>&) const; //
    virtual Matrix<T>& operator+=(const Matrix<T>&); //
    virtual Matrix<T> operator+(const Matrix<T>&) const; //
    virtual Matrix<T>& operator-=(const Matrix<T>&); //
    virtual Matrix<T> operator-(const Matrix<T>&) const; //

    virtual Matrix<T> operator^(uint64_t) const; //

    virtual bool operator==(const Matrix<T>&) const; //

    virtual Matrix<T>& operator*=(T); //
    virtual Matrix<T> operator*(T const); //
    virtual Matrix<T>& operator/=(T); //
    virtual Matrix<T> operator/(T) const; //


    template<class P>
    friend ostream& operator<<(ostream&, const Matrix<P>&); //
    template<class P>
    friend istream& operator>>(istream&, Matrix<P>&); //
	
};
