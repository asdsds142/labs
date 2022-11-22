#pragma once

#include <iostream>
#include "musical_instrument.h"

class Strunni : public Musical_instrument //наследуем от базового класса
{
public:
    Strunni();
};

Strunni::Strunni()
{
    this->type = "струнный"; //переписываем поле тип в конструкторе
}