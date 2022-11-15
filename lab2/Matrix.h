#include "Matrix_class_description.h"


//конструктор вводящий матрицу из потока input_stream
template<class T>
Matrix<T>::Matrix(istream& input_stream)
{
    input_stream >> string_number_ >> column_number_;
    this->body_.reserve(string_number_);
    for (size_t i = 0; i < this->string_number_; ++i)
    {
        this->body_[i].reserve(this->column_number_);
    }
    

    for (size_t i = 0; i < this->string_number_; ++i)
    {
        for (size_t j = 0; j < this->column_number_; ++j)
        {
            input_stream >> this->body_[i][j];
        }
    }
}


//конструктор создающий матрицу размеров i, j, заполняющий ее значениями init_value, по умолчанию 0
template<class T>
Matrix<T>::Matrix(uint64_t string_number, uint64_t column_number, T init_value): string_number_(string_number), column_number_(column_number)
{
    body_.reserve(string_number);
    for (size_t i = 0; i < this->string_number_; ++i)
    {
        body_[i].reserve(this->column_number_);
    }

    for (size_t i = 0; i < this->string_number_; ++i)
    {
        for (size_t j = 0; j < this->column_number_; ++j)
        {
            this->body_[i].push_back(init_value);
        }
    }

}

//вывод на экран
template<class T>
void Matrix<T>::show()
{
    for (size_t i = 0; i < this->string_number_; ++i)
    {
        cout << '\n';
        for (size_t j = 0; j < this->column_number_; ++j)
        {
            cout << this->body_[i][j] << ' ';
        }
    }  
    cout << endl;
}

//возврат копии значения
template<class T>
T Matrix<T>::get_value(uint64_t i, uint64_t j)
{return this->body_[i][j]; }


//оператор умножения матриц
template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other)
{
    if (this->column_number_ != other.string_number_)
    {
        throw std::runtime_error("matrix multiplication wrong sizings");
    }

    Matrix<T> return_matrix = Matrix<T>(this->string_number_, other.column_number_);

    for (size_t i = 0; i < this->string_number_; ++i)
    {
        for (size_t j = 0; j < other.column_number_; j++)
        {
            T sum = 0;
            for (size_t k = 0; k < this->column_number_; k++)
            {
                sum += (this->body_[i][k] * other.body_[k][j]);
            }
            return_matrix.body_[i][j] = sum;
        }
        
    }
    return return_matrix;
}

