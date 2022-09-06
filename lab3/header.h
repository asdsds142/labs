#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <vector>


using namespace std;


double get_average_index(vector<double>);



class Btree
{
private:
    struct node { double value; node* left = nullptr; node* right = nullptr;};
    node* root = nullptr;
    void add(node*, double);
    void write_to_file(string, node*);
    void find(double, node*);
    void sort(vector<double>);
    bool flag; //указатель на больше/меньше, необходимо доработать в конструкторах


public:
    Btree(vector<double>);
    Btree(double);
    Btree(string); //работа с файлами
    ~Btree();
    void add(double);
    void find(double);
    double get_rootvalue();
    void add_from_file(string);
    void write_to_file(string);


};

