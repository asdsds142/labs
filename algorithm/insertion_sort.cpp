#include <iostream>
#include <vector>

using namespace std;


int insertion_sort(vector<int>& a)
{
    
    for (int i = 1; i < a.size(); i++)
    {

        int j = i;
        while (j > 0 && a[j-1] > a[j])
        {
            swap(a[j-1], a[j]);
            j--;
        }
        
    }
}




int main()
{
    vector<int> v {8, 3, 7, 3, 4, 6, 1 , 7, 8, 9, 6, 7, 56};
    insertion_sort(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " " ;
    }
}




