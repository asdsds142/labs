#pragma once


#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
12. Слово, Номера страниц, на которых слово встречается (от 1 до 10), Число страниц. Создать массив объектов. Вывести:
а) слова, которые встречаются более чем на N страницах;
б) слова в алфавитном порядке;
в) для заданного слова номера страниц, на которых оно встреча-ется;

*/


class Word
{
private:
    string word;
    vector<int> pages;



public:
    Word();
    Word(string, int);
    void set_word(string);
    int get_number();
    vector<int> get_pages();
    string get_word();
    void show();

};
