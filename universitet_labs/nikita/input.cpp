#include "input.h"

#include <iostream>

using namespace std;

int inputSize() {
	while (true) {
		int size;
		cout << "Введите количество матриц: ";
		cin >> size;
		if (size > 2) {
			return size;
		}

		cout << "Введено некорректное значение, попробуйте ещё раз" << endl;
	}
}

int inputInt(string text) {
	while (true) {
		int value;
		cout << "Введите " << text << ": ";
		cin >> value;
		if (value > 0) {
			return value;
		}

		cout << "Введено некорректное значение, попробуйте ещё раз" << endl;
	}
}

double **inputMatrix(int &size) {
	size = inputInt("размер квадратной матрицы");
	double **matrix = new double*[size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new double[size];
		for (int j = 0; j < size; j++) {
			cout << "Введите " << j + 1 << " элемент " << i + 1 << " строки матрицы: ";
			cin >> matrix[i][j];
		}
	}

	return matrix;
}