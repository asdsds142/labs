#pragma once

#include <iostream>
#include "Rabotnik_firmi.h"

class Developer : public Rabotnik_firmi //наследуем от базового класса
{
public:
    Developer();
};

Developer::Developer()
{
    this->doljnost = "developer"; //переписываем поле тип в конструкторе
}