#pragma once

#include <iostream>
#include <chrono>




/*штука для отладки, 
  конструктор принимает на вход строку "имя"
  выводит "имя" started/finished в конструкторе/деструкторе

  в конструкторе засекает начальный time_point
  в деструкторе выводит длительность выполнения*/

struct time_checker
{
    using t_p = std::chrono::_V2::system_clock::time_point;
    using dur_double = std::chrono::duration<double>;
    using sys_clock = std::chrono::system_clock;
    
    std::string name;
    t_p start;
    time_checker(std::string = "");
    ~time_checker();
    void time_stomp(std::string = "");
};

