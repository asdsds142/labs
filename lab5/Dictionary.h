//Dictionary.h
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <chrono>


using namespace std;

//base class
class Dictionary
{
private:
protected:
    vector<string> words_;
    vector<string> translations_;
public:
    Dictionary() = default;
    virtual void show();
};


//derivative class
class dDictionary : public Dictionary
{
protected:
    std::chrono::_V2::system_clock::time_point time_stomp_ = chrono::system_clock::now();
    string last_change_time_ = "Dictionary wasn't changed.";

public:
    dDictionary() = default;

    void add_pair(string, string);
    void get_time();
    void show();
    
};

