#pragma once

#include <iostream>
#include <cstring>


using namespace std;

class String
{
private:
    static const int MAX_SIZE = 100;
    char* c_str = nullptr;
    int size = 0;

public:
    String();
    String(char*);

    String(const String&);
    String& operator=(const String&);
    ~String();

    char get_nth_symbol(int);
    char& operator[](int);
    char get_and_delete_nth_symbol(int);

    String& concatent(const String&);
    String& operator+=(const String&);
    String operator+(const String&);

    void show();


    bool operator<(const String&);
    bool operator>(const String&);
    bool operator==(const String&);
    bool operator<=(const String&);
    bool operator>=(const String&);


};