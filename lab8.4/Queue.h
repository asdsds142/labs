//Queue.h
#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
    

using namespace std;

//очередь
template<class T>
class Queue 
{
  private:
    static const uint64_t STANDART_SIZE = 100;
    uint64_t capacity_ = STANDART_SIZE;
    T* body_ = nullptr;
    uint64_t end_ = 0;
    uint64_t start_ = 0;

  public:
    Queue();

    Queue(const Queue&);
    ~Queue();
    Queue& operator=(const Queue&);

    uint64_t size();
    void push(T);
    T pop();

    Queue& fill_f(ifstream&);
    Queue& flush_f(ofstream&);
};

//конструктор по умолчанию
template<class T>
Queue<T>::Queue():
capacity_(STANDART_SIZE), body_(new T[STANDART_SIZE]), end_(0) {}


//конструктор копирования
template<class T>
Queue<T>::Queue(const Queue& other):
capacity_(other.capacity_), body_(new T[other.capacity_]), end_(other.end_), start_(other.start_)
{
    for (size_t i = 0; i < other.capacity_; ++i)
    {
        this->body_[i] = other.body_[i];        
    }
}


//оператор присваивания
template<class T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
    delete[] this->body_;


    this->body_ = new T[other.capacity_];
    this->capacity_ = other.capacity_;
    this->end_ = other.end_;
    this->start_ = other.start_;

    for (size_t i = 0; i < other.capacity_; ++i)
    {
        this->body_[i] = other.body_[i];        
    }
    return *this;
}

//деструктор
template<class T>
Queue<T>::~Queue()
{
    delete[] this->body_;
}


//пуш элементов в очередь
template<class T>
void Queue<T>::push(T value)
{
    if (this->end_ + 1 == this->start_ || (this->end_ == this->capacity_ - 1 && this->start_ == 0))
    {
        throw std::runtime_error("переполнение очереди");
    }

    this->body_[this->end_] = value;
    this->end_++;
    if (this->end_ == this->capacity_)
    {
        this->end_ = 0;
    }

}


//поп элементов из очереди
template<class T>
T Queue<T>::pop()
{
    if (this->start_ == this->end_)
    {
        throw std::runtime_error("очередь пуста, ненадо попать");
    }

    this->start_++;

    if (this->start_ == this->capacity_)
    {
        this->start_ = 0;
        return this->body_[this->capacity_ - 1];
    }
    
    return this->body_[this->start_ - 1];
}

//заполнение из файлового потока
template<class T>
Queue<T>& Queue<T>::fill_f(ifstream& input_s)
{
    size_t number_of_elements;
    input_s >> number_of_elements;

    for (size_t i = 0; i < number_of_elements; ++i)
    {
        T tmp;
        input_s >> tmp;
        this->push(tmp);
    }

    return *this;
}


//вывод в файловый поток
template<class T>
Queue<T>& Queue<T>::flush_f(ofstream& out_s)
{
    out_s << this->end_ << '\n';
    while (this->start_ != this->end_)
    {
        auto tmp = this->pop();
        out_s << tmp << '\n';
    }
    out_s << endl;
    
    return *this;
}

//возвращаем число элементов
template<class T>
uint64_t Queue<T>::size()
{
    return this->end_;
}