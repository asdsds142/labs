//main.cpp


#include "Vector.h"


int main()
{
    auto sebas = Vector<int64_t>();
    auto sebas_ultra = sebas;

    for (size_t i = 0; i < sebas.size() + 1; i++)
    {
        try
        {
            sebas.at(i) =  1 + 2 * i;
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
        sebas / 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    sebas.show();
    sebas_ultra.show();

    std::cout << (sebas * sebas_ultra) << std::endl;
}