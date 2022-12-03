#include "header.h"


int main()
{
    //создаем массив объектов, для них вызываются конструкторы без параметров (ввод с клавиатуры)
    Train massiv[4];

    string destination;
    int max_time;
    int minutes;
    int hours;


    //вводим параметры из условий
    cout << endl << endl << endl << "Введите требуемый пункт назначения " << endl;
    cin >> destination;
    cout << endl << "Введите максимальное время отправления в формате *часы минуты* через пробел " << endl;
    
    cin >> hours;
    cin >> minutes;
    max_time = hours * 60 + minutes;

    cout << "Вывожу поезда с совпадающим местом назначения: " << endl;
    for (size_t i = 0; i < 4; i++)
    {
        //сравниваем пункты назначения
        if (massiv[i].get_finish_station() == destination)
        {
            cout << massiv[i].get_finish_station() << ' ';
            cout << massiv[i].get_number() << ' ';
            cout << massiv[i].get_start_time()/60 << ':' << massiv[i].get_start_time()%60 << ' '; //время записано в минутах, выводим его делением на 60 и остатком от деления на 60
            cout << massiv[i].get_total_places() << ' ';
            cout << massiv[i].get_kupe_places() << ' ';
            cout << massiv[i].get_platzcart_places() << endl << endl;
        }
    }


    cout << "Вывожу поезда с совпадающим местом назначения, отправляющиеся раньше заданного времени: " << endl;
    for (size_t i = 0; i < 4; i++)
    {
        //сравниваем пункты назначения и учитываем максимальное время отправления
        if (massiv[i].get_finish_station() == destination and massiv[i].get_start_time() < max_time)
        {
            cout << massiv[i].get_finish_station() << ' ';
            cout << massiv[i].get_number() << ' ';
            cout << massiv[i].get_start_time()/60 << ':' << massiv[i].get_start_time()%60 << ' '; //время записано в минутах, выводим его делением на 60 и остатком от деления на 60
            cout << massiv[i].get_total_places() << ' ';
            cout << massiv[i].get_kupe_places() << ' ';
            cout << massiv[i].get_platzcart_places() << endl << endl;
        }
    }

 
    cout << "Вывожу поезда с совпадающим местом назначения и свободными местами: " << endl;
    for (size_t i = 0; i < 4; i++)
    {
        //сравниваем пункты назначения, и дополнительно учитываем число свободных мест больше 0
        if (massiv[i].get_finish_station() == destination and massiv[i].get_total_places() > 0)
        {
            cout << massiv[i].get_finish_station() << ' ';
            cout << massiv[i].get_number() << ' ';
            cout << massiv[i].get_start_time()/60 << ':' << massiv[i].get_start_time()%60 << ' '; //время записано в минутах, выводим его делением на 60 и остатком от деления на 60
            cout << massiv[i].get_total_places() << ' ';
            cout << massiv[i].get_kupe_places() << ' ';
            cout << massiv[i].get_platzcart_places() << endl << endl;
        }
    }

}