#include "linked_list.h"

int main()
{
    Linked_list list;

    string buf;
    cout << "Введите 5 слов: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> buf;
        list.push_back(buf);
    }

    cout << endl << endl << "Вывожу список на экран: " << endl;
    for (int i = 0; i < list.get_size(); i++)
    {
        cout << list[i].val << endl;
    }
    

    cout << endl << "Введите требуемую строку: " << endl;
    cin >> buf;
    string change_value;
    cout << "Введите значение на которое следует заменить строку: " << endl;
    cin >> change_value;
    

    for (int i = 0; i < list.get_size(); i++)
    {
        if (list[i].val == buf)
        {
            list[i].val = change_value;
        }
    }

    cout << endl << endl << "Вывожу список на экран: " << endl;
    for (int i = 0; i < list.get_size(); i++)
    {
        cout << list[i].val << endl;
    }
    
}