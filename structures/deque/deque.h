//deque.h
//TODO тестирование
#include "deque_class_description.h"

//конструктор без параметров
template<class T>
Deque<T>::Deque() 
{
    this->body_ = new T(k_max_size);
}

//конструктор копирования
template<class T>
Deque<T>::Deque(const Deque& other) : size(other.size_), k_max_size(other.k_max_size), 
        first_index(other.first_index_), last_index(other.last_index_)
{
    this->body_ = new T(other.k_max_size);
    for (size_t i = 0; i < other.k_max_size; ++i)
    {
        this->body_[i] = other.body_[i];
    }
}

//деструктор
template<class T>
Deque<T>::~Deque()
{
    delete this->body_;
}

//оператор присваивания
template<class T>
class Deque<T>& Deque<T>::operator=(const Deque& other) //вроде тут нужно слово класс иначе компилятор ругается в бдереве было так
{
    this->k_max_size = other.k_max_size;
    this->first_index_ = other.first_index_;
    this->last_index_ = other.last_index_;

    this->body_ = new T(k_max_size);
    for (size_t i = 0; i < other.k_max_size; ++i)
    {
        this->body_[i] = other.body_[i];
    }
}

//конструктор копирования
template<class T>
Deque<T>::Deque(Deque&& other)
{
    this->body_ = other.body_;
    other->body_ = nullptr;
}

//метод добавляющий элемент в конец
template<class T>
void Deque<T>::push_back(T value)
{
    if (this->size_ == this->k_max_size)
    {
        throw std::runtime_error("Переполнение очереди");
    }

    else 
    {
        ++size;
        if (this->last_index_ == (this->k_max_size - 1))
        {
            this->last_index_ = -1;
        }

        this->last_index_ += 1;
        this->body[this->last_index_] = value;
        if (this->first_index_ == -1 || this->first_index_ == this->k_max_size)
        {
            this->first_index_ = 0; 
        }
    }
}

//метод засовывающий элемент в начало очереди
template<class T>
void Deque<T>::push_front(T value)
{
    if (this->size_ == this->k_max_size)
    {
        throw std::runtime_error("Переполнение очереди");
    }

    else 
    {
        ++size;
        if (this->first_index_ <= 0)
        {
            this->first_index_ = this->k_max_size - 1;
        }

        this->first_index_ -= 1;
        this->body_[this->first_index_] = value;
        if (this->last_index_ == -1)
        {
            ++this->last_index_; //проверить префиксный инкремент
        }
    }
}

//метод удаляющий последний элемент очереди
template<class T>
T Deque<T>::pop_back()
{
    if (this->size_ == 0)
    {
        throw std::runtime_error("Deque::pop_back() очередь не содержит элементов");
    }

    else
    {
        //занулять элемент не нужно, поэтому просто уменьшаем индекс и при следующем добавлении будет писать уже поверх него
        --size;
        if (this->last_index_ != 0)
        {
            --this->last_index_;
            return this->body_[this->last_index_ + 1];
        }
        else
        {
            this->last_index_ = this->k_max_size - 1;
            return this->body_[0];
        }
        
        
    }
}

//метод удаляющий первый элемент очереди
template<class T>
T Deque<T>::pop_front()
{
    if (this->size_ == 0)
    {
        throw std::runtime_error("Deque::pop_back() очередь не содержит элементов");
    }

    else
    {
        //по аналогии с предыдущим
        --this->size_;
        if (this->first_index_ != k_max_size - 1)
        {
            ++this->first_index_;
            return this->body[this->first_index - 1];
        }
        else
        {
            this->first_index_ = 0;
            return this->body[k_max_size - 1];
        }
        
    }
}