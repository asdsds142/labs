//student.cpp
#include "Student.h"

ostream& operator<<(ostream& out_s, Student& petya)
{
    out_s << petya.name << ' ' << petya.age << ' ' << petya.is_man << ' ' << petya.kurs << ' ' << petya.avg_grade << ' ';
    out_s.flush();
    return out_s;
}

istream& operator>>(istream& inp_s, Student& petya)
{
    inp_s >> petya.name >> petya.age >> petya.is_man >> petya.kurs >> petya.avg_grade;
    return inp_s;
}

Student::Student(string name, uint16_t age, bool is_man, uint16_t kurs, double avg_grade):
    name(name), age(age), is_man(is_man), kurs(kurs), avg_grade(avg_grade) {}