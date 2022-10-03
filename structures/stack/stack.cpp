#include "stack.h"

Stack::Stack(int starting_size)
{
    this->body.reserve(starting_size);
    this->maxsize = starting_size;
}

void Stack::push_back(int value)
{
    if (this->body.size() < this->maxsize)
    {
        body.push_back(value);
        tail_index++;
    }

    else
    {
        throw runtime_error("Превышен максимальный размер стека");
    }
}


int Stack::pop()
{
    if (this->body.size() != 0)
    {
        int result = body[tail_index];
        tail_index--;
        body.pop_back();
        return result;
    }
    
    else
    {
        throw runtime_error("В стеке нет элементов");
    }
    
}

bool Stack::is_empty()
{
    bool result = 0;
    if (body.size() != 0)
        result = 1;

    return result;
}




