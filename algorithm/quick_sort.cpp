#include <iostream>
#include <vector>
#include <list>
#include <unistd.h>


using namespace std;


//мое не работало я взял тыкнул код из интернета и оно работает
//но проблема этого кода что тут не ищется элемент слева, тут просто пихаются по очереди все элементы справа налево
//надо попробовать это починить но покачто мне нужен небольшой отдых, комментарий чтобы не забыть
//UPD 2.0 я ее доделал все роботает

void coutvector (vector<int> v, int start, int finish)
{
    for (size_t i = start; i <= finish; i++)
    {
        cout << v[i] << " ";
        /* code */
    }
    cout << endl;
    
}


int partition(vector<int>& v, int first_index, int last_index)
{
    int pivot = v[last_index];
    cout << "pivot = " << pivot << endl;
    int item_from_left = first_index;
    int item_from_right = last_index - 1;
    
    cout << "sadasd " << first_index << " " << last_index << endl;
    
    coutvector(v, first_index, last_index);
    coutvector(v, 0, v.size()-1);
    while (item_from_right > item_from_left)
    {
    
        if (v[item_from_right] >= pivot)
        {
            item_from_right--;
            if (item_from_right <= first_index)
            {
                break;
            }
        }

        if (v[item_from_left] < pivot)
        {
            item_from_left++;
            if (item_from_left == last_index)
            {
                item_from_left--;
                break;
            }
        }

        if (v[item_from_right] < pivot && v[item_from_left] >= pivot) 
        {
            cout << "swapping " <<  v[item_from_left] << " " << v[item_from_right] << endl;
            swap(v[item_from_left], v[item_from_right]);
            item_from_left++;
            item_from_right--;
        }
    }

    if (item_from_left + 1 != last_index)
    {
        cout << "swapping pivot " <<  v[item_from_left] << " " << v[last_index] << endl;
        if (v[item_from_left] < pivot)
            swap(v[item_from_left + 1], v[last_index]);
        else 
        {
            swap(v[item_from_left], v[last_index]);
            item_from_left--;
        }
    }
    return (item_from_left + 1);
}


int quick_sort(vector<int>& v, int first_index, int last_index)
{   
    if (last_index == first_index + 1)
    {
        if (v[first_index] > v[last_index])
            swap(v[first_index], v[last_index]);
    }
    if (last_index > first_index + 1)
    {
        int part_index = partition(v, first_index, last_index);

        quick_sort(v, first_index, part_index-1);
        quick_sort(v, part_index + 1, last_index);
    }
}


void quick_sort(vector<int>& v)
{
    quick_sort(v, 0, v.size()-1);
}



int main()
{
    vector<int> v {8, 3, 7, 3, 4, 6, 1 , 7, 77, 32, 9, 6, 7, 56};
    for (int i = 0; i < 25; i++)
    {
        
        int num = rand()%26;
        v.push_back(num);
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " " ;
    }
    cout << endl;
    quick_sort(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " " ;
    }
}