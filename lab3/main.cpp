#include "header.h"
#include <unistd.h>



int main()
{
    time_checker ch{"main"};
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
    vector<double> randomized;
    randomized.reserve(10000000);
    for (int i = 0; i < 10000000; i++) 
    {
        randomized.push_back(((rand()))); //почему то если раскомментировать остаток от деления производительность падает в 10+ раз
    } //видимо производительность падает потому что среди чисел rand%284 гораздо меньше чисел нацело делящихся на правую штуку, а нацело разделенные проще обрабатывать
    cout << "finished" << endl; //интересный факт, 3 000 000 rand() чисел обрабатывается 4 секунды, 3 000 000 7/(rand%300) 2000 секунд
    
    Btree tr {randomized}; 
    /*
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


    tr.show();*/
    //cout << tr.find(12) << endl << tr.find(123) << endl << tr.get_rootvalue() << endl;

}