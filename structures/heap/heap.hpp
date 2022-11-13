#include "heap.h"

template<class T>
Heap<T>::Heap()
{
    this->flag = 0;
    this->body = new std::vector<T>;
    body.reserve(100);
}


template<class T>
Heap<T>::Heap(T var)
{
    this->flag = 0;
    this->body = new std::vector<T>;

    body.reserve(101);
    body.push_back(var);
}


template<class T>
Heap<T>::Heap(T* array_ptr, int size)
{
    this->flag = 0;
    this->body = new std::vector<T>;
    body.reserve(100+size);
    for (int i = 0; i < size; ++i)
    {
        body.push_back(array_ptr[i]);
    }
}


template<class T>
Heap<T>::Heap(std::string filename)
{
    std::ifstream fp{filename};
    if (!fp) 
    {
        throw std::runtime_error("Heap constructor: файл не открыт")
    }

    long number_of_elements;
    fp >> number_of_elements;

    std::vector<T> tmp;
    tmp.reserve(number_of_elements);

    int counter = 0;
    T buffer;
    while(!fp.eof())
    {
        fp >> buffer;
        //проверка буфера на вшивость
        tmp.push_back(buffer);
        counter += 1;
    }

    this->flag = 0;
    this->body = new std::vector<T>;
    body.reserve(100 + tmp.size());

    for (int i = 0; i < tmp.size(); ++i)
    {
        this->push_back(buffer[i]);
        this->heapify(i);
    }
}

/*функция восстанавливающая порядок в куче
  работает по принципу: сначала проверяем на то не нулевой ли элемент(корень) сортируем
  потом находим индексы родителя, проверяем правило кучи с родителем,
  потом находим индексы детей, проверяем правило кучи у детей
  вероятно лучше было бы сделать 2 функции heapify_up, heapify_down но пока так вот
  */
template<class T>
void Heap<T>::heapify(int index)
{
    int parent_index;

    if (index == 0)
    {
        //пропускаем
    }
    else if ((index - 1) % 2 == 0)
    {
        parent_index = (index - 1) / 2;
    }
    else if ((index - 2) % 2 = 0)
    {
        parent_index = (index - 2) / 2;
    }
    else 
    {
        throw std::runtime_error("Непредвиденная ошибка heapify");
    }
    if (index != 0)
    {

        if (this->body[index] > this->body[parent_index])
        {
            this->body.swap(index, parent_index);
        }
        heapify(parent_index);
    }

    int first_child_index = (index * 2) + 1;
    int second_child_index = (index * 2) + 1;

    if (this->body.size() < first_child_index + 1)
    {
        //рассчет закончен
    }
    else if (this->body.size() < second_child_index + 1)
    {
        //тут сравнить ток 2 штуки и сделать дело
    }
    else 
    {
        int max_index = -1;
        if (this->body[index] > this->body[first_child_index] && this->body[index] > this->body[second_child_index])
        {
            //все хорошо завершаемся
        }

        else if (this->body[first_child_index] > this->body[second_child_index] && this->body[first_child_index] > this->body[index])
        {
            this->body.swap(index, first_child_index);
            heapify(first_child_index);
        }

        else if (this->body[second_child_index] > this->body[first_child_index] && this->body[second_child_index] > this->body[index])
        {
            this->body.swap(index, second_child_index);
            heapify(second_child_index);
        }

        else 
        {
            throw std::runtime_error("heapify, непредвиденная ошибка2");
        }
    }
}


template<class T>
void Heap<T>::heapify_up(int index)
{
    int parent_index;

    if (index == 0)
    {
        //пропускаем
    }
    else if ((index - 1) % 2 == 0)
    {
        parent_index = (index - 1) / 2;
    }
    else if ((index - 2) % 2 = 0)
    {
        parent_index = (index - 2) / 2;
    }
    else 
    {
        throw std::runtime_error("Непредвиденная ошибка heapify");
    }
    if (index != 0)
    {

        if (this->body[index] > this->body[parent_index])
        {
            this->body.swap(index, parent_index);
        }
        heapify_up(parent_index);
    }
}



template<class T>
void Heap<T>::heapify_down(int index)
{
    int first_child_index = (index * 2) + 1;
    int second_child_index = (index * 2) + 1;

    if (this->body.size() < first_child_index + 1)
    {
        //рассчет закончен
    }
    else if (this->body.size() < second_child_index + 1)
    {
        if (this->body[first_child_index] > this->body[index])
        this->body.swap(index, first_child_index);
        //на этом рассчет оканчивается тк в данном случае уже не будет потомков
    }
    else 
    {
        int max_index = -1;
        if (this->body[index] > this->body[first_child_index] && this->body[index] > this->body[second_child_index])
        {
            //все хорошо завершаемся
        }

        else if (this->body[first_child_index] > this->body[second_child_index] && this->body[first_child_index] > this->body[index])
        {
            this->body.swap(index, first_child_index);
            heapify_down(first_child_index);
        }

        else if (this->body[second_child_index] > this->body[first_child_index] && this->body[second_child_index] > this->body[index])
        {
            this->body.swap(index, second_child_index);
            heapify_down(second_child_index);
        }

        else 
        {
            throw std::runtime_error("heapify, непредвиденная ошибка2");
        }
    }
}


template<class T>
void Heap<T>::add_element(T variable)
{
    this->body.push_back(variable);
    heapify_up(this->body.size() - 1);
    //вроде должно быть вот так вот но тестировать надобно
}


template<class T>
T Heap<T>::remove_head()
{
    T var;
    this->body.swap(this->body.size() - 1, 0);
    var = this->body.pop_back();
    heapify_down(0);

    return var;
}



template<class T>
void Heap<T>::cout_vector()
{
    for (int i = 0; i < this->body.size(); ++i)
    {
        cout << this->body[i] << " ";
    }
}


template<class T>
void Heap<T>::cout_heap()
{
    
}


