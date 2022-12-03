#include "math.h"

double determinant(double **matrix, int size) { // нахождение определителя методом Гаусса
	for (int i = 0; i < size; i++) { // приведение матрицы к треугольному виду
		double coefficient;
		for (int j = i + 1; j < size; j++) {
			coefficient = matrix[j][i] / matrix[i][i];
			for (int k = 0; k < size; k++) {
				matrix[j][k] -= matrix[i][k] * coefficient;
			}
		}
	}

	double determinant = matrix[0][0]; // в переменную определителя переносим значение элемента под индексами (0; 0)
	for (int i = 1; i < size; i++) // находим произведение всех элементов на главной диагонали матрицы
		determinant *= matrix[i][i];

	return determinant;
}