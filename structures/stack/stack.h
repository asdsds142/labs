#pragma once

#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Stack
{
private:
    vector<int> body;
    int tail_index = -1;
    int maxsize;
    
public:
    Stack(int);

    void push_back(int);
    int pop();
    bool is_empty();


};