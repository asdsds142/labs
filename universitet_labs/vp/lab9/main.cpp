#include "header.h"






int main()
{
    char a[] = "textfile.txt"; 
    char b[] = "((([dfghjkl(()))))){{       olikyj [{{{}}}}}{}[][][][]    {";
    createfile(a);
    append_to_file(a, b);
    cout << endl;
    show_file(a);
    //calculatebrackets_byfgetc(a);
    calculatebracketsby_fgets(a);

}




