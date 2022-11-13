#include "header.h"


int main()
{
    vector<Phone> Adresses;

    try 
    {
        ifstream file_stream{"supportive.data"};
        size_t cntr;
        file_stream >> cntr;
        cout << cntr;
        Adresses.reserve(cntr);

        for (size_t i = 0; i < cntr; i++)
        {
            string surname;
            string name;
            string father_name;
            string adress;
            long number;
            long incity_time;
            long intercity_time;

            file_stream.get();
            getline(file_stream, surname);
            getline(file_stream, name);
            getline(file_stream, father_name);
            getline(file_stream, adress);

            file_stream >> number >> incity_time >> intercity_time;
            cout << endl << surname << endl << name << endl << father_name << endl << adress << endl << number << endl << incity_time << endl << intercity_time << endl;



            Phone tmp{surname, name, father_name, adress, number, incity_time, intercity_time};
            Adresses.push_back(tmp);
        }
    }
    catch (...)
    {
        cout << "что то не так пошло" << endl;
    }
    

    Phone b;
    Adresses.push_back(b);
    ofstream file_stream {"supportive.data"};
    file_stream << Adresses.size() << endl;
    for (size_t i = 0; i < Adresses.size(); i++)
    {
        Adresses[i].to_file(file_stream); //можно и перегрузить штуку
    }

    cout << "Введите максимальное время" << endl;
    long maxtime;
    cin.ignore(1234, '\n');
    cin >> maxtime;

    cout << "Вывожу пользователей у которых incity time > " << maxtime << endl;
    for (size_t i = 0; i < Adresses.size(); i++)
    {
        if (Adresses[i].get_incity_time() > maxtime)
            Adresses[i].show();
    }

    cout << "Вывожу пользователей у которых intercity time > 0" << endl;
    for (size_t i = 0; i < Adresses.size(); i++)
    {
        if (Adresses[i].get_intercity_time() > 0)
            Adresses[i].show();
    }




}