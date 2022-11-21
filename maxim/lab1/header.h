#pragma once

#include <iostream>
#include <string>


using namespace std;

class Train
{
private:
    //поля класса
    string finish_station;
    int number;
    int start_time;
    int total_places;
    int kupe_places;
    int platzcart_place;

public:
    //конструкторы
    Train(); //ввод с клавиатуры
    Train(string, int, int, int, int, int); //ввод со значений



    //геттеры-сеттеры полей

    //геттеры, возвращают какое то из приватных полей
    string get_finish_station();
    int get_number();
    int get_start_time();
    int get_total_places();
    int get_kupe_places();
    int get_platzcart_places();

    //сеттеры, меняют значение приватных полей
    void set_finish_station(string);
    void set_number(int);
    void set_start_time(int);
    void set_total_places(int);
    void set_kupe_places(int);
    void set_platzcart_places(int);
};