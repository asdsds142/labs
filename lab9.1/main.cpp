//main.cpp

#include "Vector.h"


int main()
{
    //задание вектора с кастомными границами [2, 9]
    Vector<int64_t> sebas {1, 5, 2, 6, 2, 5, 3, 6, 7}; 
    auto sebas_ultra = sebas;
    

    //специально пробую на 1 элемент больше чем надо чтобы триггернуть кетч
    for (int64_t i = 0; i < static_cast<int64_t>(sebas.size() + 1); i++) 
    {
        try
        {
            sebas.at(i) *= i;
            sebas_ultra.at(i) = 3;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    

    try
    {
        sebas /= 0;
        std::cout << "попробывали" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    sebas.show();
    sebas_ultra.show();

    //вывод скалярного произведения
    std::cout << (sebas * sebas_ultra) << std::endl;
}