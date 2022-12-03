#pragma once

#include <iostream>
#include <string>


using namespace std;

template<class T>
class Linked_list
{
private:
    struct node
    {
        T val = 0;
        node* next = nullptr;

        node(T);

        ~node();
        node(const node&);
        node& operator=(const node&);
    };

    node* head = nullptr;
    node* tail = nullptr;
    int size = 0;
  
public:
    Linked_list();

    Linked_list(const Linked_list&);
    Linked_list& operator=(const Linked_list&);
    ~Linked_list();

    node& operator[](int);

    T get_head();
    T get_tail();
    void push_back(T);
    void pop_back();
    void pop_front();
    int get_size();
    void print();
    
    void swap(node*, node*);
    

    void bubble_sort();
    void insertion_sort();
    void selection_sort();
};