#include "Header.h"


Vector::Vector() {
	int size;
	cout << "Enter size of your Vetcors: ";
	cin >> n; //отличная идея переменной сайз, почему не сделать вот это приватным полем вектора?
	cout << endl;
	vector1 = new int[n];
			for (int i = 0; i < n; i++) {
				cout << "Type " << i+1 << " number of your thirst vector: ";
				cin >> vector1[i];
			} 
			cout << "The Result is: (";
			for (int i = 0; i < n; i++) {
				cout << " " << vector1[i];
			} 
			cout << " )";
			cout << endl;
}
	

void Vector::ScalarProduct(const Vector& other) { //опять же в целом нормально но сделав по 1 вектору в векторе можно принимать Vector::ScalarProduct(Vector& other)
	int sum = 0;											
	for (int i = 0; i < n; i++) {
		sum += vector1[i] * other.vector1[i];  //тогда вот тут вот будет условно sum += vector1[i] + other.vector1[i] и будет балдежно
	}
	cout << "The Scalar Product is " << sum << endl;
	if (sum == 0) {
		cout << " Vectors are orthogonal" << endl;
	}
	for (int i = 0; i < n; i++) {
		if (vector1[i] / other.vector1[i] == vector1[i + 1] / other.vector1[i + 1]) {
			cout << "Vectors are collinear" << endl;
			i = 100;
		}
	}

}
void Vector::VectorModulus() {
	int sum1 = 0;
	for (int i = 0; i < n; i++) {
		sum1 += vector1[i] * vector1[i];
	}
	double mod = sqrt(sum1);
	cout << "Vector 1 Modulus is " << mod << endl;
}
Vector::Vector(const Vector& other):
n(other.n), vector1(new int[other.n])
{
	for (size_t i = 0; i < n; i++)
	{
		vector1[i] = other.vector1[i];
	}
	
}
void Vector::overload(int a) {  //поменять название функции на Vector& Vector::operator*(int a) 
	cout << "The result by multiplying by " << a << " is ( ";
	for (int i = 0; i < n; i++) {
		cout << vector1[i] * a << ", ";
	}
	cout << ")"<<endl;
}

void Vector::overload(double b) //поменять название функции на Vector& Vector::operator+(double a)  
{
	cout << "The result by increasing by " << b << " is ( ";
	for (int i = 0; i < n; i++) {
		cout << vector1[i]+b << ", ";
	}
	cout << ")"<<endl;
}

void Vector::overload(long d) //поменять название функции на Vector& Vector::operator-(long a) 
{
	cout << "The result by decreasing by " << d << " is ( ";
	for (int i = 0; i < n; i++) {
		cout << vector1[i]-d << ", ";
	}
	cout << ")"<<endl;
}



Vector::~Vector()
{
	delete [] vector1;

}



/*
Vector::Vector(const Vector& other):
n(other.n), vector1(new int[n]) //такой синтаксис заполняет поля n и vector1 до входа в скобочки, это правильнее
{
	for (int i = 0; i < n; i++)
	{
		vector1[i] = other.vector1[i];
	}
}
*/