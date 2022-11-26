#pragma once

#include <iostream>
#include <string>


using namespace std;

class Linked_list
{
private:

    struct node
    {
        string val = "";
        node* next = nullptr;
        node(string);
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

    string& get_head();
    string& get_tail();
    void push_back(string);
    void pop_back();
    void pop_front();
    int get_size();
    void print();
    
    void swap(node*, node*);
    

    void bubble_sort();
    void insertion_sort();
    void selection_sort();
};