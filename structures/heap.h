#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>


/*Класс представляющий собой двоичную кучу и функции
  методы для работы с ней.
  
  левый потомок вершины с индексом i имеет индекс 2*i+1,
  правый потомок вершины с индексом i имеет индекс 2*i+2.
*/
template<class T>
class Heap
{
private:
    //возможно тут еще нужен будет макссайз
    std::vector<T> body;
    bool flag;

    void heapify(int index);
    void heapify_up(int index);
    void heapify_down(int index);
    
public:
    Heap();
    Heap(T);
    Heap(T*, int);
    Heap(std::string);
    ~Heap();

    T get_head_value();
    T remove_head();
    void cout_heap();
    void cout_vector();
    void to_file(string);
    void add_element(T);

};


