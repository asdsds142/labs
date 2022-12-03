//Btree_class_description.h
/*Вспомогательный хедер чтобы показать прототипы шаблонных функций*/
#pragma once

#include <iostream>
#include <string>
#include <vector>


using namespace std;

/*14. Построить класс для работы с бинарным деревом, узлы которого содержат действительные числа. 
  Создать дерево для заданной последовательности чисел. Используя его, упорядочить последовательность по возрастанию, убыванию.*/

template <class T>
class Btree
{
private:
    struct node 
    { 
        T value; 
        node* left = nullptr; 
        node* right = nullptr;
        node(T val);
        node(const node&);
        ~node();
        node& operator=(const node&);
    };
    node* root_ = nullptr;

    void recursive_add(node*, T);
    bool find(T, node*)const;
    void get_sorted(bool flg, vector<T> *result, node* ptr);
    void show(node*) const;
    void cycle_add(T);
    node* try_alloc(T);
    node* try_alloc(const node&);

public:
    Btree(vector<T>);
    Btree(T);
    Btree(Btree<T>&&);
    Btree(const Btree<T>&);

    ~Btree();

    void add(T);
    bool find(T) const;
    T get_rootvalue();
    void show() const;

    vector<T> get_sorted(bool flag);
    Btree& operator=(const Btree&);


};

