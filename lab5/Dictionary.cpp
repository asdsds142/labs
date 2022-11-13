//Dictionary.cpp
#include "Dictionary.h"


//вывести время на екран
void dDictionary::get_time()
{
    const std::chrono::duration<double> dur = chrono::system_clock::now() - this->time_stomp_;
    cout << "The local date and time of last change is: " << this->last_change_time_; 
    cout << "Time from last change is " << dur.count() << " seconds." << endl << endl;
}

//конструктор
dDictionary::dDictionary() //я не знаю как засунуть через список инициализации, оно постоянно ругается и очень злобно
{
    auto now = time(0);
    this->last_change_time_ = (char*)ctime(&now); //если делать ctime((const time_t *)time(0)); сегфолт
}

//добавить пару в словарь
void Dictionary::add_pair(string word, string translation)
{
    this->words_.push_back(word);
    this->translations_.push_back(translation);
}


//добавить пару в словарь
void dDictionary::add_pair(string word, string translation)
{
    this->words_.push_back(word);
    this->translations_.push_back(translation);

    auto now = time(0);
    this->last_change_time_ = ctime(&now);

    this->time_stomp_ = chrono::system_clock::now();
}


//вывод на екран
void Dictionary::show()
{
    system("clear");
    for (size_t i = 0; i < this->words_.size(); i++)
    {
        cout << this->words_[i] << ' ' << this->translations_[i] << endl;
    }
}


//вывод на екран
void dDictionary::show()
{
    system("clear");
    this->get_time();
    for (size_t i = 0; i < this->words_.size(); i++)
    {
        cout << this->words_[i] << ' ' << this->translations_[i] << endl;
    }
}