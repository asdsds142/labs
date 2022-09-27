#include <iostream>
#include <vector>
#include <list>


using namespace std;


vector<int> merge_sort(vector<int>&);
vector<int> merge(vector<int>, vector<int>);




//алгоритм в такой реализации жрет очень много памяти, по хорошему его надо как нибудь оптимизировать но я пока не знаю как
//в интернетах везде говорят создавать новые массивы для сливания но это же 2x памяти нужно тогда на сортировку
//протестировано, все работает, но вопрос с памятью остается открытым потом займусь им
vector<int> merge_sort(vector<int>& v)
{

    vector<int> first_half;
    vector<int> second_half;

    first_half.reserve(v.size()/2);
    int i = 0;
    if (v.size() > 1)
    {
        for ( ; i < v.size()/2; ++i)
        {
            first_half.push_back(v[i]);
        }
        for ( ; i < v.size(); ++i)
        {
            second_half.push_back(v[i]);
        }
        merge_sort(first_half);
        merge_sort(second_half);

        v = merge(first_half, second_half);
    }

    return v;
}


vector<int> merge(vector<int> v1, vector<int> v2)
{
    vector<int> result;
    result.reserve(v1.size() + v2.size());
    for (int i = 0, j = 0; i < v1.size(), j < v2.size(); )
    {
        
        //предусмотреть засовывание последнего элемента возможно надо будет
        if (v1[i] < v2[j])
        {
            result.push_back(v1[i]);
            i++;
            if (i == v1.size())
            {
                for ( ; j < v2.size(); j++)
                {
                    result.push_back(v2[j]);
                }
            }
        }
        else
        {
            result.push_back(v2[j]);
            j++;
            if (j == v2.size())
            {
                for ( ; i < v1.size(); i++)
                {
                    result.push_back(v1[i]);
                }
            }
        }

        
    }

    return result;
}








int main()
{
    vector<int> v {8, 3, 7, 3, 4, 6, 1 , 7, 8, 9, 6, 7, 56};
    merge_sort(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " " ;
    }
}
