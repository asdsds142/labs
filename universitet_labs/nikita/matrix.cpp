#include "matrix.h"
#include "math.h"

#include <iostream>

using namespace std;

// private methods
int Matrix::chooseMinorRow() {
    while (true) {
        cout << "Введите строку (0 - " << size - 1 << "): ";
        cin >> minorRow;
        if (minorRow > -1 && minorRow < size) {
            break;
        }

        cout << "Введено некорректное значение, попробуйте ещё раз" << endl;
    }
}
int Matrix::chooseMinorColumn() {
    while (true) {
        cout << "Введите стобец (0 - " << size - 1 << "): ";
        cin >> minorColumn;
        if (minorColumn > -1 && minorColumn < size) {
            break;
        }

        cout << "Введено некорректное значение, попробуйте ещё раз" << endl;
    }
}
double** Matrix::getMatrixForMinor() {
    double **matrixForMinor = new double*[size - 1];
    int a = 0; // index for rows of minor matrix
    for (int i = 0; i < size; i++) {
        if (i == minorRow) {
            continue;
        }

        int b = 0; // index for columns of minor matrix
        matrixForMinor[a] = new double[size - 1];
        for (int j = 0; j < size; j++) {
            if (j == minorColumn) {
                continue;
            }

            matrixForMinor[a][b] = matrix[i][j];
            b++;
        }

        a++;
    }

    return matrixForMinor;
}

//public methods
Matrix::Matrix(int size, double **matrix) {
    this->size = size;
    this->matrix = matrix;
}
Matrix::Matrix(Matrix *matrix) {
    size = matrix->getSize();
    this->matrix = matrix->getMatrix();
    minorRow = matrix->getMinorRow();
    minorColumn = matrix->getMinorColumn();
    minor = matrix->getMinor();
}
int Matrix::getSize() {
    return size;
}
double** Matrix::getMatrix() {
    return matrix;
}
int Matrix::getMinorRow() {
    return minorRow;
}
int Matrix::getMinorColumn() {
    return minorColumn;
}
double Matrix::getMinor() {
    return minor;
}
void Matrix::setSize(int size) {
    this->size = size;
}
void Matrix::setMatrix(double **matrix) {
    this->matrix = matrix;
}
void Matrix::setMinorRow(int minorRow) {
    this->minorRow = minorRow;
}
void Matrix::setMinorColumn(int minorColumn) {
    this->minorColumn = minorColumn;
}
void Matrix::setMinor(double minor) {
    this->minor = minor;
}
void Matrix::showMatrix() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}
void Matrix::createMinor() {
    chooseMinorRow();
    chooseMinorColumn();
    double **matrixForMinor = getMatrixForMinor();
    minor = determinant(matrixForMinor, size - 1);
    cout << "Минор найден" << endl;
}
void Matrix::updateMinor() {
    if (minorRow == -1 || minorColumn == -1) {
        cout << "Минор для данной матрицы не создан" << endl;
        return;
    }

    double **matrixForMinor = getMatrixForMinor();
    minor = determinant(matrixForMinor, size - 1);
    cout << "Минор найден" << endl;
}
void Matrix::showMinor() {
    if (minorRow == -1 || minorColumn == -1) {
        cout << "Минор для данной матрицы не создан" << endl;
        return;
    }

    cout << "Минор: " << minorRow << ", " << minorColumn << endl;
    cout << "Минор = " << minor << endl;
}
void Matrix::additionOfMinors(Matrix m2) {
    if (minorRow == -1 || minorColumn == -1) {
        cout << "Минор для первой матрицы не создан" << endl;
        return;
    }

    if (m2.getMinorRow() == -1 || m2.getMinorColumn() == -1) {
        cout << "Минор для второй матрицы не создан" << endl;
        return;
    }

    cout << "Сумма миноров: " << minor << " + " << m2.getMinor() << " = " << minor + m2.getMinor() << endl;
}
void Matrix::subtractionOfMinors(Matrix m2) {
    if (minorRow == -1 || minorColumn == -1) {
        cout << "Минор для первой матрицы не создан" << endl;
        return;
    }

    if (m2.getMinorRow() == -1 || m2.getMinorColumn() == -1) {
        cout << "Минор для второй матрицы не создан" << endl;
        return;
    }

    cout << "Разница миноров: " << minor << " - " << m2.getMinor() << " = " << minor - m2.getMinor() << endl;
}
void Matrix::multiplicationOfMinors(Matrix m2) {
    if (minorRow == -1 || minorColumn == -1) {
        cout << "Минор для первой матрицы не создан" << endl;
        return;
    }

    if (m2.getMinorRow() == -1 || m2.getMinorColumn() == -1) {
        cout << "Минор для второй матрицы не создан" << endl;
        return;
    }

    cout << "Произведение миноров: " << minor << " * " << m2.getMinor() << " = " << minor * m2.getMinor() << endl;
}
bool Matrix::isMinorCreated() {
    return minorRow == -1 || minorColumn == -1;
}
Matrix Matrix::multiplication(int constant) {
    double **matrix = this->matrix;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] *= constant;
        }
    }

    Matrix newMatrix = *this;
    newMatrix.setMatrix(matrix);
    return newMatrix;
}
double Matrix::operator + (Matrix m2) { // перегрузка
    return minor + m2.getMinor();
}
double Matrix::operator - (Matrix m2) {
    return minor - m2.getMinor();
}
double Matrix::operator * (Matrix m2) {
    return minor * m2.getMinor();
}
Matrix Matrix::operator = (Matrix m2) {
    size = m2.getSize();
    matrix = m2.getMatrix();
    minorRow = m2.getMinorRow();
    minorColumn = m2.getMinorColumn();
    minor = m2.getMinor();
    return *this;
}
Matrix Matrix::operator *= (int constant) {
    this->multiplication(constant);
    return *this;
}

ostream& operator << (ostream& os, Matrix m) {
  string result = "Размер матрицы: " + to_string(m.getSize()) + " x " + to_string(m.getSize()) + "\nМатрица:\n";
  for (int i = 0; i < m.getSize(); i++) {
    for (int j = 0; j < m.getSize(); j++) {
      result.append(to_string(m.getMatrix()[i][j]) + " ");
    }

    result.append("\n");
  }

  return os << result;
}