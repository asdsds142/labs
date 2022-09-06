#include "boolmatrix.h"

/**/
//todo: (сделать еще функций?) (сделать еще операторов??(каких??))


int main()
{
    string filename = "BoolMatrix.txt";
    BoolMatrix M{filename};
    M.show();
    BoolMatrix c{M};
    M.inverse();
    M.show();
    c.show();
    BoolMatrix D = c|M;
    D.show();
    D = c/M;
    D.show();
    D = c&M;
    D.show();
    c.show();
    M.to_file(filename);
}