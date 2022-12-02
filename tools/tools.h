//tools.h
//штука для разных полезных штук
#pragma once

#include <iostream>
#include <string>
#include <chrono>


namespace tools
{
    void try_input(std::istream&, long&, std::string = "");
    void try_input(std::istream&, std::string&, std::string = "");
    void try_getline(std::istream&, std::string&, std::string = "");
    void ignore_much(std::istream&);

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

} // namespace tools