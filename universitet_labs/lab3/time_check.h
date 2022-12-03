#pragma once

#include <iostream>
#include <chrono>


using namespace std;


/*функция для отладки, помещать в самое начало функции
  выводит "имя" started/finished в конструкторе/деструкторе
  а так же выводит длительность выполнения*/
struct time_checker
{
    string name;
    std::chrono::_V2::system_clock::time_point start;
    time_checker(string);
    ~time_checker();
};

