#pragma once

#include <iostream>
#include <string>

using namespace std;

class Musical_instrument //базовый клас
{
protected:
    string type = "null"; //защищенное поле *тип*, по умолчанию ставится null производные классы переопределяют поле
public:
    //конструктор - конструктор по умолчанию, определять его не нужно

    virtual void cout_type(); //метод выводящий поле на экран
};

void Musical_instrument::cout_type() //определение метода
{
    cout << this->type << endl;
}