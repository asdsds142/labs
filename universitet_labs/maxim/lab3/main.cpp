#include "linked_list.h"

int main()
{
    Linked_list list1;
    Linked_list list2;
    Linked_list list3;
    for (int i = 20; i > 0; i--)
    {
        list1.push_back(rand()%45); //записываем рандомные числа в списки
        list2.push_back(rand()%45);
        list3.push_back(rand()%45);
    }
    

    //печатаем до, сортируем, печатаем после
    cout << "Список 1 до: " << endl;
    list1.print(); 
    list1.bubble_sort(); 
    cout << "Список 1 плсле: " << endl;
    list1.print();
    cout << "Список 2 до: " << endl;
    list2.print();
    list2.selection_sort();
    cout << "Список 2 после: " << endl;
    list2.print();
    cout << "Список 3 до: " << endl;
    list3.print();
    list3.insertion_sort();
    cout << "Список 3 после: " << endl;
    list3.print();
    cout << list1.get_size();
}