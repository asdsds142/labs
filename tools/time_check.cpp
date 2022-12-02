#include "tools.h"

tools::time_checker::time_checker(std::string name_)
{
    this->name = name_;
    std::cout << name << " started" << std::endl;
    this->start = sys_clock::now();
}

tools::time_checker::~time_checker()
{
    dur_double dur = sys_clock::now() - start;
    std::cout << name << " finished" << std::endl;  
    std::cout << "Время выполнения: " << dur.count() << " seconds" << std::endl; 
}


void tools::time_checker::time_stomp(std::string msg)
{
    static uint64_t cntr = 0;
    dur_double dur = sys_clock::now() - start;
    std::cout << msg << "time_stomp" << std::endl;  
    std::cout << "time: " << dur.count() << " seconds" << std::endl;
    cntr++;
}