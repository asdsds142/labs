#include <iostream>
#include <vector>
#include <list>


using namespace std;


int quick_sort(vector<int> v, int first_index, int last_index)
{
    if (first_index == last_index || last_index - first_index == 1)
        return 0;
    cout << "b" << endl;
    int pivot_index = v.size()/2;
    swap(v[pivot_index], v[last_index]); //может тут можно чот подфурычить избавиться от одного из куказателей но то пока не критично да и не напряжно
    pivot_index = last_index;
    last_index--;

    int left_index = first_index, right_index = last_index;

    while(left_index < right_index)
    {
        //предусмотреть зашиту от выхода за границы массива, защиту от того что все элементы больше или меньше пивота
        //пока что из-за этого не работает но на сегодня я временно устал
        if (v[left_index] > v[pivot_index] && v[right_index] < v[pivot_index] && left_index < right_index)
        {
            swap(v[left_index], v[right_index]);
        }
        
        if (v[left_index] < v[pivot_index])
        {
            left_index++;
        }

        if (v[right_index] > v[pivot_index])
        {
            right_index--;
        }
    }

    cout << first_index << " " << left_index-1 << " " << left_index << " " << last_index << endl;
    swap(v[pivot_index], v[left_index]);
    quick_sort(v, first_index, left_index-1);
    quick_sort(v, left_index, last_index);

}


void quick_sort(vector<int> v)
{
    quick_sort(v, 0, v.size()-1);
}



int main()
{
    vector<int> v {8, 3, 7, 3, 4, 6, 1 , 7, 8, 9, 6, 7, 56};
    quick_sort(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " " ;
    }
}