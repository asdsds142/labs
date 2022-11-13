//deque_class_description.h
#pragma once

#include <iostream>

template<class T>
class Deque
{
private:
    T* body_; //массив элементов, собсна сама очередь
    const size_t k_max_size = 100; //подумать еще может какие то поля следует сделать публичными
    size_t size_ = 0;
    int64_t first_index_ = -1;
    int64_t last_index_ = -1;
public:
    Deque();
    Deque(int);
    Deque(const Deque&);
    Deque(Deque&&);

    ~Deque();
    Deque& operator=(const Deque&);

    void push_back(T);
    void push_front(T);
    T pop_back();
    T pop_front();

    T get_first();
    T get_last()

};