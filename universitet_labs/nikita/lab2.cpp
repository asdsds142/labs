// 11. Составить описания класса, обеспечивающего представление матрицы заданного размера nхn и любого минора в ней. Память для матрицы выделять динамически.
// Написать несколько конструкторов, в том числе конструктор копирования. Реализовать методы для отображения на экране как матрицы в целом, так и заданного минора;
// сложения, вычитания, умножения миноров. Перегрузить операции сложения, вычитания, умножения и присваивания для данного класса. Создать массив объектов данного
// класса и передать его в функцию, которая изменяет для i-й матрицы ее минор путем умножения на константу.

#include <iostream>

#include "matrix.h"
#include "input.h"

using namespace std;

Matrix changeMinor(Matrix matrix) {
    int constant;
    cout << "Введите константу: ";
    cin >> constant;
    matrix *= constant;
    matrix.updateMinor();
    return matrix;
}

int chooseIndex(int size, int chosenIndex = -1) {
    while (true) {
        int index;
        cout << "Введите индекс (0 - " << size - 1 << "): ";
        cin >> index;
        if (index > -1 && index < size && index != chosenIndex) {
            return index;
        }

        cout << "Введено некорректное значение, попробуйте ещё раз" << endl;
    }
}

int main() {
    int size = inputSize();
    Matrix** matrices = new Matrix * [size];
    for (int i = 0; i < size; i++) {
        int sizeOfMatrix;
        double** matrix = inputMatrix(sizeOfMatrix);
        matrices[i] = new Matrix(sizeOfMatrix, matrix);
    }

    while (true) {
        int menu;
        cout << "Меню программы:" << endl;
        cout << "1 - вывод матрицы" << endl;
        cout << "2 - вычисление минора" << endl;
        cout << "3 - вывод минора" << endl;
        cout << "4 - сложение миноров" << endl;
        cout << "5 - вычитание миноров" << endl;
        cout << "6 - умножение миноров" << endl;
        cout << "7 - изменение минора путём умножения матрицы на константу" << endl;
        cout << "0 - завершение работы" << endl;
        cout << "Ваш выбор: ";
        cin >> menu;
        switch (menu) {
        case 1: {
            int index = chooseIndex(size);
            cout << "Метод:" << endl;
            matrices[index]->showMatrix();
            cout << "Перегрузка:" << endl;
            cout << *matrices[index];
        }
              break;
        case 2: {
            int index = chooseIndex(size);
            matrices[index]->createMinor();
        }
              break;
        case 3: {
            int index = chooseIndex(size);
            matrices[index]->showMinor();
        }
              break;
        case 4: {
            int indexM1 = chooseIndex(size);
            int indexM2 = chooseIndex(size, indexM1);
            if (matrices[indexM1]->isMinorCreated()) {
                cout << "В первой матрице не создан минор" << endl;
                break;
            }

            if (matrices[indexM2]->isMinorCreated()) {
                cout << "Во второй матрице не создан минор" << endl;
                break;
            }

            cout << "Перегрузка оператора:" << endl;
            cout << "Сумма миноров: " << *matrices[indexM1] + *matrices[indexM2] << endl;
            cout << "Метод:" << endl;
            matrices[indexM1]->additionOfMinors(*matrices[indexM2]);
        }
              break;
        case 5: {
            int indexM1 = chooseIndex(size);
            int indexM2 = chooseIndex(size, indexM1);
            if (matrices[indexM1]->isMinorCreated()) {
                cout << "В первой матрице не создан минор" << endl;
                break;
            }

            if (matrices[indexM2]->isMinorCreated()) {
                cout << "Во второй матрице не создан минор" << endl;
                break;
            }

            cout << "Перегрузка оператора:" << endl;
            cout << "Разница миноров: " << *matrices[indexM1] - *matrices[indexM2] << endl;
            cout << "Метод:" << endl;
            matrices[indexM1]->subtractionOfMinors(*matrices[indexM2]);
        }
              break;
        case 6: {
            int indexM1 = chooseIndex(size);
            int indexM2 = chooseIndex(size, indexM1);
            if (matrices[indexM1]->isMinorCreated()) {
                cout << "В первой матрице не создан минор" << endl;
                break;
            }

            if (matrices[indexM2]->isMinorCreated()) {
                cout << "Во второй матрице не создан минор" << endl;
                break;
            }

            cout << "Перегрузка оператора:" << endl;
            cout << "Произведение миноров: " << *matrices[indexM1] * *matrices[indexM2] << endl;
            cout << "Метод:" << endl;
            matrices[indexM1]->multiplicationOfMinors(*matrices[indexM2]);
        }
              break;
        case 7: {
            int index = chooseIndex(size);
            *matrices[index] = changeMinor(*matrices[index]);
        }
              break;
        case 0:
            exit(0);
        default:
            cout << "Введено некорректное значение, попробуйте ещё раз" << endl;
        }
    }
}