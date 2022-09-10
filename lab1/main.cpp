#include "header.h"


int main()
{
    vector<Phone> Adresses;

    int cntr;
    cout << "Введите число вводимых элементов" << endl;
    cin >> cntr;

    for (int i = 0; i < cntr; i++)
    {
        Phone a{};
        Adresses.push_back(a);
    }

    cout << "Введите максимальное время"
    long maxtime;
    //допустим тут заполнили массив


    for (int i = 0; i < Adresses.size(); i++)
    {
        if (Adresses[i].get_incity_time() > maxtime)
            Adresses[i].show();
    }


    for (int i = 0; i < Adresses.size(); i++)
    {
        if (Adresses[i].get_intercity_time() > 0)
            Adresses[i].show();
    }




}