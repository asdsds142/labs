//Dictionary.h
#pragma once

#include <iostream>
#include <string>
#include <vector>
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
    virtual void add_pair(string, string);
};


//derivative class
class dDictionary : public Dictionary
{
protected:
    using time_point = std::chrono::_V2::system_clock::time_point;
    time_point time_stomp_ = chrono::system_clock::now();
    string last_change_time_ = "Dictionary wasn't changed.\n";

public:
    dDictionary();

    void add_pair(string, string) override;
    void get_time();
    void show() override;
    
};

