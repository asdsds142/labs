#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>


using namespace std;






/*14. Построить класс для работы с бинарным деревом, узлы которого содержат действительные числа. 
  Создать дерево для заданной последовательности чисел. Используя его, упорядочить последовательность по возрастанию, убыванию.*/


class Btree
{
private:
    struct node { double value; node* left = nullptr; node* right = nullptr;};
    node* root = nullptr;
    void add(node*, double);
    void write_to_file(string, node*);
    bool find(double, node*);
    void sort(vector<double>);
    void get_sorted(bool flg, vector<double> result, node* ptr);

    bool flag; //указатель на больше/меньше, необходимо доработать в конструкторах


public:
    Btree(vector<double>);
    Btree(double);
    Btree(string); //работа с файлами
    ~Btree();
    void add(double);
    bool find(double);
    double get_rootvalue();
    void add_from_file(string);
    void write_to_file(string);

    vector<double> get_sorted(bool flag);


};

