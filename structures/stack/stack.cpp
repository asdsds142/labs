#include "stack.h"

Stack::Stack(int starting_size)
{
    this->body.reserve(starting_size);
}

void Stack::push_back(int value)
{
    body.push_back(value);
    tail_index++;
}


int Stack::pop()
{
    int result = body[tail_index];
    tail_index--;
    body.pop_back();
    
    return result;
}

bool Stack::is_empty()
{
    bool result = 0;
    if (body.size() != 0)
        result = 1;

    return result;
}




