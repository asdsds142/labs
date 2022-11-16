//Queue.h
#pragma once

#include <iostream>
#include <vector>
#include <fstream>
    

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
};

template<class T>
Queue<T>::Queue():
size_(STANDART_SIZE), body_(new T[STANDART_SIZE]), end_(0)
{
}

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
    delete[] this->body;
}

template<class T>
void Queue<T>::push(T value)
{
    if (this->end_ ==)
    {
      /* code */
    }
    
}