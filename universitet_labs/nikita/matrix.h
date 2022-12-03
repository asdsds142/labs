// 11. Составить описания класса, обеспечивающего представление матрицы заданного размера nхn и любого минора в ней. Память для матрицы выделять динамически.
// Написать несколько конструкторов, в том числе конструктор копирования. Реализовать методы для отображения на экране как матрицы в целом, так и заданного минора;
// сложения, вычитания, умножения миноров. Перегрузить операции сложения, вычитания, умножения.

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

using namespace std;

class Matrix {
private:
    int size;
    double **matrix;
    int minorRow = -1;
    int minorColumn = -1;
    double minor;

    int chooseMinorRow();
    int chooseMinorColumn();
    double **getMatrixForMinor();
public:
    //constructors
    Matrix(int, double **);
    Matrix(Matrix *);
    //gets
    int getSize();
    double **getMatrix();
    int getMinorRow();
    int getMinorColumn();
    double getMinor();
    //sets
    void setSize(int);
    void setMatrix(double **);
    void setMinorRow(int);
    void setMinorColumn(int);
    void setMinor(double);
    //output
    void showMatrix();
    void showMinor();
    // operations with minor
    void createMinor();
    void updateMinor();
    void additionOfMinors(Matrix);
    void subtractionOfMinors(Matrix);
    void multiplicationOfMinors(Matrix);
    bool isMinorCreated();
    //overread
    Matrix multiplication(int);
    double operator + (Matrix);
    double operator - (Matrix);
    double operator * (Matrix);
    Matrix operator = (Matrix);
    Matrix operator *= (int);
};

ostream& operator << (ostream& os, Matrix m);

#endif // MATRIX_H