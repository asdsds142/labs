#include <iostream>
#include <string>
#include <fstream>


using namespace std;


int createfile(char filename[])
{
    FILE *fp;
    fp = fopen(filename, "wt+");
    if (fp == NULL)
    {
        cout << "ошибка при открытии файла createfile" << endl;
    }

    fclose(fp);
    return 0;
}

int calculatebrackets_byfgetc(char filename[])
{

    FILE *fp;
    fp = fopen(filename, "rt");

    if (fp == NULL);
    {
        cout << "Ошибка при открытии файла calculatebrackets_byfgetc " << endl;
        int i = 0;
        while (1)
        {
            cout << filename[i];
            i += 1;
            if (filename [i] == '\0' || filename[i] == '\n')
                break;
        }
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


    int openbracket1 = 0;
    int openbracket2 = 0;
    int openbracket3 = 0;
    int closebracket1 = 0;
    int closebracket2 = 0;
    int closebracket3 = 0;

    bool efo = 0;

    while (!feof(fp))
    {
        cout << "flag1" << endl;
        char a[40] = ""; // засунул инициализацию сюда а не вне цикла на всякий случай чтобы случайно не получилось что нету символа '\0' после перезаписи
        fgets(a, 40, fp);
        for (int i = 0; i < 40; i++)
        {
            cout << a[i];
            if (a[i] == EOF)
            {
                efo = 1;
                break;
            }
            if (a[i] == '\n')
            {
                break;
            }

            if (a[i] == '[')
            {
                openbracket1 += 1;
                continue;
            }

            if (a[i] == '{')
            {
                openbracket2 += 1;
                continue;
            }

            if (a[i] == '(')
            {
                openbracket3 += 1;
                continue;
            }

            if (a[i] == ']')
            {
                closebracket1 += 1;
                continue;
            }

            if (a[i] == '}')
            {
                closebracket2 += 1;
                continue;
            }

            if (a[i] == ')')
            {
                closebracket3 += 1;
                continue;
            }      
        }
        if (!efo)
        {
            fgets(a, 40, fp);
        }
    }

    if (openbracket1 == closebracket1)
        cout << "Скобки [] расставлены верно" << endl;

    else
        cout << "Скобки [] расставлены неверно" << endl;

    if (openbracket2 == closebracket2)
        cout << "Скобки {} расставлены верно" << endl;

    else
        cout << "Скобки {} расставлены неверно" << endl;

    if (openbracket3 == closebracket3)
        cout << "Скобки () расставлены верно" << endl;

    else
        cout << "Скобки () расставлены верно" << endl;

    fclose(fp);   
    return 0;

}



int main()
{
    char a[] = "textfile.txt";

    
    //createfile(a);
    calculatebracketsby_fgets(a);

}




