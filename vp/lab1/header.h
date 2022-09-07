#pragma once


#include <iostream>

using namespace std;

class Vector
{
private:
    short size;
    short memory;
    int *ptr;




public:

    Vector(int);
    void reserve(int);
    void push_back(int);
    int pop_back();
    int find_kmax(int);
    ~Vector();
};