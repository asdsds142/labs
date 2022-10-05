#include <iostream>
#include <vector>

using namespace std;


/*функция принимает на вход отсортированный массив и делает бинарный поиск
  результат выдается в виде bool значения (присутствует/отсутствует искомый элемент)*/
bool binary_search(vector<int> v, int search_value)
{
    bool result = 0;

    if (v.size() == 0)
        return result;

    int left_bracket = 0;
    int right_bracket = v.size() - 1;
    int starting_index = v.size() / 2;

    while (left_bracket != right_bracket)
    {

        if (v[starting_index] == search_value)
        {
            result = 1;
            return result;
        }

        else if (v[starting_index] > search_value)
        {
            right_bracket = starting_index;
            starting_index = (right_bracket - left_bracket) / 2;

        }

        else if (v[starting_index] < search_value)
        {
            left_bracket = starting_index;
            starting_index = (right_bracket - left_bracket) / 2;

        }

        if (right_bracket - left_bracket == 1)
        {
            if (search_value == v[right_bracket] || search_value == v[left_bracket])
            {
                result = 1;
                return result;
            }

            else
            {
                result = 0;
                return result;
            }
        }

    }
}


int main()
{
    bool res;

    vector<int> a{1, 3 ,6 ,7 ,8, 9, 13, 16, 35, 36, 55, 62, 73, 76};
    res = binary_search(a, 2);

    cout << res << endl;
}