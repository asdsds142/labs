//Queue.h
#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
    

using namespace std;

template<class T>
class Queue 
{
  private:
    static const uint64_t STANDART_SIZE = 100;
    uint64_t size_;
    T* body_;
    uint64_t end_;

  public:
    Queue();

    Queue(const Queue&);
    ~Queue();
    Queue& operator=(const Queue&);

    void push(T);
    T pop();

    Queue& fill_f(ifstream&);
    Queue& flush_f(ofstream&);
};

template<class T>
Queue<T>::Queue():
size_(STANDART_SIZE), body_(new T[STANDART_SIZE]), end_(0) {}

template<class T>
Queue<T>::Queue(const Queue& other):
size_(other.size_), body_(new T[other.size_]), end_(other.end_)
{
    for (size_t i = 0; i < other.size_; ++i)
    {
        this->body_[i] = other.body_[i];        
    }
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
    delete[] this->body_;


    this->body_ = new T[other.size_];
    this->size_ = other.size_;
    this->end_ = other.end_;

    for (size_t i = 0; i < other.size_; ++i)
    {
        this->body_[i] = other.body_[i];        
    }
}

template<class T>
Queue<T>::~Queue()
{
    delete[] this->body_;
}

template<class T>
void Queue<T>::push(T value)
{
    if (this->end_ == this->size_)
    {
        throw std::runtime_error("переполнение очереди");
    }

    this->body_[this->end_] = value;
    this->end_++;   
}

template<class T>
T Queue<T>::pop()
{
    if (this->end_ == 0)
    {
        throw std::runtime_error("очередь пуста, ненадо попать");
    }

    this->end_--;
    return this->body_[this->end_];
}


template<class T>
Queue<T>& Queue<T>::fill_f(ifstream& input_s)
{
    T tmp;
    while(!input_s.eof())
    {
        input_s >> tmp;
        this->push(tmp);
    }

    return *this;
}

template<class T>
Queue<T>& Queue<T>::flush_f(ofstream& out_s)
{
    while (this->end_ != 0)
    {
        auto tmp = this->pop();
        cout << tmp;
        out_s << tmp << '\n';
    }
    out_s << endl;
    
    return *this;
}