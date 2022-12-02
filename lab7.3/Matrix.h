//Matrix.h
#include "Matrix_class_description.h"

template<class T>
uint64_t Matrix<T>::matrix_id_ = 1;

//конструктор вводящий матрицу из потока input_stream
template<class T>
Matrix<T>::Matrix(istream& input_stream): 
name_("matrix" + to_string(matrix_id_))
{
    matrix_id_++;
    input_stream  >> string_number_ >> column_number_;

    this->body_= new T*[string_number_];
    for (size_t i = 0; i < string_number_; ++i)
    {
        this->body_[i] = new T[column_number_];
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
Matrix<T>::Matrix(uint64_t string_number, uint64_t column_number, T init_value): 
name_("matrix" + to_string(matrix_id_)), string_number_(string_number), 
column_number_(column_number), body_(new T*[string_number_]) //уточнить
{
    matrix_id_++;
    for (size_t i = 0; i < string_number_; ++i)
    {
        this->body_[i] = new T[column_number_];
    }
    
    for (size_t i = 0; i < this->string_number_; ++i)
    {
        for (size_t j = 0; j < this->column_number_; ++j)
        {
            this->body_[i][j] = init_value;
        }
    }
}

//конструктор копирования
template<class T>
Matrix<T>::Matrix(const Matrix<T>& other): 
name_("matrix" + to_string(matrix_id_)), string_number_(other.string_number_), 
column_number_(other.column_number_), body_(new T*[string_number_])
{
    matrix_id_++;
    static int64_t counter = 0;
    cout << "copy" << counter << endl;
    counter++;

    for (size_t i = 0; i < string_number_; ++i)
    {
        this->body_[i] = new T[column_number_];
    }
    
    for (size_t i = 0; i < other.string_number_; ++i)
    {
        for (size_t j = 0; j < other.column_number_; ++j)
        {
            this->body_[i][j] = other.body_[i][j];
        }

    }
}

//присваивание
template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other)
{
    for (size_t i = 0; i < string_number_; ++i)
    {
        delete[] this->body_[i];
    }
    delete[] this->body_;
    

    this->string_number_ = other.string_number_;
    this->column_number_ = other.column_number_;
    this->body_ = new T*[string_number_];
    for (size_t i = 0; i < string_number_; ++i)
    {
        this->body_[i] = new T[column_number_];
    }

    for (size_t i = 0; i < string_number_; ++i)
    {
        for (size_t j = 0; j < string_number_; ++j)
        {
            this->body_[i][j] = other.body_[i][j];
        }
    }

    return *this;
}

//деструктор
template<class T>
Matrix<T>::~Matrix()
{
    cout << "dest called" << endl;
    for (size_t i = 0; i < string_number_; ++i)
    {
        delete[] this->body_[i];
    }
    delete[] this->body_;
}


//вывод на экран
template<class T>
void Matrix<T>::show() const
{
    cout << '\n' <<this->name_;
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
T Matrix<T>::get_value(uint64_t i, uint64_t j) const
{return this->body_[i][j]; }

//унарный минус
template<class T>
Matrix<T> Matrix<T>::operator-() const
{

    auto return_value = Matrix<T>(*this);

    for (size_t i = 0; i < return_value.string_number_; ++i)
    {
        for (size_t j = 0; j < return_value.column_number_; ++j)
        {
            return_value.body_[i][j] = -return_value.body_[i][j];
        }
    }
    return return_value;
}

//оператор умножения матриц
template<class T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& other) 
{
    if (this->column_number_ != other.string_number_)
    {
        throw std::runtime_error("matrix multiplication wrong sizings");
    }

    auto return_matrix = Matrix<T>(this->string_number_, other.column_number_);

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
    *this = return_matrix; //немного не оптимально но как делать move я разберусь чуть позже
    return *this;
}


template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const
{
    auto return_matrix = Matrix<T>(*this);
    return_matrix *= other;
    return return_matrix;
} 


template<class T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& other)
{
    if (this->string_number_ != other.string_number_ or 
        this->column_number_ != other.column_number_)
    {
        throw std::runtime_error("matrix multiplication wrong sizings");
    }

    for (size_t i = 0; i < this->string_number_; ++i)
    {
        for (size_t j = 0; j < this->column_number_; ++j)
        {
            this->body_[i][j] += other.body_[i][j];
        }     
    }

    return *this;
}


