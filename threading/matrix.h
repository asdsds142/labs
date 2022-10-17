#pragma once

#include <iostream>
#include <vector>
#include <mutex>
#include <chrono>
#include <thread>


using namespace std;


//квадратные матрицы онли
class Matrix
{
private:


public:
    int i;
    int** body;
    Matrix(int);

    void show();
    Matrix operator*(Matrix);
};