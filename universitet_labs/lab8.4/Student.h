//Student.h
#pragma once

#include <iostream>
#include <string>

using namespace std;
struct Student
{
    string name = "";
    uint16_t age = 0;
    bool is_man = 1;
    uint16_t kurs = 0;
    double avg_grade = 0;    

    Student() = default;
    Student(string, uint16_t, bool, uint16_t, double);

    friend ostream& operator<<(ostream& out_s, Student& petya);
    friend istream& operator>>(istream& inp_s, Student& petya);
};