#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "../threading/time_check.h"
#include "quick_sort.cpp"


int main()
{

    time_checker asd("main");
    auto inp_s = std::ifstream("test_block");
    auto inp_s2 = std::ifstream("test_block2");
    auto inp_s3 = std::ifstream("test_block3");
    auto inp_s4 = std::ifstream("test_block4");
    std::vector<int> vect;
    std::vector<int> vect2;
    std::vector<int> vect3;
    std::vector<int> vect4;
    std::vector<int> vect5;
    {
        time_checker all("allocate");
        vect.reserve(30);
        vect2.reserve(3000);
        vect3.reserve(30000);
        vect4.reserve(300000);
        vect5.reserve(999999);
    }
    {
        time_checker cycle("cycle");
    for (size_t i = 0; i < 999999; i++)
    {
        vect5.push_back(rand());
    }
    }
    
    
    int tmp;
    while (!inp_s.eof())
    {
        inp_s >> tmp;
        vect.push_back(tmp);
    }
    while (!inp_s2.eof())
    {
        inp_s2 >> tmp;
        vect2.push_back(tmp);
    }
    while (!inp_s3.eof())
    {
        inp_s3 >> tmp;
        vect3.push_back(tmp);
    }
    while (!inp_s4.eof())
    {
        inp_s4 >> tmp;
        vect4.push_back(tmp);
    }

    auto _vect = vect;
    auto _vect2 = vect2;
    auto _vect3 = vect3;
    auto _vect4 = vect4;
    auto _vect5 = vect5;


    {
        time_checker my ("my");
        quick_sort(_vect);
        quick_sort(_vect2);
        quick_sort(_vect3);
        quick_sort(_vect4);
        quick_sort(_vect5);
    }
    {
        time_checker ts("std::sort");
        std::sort(vect.begin(), vect.end());
        std::sort(vect2.begin(), vect2.end());
        std::sort(vect3.begin(), vect3.end());
        std::sort(vect4.begin(), vect4.end());
        std::sort(vect5.begin(), vect5.end());
    }
    std::cout << vect4.size();


    for (size_t i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] << ' ';
        
    }
    std::cout << std::endl;
    
    for (size_t i = 0; i < vect.size(); i++)
    {
        std::cout << _vect[i] << ' ';
    }
    std::cout << std::endl;

    for (size_t i = 0; i < vect.size(); i++)
    {
        if (vect[i] != _vect[i])
        {
            std::cout << "wrong!!!!" << std::endl;
        }
    }
    for (size_t i = 0; i < vect2.size(); i++)
    {
        if (vect2[i] != _vect2[i])
        {
            std::cout << "wrong!!!!" << std::endl;
        }
    }
    for (size_t i = 0; i < vect3.size(); i++)
    {
        if (vect3[i] != _vect3[i])
        {
            std::cout << "wrong!!!!" << std::endl;
        }
    }
    for (size_t i = 0; i < vect4.size(); i++)
    {
        if (vect4[i] != _vect4[i])
        {
            std::cout << "wrong!!!!" << std::endl;
        }
    }
    
}