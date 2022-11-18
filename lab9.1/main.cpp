//main.cpp


#include "Vector.h"


int main()
{
    auto sebas = Vector<int64_t>();

    for (size_t i = 0; i < sebas.size() + 1; i++)
    {
        try
        {
            sebas.at(i) = i;
            sebas.at(i) *= i;
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
}