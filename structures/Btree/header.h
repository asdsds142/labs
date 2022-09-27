#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>


using namespace std;






/*14. Построить класс для работы с бинарным деревом, узлы которого содержат действительные числа. 
  Создать дерево для заданной последовательности чисел. Используя его, упорядочить последовательность по возрастанию, убыванию.*/

template <class T>
class Btree
{
private:
    struct node { T value; node* left = nullptr; node* right = nullptr;};
    node* root = nullptr;
    void add(node*, T);
    void write_to_file(string, node*);
    bool find(T, node*);
    void sort(vector<T>*);
    void get_sorted(bool flg, vector<T> *result, node* ptr);

    bool flag; //указатель на больше/меньше, необходимо доработать в конструкторах


public:
    Btree(vector<T>);
    Btree(T);
    Btree(string); //работа с файлами
    ~Btree();
    void add(T);
    bool find(T);
    double get_rootvalue();
    void add_from_file(string);
    void write_to_file(string);

    vector<T> get_sorted(bool flag);


};

