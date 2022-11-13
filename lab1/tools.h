//tools.h
//штука для разных полезных штук
#pragma once

#include <iostream>
#include <string>





using namespace std;

void try_input(istream&, long&, string = "");
void try_input(istream&, string&, string = "");
void try_getline(istream&, string&, string = "");
void ignore_much(istream&);