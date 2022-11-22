#include <iostream>

#include "strunni.h"
#include "udarni.h"
#include "duhovoy.h"

int main()
{
    Musical_instrument orkestr[10];

    for (int i = 0; i < 10; i++)
    {
        if (i % 4 == 0)
        {
            orkestr[i] = Udarni();
        }

        else if (i % 3 == 0)
        {
            orkestr[i] = Duhovoy();
        }

        else 
        {
            orkestr[i] = Strunni();
        }
    }
    for (int i = 0; i < 10; i++)
    {
        orkestr[i].cout_type();
    }


}
