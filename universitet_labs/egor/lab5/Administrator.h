#pragma once

#include <iostream>
#include "Rabotnik_firmi.h"

class Administrator : public Rabotnik_firmi //наследуем от базового класса
{
public:
    Administrator();
};

Administrator::Administrator()
{
    this->doljnost = "Administrator"; //переписываем поле тип в конструкторе
}