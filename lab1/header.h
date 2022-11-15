#pragma once


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "../tools/tools.h"

using namespace std;

/*
14. Phone: Фамилия, Имя, Отчество, Адрес, Номер, Время внутригородских разговоров, Время междугородних разговоров. Создать массив объектов. Вывести:
а) сведения об абонентах, время внутригородских разговоров которых превышает заданное;
б) сведения об абонентах, воспользовавшихся междугородней связью;
*/

class Phone
{
private:
    
    string surname;
    string name;
    string father_name;
    string adress;
    long number;
    long incity_time;
    long intercity_time;


public:
    Phone();
    Phone(ifstream&);
    Phone(string, string, string, string, long, long, long);
    ~Phone() = default;

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

    void to_file(ofstream&);
    void show();
    void add_intercity_call_time(long);
    void add_incity_call_time(long);

};


