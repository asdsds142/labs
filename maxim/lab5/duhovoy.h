#pragma once

#include <iostream>
#include "musical_instrument.h"

class Duhovoy : public Musical_instrument //наследуем от базового класса
{
public:
    Duhovoy();
};

Duhovoy::Duhovoy()
{
    this->type = "духовой"; //переписываем поле тип в конструкторе
}