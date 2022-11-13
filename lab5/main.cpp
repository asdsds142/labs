//main.cpp
#include "Dictionary.h"
#include <unistd.h>


//Иммитация бурной деятельности
void data_analysis()
{
    cout << "Analysing data";
    for (size_t i = 0; i < 3; ++i)
    {
        cout << '.';
        flush(cout); //противостоим буферизации
        sleep(1);
    }
    
    cout << endl << "Data confirmed." << endl;
}

// -//-
void data_adder()
{
    cout << "Data processing, please wait";
    for (size_t i = 0; i < 7; ++i)
    {
        cout << '.';
        flush(cout); //противостоим буферизации
        sleep(1);
    }
    cout << endl;
}

int main()
{
    system("clear");
    dDictionary first_dict;

    while (1) 
    {
        int tmp;
        cout << "Введите опцию\n1. Добавить элемент\n2. Вывести дату последнего изменения \n3. Показать словарь\n4. Выход из программы" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cin >> tmp;

        if (tmp == 4)
        {
            system("clear");
            break;
        }

        else if (tmp == 1)
        {
            string word;
            string translation;

            system("clear");
            cout << "Введите слово" << endl;
            cin >> word;
            data_analysis();
            system("clear");
            cout << "Введите перевод" << endl;
            cin >> translation;
            data_analysis();

            system("clear");
            data_adder();
            first_dict.add_pair(word, translation);

            cout << "Введено успешно" << endl << endl;
        }

        else if (tmp == 2)
        {
            system("clear");
            first_dict.get_time();
        }

        else if(tmp == 3)
        {
            system("clear");
            first_dict.show();
        }

        else 
        {
            system("clear");
            cout << "Ошибка ввода" << endl;
            continue;
        }

    }

}