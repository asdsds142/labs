#pragma once


#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
12. �����, ������ �������, �� ������� ����� ����������� (�� 1 �� 10), ����� �������. ������� ������ ��������. �������:
�) �����, ������� ����������� ����� ��� �� N ���������;
�) ����� � ���������� �������;
�) ��� ��������� ����� ������ �������, �� ������� ��� �������-����;

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
