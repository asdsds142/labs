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



int main()
{
    time_checker main_checker;

    Matrix a{421};
    Matrix b{421};
    Matrix c{421};

    c = a*b;

}