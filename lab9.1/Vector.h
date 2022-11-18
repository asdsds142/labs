//Vector.h
#pragma once

#include "Vector_class_description.h"

template<typename T>
Vector<T>::Vector()
{
    try
    {
        this->body_ = new T[STANDART_SIZE];
    }
    catch(...)
    {

        throw v_memory_allocate_exception("asdf");
    }
    
    this->size_ = STANDART_SIZE;
}

template<typename T>
Vector<T>::Vector(const Vector& other):
size_(other.size_)
{
    try
    {
        this->body_ = new T[other.size_];
    }

    catch(const std::exception& e)
    {

        throw v_memory_allocate_exception("aas");
    }
    
    for (size_t i = 0; i < size_; ++i)
    {
        this->body_[i] = other.body_[i];
    }
    
}

template<typename T>
Vector<T>::~Vector()
{
    delete[] this->body_;
}


template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other)
{
    delete[] this->body_;

    try
    {
        this->body_ = new T[other.size_];
    }

    catch(const std::exception& e)
    {
        throw v_memory_allocate_exception("");
    }

    this->size_ = other.size_();
    for (size_t i = 0; i < size_; ++i)
    {
        this->body_[i] = other.body_[i];
    }
}

template<typename T>
Vector<T>& Vector<T>::operator+=(const Vector& other)
{
    if (this->size_ != other.size_)
    {
        throw v_wrong_sizing_exception("");
    }
    
    for (size_t i = 0; i < size_; ++i)
    {
        this->body_[i] += other.body_[i];
    }
}

template<typename T>
Vector<T> Vector<T>::operator+(const Vector& other) const
{
    auto return_value = Vector(*this);
    return_value += other;
    return return_value;
}

template<typename T>
Vector<T>& Vector<T>::operator-=(const Vector& other) 
{
    if (this->size_ != other.size_)
    {
        throw v_wrong_sizing_exception("");
    }
    
    for (size_t i = 0; i < size_; ++i)
    {
        this->body_[i] -= other.body_[i];
    }
}

template<typename T>
Vector<T> Vector<T>::operator-(const Vector& other) const
{
    auto return_value = Vector(*this);
    return_value += other;
    return return_value;
}

template<typename T>
Vector<T>& Vector<T>::operator*=(double scalar)
{
    for (size_t i = 0; i < this->size_; ++i)
    {
        this->body_[i] *= scalar;
    }
    return *this;
}

template<typename T>
Vector<T> Vector<T>::operator*(double scalar) const
{
    auto return_value = Vector(*this);
    return_value *= scalar;
    return return_value;
}

template<typename T>
Vector<T>& Vector<T>::operator/=(double scalar) 
{
    if (scalar == 0)
    {
        throw v_division_by_zero_exception("");
    }

    return *this *= (1/scalar);
}

template<typename T>
Vector<T> Vector<T>::operator/(double scalar) const
{
    if (scalar == 0)
    {
        throw v_division_by_zero_exception("");
    }

    return *this * (1/scalar);
}

template<typename T>
void Vector<T>::show()
{
    for (size_t i = 0; i < this->size_; ++i)
    {
        std::cout << this->body_[i];
    }
    
}


template<typename T>
T& Vector<T>::operator[](uint64_t index)
{
    return this->body_[index];
}


template<typename T>
T& Vector<T>::at(uint64_t index)
{
    if (index < 0 || index >= this->size_)
    {
        throw v_wrong_index_exception("at");
    }
    
    return this->body_[index];
}