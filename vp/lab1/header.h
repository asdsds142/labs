#pragma once


#include <iostream>
#include <cstdlib>

using namespace std;

class Vector
{
private:
    short size;
    short memory;
    int *ptr;




public:

    Vector(int = 0);
    void reserve(int);
    void push_back(int);
    void push_back(int[], int);// передавать рядом с массивом его размер, ибо в функции массив превращается в указатель, в интернетах другого решения не пишут
    int pop_back();
    int find_kmax(int);
    void show();
    ~Vector();
};