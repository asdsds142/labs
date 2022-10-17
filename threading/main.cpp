#include "matrix.h"

struct time_checker
{
    std::chrono::_V2::system_clock::time_point sta;
    time_checker()
    {
        sta = std::chrono::system_clock::now();
    }

    ~time_checker()
    {
        const std::chrono::duration<double> dur = std::chrono::system_clock::now() - sta;
        cout << "Время выполнения: " << dur.count() << " seconds" << endl;   
    }
};

struct named_time_checker : public time_checker
{
    string name;
    named_time_checker(string buf)
    {
        name = buf;
        cout << name <<  " начала свою работу" << endl;
    }
    ~named_time_checker()
    {
        cout << name << " закончила свою работу" << endl;
    }
};



int main()
{
    named_time_checker main_checker {"main"};

    Matrix a{821};
    Matrix b{821};
    Matrix c{821};

    c = a*b;

}