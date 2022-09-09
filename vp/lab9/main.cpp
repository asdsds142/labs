#include <iostream>
#include <string>
#include <fstream>


using namespace std;




int calculatebrackets_byfgetc(char filename[])
{

    FILE *fp;
    fp = fopen(filename, "r" );
    if (fp = NULL);
    {
        cout << "Ошибка при открытии файла" << endl;
        return -1;
    }
    
    char ch;
    ch = fgetc(fp);

    int openbracket1 = 0;
    int openbracket2 = 0;
    int openbracket3 = 0;
    int closebracket1 = 0;
    int closebracket2 = 0;
    int closebracket3 = 0;


    while(ch != EOF)
    {
        /*if (ch == '/')
        {
            ch = fgetc(fp);
            if (ch == '/')
            {
                cout << "Обнаружен однострочный комментарий" << endl;
            
                do
                {
                    ch = fgetc(fp);
                } while (ch != '\n' || ch != EOF);

                if (ch == EOF)
                {
                    cout << "EOF" << endl;
                }

                if (ch == '\n')
                {
                    cout << "Однострочный комментарий закончен, продолжаю подсчет" << endl;
                }


                
            }
            else 
            {
                if (ch == '*')
                {
                    ch = fgetc(fp);
                    cout << "Обнаружен многострочный комментарий" << endl;
                    do
                    {
                        if (ch == '*')
                        {
                            while (ch == '*')
                            {
                                ch = fgetc(fp);
                            }

                            if (ch == '/')
                            {
                                cout << "Комментарий окончен" << endl;
                                break;
                            }
                        }
                    } while (ch != EOF);
                    if (ch == EOF)
                    {
                        cout << "EOF" << endl;
                    }

                    
                }
            }
        }только уже написав кучу текста обнаружил что в условии сказано что скобки не используются в комментариях или в виде символов
         вроде оно должно работать но раз в условии нету то пожалуй пока выключу*/

        if (ch == '[')
        {
            openbracket1 += 1;
            continue;
        }

        if (ch == '{')
        {
            openbracket2 += 1;
            continue;
        }

        if (ch == '(')
        {
            openbracket3 += 1;
            continue;
        }

        if (ch == ']')
        {
            closebracket2 += 1;
            continue;
        }

        if (ch == '}')
        {
            closebracket2 += 1;
            continue;
        }

        if (ch == ')')
        {
            closebracket3 += 1;
            continue;
        }
        ch = fgetc(fp);
    }

    if (openbracket1 == closebracket1)
    {
        cout << "Скобки [] расставлены верно" << endl;
    }

    else
    {
        cout << "Скобки [] расставлены неверно" << endl;
    }

    if (openbracket2 == closebracket2)
    {
        cout << "Скобки {} расставлены верно" << endl;
    }

    else
    {
        cout << "Скобки {} расставлены неверно" << endl;
    }

    if (openbracket3 == closebracket3)
    {
        cout << "Скобки () расставлены верно" << endl;
    }

    else
    {
        cout << "Скобки () расставлены верно" << endl;
    }

    fclose(fp);   
    return 0;
}



int calculatebracketsby_fgets(char fn[])
{
    FILE *fp;
    fp = fopen(fn, "r");
    if (fp == NULL)
    {
        cout << "Ошибка при открытии файла" << endl;
        return -1;
    }
    char a[40] = "";

    fgets(a, 40, fp);
    bool efo = 0;


    while (!efo)
    {
        
    }

}



int main()
{

}




