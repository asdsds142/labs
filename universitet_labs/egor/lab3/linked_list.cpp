#include "linked_list.h"

//конструктор по значению
Linked_list::node::node(string value)
{
    val = value;
}

//конструктор копирования
Linked_list::node::node(const node& other)
{

    val = other.val; //переписываем значение
    if (other.next)
    {
        next = new node(*other.next); //рекурсивно делаем новые ноды
    }
}

//деструктор
Linked_list::node::~node()
{
    delete next; //чистим память, если тут будет nullptr делит ничего не сделает
}
 
//оператор присваивания
Linked_list::node& Linked_list::node::operator=(const node& other)
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
Linked_list::Linked_list()
{

}

//конструктор копирования
Linked_list::Linked_list(const Linked_list& other)
{
    size = other.size;
    if (other.head)
    {
        head = new node(*other.head); //создали голову, дальнейшие ноды создадутся рекурсивно
    }
}

//деструктор
Linked_list::~Linked_list()
{
    delete head; //удалять надо только "голову", хвост удалится рекурсивно через деструктор ноды
}

//оператор присваивания
Linked_list& Linked_list::operator=(const Linked_list& other)
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
void Linked_list::push_back(string value)
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


void Linked_list::pop_front()
{
    node* tmp = &*head; 
    head = head->next; //передвинули голову

    tmp->next = nullptr; //убрали next, чтобы не чистилось рекурсивно
    delete tmp; //почистили
    
}

//оператор предоставляющий доступ к элементу с индексом index
Linked_list::node& Linked_list::operator[](int index)
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
int Linked_list::get_size()
{
    return size;
}

//функция меняющая местами значения 2 элементов
void Linked_list::swap(node* first, node* second)
{
    if (first == second)
    {
        
    }
    
    else
    {   
        string tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
}

string& Linked_list::get_head()
{
    return head->val;
}

string& Linked_list::get_tail()
{
    return tail->val;
}


//функция выводящая список на экран
void Linked_list::print()
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