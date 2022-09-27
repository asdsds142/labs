#pragma once


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

/*
14. Phone: Фамилия, Имя, Отчество, Адрес, Номер, Время внутригородских разговоров, Время междугородних разговоров. Создать массив объектов. Вывести:
а) сведения об абонентах, время внутригородских разговоров которых превышает заданное;
б) сведения об абонентах, воспользовавшихся междугородней связью;
*/


class Phone
{
private:
    string name;
    string surname;
    string father_name;
    string adress;
    long number;
    long intercity_time;
    long incity_time;


public:
    Phone();
    Phone(string);
    Phone(string, string, string, string, long, long, long);
    ~Phone();

    void set_name(string);
    void set_surname(string);
    void set_father_name(string);
    void set_adress(string);
    void set_number(long);
    void set_intercity_time(long);
    void set_incity_time(long);

    string get_name();
    string get_surname();
    string get_father_name();
    string get_adress();
    long get_number();
    long get_intercity_time();
    long get_incity_time();

    void to_file(string);
    void show();
    void add_intercity_call_time(long);
    void add_incity_call_time(long);

};