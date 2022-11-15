//tools.h
//штука для разных полезных штук
#pragma once

#include <iostream>
#include <string>





using namespace std;

class Tools
{
  private:
    Tools() = delete;
  public:
    static void try_input(istream&, long&, string = "");
    static void try_input(istream&, string&, string = "");
    static void try_getline(istream&, string&, string = "");
    static void ignore_much(istream&);
};


