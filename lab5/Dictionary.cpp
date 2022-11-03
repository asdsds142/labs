//Dictionary.cpp
#include "Dictionary.h"

void dDictionary::get_time()
{
    const std::chrono::duration<double> dur = chrono::system_clock::now() - this->time_stomp_;
    cout << "The local date and time of last change is: " << this->last_change_time_ << endl;
    cout << "Time from last change is " << dur.count() << " seconds." << endl;
}

void dDictionary::add_pair(string word, string translation)
{
    this->words_.push_back(word);
    this->translations_.push_back(translation);

    time_t now = time(0);
    this->last_change_time_ = ctime(&now);

    this->time_stomp_ = chrono::system_clock::now();
}

void Dictionary::show(){}

void dDictionary::show(){}