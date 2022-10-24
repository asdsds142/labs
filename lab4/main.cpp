#include "Btree.h"


int main()
{
    
    vector<int> randomized;
    randomized.reserve(7);
    for (int i = 0; i < 7; i++) 
    {
        randomized.push_back(i); 
    }
    
    Btree<int> tr {randomized}; 
    Btree<int> tr2 {tr};

    tr.show();
    tr2.show();

}