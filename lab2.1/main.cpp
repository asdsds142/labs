#include "boolmatrix.h"


int main()
{

    string filename1 = "matrix1";
    string filename2 = "matrix2";
    string filename3 = "matrix3";


    BoolMatrix A{filename1};
    BoolMatrix B{filename2};
    BoolMatrix C{filename3};


    A.show();
    B.show();

    A.to_file(filename1);
    B.to_file(filename2);



    C = A&B;
    C.to_file(filename3);
    cout << C;

    C.lexicographic_sort();
    cout << C;
    
    C.inverse();
    cout << C;

    C.lexicographic_sort();
    cout << C;


    cout << "---------------------------------------------" << endl;
    BoolMatrix D{filename3};
    D = A*B;
    cout << D;

    return 0;
}