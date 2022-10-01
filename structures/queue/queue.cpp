#include "queue.h"

Queue::Queue(int value)
{
    this->max_size = value;
    this->body.reserve(value);


}

void Queue::push(int value)
{
    if (this->tail_index == this->body.size() - 1 && this->head_index == 0)
    {
        throw runtime_error("Переполнение очереди");
    }

    if (tail_index )

    if (this->tail_index == this->body.size() - 1 && this->head_index != 0)
    {
        this->tail_index = 0;
    }
    this->body[tail_index] = value;
}