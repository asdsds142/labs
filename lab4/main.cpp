#include "header.h"


int main()
{
    string filename1 = "textfile.txt";
    ifstream fp{filename1};
    vector<double> asd {}; //потом для профилактики позасовывать суда разных типов может получится нормально, главное чтобы были перегружены операции сравнения
    asd.reserve(25);
    while (!fp.eof())
    {
        int a;
        fp >> a;
        asd.push_back(a);
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
    //cout << tr.find(12) << endl << tr.find(123) << endl << tr.get_rootvalue() << endl;

}