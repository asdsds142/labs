//11. Составить описания класса, обеспечивающего представление матрицы заданного размера n x m и любого минора в ней.
//Память для матрицы выделять динамически. Написать несколько конструкторов, в том числе конструктор копирования. 
//Реализовать методы для отображения на экране как матрицы в целом, так и заданного минора, а также для изменения минора; сложения, вычитания, умножения миноров. 
//Перегрузить операции сложения, вычитания, умножения и присваивания для данного класса.
//Создать массив объектов данного класса и передать его в функцию, которая изменяет для i-й матрицы ее минор путем умножения на константу.


#include <iostream>
#include <cstdlib>
#include <math.h>
#include <ctime>
#include <algorithm>
using namespace std;
class Matrix {
    int rows; //количество строк
    int cols; //количество столбцов
    double* elements; 
public:
    Matrix(); //конструктор по умолчанию
    Matrix(int n, int m); //конструктор объекта по заданной размерности матрицы
    Matrix(int n, int m,  double* mas); //конструктор объекта по заданным размерности и элементам матрицы
    Matrix(const Matrix& ob); //конструктор копирования
    ~Matrix() { delete[]elements; } //деструктор
    int getMinorSize(); //метод возвращает максимально возможное значение порядка минора матрицы
    void show(); 
    Matrix getMinor(int k); //метод возвращает минор заданного порядка как объект класса матрица
    friend void changeMinorMul(Matrix* mas); //функция для изменения минора матрицы путем умножения на число
    friend void changeMinors(Matrix& ob1, Matrix& ob2, Matrix& minor); //функция для изменения миноров в двух матрицах
    Matrix operator+(Matrix ob); //перегрузка операторов
    Matrix operator*(Matrix ob);
    Matrix operator-(Matrix ob);
    Matrix& operator = (const Matrix p);
};


//*********** Matrix() **********************************
Matrix::Matrix()
{
    rows = rand() % 3 + 2;
    cols = rand() % 3 + 2;
    elements = new double[rows*cols];
    if (!elements) { cout << "Error"; return; }
    for (int i = 0; i < rows * cols; i++)
        elements[i] = rand() % 10 - rand()%10;
}
//************* Matrix(int n, int m) *******************************
Matrix::Matrix(int n, int m)
{   
    rows = n;
    cols = m;
    elements = new double[rows * cols];
    if (!elements) { cout << "Error"; return; }
    for (int i = 0; i < rows * cols; i++)
        elements[i] = rand() % 10 - rand() % 10;
}
//****************** Matrix(int n, int m, double mas[]) ******************
Matrix::Matrix(int n, int m, double * mas)
{
    rows = n;
    cols = m;
    elements = mas;
}
//*************** Matrix(const Matrix&ob) *********************
Matrix::Matrix(const Matrix& ob)
{
    rows = ob.rows;
    cols = ob.cols;
    elements = new double[cols * rows];
    for (int i = 0; i < rows * cols; i++) {
        elements[i] = ob.elements[i];
    }
}

//*************** getMinorSize() ***************
int Matrix::getMinorSize() 
{
    return min(rows, cols);
}
//***************  changeMinors(Matrix& ob1, Matrix& ob2, Matrix& minor)  ***************
void changeMinors(Matrix& ob1, Matrix& ob2, Matrix& minor) 
{
    int k;
    k = minor.rows; 
    int j = 0;
    int counter = 0;
    for (int i = 0; i < k * k; i++) {
        if ((i>0)&& i % k == 0) { j++;  counter = 0; }
        ob1.elements[j * ob1.cols + counter] = minor.elements[i];
        ob2.elements[j * ob2.cols + counter] = minor.elements[i];
        counter++;
    }

}
//*************** changeMinorMul(Matrix* mas)  ***************
void changeMinorMul(Matrix* mas) 
{
    int n;
    cout << "Input number of matrix you want to change: "; cin >> n;
    cout << endl;
    int k;
    cout << "Enter minor size" << endl; cin >> k;
    while (k > min(mas[n].rows, mas[n].cols)) {
        cout << "Error" << endl;
        cout << "Enter minor size" << endl; cin >> k;
    }
    double f;
    cout << "Input factor: "; cin >> f;
    cout << endl;
    
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++)
            mas[n].elements[i * mas[n].cols + j] = mas[n].elements[i * mas[n].cols + j] * f;
    }

    mas[n].show();
}
//**************** Matrix operator+(Matrix ob) ***************
Matrix Matrix::operator+(Matrix ob)
{
    if (rows == ob.rows && cols == ob.cols) {
        Matrix tmp(ob.rows, ob.cols);
        for (int i = 0; i < ob.rows; i++)
            for (int j = 0; j < ob.cols; j++)
                tmp.elements[i*cols+j] = elements[i * cols + j] + ob.elements[i * cols + j];
        return tmp;
    }
    else
    {
        cout << "incompatible matrix sizes" << endl;
        return Matrix(0, 0);
    }

}
//**************** Matrix operator-(Matrix ob) ***************
Matrix Matrix::operator-(Matrix ob)
{
    if (rows == ob.rows && cols == ob.cols) {
        Matrix tmp(ob.rows, ob.cols);
        for (int i = 0; i < ob.rows; i++)
            for (int j = 0; j < ob.cols; j++)
                tmp.elements[i * cols + j] = elements[i * cols + j] - ob.elements[i * cols + j];
        return tmp;
    }
    else
    {
        cout << "incompatible matrix sizes" << endl;
        return Matrix(0, 0);
    }

}
//*************** Matrix operator*(Matrix ob) ***************
Matrix Matrix::operator*(Matrix ob)
{
    if (cols == ob.rows) {
        Matrix tmp(rows, ob.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < ob.cols; j++) {
                tmp.elements[i * ob.cols + j] = 0;
                for (int k = 0; k < cols; k++)
                    tmp.elements[i * ob.cols + j] += elements[i * cols + k] * ob.elements[k * ob.cols + j];
            }
        return tmp;
            
   }
    else
    {
        cout << "incompatible matrix sizes" << endl;
        return Matrix(0, 0);
    }
}
//*************** Matrix operator = (const Matrix p) ***************
Matrix& Matrix::operator = (const Matrix p) {
    if (&p == this) return *this;
    if (elements) delete[] elements;
    rows = p.rows;
    cols = p.cols;
    elements = new double[cols * rows];
    for (int i = 0; i < rows * cols; ++i) {
        elements[i] = p.elements[i];
    }
    return *this;
}
//*************** show() ***************
void Matrix::show() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout.width(4);
            cout << elements[i*cols+j];
        }
        cout << endl;
    }
    cout << endl;
}

