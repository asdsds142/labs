#pragma once

#include <iostream>
#include <memory>



template<class T>
class Linked_list
{
private:

    struct node
    {
        T val;
        node* next = nullptr;
        node(T);
    };

    node* head = nullptr;
    node* tail = nullptr;
  
    



public:
    Linked_list();


    node* begin();//тыкнуть сюда свой итерутор
    node* end();
    void push_back(T);
    T pop_back();
    T pop_front();
    
};