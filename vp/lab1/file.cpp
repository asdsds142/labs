#include "header.h"

//функция поиска Кмаксимального (вариант 14) в самом низу, впринципе еще чутка подрихтовать и будет готово


Vector::Vector(int n)
{
    this->memory = n;
    this->ptr = new int[n];
}


Vector::~Vector()
{
    delete ptr;
}


void Vector::reserve(int n)
{
    int *p = new int[this->memory+n];
    for (int i = 0; i < this->size; i++)
    {
        p[i] = this->ptr[i];
    }
    delete this->ptr;
    this->ptr = p;
    this->memory += n;
}


void Vector::push_back(int value)
{
    if (this->size < this->memory)
    {
        this->ptr[size] = value;
        this->size += 1;
    }

    else
    {
        reserve(1);
        this->ptr[size] = value;
        this->size += 1;
    }
}


int Vector::pop_back()
{
    int a = this->ptr[size];
    this->size -= 1;

    return a;
}


int Vector::find_kmax(int k)
{
    if (this->size == 0)
    {
        cout << "В данном массиве отсутствуют элементы, поиск невозможен" << endl;
        return -1;
    }


    if (this->size < k)
    {
        cout << "в данном массиве меньше " << k << " элементов, поиск невозможен." << endl;
        return -2;
    }

    int *p = new int[this->size];
    for (int i = 0; i < this->size; i++)
        p[i] = this->ptr[i];


    int min = this->ptr[0];
    int max = this->ptr[0];
    short min_index = 0;
    short max_index = 0;

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < this->size; j++)
        {
            if (p[i] < min)
            {
                min = p[i];
                min_index = i;
            }
            if (p[i] > max)
            {
                max = p[i];
                max_index = i;
            }
        }
        if (i == k-1)
        {
            cout << k << "-тое максимальное значение = " << max << endl;
            return max;
        }

        p[max_index] = min;
        max = min;
    }


}

