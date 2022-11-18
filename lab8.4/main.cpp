//main.cpp
/*Разработать функции для выполнения базовых операций над линейными структурами, 
  содержащими записи со сведениями о студентах: ФИО, возраст, пол, курс,  успеваемость. 
  Реализовать функции заполнения очереди значениями из файла и вывода элементов очереди в файл.*/
#include "Queue.h"


struct Student
{
    string name = "";

    uint16_t age = 0;
    bool is_man = 1;
    uint8_t kurs = 0;
    double avg_grade = 0;    

    Student(){}
    Student(string name, uint16_t age, bool is_man, uint8_t kurs, double avg_grade):
    name(name), age(age), is_man(is_man), kurs(kurs), avg_grade(avg_grade) {}

    friend ostream& operator<<(ostream& out_s, Student petya)
    {
        out_s << petya.name << ' ' << petya.age << ' ' << petya.is_man << ' ' << petya.kurs << ' ' << petya.avg_grade << ' ';
        out_s.flush();
        return out_s;
    }

};



int main()
{
    Queue<Student> que;
    Queue<Student> que_second;

    auto petya = Student("Petrov Petr Petrovich", 21, 1, 2, 7.2);
    que.push(petya);

    auto out_s = ofstream("supportive.data");
    que.flush_f(out_s);
}