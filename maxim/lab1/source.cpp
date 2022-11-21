#include "header.h"


//конструктор ввода с клавиатуры
Train::Train()
{
    cout << "Введите пункт назначения" << endl;
    cin >> finish_station;
    cout << "Введите номер поезда" << endl;
    cin >> number;
    cout << "Введите время отправления в формате *часы минуты* через пробел" << endl;
    int minutes;
    int hours;
    cin >> hours;
    cin >> minutes;
    start_time = hours * 60 + minutes;
    cout << "Введите число общих мест" << endl;
    cin >> total_places;
    cout << "Введите число купейных мест" << endl;
    cin >> kupe_places;
    cout << "Введите число плацкартных мест" << endl;
    cin >> platzcart_place;
}

//конструктор с параметрами
Train::Train(string finish, int num, int start, int total, int kupe, int platzkart)
{
    finish_station = finish;
    number = num;
    start_time = start;
    total_places = total;
    kupe_places = kupe;
    platzcart_place = platzkart;
}

//геттеры
string Train::get_finish_station() 
{
    return finish_station;
}

int Train::get_kupe_places()
{
    return kupe_places;
}

int Train::get_total_places()
{
    return total_places;
}

int Train::get_platzcart_places()
{
    return platzcart_place;
}

int Train::get_number()
{
    return number;
}

int Train::get_start_time()
{
    return start_time;
}


//сеттеры
void Train::set_finish_station(string value)
{
    finish_station = value;
}

void Train::set_number(int value)
{
    number = value;
}

void Train::set_start_time(int value)
{
    start_time = value;
}

void Train::set_total_places(int value)
{
    total_places = value;
}

void Train::set_kupe_places(int value)
{
    kupe_places = value;
}

void Train::set_platzcart_places(int value)
{
    platzcart_place = value;
}

