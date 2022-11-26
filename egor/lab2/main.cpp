#include <iostream>

#include "String.h"
#include <string> //исключительно для ввода с клавиатуры


//меняем местами 2 строки, функция для сортировки
void swap(String& first, String& second)
{
    String tmp = first;
    first = second;
    second = tmp;
}


//сортировка, сравниваем сортируем
void bubble_sort(String* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}


int main()
{
    String str1[5]; //создаем массив строк

    for (size_t i = 0; i < 5; i++) //в этом цикле вводим строки с клавиатуры
    {
        char buf[100] = "";
        cin.getline(buf, 100);
        str1[i] = buf;
    }

    cout << endl << endl;
    for (size_t i = 0; i < 5; i++) // выводим на экран проверить правильность записывания
    {
        str1[i].show();
    }

    bubble_sort(str1, 5); //сортируем

    cout << endl << endl << endl;
    for (size_t i = 0; i < 5; i++) //выводим снова, проверить правильность сортировки
    {
        str1[i].show();
    }
    

}