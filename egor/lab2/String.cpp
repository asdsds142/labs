#include "String.h"

String::String()
{
    //ничего не делаем, поля инициализируются по умолчанию
}

//конструктор из набора символов
String::String(char* s)
{
    this->size = strlen(s); //вычисляем размер
    this->c_str = new char[this->size]; //выделяем память

    for (int i = 0; i < size; i++)
    {
        this->c_str[i] = s[i]; //переписываем значения
    }
}

//конструктор копирования
String::String(const String& other)
{
    this->size = other.size; //переписываем размер
    this->c_str = new char[size]; //выделяем память

    for (int i = 0; i < size; i++)
    {
        this->c_str[i] = other.c_str[i]; //переписываем поля
    }
}

//оператор присваивания
String& String::operator=(const String& other)
{
    delete[] this->c_str; //удаляем то что было

    this->size = other.size; //по аналогии с конструктором копирования
    this->c_str = new char[size];

    for (int i = 0; i < size; i++)
    {
        this->c_str[i] = other.c_str[i];
    }

    return *this;
}

//деструктор, чистим память
String::~String()
{
    delete[] this->c_str;
}

//функция возвращает значение символа с заданным индексом
char String::get_nth_symbol(int index)
{
    return this->c_str[index];
}

//функция которая возвращает значение символа с заданным индексом и удаляет его из строки
char String::get_and_delete_nth_symbol(int index)
{
    char tmp = this->c_str[index];

    for (int i = index; i < this->size - 1; i++)
    {
        this->c_str[i] = this->c_str[i+1];
    }

    this->c_str[size - 1] = '\0';

    return tmp;
}

//оператор индексирования, возвращает ссылку на символ с заданным индексом
char& String::operator[](int index)
{
    return this->c_str[index]; 
}


//функция конкатент, "приклеивает" к строке другую строку
String& String::concatent(const String& other)
{
    int total_size = this->size + other.size; //вычисляем размер новой строки
    char* tmp = new char[total_size]; //выделяем новую память

    for (int i = 0; i < this->size; i++) //переписываем данные в новую, большую строку через 2 цикла
    {
        tmp[i] = this->c_str[i];
    }
    for (int i = this->size, j = 0; i < total_size; i++)
    {
        tmp[i] = other.c_str[j]; 
    }
    
    delete[] this->c_str; //удаляем то что было

    this->c_str = tmp;
    this->size = total_size;
    
    return *this;
}

//оператор плюсравно, "приклеивает" к заданной строке другую строку other, реализовано через функцию конкатент чтобы писать меньше кода
String& String::operator+=(const String& other)
{
    this->concatent(other);

    return *this;
}

//оператор + возвращающий копию объекта String
String String::operator+(const String& other)
{
    String return_value = *this;
    return_value += other;
    return return_value;
}

//оператор сравнения меньше
bool String::operator<(const String& other)
{
    int min_size;
    bool return_value = true;
    if (this->size < other.size)
    {
        min_size = this->size;
    }
    else 
    {
        min_size = other.size;
        return_value = false;
    }

    for (int i = 0; i < min_size; i++)
    {
        if (this->c_str[i] < other.c_str[i])
        {
            return true;
        }

        if (this->c_str[i] > other.c_str[i])
        {
            return false;
        }
    }

    return return_value;
}

//оператор сравнения меньшеравно
bool String::operator<=(const String& other)
{
    int min_size;
    bool return_value = false;
    if (this->size <= other.size)
    {
        min_size = this->size;
        return_value = true;
    }
    else 
    {
        min_size = other.size;
    }

    for (int i = 0; i < min_size; i++)
    {
        if (this->c_str[i] < other.c_str[i])
        {
            return true;
        }

        if (this->c_str[i] > other.c_str[i])
        {
            return false;
        }
    }

    return return_value;
}

//оператор сравнения равноравно
bool String::operator==(const String& other)
{
    int min_size;
    bool return_value = true;

    if (this->size == other.size)
    {
        min_size = this->size;
    }
    else 
    {
        return false;
    }

    for (int i = 0; i < min_size; i++)
    {
        if (this->c_str[i] < other.c_str[i])
        {
            return false;
        }

        if (this->c_str[i] > other.c_str[i])
        {
            return false;
        }
    }

    return return_value;
}

//оператор сравнения больше
bool String::operator>(const String& other)
{
    int min_size;
    bool return_value = true;
    if (this->size <= other.size)
    {
        min_size = this->size;
        return_value = false;
    }
    else 
    {
        min_size = other.size;
    }

    for (int i = 0; i < min_size; i++)
    {
        if (this->c_str[i] > other.c_str[i])
        {
            return true;
        }

        if (this->c_str[i] < other.c_str[i])
        {
            return false;
        }
    }

    return return_value;
}

//оператор сравнения большеравно
bool String::operator>=(const String& other)
{
    int min_size;
    bool return_value = true;
    if (this->size < other.size)
    {
        min_size = other.size;
        return_value = false;
    }
    else 
    {
        min_size = this->size;
    }

    for (int i = 0; i < min_size; i++)
    {
        if (this->c_str[i] > other.c_str[i])
        {
            return true;
        }

        if (this->c_str[i] < other.c_str[i])
        {
            return false;
        }
    }

    return return_value;
}

//вывод на экран
void String::show()
{
    for (int i = 0; i < this->size; i++)
    {
        cout << this->c_str[i];
    }
    cout << endl;
}

