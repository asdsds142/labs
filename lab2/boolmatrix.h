#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <vector>



using namespace std;


/*Класс описывающий булеву матрицу, хранение данных происходит в виде массива long,
 *доступ к элементам производится при помощи битовых операций сдвига и остатка от деления на 2*/
class BoolMatrix
{
private:
	short i, j;
    vector<long> p; //проставлять везде unsigned ради 1 бита мне немножко лень хотя я возможно чего то не знаю

	

public:
	BoolMatrix(int, int); // добавить для всех конструкторов защиту от матриц больше размера j = 63 (с учетом знака) (или ненада)
	BoolMatrix(string);														//или сколько там битов в лонге		
    BoolMatrix(const BoolMatrix&); 

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
	long count_ones();


	
	

};