//минусравно, можно было реализовать через унарный минус сэкономив строчки кода 
//но это нужно лишний раз перезаписывать все данные в штуке + создавать копию
template<class T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& other)
{
    if (this->string_number_ != other.string_number_ or 
        this->column_number_ != other.column_number_)
    {
        throw std::runtime_error("matrix multiplication wrong sizings");
    }

    for (size_t i = 0; i < this->string_number_; ++i)
    {
        for (size_t j = 0; j < this->column_number_; ++j)
        {
            this->body_[i][j] -= other.body_[i][j];
        }     
    }

    return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const
{

    auto return_matrix = *this;
    return_matrix += other;
    return return_matrix;

}

//минус
template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const
{
    auto return_matrix = *this;
    return_matrix -= other;
    return return_matrix;
}

//вывод в поток
template<class T>
std::ostream& operator<<(ostream& out, const Matrix<T>& matrix)
{
    out << matrix.string_number_ << ' ' << matrix.column_number_ << '\n';
    for (size_t i = 0; i < matrix.string_number_; ++i)
    {
        for (size_t j = 0; j < matrix.column_number_; ++j)
        {
            out << matrix.body_[i][j] << ' ';
        }
        out << '\n';
    }
    return out;
}

//ввод из потока
template<class T>
istream& operator>>(istream& input_stream, Matrix<T>& matrix)
{
    input_stream  >> matrix.string_number_ >> matrix.column_number_;
    for (size_t i = 0; i < matrix.string_number_; ++i)
    {
        for (size_t j = 0; j < matrix.column_number_; ++j)
        {
            input_stream >> matrix.body_[i][j];
        }
    }
    return input_stream;
}


//возведение в степень
template<class T>
Matrix<T> Matrix<T>::operator^(uint64_t power) const
{
    auto return_value = Matrix<T>(*this);

    for (size_t i = 0; i < power; ++i)
    {
        return_value *= *this;
    }

    return return_value;    
}

//умножение матрицы на число
template<class T>
Matrix<T>& Matrix<T>::operator*=(T value)
{
    for (size_t i = 0; i < this->string_number_; ++i)
    {
        for (size_t j = 0; j < this->column_number_; ++j)
        {
            this->body_[i][j] *= value;
        }
    }
    return *this;
}

//умножение матрицы на число
template<class T>
Matrix<T> Matrix<T>::operator*(T value)
{
    auto return_value = Matrix<T>(*this);
    for (size_t i = 0; i < this->string_number_; ++i)
    {
        for (size_t j = 0; j < this->column_number_; ++j)
        {
            return_value.body_[i][j] *= value;
        }
    }
    return return_value;
}

//деление матрицы на число
template<class T>
Matrix<T>& Matrix<T>::operator/=(T value)
{
    return *this *= (1/value);
}

//деление матрицы на число
template<class T>
Matrix<T> Matrix<T>::operator/(T value) const
{
    auto return_value = Matrix(*this);
    return return_value * (1/value);
}


//возврат значения минимального элемента матрицы
template<class T>
T Matrix<T>::min()
{
    T min = this->body_[0][0];

    for (size_t i = 0; i < this->string_number_; ++i)
    {
        for (size_t j = 0; j < this->column_number_; ++j)
        {
            if (this->body_[i][j] < min)
            {
                min = this->body_[i][j];
            }
        }
    }
    return min;
}


//возврат значения максимального элемента матрицы
template<class T>
T Matrix<T>::max()
{
    T max = this->body_[0][0];

    for (size_t i = 0; i < this->string_number_; ++i)
    {
        for (size_t j = 0; j < this->column_number_; ++j)
        {
            if (this->body_[i][j] > max)
            {
                max = this->body_[i][j];
            }
        }
    }
    return max;
}

//вывод вектора из минимальных элементов столбцов
template<class T>
vector<T> Matrix<T>::get_min_vector()
{
    T min_tmp;
    vector<T> return_value;
    return_value.reserve(this->string_number_);

    for (size_t i = 0; i < this->string_number_; ++i)
    {
        min_tmp = this->body_[i][0];

        for (size_t j = 0; j < this->column_number_; ++j)
        {
            if (this->body_[i][j] < min_tmp)
            {
                min_tmp = this->body_[i][j];
            }
        }
        return_value.push_back(min_tmp);
    }

    return return_value;
}

//сумма элементов строки с индексом str_number
template<class T>
T Matrix<T>::string_sum(uint64_t str_number)
{
    T summ = this->body_[str_number][0];
    //инициализируем элементом с индексом 0 на всякий случай, начинаем цикл с 1
    for (size_t i = 1; i < this->column_number_; ++i)
    {
        summ += this->body_[str_number][i];
    }
    
    return summ;
}

//сумма элементов столбца с номером col_number
template<class T>
T Matrix<T>::column_sum(uint64_t col_number)
{
    T summ = this->body_[0][col_number];
    //инициализируем элементом с индексом 0 на всякий случай, начинаем цикл с 1
    for (size_t i = 1; i < this->string_number_; ++i)
    {
        summ += this->body_[i][col_number];
    }
    
    return summ;
}

//оператор сравнения
template<class T>
bool Matrix<T>::operator==(const Matrix& other) const
{
    if (this->string_number_ != other.string_number_ || 
        this->column_number_ != other.column_number_)
    {
        return false;
    }
    for (size_t i = 1; i < this->string_number_; ++i)
    {
        for (size_t j = 1; j < this->column_number_; ++j)
        {
            if (this->body_[i][j] != other.body_[i][j])
            {
                return false;
            }
        }
    }

    return true;
}