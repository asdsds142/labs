//Vector.h
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

template<typename T>
class Vector
{
  private:
    static constexpr uint64_t STANDART_SIZE = 3;

    T* body_ = nullptr;
    uint64_t size_ = 0;
    int64_t left_bound;
    int64_t right_bound;

    T* try_allocate(uint64_t);

  public:
    class v_overflow_exception : public std::runtime_error 
    {
      public:
        v_overflow_exception(std::string msg): runtime_error(msg) {};
    };

    class v_memory_allocate_exception : public std::runtime_error 
    {
      public:
        v_memory_allocate_exception(std::string msg): runtime_error(msg) {};
    };

    class v_wrong_index_exception : public std::runtime_error 
    {
      public:
        v_wrong_index_exception(std::string msg): runtime_error(msg) {};
    };

    class v_wrong_sizing_exception : public std::runtime_error 
    {
      public:
        v_wrong_sizing_exception(std::string msg): runtime_error(msg) {};
    };

    class v_division_by_zero_exception : public std::runtime_error 
    {
      public:
        v_division_by_zero_exception(std::string msg): runtime_error(msg) {};
    };

    Vector();
    Vector(int64_t, int64_t);
    explicit Vector(uint64_t);
    Vector(const Vector&);
    Vector& operator=(const Vector&);
    ~Vector();



    Vector& operator+=(const Vector&);
    Vector operator+(const Vector&) const;
    Vector& operator-=(const Vector&);
    Vector operator-(const Vector&) const;

    double operator*(const Vector&) const;

    Vector& operator*=(double);
    Vector operator*(double) const;
    Vector& operator/=(double);
    Vector operator/(double) const;
    
    void show();
    void show(uint64_t);
    uint64_t size() {return this->size_; }

    T& operator[](int64_t);
    T& at(int64_t);
};
