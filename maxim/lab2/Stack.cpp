#include "Stack.h"



//конструктор по умолчанию
Stack::Stack()
{
    this->body_ = new int[STANDART_SIZE];
}


//конструктор копирования
Stack::Stack(const Stack& other)
{
    this->size_ = other.size_;
    this->body_ = new int[other.size_];
    this->end_ = other.end_;

    for (int i = 0; i < other.size_; ++i)
    {
        this->body_[i] = other.body_[i];        
    }
}


//оператор присваивания
Stack& Stack::operator=(const Stack& other)
{
    delete[] this->body_; //удаляем то что было


    this->body_ = new int[other.size_]; //выделяем новую память
    this->size_ = other.size_;
    this->end_ = other.end_;

    for (int i = 0; i < other.size_; ++i)
    {
        this->body_[i] = other.body_[i]; //записываем новые значения 
    }
    return *this;
}

//деструктор
Stack::~Stack()
{
    delete[] this->body_; //удаляем тело
}


//пуш элементов в очередь
int Stack::push(int value)
{
    if (this->end_ == this->size_) // если память заполнена
    {
        int* tmp = new int[this->size_ * 2]; //выделяем новую память под указатель tmp
        for (int i = 0; i < this->size_; i++)
        {
            tmp[i] = this->body_[i]; //переписываем значения
        }
        

        delete[] this->body_; //удаляем текущее "тело"
        this->body_ = tmp; //переназначаем тело (указатель) туда же куда указывает tmp
        this->size_ *= 2; //увеличиваем размер
    }

    this->body_[this->end_] = value; //ставим значение в ячейку
    this->end_++; //увеличиваем индекс
    return 0;
}


//поп элементов из очереди
int Stack::pop()
{
    if (this->end_ == 0)
    {
        cout << "Ошибка, стек пустой, возвращаю 0" << endl;
        return 0;
    }

    this->end_--; //уменьшаем индекс элемента следующего за последним
    return this->body_[this->end_]; //возвращаем значение
}

//функция возвращающая число элементов стека
int Stack::size()
{
    return this->end_;
}


Stack& operator>>(Stack& st, int& buffer) //перегруженный оператор вывода
{
    buffer = st.pop();
    return st;
}

Stack& operator<<(Stack& st, int value) //перегруженный оператор ввода
{
    st.push(value); 
    return st;
}


//функция удаляющая все четные (по номеру а не по значению) элементы стека
void Stack::pop_even()
{
    Stack tmp; //создаем новый стек для сохранения и перелива значений
    int buf; 

    int S = this->size(); //переменная чтобы хранить начальный размер для цикла
    for (int i = 0; i < S; i++)
    {
        buf = this->pop(); //попаем значение в переменную
        if ((i % 2) == 1) //если проход цикла нечетный
        {
            tmp.push(buf); //сохраняем значение во временный цикл
        }
    }

    S = tmp.size(); // переназначаем S
    for (int i = 0; i < S; i++)
    {
        this->push(tmp.pop()); //засовываем элементы обратно
    }
}

//функция удаляющая все нечетные (по номеру а не по значению) элементы стека
void Stack::pop_odd()
{
    Stack tmp;
    int buf;

    int S = this->size();
    for (int i = 0; i < S; i++)
    {
        buf = this->pop();
        if ((i % 2) == 0) //различие с предыдущей функцией только здесь
        {
            tmp.push(buf);
        }
    }

    S = tmp.size();
    for (int i = 0; i < S; i++)
    {
        this->push(tmp.pop());
    }
}

//функция показывающая элементы очереди не производя попы
void Stack::show_without_pop()
{
    for (int i = 0; i < this->size(); i++)
    {
        cout << this->body_[i] << ' ';
    }
    cout << endl;
}