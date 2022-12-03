//main.cpp
/*Разработать функции для выполнения базовых операций над линейными структурами, 
  содержащими записи со сведениями о студентах: ФИО, возраст, пол, курс,  успеваемость. 
  Реализовать функции заполнения очереди значениями из файла и вывода элементов очереди в файл.*/

#include "Queue.h"
#include "Student.h"


int main()
{
    Queue<Student> que;
    Queue<Student> que_second;

    {
        auto if_str = ifstream("supportive.data");
        que.fill_f(if_str);
    }
    que_second = que;

    Student min_aged;
    constexpr uint64_t FALSE_AGE = 10000;
    uint64_t min_age = FALSE_AGE;
    cout << "Введите курс" << endl;
    uint64_t num;
    cin >> num;


    for (size_t i = que.size(); i > 0; i--)
    {
        Student tmp = que.pop();
        if (tmp.age < min_age && tmp.kurs == num)
        {
            min_age = tmp.age;
            min_aged = tmp;
        }
    }
    
    min_age == FALSE_AGE ? cout << "not found" << endl : cout << min_aged << endl;

        

    auto out_s = ofstream("supportive.data");
    que_second.flush_f(out_s);

}