//*************** getMinor(int k) ***************
Matrix Matrix::getMinor(int k)
{
    Matrix tmp(k,k);
    for(int i = 0; i < k; i++){
        for (int j = 0; j < k; j++)
            tmp.elements[i*k+j] = elements[i * cols + j];
    }
    return tmp;
}

//******************** MAIN ****************************
int main()
{
    srand(time(NULL));
    
    int n;
    cout << "Enter a number of matrices: "; cin >> n;
    cout << endl;
    int r, c;
    Matrix* spis = new Matrix[n];

    int select1;
        cout << endl << "Choose the option:\n";
        cout << "  Random matrices of random size    --------->  1\n"
             << "  Random matrices of given sizes    --------->  2\n"
             << "  Enter matrices                    --------->  3\n";
           
        cin >> select1;
        cout << endl;
        switch (select1) {
        case 1: spis = new Matrix[n]; break;
        case 2: for (int i = 0; i < n; i++) 
        {
            cout << "Enter number of rows and columns: "; cin >> r >> c;
            cout << endl;
            spis[i] = Matrix(r, c);
        }
            break;
        case 3: for (int i = 0; i < n; i++)
        {
            cout << "Enter number of rows and columns: "; cin >> r >> c;
            double* elems = new double[r*c];
            cout << "Enter elements: ";
            for (int j = 0; j < r * c; j++) cin >> elems[j]; 
            spis[i] = Matrix(r, c, elems);
        }
            break;
        default: cout << "Error\n";
        }
    
   
    int flag = 1, select2;
    while (flag) {
        cout << "Sourse matrices" << endl;
        for (int i = 0; i < n; i++) {
            spis[i].show();
        }
        cout << endl << "Choose the option:\n";
        cout<< "  Operations on matrices            --------->1\n"
            << "  Operations on minors              --------->2\n"
            << "  Change minor by multiplication    --------->3\n"
            << "  End                               --------->4\n";
        cin >> select2;
        cout << endl;
        Matrix matr;
        int a, b, select3;
        switch (select2) {
        case 1: cout << "Choose 2 matrices: "; cin >> a >> b;
	    if (a >= n || b >= n){
	    	cout << "Incorrect matrices indexes\n\n";
		break;
            }
            cout << endl << "Choose the operation:\n";
            cout<< "  Addition         --------->1\n"
                << "  Substitution     --------->2\n"
                << "  Multiplication   --------->3\n";
            cin >> select3;
            switch (select3) {
            case 1: matr = spis[a] + spis[b]; matr.show(); break;
            case 2: matr = spis[a] - spis[b]; matr.show(); break;
            case 3: matr = spis[a] * spis[b]; matr.show(); break;
            }
            break;
        case 2: cout << "Choose 2 matrices: "; cin >> a >> b;
            int k;
            cout << "Enter minor size" << endl; cin >> k;
            while (k > min(spis[a].getMinorSize(), spis[b].getMinorSize())) {
                cout << "Error" << endl;
                cout << "Enter minor size" << endl; cin >> k;
            }
            cout << endl << "Choose the operation:\n";
            cout << "  Addition         --------->1\n"
                << "  Substitution     --------->2\n"
                << "  Multiplication   --------->3\n";
            cin >> select3;
            switch (select3) {
            case 1: matr = spis[a].getMinor(k) + spis[b].getMinor(k); matr.show(); changeMinors(spis[a], spis[b], matr); break;
            case 2: matr = spis[a].getMinor(k) - spis[b].getMinor(k); matr.show(); changeMinors(spis[a], spis[b], matr); break;
            case 3: matr = spis[a].getMinor(k) * spis[b].getMinor(k); matr.show(); changeMinors(spis[a], spis[b], matr); break;
            } break;
        case 3: changeMinorMul(spis); break;
        case 4: flag = 0;	cout << "End" << endl;	break;
        default: cout << "Error\n";
        }
    }

    delete[] spis;
}