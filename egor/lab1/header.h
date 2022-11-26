#pragma once

#include <iostream>
#include <string>


using namespace std;

/*
8. Patient: Фамилия, Имя, Отчество, Адрес, Номер медицинской карты, Диагноз. Создать массив объектов. Вывести:
а) список пациентов, имеющих данный диагноз;
б) список пациентов, номер медицинской карты которых находится в заданном интервале.*/
class Patient
{
private:
    //поля класса
    string first_name;
    string last_name;
    string father_name;
    string adress;
    int medical_card_number;
    string diagnos;

public:
    //конструкторы
    Patient(); //ввод с клавиатуры
    Patient(string, string, string, string, int, string); //ввод со значений



    //геттеры-сеттеры полей

    //геттеры, возвращают какое то из приватных полей
    string get_first_name();
    string get_last_name();
    string get_father_name();
    string get_adress();
    int get_medical_card_number();
    string get_diagnos();

    //сеттеры, меняют значение приватных полей
    void set_first_name(string);
    void set_last_name(string);
    void set_father_name(string);
    void set_adress(string);
    void set_medical_card_number(int);
    void set_diagnos(string);
};