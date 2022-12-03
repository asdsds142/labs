#include "Header.h"
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;


int main() {
	Vector objA;
	Vector objB;

	

	objA.ScalarProduct(objB);
	cout << endl;
	objA.VectorModulus();
	int a;
	double b;
	long d;
	cout << "At what number do you want to multiply? " <<endl;
	cin >> a;
	cout << endl;
	cout << "By what number do you want to increase your Vector " << endl;
	cin >> b;
	cout << endl;
	cout << "By what number do you want to decrease your Vector " << endl;
	cin >> d;
	cout << endl;
	objB.overload(a);
	objB.overload(b);
	objB.overload(d);

}