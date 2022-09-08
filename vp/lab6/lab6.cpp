#include "header.h"


short getstatus(stud s)
{
    short st = 5;
    for (int i = 0; i < s.scorenumber; i++)
    {
        if (s.p[i] == 1 || s.p[i] == 2 || s.p[i] == 3)
        {
            st = 2;
            break;
        }

        if ((s.p[i] == 4 || s.p[i] == 5) && st < 4)
        {
            st = 3;
            continue;
        }

        if ((s.p[i] == 6 || s.p[i] == 7 || s.p[i] == 8) && st < 5)
        {
            st = 4;
            continue;
        }
    }

    s.status = st;
    return st;
}



void sort_status(st)




