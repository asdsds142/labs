#include "linked_list.h"

template<class T>
Linked_list<T>::Linked_list()
{
    this->head = nullptr;
    this->tail = nullptr;
}

template<class T>
Linked_list<T>::node::node(T value)
{
    this->next = nullptr;
    this->val = value;
}

template<class T>
void Linked_list<T>::push_back(T value)
{
    node* ptr = new node(value);

    if (this->head == nullptr && this->tail != nullptr)
    {
        throw std::runtime_error("странные вещи происходят в linked_list_push_back");
    }

    if (this->head == nullptr && this->tail == nullptr)
    {
        this->head = ptr;
        this->tail = ptr;
    }

    if (this->head != nullptr && this->tail != nullptr)
    {
        this->tail->next = ptr;
    }
}



template<class T>
T Linked_list<T>::pop_front()
{
    this->head = this->head->next;
}