#pragma once

#include <iostream>
#include <string>

using namespace std;

class Rabotnik_firmi //базовый клас
{
protected:
    string doljnost = "null"; //защищенное поле *тип*, по умолчанию ставится "null" производные классы переопределяют поле
public:
    //конструктор - конструктор по умолчанию, определять его не нужно

    virtual void show_doljnost(); //метод выводящий поле на экран
    virtual ~Rabotnik_firmi(); //виртуальный деструктор 
};

void Rabotnik_firmi::show_doljnost() //определение метода
{
    cout << this->doljnost << endl;
}

Rabotnik_firmi::~Rabotnik_firmi(){}