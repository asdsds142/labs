#include "linked_list_header.h"

//конструктор по значению
template<class T>
Linked_list<T>::node::node(T value)
{
    this->val = value;
}

//конструктор копирования
template<class T>
Linked_list<T>::node::node(const node& other)
{

    this->val = other.val; //переписываем значение
    if (other.next)
    {
        this->next = new node(*other.next); //рекурсивно делаем новые ноды
    }
}

//деструктор
template<class T>
Linked_list<T>::node::~node()
{
    delete this->next; //чистим память, если тут будет nullptr делит ничего не сделает
}
 
//оператор присваивания
template<class T>
typename Linked_list<T>::node& Linked_list<T>::node::operator=(const node& other)
{
    delete this->next; //удаляем все что было "за" нодой

    this->val = other.val; //переписываем значение
    if (other.next)
    {
        this->next = new node(*other.next); //рекурсивно создаем новые ноды на основе other
    }

    return *this;
}

//конструктор без параметров (задает значения по умолчанию)
template<class T>
Linked_list<T>::Linked_list()
{

}

//конструктор копирования
template<class T>
Linked_list<T>::Linked_list(const Linked_list& other)
{
    this->size = other.size;
    if (other.head)
    {
        this->head = new node(*other.head); //создали голову, дальнейшие ноды создадутся рекурсивно
    }
}

//деструктор
template<class T>
Linked_list<T>::~Linked_list()
{
    delete this->head; //удалять надо только "голову", хвост удалится рекурсивно через деструктор ноды
}

//оператор присваивания
template<class T>
Linked_list<T>& Linked_list<T>::operator=(const Linked_list& other)
{
    delete this->head; //почистили то что было

    this->size = other.size;
    if (other.head)
    {
        this->head = new node(*other.head); //создали новую голову на основе other, другие новые ноды создадутся рекурсивно
    }

    return *this;
}

//добавить элемент в список
template<class T>
void Linked_list<T>::push_back(T value)
{
    node* ptr = new node(value);

    if (this->head == nullptr && this->tail == nullptr)
    {
        this->head = ptr;
        this->tail = ptr;
    }

    else if (this->head != nullptr && this->tail != nullptr)
    {
        this->tail->next = ptr;
        this->tail = ptr;
    }

    this->size++;
}

template<class T>
void Linked_list<T>::pop_front()
{
    node* tmp = &*this->head; 
    this->head = this->head->next; //передвинули голову

    tmp->next = nullptr; //убрали next, чтобы не чистилось рекурсивно
    delete tmp; //почистили
    
}

//оператор предоставляющий доступ к элементу с индексом index
template<class T>
typename Linked_list<T>::node& Linked_list<T>::operator[](int index)
{
    node* return_value = this->head;
    
    for (int i = 0; i < index; i++)
    {
        if (!return_value->next) //если тут нуллптр
        {
            cout << "обращение по неверному индексу" << endl;
            break;
        }
        return_value = return_value->next;
    }

    return *return_value;   
}


//функция возвращающая размер списка
template<class T>
int Linked_list<T>::get_size()
{
    return this->size;
}

template<class T>
T Linked_list<T>::get_head()
{
    return this->head->val;
}

template<class T>
T Linked_list<T>::get_tail()
{
    return this->tail->val;
}

//функция меняющая местами значения 2 элементов
template<class T>
void Linked_list<T>::swap(node* first, node* second)
{
    if (first == second)
    {
        
    }
    
    else
    {   
        T tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
}


//функция выводящая список на экран
template<class T>
void Linked_list<T>::print()
{
    node* tmp = this->head;

    cout << "Список:   ";
    while (tmp) //пока tmp не nullptr
    {
        cout << tmp->val << ' ';
        tmp = tmp->next;
    }
    cout << endl;
}


//пузырьковая сортировка
template<class T>
void Linked_list<T>::bubble_sort()
{
    for (int i = 0; i < this->size; i++)
    {
        node* tmp = this->head;

        for (int j = 0; j < this->size - 1; j++)
        {
            if (tmp->val > tmp->next->val)
            {
                swap(tmp, tmp->next); //если выполняется меняем местами
            }

            if (tmp->next) 
            {
                tmp = tmp->next; //двигаем указатель
            }

        }
    }
}

//сортировка выбором
template<class T>
void Linked_list<T>::selection_sort()
{
    for (int i = 0; i < this->size; i++)
    {
        node* minimal = &(*this)[i]; //&(*this)[i] -> получаем доступ к элементу с индексом i
        node* tmp = &(*this)[i];
        for (int j = 0; j < this->size; j++)
        {
            if (tmp->val < minimal->val)
            {
                minimal = &*tmp; //если элемент меньше ставим его за минимум
            }
            if (tmp->next)
            {
                tmp = tmp->next; //двигаем указатель
            }
        }
        swap(&(*this)[i], minimal); //ставим минимум на нужное место
    }    
}

//сортировка вставками
template<class T>
void Linked_list<T>::insertion_sort()
{
    for (int i = 0; i < this->size; i++)
    {
        node* current = &(*this)[i]; //&(*this)[i] -> получаем доступ к элементу с индексом i
        node* tmp = &(*this)[i];
        for (int j = 0; j < this->size; j++)
        {
            if (tmp->val < current->val)
            {
                swap(tmp, current); //берем элемент, если он меньше соседа двигаем его 
                                    //в сторону его правильного места в уже отсортированнной части списка
            }
            if (tmp->next)
            {
                tmp = tmp->next;
            }
        } 
    } 
}


