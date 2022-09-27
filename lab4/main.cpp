#include "header.h"


int main()
{
    string filename1 = "textfile.txt";
    Btree<double> tr {filename1};
    vector<double> vtr;
    vtr = tr.get_sorted(1);
    cout << "flag1" << endl;
    for (size_t i = 0; i < vtr.size(); i++)
    {
        cout << vtr[i] << " ";
    }

    vtr = tr.get_sorted(0);
    cout << "flag1" << endl;
    for (size_t i = 0; i < vtr.size(); i++)
    {
        cout << vtr[i] << " ";
    }
    

}