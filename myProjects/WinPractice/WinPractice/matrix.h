#pragma once
/**
 * @brief считывание матрицы
 * @param matrix_ матрица, куда считываем
 * @param row_ количество строк матрицы
 * @param cols_ количество столбцов матрицы
*/
void readMatrix(double** matrix_, int rows_, int cols_);

/**
* @brief вывод матрицы
* @param matrix_ матрица, которую выводим
 * @param row_ количество строк матрицы
 * @param cols_ количество столбцов матрицы
*/
void printMatrix(double** matrix_, int rows_, int cols_);

/**
* @brief функция по копировнию матрицы
* @param matrix_ матрицы, которую копируем
* @param rows_ количество строк в матрице, которую копируем
* @param cols_ количество столбцов в матрице, которую копируем
* @return скопированная матрица
*/
double** copyMatrix(double** matrix_, int rows_, int cols_);

/**
* @brief функция, которая менят местами две строки в матрице
* @param matrix_ матрица, с которой работаем
* @param row1_ первая строка
* @param row2_ вторая строка
* @param n_ размер матрицы
*/
void swapRows(double** matrix_, int row1_, int row2_, int n_);

/**
* @brief функция, которая вычитает из одной строки другую
* @param matrix_ матрица, с которой работаем
* @param row1_ первая строка, которую вычитаем
* @param row2_ вторая строка, из которой вычитаем
* @param n_ размер матрицы
* @param s_ коэффициент вычитания
*/
void subtractRows(double** matrix_, int row1_, int row2_, int n_, double s_);

/**
* @brief функция, которая вычисляет определитель матрицы
* @param matrix_ матрица, определеитель которой считаем
* @param n_ размер матрицы
* @return определитель матрицы
*/
double determinant(double** matrix_, int n_);

/**
* @brief функция, которая приводит матрицу к треугольному виду
* @param matrix_ матрица, с которой работаем
* @param n_ размер матрицы
*/
void zerosAboveDiagonal(double** matrix_, int n_);

/**
 * @brief функция по транспонированию матрицы
 * @param matrix_ матрицыа, которую транспонируем
 * @param rows_ количество строк в матрице, которую транспонируем
 * @param cols_ количество стобцов в матрице, которую транспонируем
 * @return транспонированная матрица
*/
double** transposeMatrix(double** matrix_, int rows_, int cols_);

/**
 * @brief функция, которя делит каждый элемент матрицы на число
 * @param matrix_ матрица элементы которой делим
 * @param rows_ количество строк в матрице
 * @param cols_ количество стобцов в матрице
 * @param div_ коэффициент деления
*/
void divideMatrix(double** matrix_, int rows_, int cols_, double div_);

/**
 * @brief функция которая находит минор к месту n_ m_
 * @param matrix_ матрица, в которой находим минор
 * @param rows_ количество строк в матрице
 * @param cols_ количество столбцов в матрице
 * @param n_ номер строки, к которой берём минор
 * @param m_ номер столбца, к которой берём минор
 * @return минор к месту n_ m_
*/
double** findMinor(double** matrix_, int rows_, int cols_, int n_, int m_);

/**
 * @brief функция по нахождению алгебраических дополнений
 * @param matrix_ матрица, в которой вычисляем алгеьраические дополнения
 * @param rows_ количество строк в матрице
 * @param cols_ количество столбцов в матрице
 * @return массив из алгебраичесикх дополнений
*/
double** findAlgComplement(double** matrix_, int rows_, int cols_);

/**
 * @brief функция по вычислению обратной матрицы
 * @param matrix_ матрица, к которой находим обратную
 * @param rows_ количество строк в матрице
 * @param cols_ количество столбцов в матрице
 * @return обратная матрица
*/
double** reverseMatrix(double** matrix_, int rows_, int cols_);

