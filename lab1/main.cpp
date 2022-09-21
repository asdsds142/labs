#include "header.h"


int main()
{
    vector<Phone> Adresses;




    string file = {"supportive/"};
    int cntr;
    cout << "Введите число вводимых элементов" << endl;
    cin >> cntr;
    for (int i = 0; i < cntr; i++)
    {
        char d = i + 48;
        string first {"user"};
        first += d;
        string adress {"adress"};
        adress += d;

        string filename = {"supportive/"};
        filename += to_string(i);

        Phone a{first, first, first, adress, 375291112240 + i, 10 * i, 5 * i};
        Adresses.push_back(a);
        a.to_file(filename);
    }
    Phone b;
    Adresses.push_back(b);
    ofstream fp {"asdsds.txt"};

    cout << "Введите максимальное время" << endl;
    long maxtime;
    cin.ignore(1234, '\n');
    cin >> maxtime;

    cout << "Вывожу пользователей у которых incity time > " << maxtime << endl;
    for (int i = 0; i < Adresses.size(); i++)
    {
        if (Adresses[i].get_incity_time() > maxtime)
            Adresses[i].show();
    }

    cout << "Вывожу пользователей у которых intercity time > 0" << endl;
    for (int i = 0; i < Adresses.size(); i++)
    {
        if (Adresses[i].get_intercity_time() > 0)
            Adresses[i].show();
    }




}