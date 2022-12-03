#include "Btree.h"

int main()
{
    
    vector<int> buf;
    buf.reserve(20);

    for (size_t i = 0; i < 20; ++i) 
    {
        buf.push_back(i); 
    }
    
    Btree<int> tr {buf}; 
    auto tr2 = tr;

    tr.show();
    tr2.show();
}