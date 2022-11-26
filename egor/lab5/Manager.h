#pragma once

#include <iostream>
#include "Rabotnik_firmi.h"

class Manager : public Rabotnik_firmi //наследуем от базового класса
{
public:
    Manager();
};

Manager::Manager()
{
    this->doljnost = "manager"; //переписываем поле тип в конструкторе
}