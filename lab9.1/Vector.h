//Vector.h
#pragma once

#include "Vector_class_description.h"

template<typename T> 
T* Vector<T>::try_allocate(uint64_t size)
{
    T* return_value = nullptr;
    for (size_t i = 0; i < 10; i++) //пробуем 10 раз не получается ну значит не получается
    {
        try
        {
            return_value = new T[size];
            break;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    if (!return_value)
    {
        throw v_memory_allocate_exception("try_allocate_failed");
    }

    return return_value;    
}

template<typename T>
Vector<T>::Vector():
body_(try_allocate(STANDART_SIZE)), size_(STANDART_SIZE), left_bound(0), right_bound(STANDART_SIZE - 1)
{
}

template<typename T>
Vector<T>::Vector(int64_t left_bound, int64_t right_bound):
body_(try_allocate(abs(right_bound - left_bound))), size_(abs(right_bound - left_bound)), left_bound(left_bound), right_bound(right_bound)
{
}

template<typename T>
Vector<T>::Vector(const Vector& other):
body_(try_allocate(other.size_)), size_(other.size_), left_bound(other.left_bound), right_bound(other.right_bound)
{
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

    this->body_ = try_allocate(other.size_);
    this->size_ = other.size_;
    this->left_bound = other.left_bound;
    this->right_bound = other.right_bound;

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
double Vector<T>::operator*(const Vector& other) const
{
    if (this->size_ != other.size_)
    {
        throw v_wrong_sizing_exception("scalar_product");
    }
    
    double return_value = 0;

    for (size_t i = 0; i < this->size_; ++i)
    {
        return_value += (this->body_[i] * other.body_[i]);
    }

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
        std::cout << this->body_[i] << ' ';
    }
    std::cout << std::endl;
    
}


template<typename T>
T& Vector<T>::operator[](int64_t index)
{
    if (this->left_bound < this->right_bound)
    {   
        return this->body_[index - this->left_bound];
    }
    else
    {
        return this->body_[this->left_bound - index];
    }

}


template<typename T>
T& Vector<T>::at(int64_t index)
{
    if (this->left_bound < this->right_bound)
    {   
        if (index < this->left_bound || index > this->right_bound)
        {
            throw v_wrong_index_exception("at wrong index");
        }
        
        return this->body_[index - this->left_bound];
    }
    else
    {
        if (index > this->left_bound || index < this->right_bound)
        {
            throw v_wrong_index_exception("at wrong index");
        }
        return this->body_[this->left_bound - index];
    }
    
}