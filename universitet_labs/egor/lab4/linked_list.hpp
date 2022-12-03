#include "linked_list.h"

//конструктор по значению
template<class T>
Linked_list<T>::node::node(T value): val(value)
{
}

//конструктор копирования
template<class T>
Linked_list<T>::node::node(const node& other)
{

    val = other.val; //переписываем значение
    if (other.next)
    {
        next = new node(*other.next); //рекурсивно делаем новые ноды
    }
}

//деструктор
template<class T>
Linked_list<T>::node::~node()
{
    delete next; //чистим память, если тут будет nullptr делит ничего не сделает
}
 
//оператор присваивания
template<class T>
typename Linked_list<T>::node& Linked_list<T>::node::operator=(const node& other)
{
    delete next; //удаляем все что было "за" нодой

    val = other.val; //переписываем значение
    if (other.next)
    {
        next = new node(*other.next); //рекурсивно создаем новые ноды на основе other
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
    size = other.size;
    if (other.head)
    {
        head = new node(*other.head); //создали голову, дальнейшие ноды создадутся рекурсивно
    }
}

//деструктор
template<class T>
Linked_list<T>::~Linked_list()
{
    delete head; //удалять надо только "голову", хвост удалится рекурсивно через деструктор ноды
}

//оператор присваивания
template<class T>
Linked_list<T>& Linked_list<T>::operator=(const Linked_list& other)
{
    delete head; //почистили то что было

    size = other.size;
    if (other.head)
    {
        head = new node(*other.head); //создали новую голову на основе other, другие новые ноды создадутся рекурсивно
    }

    return *this;
}

//добавить элемент в список
template<class T>
void Linked_list<T>::push_back(T value)
{
    node* ptr = new node(value);

    if (head == nullptr && tail == nullptr)
    {
        head = ptr;
        tail = ptr;
    }

    else if (head != nullptr && tail != nullptr)
    {
        tail->next = ptr;
        tail = ptr;
    }

    size++;
}

template<class T>
void Linked_list<T>::pop_front()
{
    node* tmp = &*head; 
    head = head->next; //передвинули голову

    tmp->next = nullptr; //убрали next, чтобы не чистилось рекурсивно
    delete tmp; //почистили
    
}

//оператор предоставляющий доступ к элементу с индексом index
template<class T>
typename Linked_list<T>::node& Linked_list<T>::operator[](int index)
{
    node* return_value = head;
    
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
    return size;
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

template<class T>
T& Linked_list<T>::get_head()
{
    return head->val;
}

template<class T>
T& Linked_list<T>::get_tail()
{
    return tail->val;
}


//функция выводящая список на экран
template<class T>
void Linked_list<T>::print()
{
    node* tmp = head;

    cout << "Список:   ";
    while (tmp) //пока tmp не nullptr
    {
        cout << tmp->val << ' ';
        tmp = tmp->next;
    }
    cout << endl;
}