//Queue.h
#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
    

using namespace std;

//стек
class Stack 
{
  private:
    static const int STANDART_SIZE = 100; //размер по умолчанию
    int size_ = STANDART_SIZE; //переменная хранящая текущий максимальный размер
    int* body_ = nullptr; //динамический массив
    int end_ = 0; //индекс элемента следующего за последним

  public:
    //конструктор

    Stack();

    //конструктор копирования, оператор присваивания, деструктор

    Stack(const Stack&);
    ~Stack();
    Stack& operator=(const Stack&);

    //методы, возврат размера, засунуть элемент, удалить элемент (вернув значение), вывести на экран

    int size();
    int push(int);
    int pop();
    void show_without_pop();

    //перегруженные операторы ввода-вывода 

    friend Stack& operator>>(Stack&, int&);
    friend Stack& operator<<(Stack&, int);

    
    //функции удаляющие четные/нечетные (по индексам) элементы стека

    void pop_even();
    void pop_odd();


};
