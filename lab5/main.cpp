//main.cpp
#include "Dictionary.h"

//для sleep();
#include <unistd.h>

//Иммитация бурной деятельности
void data_analysis()
{
    cout << "Analysing data";
    for (size_t i = 0; i < 4; ++i)
    {
        cout << '.';
        flush(cout); //противостоим буферизации
        sleep(1);
    }
    
    cout << endl << "Data confirmed." << endl;
}

// -//-
void data_adder()
{
    cout << "Data processing, please wait";
    for (size_t i = 0; i < 7; ++i)
    {
        cout << '.';
        flush(cout); //противостоим буферизации
        sleep(1);
    }
    cout << endl;
}

int main()
{
    dDictionary first_dict;

    for (size_t i = 0; i < 11; ++i)
    {
        string word = "word" + to_string(i);
        string translation = "translation" + to_string(i);

        first_dict.add_pair(word, translation);
    }
    
    string tmp_word;
    string tmp_translation;

    cout << "Input word " << endl;
    cin >> tmp_word;
    data_analysis();
    cout << "Input translation" << endl;
    cin >> tmp_translation;
    data_analysis();

    first_dict.add_pair(tmp_word, tmp_translation);
    data_adder();


    first_dict.get_time();
}