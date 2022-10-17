#include "header.h"
#include <unistd.h>



int main()
{
    const auto sta = std::chrono::system_clock::now();
    string filename1 = "textfile.txt";
    ifstream fp{filename1};
    vector<double> asd {};
    asd.reserve(25);
    while (!fp.eof())
    {
        double a;
        fp >> a;

        asd.push_back(a);
        //sleep(1);
    } //дабы лишний раз не перекомпилировать для тестировки можно просто менять содержимое "textfile.txt"

    cout << "Исходный массив: " << endl;
    for (int i = 0; i < asd.size(); i++)
    {
        cout << asd[i] << " ";
    }
    cout << endl;

    Btree tr {asd};
    vector<double> vtr;
    vtr = tr.get_sorted(1);
    cout << "полученный 'сортировкой' по неубыванию массив: " << endl;
    for (size_t i = 0; i < vtr.size(); i++)
    {
        cout << vtr[i] << " ";
    }

    vtr = tr.get_sorted(0);
    cout << endl << endl;
    cout << "полученный 'сортировкой' по невозрастанию массив: " << endl;
    for (size_t i = 0; i < vtr.size(); i++)
    {
        cout << vtr[i] << " ";
    }
    cout << endl;


    tr.show();
    const std::chrono::duration<double> dur = std::chrono::system_clock::now() - sta;
    cout << "Время выполнения: " << dur.count() << " seconds" << endl;
    //cout << tr.find(12) << endl << tr.find(123) << endl << tr.get_rootvalue() << endl;

}