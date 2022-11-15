#include "tools.h"

//вызывает input_stream.ignore(9090, слеш n); для заданного потока
void Tools::ignore_much(istream& input_stream)
{
    input_stream.ignore(9090, '\n');
}



//трай-кетчит ввод stringa из input_stream, опционально выводит msg перед вводом
void Tools::try_input(istream& input_stream, string& buffer, string msg)
{
    cout << msg;
    cout.flush();

    bool i = true;
    while (i)
    {
        try
        {
            input_stream >> buffer;
            if (input_stream.fail())
            {
                input_stream.clear();
                throw std::runtime_error("input failed");
            }
            i = false;
        }
        catch(const std::exception& e)
        {
            Tools::ignore_much(input_stream);
            std::cerr << e.what() << '\n';
        }
    }
}


//трай-кетчит getline для stringa из потока input_stream, опционально выводит msg перед вводом
void Tools::try_getline(istream& input_stream, string& buffer, string msg)
{
    cout << msg;
    cout.flush();

    bool i = true;
    while (i)
    {
        try
        {
            Tools::ignore_much(input_stream);
            getline(input_stream, buffer);
            if (input_stream.fail())
            {
                input_stream.clear();
                throw std::runtime_error("stream.getline failed");
            }
            i = 0;
        }
        catch(const std::exception& e)
        {

            std::cerr << e.what() << '\n';
        }
        
    }
}

//трай-кетчит ввод long из потока input_stream, aопционально выводит msg перед вводом
void Tools::try_input(istream& input_stream, long& buffer, string msg)
{
    cout << msg;
    cout.flush();

    string str_buffer;
    bool i = true;
    while (i)
    {
        Tools::try_input(input_stream, str_buffer);
        try
        {
            buffer = stoi(str_buffer); 
            //по хорошему надо бы написать свою stoi, то при подаче в нее строки типа "34dfskjfjkj" она нормально сработает вернув 34

            i = false;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }  
    }
}