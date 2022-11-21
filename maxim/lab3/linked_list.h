#pragma once

#include <iostream>
#include <string>


using namespace std;

class Linked_list
{
private:

    struct node
    {
        int val = 0;
        node* next = nullptr;

        node(int);

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

    int get_head();
    int get_tail();
    void push_back(int);
    void pop_back();
    void pop_front();
    int get_size();
    void print();
    
    void swap(node*, node*);
    

    void bubble_sort();
    void insertion_sort();
    void selection_sort();
};