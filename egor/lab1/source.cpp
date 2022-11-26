#include "header.h"



/*
8. Patient: Фамилия, Имя, Отчество, Адрес, Номер медицинской карты, Диагноз. Создать массив объектов. Вывести:
а) список пациентов, имеющих данный диагноз;
б) список пациентов, номер медицинской карты которых находится в заданном интервале.*/
//конструктор ввода с клавиатуры
Patient::Patient()
{
    cout << "Введите Фамилию" << endl;
    cin >> last_name;
    cout << "Введите Имя" << endl;
    cin >> first_name;
    cout << "Введите Отчество" << endl;
    cin >> father_name;
    cout << "Введите Адрес *без пробелов*" << endl;
    cin >> adress;
    cout << "Введите Номер медицинской карты" << endl;
    cin >> medical_card_number;
    cout << "Введите Диагноз" << endl;
    cin >> diagnos;
}

//конструктор с параметрами
Patient::Patient(string ln, string fn, string fath_n, string addr, int card_num, string diag)
{
    last_name = ln;
    first_name = fn;
    father_name = fath_n;
    adress = addr;
    medical_card_number = card_num;
    diagnos = diag;
}

//геттеры
string Patient::get_first_name()
{
    return first_name;
}
string Patient::get_last_name()
{
    return last_name;
}

string Patient::get_father_name()
{
    return father_name;
}

string Patient::get_adress()
{
    return adress;
}

int Patient::get_medical_card_number()
{
    return medical_card_number;
}

string Patient::get_diagnos()
{
    return diagnos;
}


//сеттеры
void Patient::set_first_name(string f_n)
{
    first_name = f_n;
}
void Patient::set_last_name(string l_n)
{
    last_name = l_n;
}
void Patient::set_father_name(string fath_n)
{
    father_name = fath_n;
}

void Patient::set_adress(string adr)
{
    adress = adr;
}

void Patient::set_medical_card_number(int num)
{
    medical_card_number = num;
}

void Patient::set_diagnos(string diag)
{
    diagnos = diag;
}

