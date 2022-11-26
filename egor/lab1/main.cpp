#include "header.h"


int main()
{
    //создаем массив объектов, для них вызываются конструкторы без параметров (ввод с клавиатуры)
    Patient pat[4];

    string diagnos;
    int start;
    int finish;


    //вводим параметры из условий
    cout << endl << "Введите диагноз " << endl;
    cin >> diagnos;
    cout << endl << "Введите минимальный номер мед. карты  " << endl;
    cin >> start;
    cout << endl << "Введите максимальный номер мед. карты  " << endl;
    cin >> finish;

    cout << "Вывожу пациентов с совпадающим диагнозом: " << endl;
    for (int i = 0; i < 4; i++)
    {
        //сравниваем диагнозы
        if (pat[i].get_diagnos() == diagnos)
        {
            cout << pat[i].get_first_name() << ' ';
            cout << pat[i].get_last_name() << ' ';
            cout << pat[i].get_father_name() << ' ';
            cout << pat[i].get_adress() << ' ';
            cout << pat[i].get_medical_card_number() << ' ';
            cout << pat[i].get_diagnos() << endl << endl;
        }
    }


    cout << "\n\n" <<  "Вывожу пациентов с номерами медицинских карт лежащих в диапазоне [" << start << ", " << finish << "] "  << endl;
    for (size_t i = 0; i < 4; i++)
    {
        //сравниваем номера медицинских карт с заданными пределами
        if (pat[i].get_medical_card_number() >= start and pat[i].get_medical_card_number() <= finish)
        {
            cout << pat[i].get_first_name() << ' ';
            cout << pat[i].get_last_name() << ' ';
            cout << pat[i].get_father_name() << ' ';
            cout << pat[i].get_adress() << ' ';
            cout << pat[i].get_medical_card_number() << ' ';
            cout << pat[i].get_diagnos() << endl << endl;
        }
    }

}