#pragma once

/**
 * @brief функция по считыванию матрицы
 * @param A_ матрица коэффициентов
 * @param B_ столбец свободных членов
 * @param n_ количество неизвестных
*/
void readSLAYmatrix(double** A_, double* B_, int n_);

/**
 * @brief вывод расширенной матрицы
 * @param A_ матрица коэффициентов
 * @param B_ столбец свободных членов
 * @param n_ количество неизвестных
*/
void printSLAYmatrix(double** A_, double* B_, int n_);

/**
 * @brief функция которая заменяет в матрице один столбец на другой
 * @param matrix_ матрица в которой заменяем столбец
 * @param rows_ количество строк в матрице
 * @param newCols_ номер столбца, который заменяем
 * @param newColumn_ новый столбец
*/
void replaceColumn(double** arr_, int rows_, int newCols_, double* newColumn_);

/**
 * @brief функция по вычислению определителя
 * @param matrix_ матрица определитель которой считаем
 * @param size_ размер матрицы
 * @return определитель матрицы
*/
double determinantSlay(double** matrix_, double size_);

/**
 * @brief функция решающая СЛАУ методом Крамера
 * @param A_ матрица коэффициентов
 * @param B_ столбец свободных членов
 * @param n_ количество неизвестных
*/
void CramerMethod(double** A_, double* B_, int n_);