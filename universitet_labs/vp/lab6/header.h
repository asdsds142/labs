#pragma once

#include <iostream>
#include <vector>
#include <string>


using namespace std;

/*    2. Сформировать массив структур, каждый элемент которого содержит следующие че­тыре поля: 
курс (вводим);
фамилия, имя отчество (вводим);
массив оценок в десятибалльной системе (вводим);
признак.
Для каждого студента получить одно из следующих значений признака: 
5 –отличник (только 9 и (или) 10), 4 – хорошист (нет оценок, меньше 6, но не все  9 или 10, 
а есть 6 и (или) 7 и (или) 8), 3 – троечник (нет оценок, меньше 4, но есть 4 и (или) 5), 
2 – неуспеваю­щий (есть 1 и (или) 2 и (или) 3). 
Рассорти­ровать массив структур по курсам, внутри курса – по этому полученному признаку.*/

struct stud
{
    string name;
    int scorenumber;
    int *p;
    int kurs;
    short status;
    stud();
    stud(int);
    void show();
    short get_status();
};


void sort_status(stud[], int number);
void sort_kurs(stud[], int number);


