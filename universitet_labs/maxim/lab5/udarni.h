#pragma once

#include <iostream>
#include "musical_instrument.h"

class Udarni : public Musical_instrument //наследуем от базового класса
{
public:
    Udarni();
};

Udarni::Udarni()
{
    this->type = "ударный"; //переписываем поле тип в конструкторе
}