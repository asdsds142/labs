#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>
#include "time_check.h"


using namespace std;





/*14. Построить класс для работы с бинарным деревом, узлы которого содержат действительные числа. 
  Создать дерево для заданной последовательности чисел. Используя его, упорядочить последовательность по возрастанию, убыванию.*/


class Btree
{
private:
    struct node 
    { 
        double value; 
        node* left = nullptr; 
        node* right = nullptr;
        node(double val);
        ~node();
    };
    node* root = nullptr;

    void add(node*, double);
    void write_to_file(string, node*);
    bool find(double, node*);
    void sort(vector<double>*);
    void get_sorted(bool flg, vector<double> *result, node* ptr);
    void show(node*);
    void cycle_add(double value);

public:
    Btree(vector<double>);
    Btree(double);
    Btree(string); //работа с файлами
    Btree(Btree&&);
    Btree(Btree&) = default;

    ~Btree();

    void add(double);
    bool find(double);
    double get_rootvalue();
    void add_from_file(string);
    void write_to_file(string);
    void show();

    vector<double> get_sorted(bool flag);


};

