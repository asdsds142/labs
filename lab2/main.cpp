#include "boolmatrix.h"

void tester()
{
    static int i = 0;
    cout << i << endl;
    i++;
}

int main()
{


    ifstream first_filestream {"matrix1"};
    ifstream second_filestream {"matrix2"};
    ifstream third_filestream {"matrix3"};


    BoolMatrix A{first_filestream};
    BoolMatrix B{second_filestream};
    BoolMatrix C{third_filestream};

        
    A.show();
    B.show();
    C.show();
    
    C = A&B;
    tester(); 
    C.show(); //тута ломается
    tester();
    

    C.lexicographic_sort();
    tester();
    cout << C;
    tester();
        
    C.inverse();
    tester();
    cout << C;
    tester();

    C.lexicographic_sort();
    tester();
    cout << C;
    tester();
        
    cout << "---------------------------------------------" << endl;

    first_filestream.close();
    second_filestream.close();
    third_filestream.close();

    ofstream first_ofilestream {"matrix1"};
    ofstream second_ofilestream {"matrix2"};
    ofstream third_ofilestream {"matrix3"};

    A.to_file(first_ofilestream);
    B.to_file(second_ofilestream);
    C.to_file(third_ofilestream);

    

    return 0;
}