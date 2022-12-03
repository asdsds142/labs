//main.cpp
/*
Лабораторная работа № 8.1.
Использование параметризованных классов стандартной библиотеки.
Реализовать алгоритм, используя объекты  класса «String».

Вариант 1. 
Вывести текст, составленный из последних букв всех слов. Вывести все слова, содержащие ровно две буквы 'd'.
*/
#include <iostream>
#include <string>
#include <fstream>

bool nonvalueble(char s)
{
    if (s != 'A' && s != 'a' && s != 'B' && s != 'b' && s != 'C' && s != 'c' && s != 'D' && s != 'd' && s != 'E'
     && s != 'e' && s != 'F' && s != 'f' && s != 'G' && s != 'g' && s != 'H' && s != 'h' && s != 'I' && s != 'i'
     && s != 'J' && s != 'j' && s != 'K' && s != 'k' && s != 'L' && s != 'l' && s != 'M' && s != 'm' && s != 'N'
     && s != 'n' && s != 'O' && s != 'o' && s != 'P' && s != 'p' && s != 'Q' && s != 'q' && s != 'R' && s != 'r'
     && s != 'S' && s != 's' && s != 'T' && s != 't' && s != 'U' && s != 'u' && s != 'V' && s != 'v' && s != 'W'
     && s != 'w' && s != 'X' && s != 'x' && s != 'Y' && s != 'y' && s != 'Z' && s != 'z') //а еще можно русские буквы добавить
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}


int main()
{
    std::string text = "";
    auto inp_s = std::ifstream("supportive.data");

    unsigned long field = 0;
    field += 3240924529348552985;
    std::cout << field << std::endl;
    
    while (!inp_s.eof())
    {
        std::string buf;
        getline(inp_s, buf);
        text += buf;
        text += '\n';
    }

    std::string last_literals_text; //буфер для текста из последних букв
    std::string double_d_words; //буфер для текста из слов с двумя d


    //удаляем из текста знаки препинания
    for (size_t i = 0; i < text.size(); i++)
    {
        if (text[i] == ',' || text[i] == '.' || text[i] == '-' || text[i] == ':' || text[i] == ';')
        {
            text[i] = ' ';
        }
    }
    

    //liter_counter - переменная счетчик для букв, word_start - переменная счетчик для индекса начала слова
    for (size_t i = 0, liter_counter = 0, word_start = 0; i < text.size(); i++)
    {
        //если символ с индексом i равен искомой букве увеличиваем счетчик
        if (text[i] == 'd')
        {
            liter_counter++;
        }
        
        //если счетчик = 2 и слово закончилось (текущий символ пробел или конец строки, или достигнут конец массива)
        if (liter_counter == 2 && (text[i] == '\n' || text[i] == ' ' || i + 1 == text.size())) 
        {
            for (size_t j = word_start; j < i; j++)
            {
                double_d_words += text[j];
            }
            double_d_words += ' ';
        }
        
        if (i > 0)
        {
            //если предыдущий символ - пробел или конец строки а текущий символ не пробел - начинаем новое слово
            if ((text[i - 1] == ' ' || text[i - 1] == '\n') && (text[i] != ' ' && text[i] != '\n'))
            {
                word_start = i;
            }
        }

        //если текущий символ пробельный или конец строки, а предыдущий нет записываем последнюю букву
        if ((text[i] == ' ' || text[i] == '\n') && (text[i - 1] != ' ' && text[i - 1] != '\n'))
        {
            last_literals_text += text[i - 1];
        }

        //если слово закончилось обнуляем счетчик
        if (text[i] == ' ' || text[i] == '\n')
        {
            liter_counter = 0;
        }
    }   

    std::cout << "Текст из последних букв: " << last_literals_text << std::endl;
    std::cout << "Текст из слов с двумя буквами d: " << double_d_words << std::endl; 

}