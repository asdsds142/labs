//Vector.h
#pragma once

#include "Vector_class_description.h"

template<typename T> 
T* Vector<T>::try_allocate(uint64_t size)
{
    for (size_t i = 0; i < 10; i++) //пробуем 10 раз не получается ну значит не получается
    {
        try
        {
            this->body_ = new T[size];
            break;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    if (!this->body_)
    {
        throw v_memory_allocate_exception("try_allocate_failed");
    }    
    return this->body_;
}

template<typename T>
Vector<T>::Vector():
body_(try_allocate(STANDART_SIZE)), size_(STANDART_SIZE), left_bound_(0), 
right_bound_(STANDART_SIZE - 1)
{
}

template<typename T>
Vector<T>::Vector(int64_t left_bound, int64_t right_bound):
body_(try_allocate(static_cast<uint64_t>(std::abs(right_bound - left_bound + 1)))), 
size_(static_cast<uint64_t>(std::abs(right_bound - left_bound + 1))), 
left_bound_(left_bound), right_bound_(right_bound)
{
}


template<typename T>
Vector<T>::Vector(std::initializer_list<T> list):
body_(try_allocate(list.size())), size_(list.size()),
left_bound_(0), right_bound_(static_cast<int64_t>(size_) - 1)
{
    auto it = list.begin();
    for (size_t i = 0; i < list.size() ||
         it != list.end(); i++, it++)
    {
        this->body_[i] = *it;
    }
}

template<typename T>
Vector<T>::Vector(const Vector& other):
body_(try_allocate(other.size_)), size_(other.size_), 
left_bound_(other.left_bound_), right_bound_(other.right_bound_)
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
    this->left_bound_ = other.left_bound;
    this->right_bound_ = other.right_bound;

    for (size_t i = 0; i < size_; ++i)
    {
        this->body_[i] = other.body_[i];
    }
}

template<typename T>
inline Vector<T>& Vector<T>::operator+=(const Vector& other)
{
    if (this->size_ != other.size_)
    {
        throw v_wrong_sizing_exception("");
    }
    
    for (size_t i = 0; i < size_; ++i)
    {
        this->body_[i] += other.body_[i];
    }
    return *this;
}

template<typename T>
inline Vector<T> Vector<T>::operator+(const Vector& other) const
{
    auto return_value = Vector(*this);
    return_value += other;
    return return_value;
}

template<typename T>
inline Vector<T>& Vector<T>::operator-=(const Vector& other) 
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
inline Vector<T> Vector<T>::operator-(const Vector& other) const
{
    auto return_value = Vector(*this);
    return_value += other;
    return return_value;
}

template<typename T>
T Vector<T>::operator*(const Vector& other) const
{
    if (this->size_ != other.size_)
    {
        throw v_wrong_sizing_exception("scalar_product");
    }
    
    T return_value = 0;

    for (size_t i = 0; i < this->size_; ++i)
    {
        return_value += (this->body_[i] * other.body_[i]);
    }

    return return_value;    
}

template<typename T>
inline Vector<T>& Vector<T>::operator*=(double scalar)
{
    for (size_t i = 0; i < this->size_; ++i)
    {
        this->body_[i] = static_cast<T>(static_cast<double>(this->body_[i]) * scalar);
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
    if (scalar == 0.0)
    {
        throw v_division_by_zero_exception("division by zero");
    }

    return *this *= (1/scalar);
}

template<typename T>
Vector<T> Vector<T>::operator/(double scalar) const
{
    if (scalar == 0.0)
    {
        throw v_division_by_zero_exception("division by zero");
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
inline T& Vector<T>::operator[](int64_t index)
{
    if (this->left_bound_ < this->right_bound_)
    {   
        return this->body_[index - this->left_bound_];
    }
    else
    {
        return this->body_[this->left_bound_ - index];
    }

}


template<typename T>
inline T& Vector<T>::at(int64_t index)
{
    if (this->left_bound_ < this->right_bound_)
    {   
        if (index < this->left_bound_ || index > this->right_bound_)
        {
            throw v_wrong_index_exception("at wrong index");
        }
        
        return this->body_[index - this->left_bound_];
    }
    else
    {
        if (index > this->left_bound_ || index < this->right_bound_)
        {
            throw v_wrong_index_exception("at wrong index");
        }
        return this->body_[this->left_bound_ - index];
    }
    
}