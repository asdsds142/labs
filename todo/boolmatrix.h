#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <vector>



using namespace std;



class BoolMatrix
{
private:
	short i, j;
    vector<long> p;

	

public:
	BoolMatrix(int, int);
	BoolMatrix(string);
    BoolMatrix(const BoolMatrix&); //доделать копирование

	~BoolMatrix();
	void to_file(string);
	void show();
	void inverse();
	/*BoolMatrix operator+(BoolMatrix);
	BoolMatrix operator-(BoolMatrix);
	BoolMatrix operator*(BoolMatrix);*/
    BoolMatrix operator&(BoolMatrix);
    BoolMatrix operator|(BoolMatrix);
    BoolMatrix operator/(BoolMatrix);
    void operator=(BoolMatrix);


	
	

};