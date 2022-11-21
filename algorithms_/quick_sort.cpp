#include <iostream>
#include <vector>
#include <list>
#include <unistd.h>


using namespace std;

//оно работает прошло тесты но почему то не дает поменять int64_t на uint64_t

int64_t partition(vector<int>& vect, uint64_t first_index, uint64_t last_index)
{
    int pivot = vect[last_index];
    uint64_t pi = first_index;

    for (size_t i = first_index; i < last_index; i++)
    {
        if (vect[i] < pivot)
        {
            std::swap(vect[pi], vect[i]);
            pi++;
        }
    }

    std::swap(vect[pi], vect[last_index]);
    return pi;
}


void quick_sort(vector<int>& vect, uint64_t first_index, uint64_t last_index)
{   
    if (last_index > first_index)
    {
        uint64_t part_index = partition(vect, first_index, last_index);
        
        if (part_index != 0)
        {
            quick_sort(vect, first_index, part_index-1);
        }
        quick_sort(vect, part_index + 1, last_index);
    }
}


void quick_sort(vector<int>& vect)
{

    quick_sort(vect, 0, static_cast<uint64_t>(vect.size()-1));
}


