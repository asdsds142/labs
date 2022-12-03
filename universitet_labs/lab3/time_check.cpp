#include "time_check.h"

time_checker::time_checker(string name_)
{
    this->name = name_;
    cout << name << " started" << endl;
    this->start = chrono::system_clock::now();
}

time_checker::~time_checker()
{
    const std::chrono::duration<double> dur = std::chrono::system_clock::now() - start;
    cout << name << " finished" << endl;  
    cout << "Время выполнения: " << dur.count() << " seconds" << endl; 
}
