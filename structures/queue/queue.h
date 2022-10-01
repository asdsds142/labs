#pragma once

#include <iostream>
#include <vector>
#include <array>

using namespace std;


class Queue
{
private:
    //нужно решить вопрос с инициализацией через array
    vector<int> body;

    int head_index = 0;
    int tail_index = 0;
    int max_size;
    
public:
    Queue(int);

    void push(int);
    int pop();
    bool is_empty();


};