#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

template<typename T>
class Matrix
{
private:
   size_t rows;
   size_t cols;
   vector<vector<T>> matrix;

   T determinant(const vector<vector<T>>& data) const;
   vector<vector<T>> getMinor(const vector<vector<T>>& data, const size_t row, const size_t col) const;

public:
   Matrix();
   Matrix(const size_t& rows, const size_t& cols, const T& data = 0)
      : rows(rows), cols(cols), matrix(rows, vector<T>(cols, data)) {}

   Matrix(const Matrix<T>& other)
      : rows(other.rows), cols(other.cols), matrix(other.matrix) {}
   Matrix(const vector<vector<T>>& data);

   size_t numRows() const;
   size_t numCols() const;

   T& operator()(const size_t row, const size_t col);
   const T& operator()(const size_t row, const size_t col) const;

   Matrix<T>& operator=(const Matrix<T>& other);
   bool operator==(const Matrix<T>& other) const;
   bool operator!=(const Matrix<T>& other) const;
   bool operator>(const Matrix<T>& other) const;
   bool operator<(const Matrix<T>& other) const;
   bool operator>=(const Matrix<T>& other) const;
   bool operator<=(const Matrix<T>& other) const;

   Matrix<T> operator/(const T& scalar) const;
   Matrix<T> operator+(const Matrix<T>& other) const;
   Matrix<T> operator-(const Matrix<T>& other) const;
   Matrix<T> operator*(const Matrix<T>& other) const;
   Matrix<T> operator*(const T& scalar) const;

   Matrix<T>& operator/=(const T& scalar);
   Matrix<T>& operator+=(const Matrix<T>& other);
   Matrix<T>& operator-=(const Matrix<T>& other);
   Matrix<T>& operator*=(const Matrix<T>& other);
   Matrix<T>& operator*=(const T& scalar);

   bool isIdentityMatrix() const;

   template<typename U>
   friend ostream& operator<<(ostream& out, const Matrix<U>& other);
   template<typename U>
   friend istream& operator>>(istream& in, Matrix<U>& other);

   void swapRows(const size_t row1, const size_t row2);
   void swapCols(const size_t col1, const size_t col2);
   void subtractRow(const size_t targetRow, const size_t sourceRow, const T scalar = 1);
   void addRow(const size_t targetRow, const size_t sourceRow, const T scalar = 1);
   void subtractCol(const size_t targetCol, const size_t sourceCol, const T scalar = 1);
   void addCol(const size_t targetCol, const size_t sourceCol, const T scalar = 1);
   void replaceColumn(const size_t targetCol, const Matrix<T>& sourceMatrix, const size_t sourceCol);
   void replaceColumn(const size_t targetCol, const vector<T>& source);

   T determinant() const;
   Matrix<T> transpose() const;
   Matrix<T> getMinor(const size_t row, const size_t col) const;
   Matrix<T> adjugate() const;
   Matrix<T> inverse() const;
};

/**
 * @brief Конструктор по умолчанию для класса Matrix. Запрашивает у пользователя размеры матрицы и её элементы.
 * @tparam T Тип элементов матрицы.
 */
template<typename T>
inline Matrix<T>::Matrix()
   : rows(0), cols(0)
{
   cout << "Введите размер матрицы через пробел: ";
   cin >> rows >> cols;
   cout << "Введите элементы матрицы построчно через пробел:" << endl;
   matrix.resize(rows, vector<T>(cols));

   for (size_t i = 0; i < rows; i++)
   {
      for (size_t j = 0; j < cols; j++)
      {
         cin >> matrix[i][j];
      }
   }

   cout << endl;
}

/**
 * @brief Конструктор класса Matrix, который инициализирует матрицу данными.
 * @tparam T Тип элементов матрицы.
 * @param data Исходные данные для заполнения матрицы.
 */
template<typename T>
inline Matrix<T>::Matrix(const vector<vector<T>>& data)
   : rows(data.size()), cols(data.empty() ? 0 : data[0].size()), matrix(data)
{
   for (size_t i = 1; i < data.size(); i++)
   {
      if (data[i].size() != cols)
      {
         cerr << "[!] Векторы внутреннего вектора должны быть одинаковой длины" << endl;
         matrix.clear();
         rows = 0;
         cols = 0;
         break;
      }
   }
}

/**
 * @brief Получить количество строк в матрице.
 * @tparam T Тип элементов матрицы.
 * @return Количество строк в матрице.
 */
template<typename T>
inline size_t Matrix<T>::numRows() const
{
   return rows;
}

/**
 * @brief Получить количество столбцов в матрице.
 * @tparam T Тип элементов матрицы.
 * @return Количество столбцов в матрице.
 */
template<typename T>
inline size_t Matrix<T>::numCols() const
{
   return cols;
}

/**
 * @brief Доступ к элементу матрицы для модификации.
 * @tparam T Тип элементов матрицы.
 * @param row Индекс строки элемента.
 * @param col Индекс столбца элемента.
 * @return Ссылка на элемент в указанной позиции.
 */
template<typename T>
inline T& Matrix<T>::operator()(const size_t row, const size_t col)
{
   if (row >= rows || col >= cols)
   {
      cout << "[!] Матричные индексы выходят за пределы допустимого диапазона" << endl;
      exit(EXIT_FAILURE);
   }

   return matrix[row][col];
}

/**
 * @brief Доступ к элементу матрицы для чтения.
 * @tparam T Тип элементов матрицы.
 * @param row Индекс строки элемента.
 * @param col Индекс столбца элемента.
 * @return Константная ссылка на элемент в указанной позиции.
 */
template<typename T>
inline const T& Matrix<T>::operator()(const size_t row, const size_t col) const
{
   if (row >= rows || col >= cols)
   {
      cout << "[!] Матричные индексы выходят за пределы допустимого диапазона" << endl;
      exit(EXIT_FAILURE);
   }

   return matrix[row][col];
}

/**
 * @brief Оператор присваивания для матриц.
 * @tparam T Тип элементов матрицы.
 * @param other Другой объект матрицы для присваивания.
 * @return Ссылка на текущий объект матрицы после присваивания.
 */
template<typename T>
inline Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other)
{
   if (this == &other)
   {
      return *this;
   }

   rows = other.rows;
   cols = other.cols;
   matrix = other.matrix;

   return *this;
}

/**
 * @brief Оператор проверки равенства матриц.
 * @tparam T Тип элементов матрицы.
 * @param other Другой объект матрицы для сравнения.
 * @return true, если все элементы матрицы равны, иначе false.
 */
template<typename T>
inline bool Matrix<T>::operator==(const Matrix<T>& other) const
{
   if (rows != other.rows || cols != other.cols)
   {
      return false;
   }

   for (size_t i = 0; i < rows; i++)
   {
      for (size_t j = 0; j < cols; j++)
      {
         if (matrix[i][j] != other.matrix[i][j])
         {
            return false;
         }
      }
   }

   return true;
}

/**
 * @brief Оператор проверки неравенства матриц.
 * @tparam T Тип элементов матрицы.
 * @param other Другой объект матрицы для сравнения.
 * @return true, если все элементы матрицы не равны, иначе false.
 */
template<typename T>
inline bool Matrix<T>::operator!=(const Matrix<T>& other) const
{
   return !(*this == other);
}

/**
 * @brief Оператор сравнения (больше) для матриц.
 * @tparam T Тип элементов матрицы.
 * @param other Другой объект матрицы для сравнения.
 * @return true, если текущая матрица больше другой, иначе false.
 */
template<typename T>
inline bool Matrix<T>::operator>(const Matrix<T>& other) const
{
   if (rows > other.rows || (rows == other.rows && cols > other.cols))
   {
      return true;
   }
   else if (rows == other.rows && cols == other.cols)
   {
      for (size_t i = 0; i < rows; i++)
      {
         for (size_t j = 0; j < cols; j++)
         {
            if (matrix[i][j] <= other.matrix[i][j])
            {
               return false;
            }
         }
      }

      return true;
   }

   return false;
}

/**
 * @brief Оператор сравнения (меньше) для матриц.
 * @tparam T Тип элементов матрицы.
 * @param other Другой объект матрицы для сравнения.
 * @return true, если текущая матрица меньше другой, иначе false.
 */
template<typename T>
inline bool Matrix<T>::operator<(const Matrix<T>& other) const
{
   if (rows < other.rows || (rows == other.rows && cols < other.cols))
   {
      return true;
   }
   else if (rows == other.rows && cols == other.cols)
   {
      for (size_t i = 0; i < rows; i++)
      {
         for (size_t j = 0; j < cols; j++)
         {
            if (matrix[i][j] >= other.matrix[i][j])
            {
               return false;
            }
         }
      }

      return true;
   }

   return false;
}

/**
 * @brief Оператор сравнения (больше или равно) для матриц.
 * @tparam T Тип элементов матрицы.
 * @param other Другой объект матрицы для сравнения.
 * @return true, если текущая матрица больше или равна другой, иначе false.
 */
template<typename T>
inline bool Matrix<T>::operator>=(const Matrix<T>& other) const
{
   return (*this > other) || (*this == other);
}

/**
 * @brief Оператор сравнения (меньше или равно) для матриц.
 * @tparam T Тип элементов матрицы.
 * @param other Другой объект матрицы для сравнения.
 * @return true, если текущая матрица меньше или равна другой, иначе false.
 */
template<typename T>
inline bool Matrix<T>::operator<=(const Matrix<T>& other) const
{
   return (*this < other) || (*this == other);
}

/**
 * @brief Оператор деления матрицы на скаляр.
 * @tparam T Тип элементов матрицы.
 * @param scalar Скалярное значение, на которое делится каждый элемент матрицы.
 * @return Результирующая матрица после деления на скаляр.
 */
template<typename T>
inline Matrix<T> Matrix<T>::operator/(const T& scalar) const
{
   if (scalar == 0)
   {
      cerr << "[!] Деление на ноль" << endl;
      return Matrix<T>();
   }

   Matrix<T> result(rows, cols);
   for (size_t i = 0; i < rows; i++)
   {
      for (size_t j = 0; j < cols; j++)
      {
         result.matrix[i][j] = matrix[i][j] / scalar;
      }
   }

   return result;
}

/**
 * @brief Оператор для сложения матриц.
 * @tparam T Тип элементов матрицы.
 * @param other Матрица, которую нужно сложить с текущей.
 * @return Новая матрица, являющаяся результатом сложения текущей матрицы и 'other'.
 */
template<typename T>
inline Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const
{
   if (rows != other.rows || cols != other.cols)
   {
      cout << "[!] Размеры матриц не совпадают для сложения" << endl;
      return Matrix<T>();
   }

   Matrix<T> result(rows, cols);
   for (size_t i = 0; i < rows; i++)
   {
      for (size_t j = 0; j < cols; j++)
      {
         result(i, j) = matrix[i][j] + other(i, j);
      }
   }

   return result;
}

/**
 * @brief Оператор для вычитания матриц.
 * @tparam T Тип элементов матрицы.
 * @param other Матрица, которую нужно вычесть из текущей.
 * @return Новая матрица, являющаяся результатом вычитания 'other' из текущей матрицы.
 */
template<typename T>
inline Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const
{
   if (rows != other.rows || cols != other.cols)
   {
      cout << "[!] Размеры матриц не совпадают для вычитания" << endl;
      return Matrix<T>();
   }

   Matrix<T> result(rows, cols);
   for (size_t i = 0; i < rows; i++)
   {
      for (size_t j = 0; j < cols; j++)
      {
         result(i, j) = matrix[i][j] - other(i, j);
      }
   }

   return result;
}

/**
 * @brief Оператор для умножения матриц.
 * @tparam T Тип элементов матрицы.
 * @param other Матрица, на которую нужно умножить текущую матрицу.
 * @return Новая матрица, являющаяся результатом умножения текущей матрицы на 'other'.
 */
template<typename T>
inline Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const
{
   if (cols != other.rows)
   {
      cerr << "[!] Некорректные размеры матриц для умножения" << endl;
      return vector<vector<T>>();
   }

   Matrix<T> result(rows, other.cols, T());
   for (size_t i = 0; i < rows; i++)
   {
      for (size_t j = 0; j < other.cols; j++)
      {
         for (size_t k = 0; k < cols; k++)
         {
            result(i, j) += matrix[i][k] * other(k, j);
         }
      }
   }

   return result;
}


/**
 * @brief Оператор умножения матрицы на скаляр.
 * @tparam T Тип элементов матрицы.
 * @param scalar Скалярное значение, на которое умножается каждый элемент матрицы.
 * @return Результирующая матрица после умножения на скаляр.
 */
template<typename T>
inline Matrix<T> Matrix<T>::operator*(const T& scalar) const
{
   Matrix<T> result(rows, cols);
   for (size_t i = 0; i < rows; i++)
   {
      for (size_t j = 0; j < cols; j++)
      {
         result.matrix[i][j] = matrix[i][j] * scalar;
      }
   }

   return result;
}

/**
 * @brief Оператор деления матрицы на скаляр.
 * @tparam T Тип элементов матрицы.
 * @param scalar Скалярное значение, на которое делится каждый элемент матрицы.
 * @return Результирующая матрица после деления на скаляр.
 */
template<typename T>
inline Matrix<T>& Matrix<T>::operator/=(const T& scalar)
{
   if (scalar == 0)
   {
      cerr << "[!] Деление на ноль" << endl;
      return *this;
   }

   for (size_t i = 0; i < rows; i++)
   {
      for (size_t j = 0; j < cols; j++)
      {
         matrix[i][j] /= scalar;
      }
   }

   return *this;
}

/**
 * @brief Оператор сложения матрицы с другой матрицей.
 * @tparam T Тип элементов матрицы.
 * @param other Другая матрица, которую нужно добавить к текущей.
 * @return Ссылка на текущий объект матрицы после операции сложения.
 */
template<typename T>
inline Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& other)
{
   if (rows != other.rows || cols != other.cols)
   {
      cout << "[!] Размеры матриц не совпадают" << endl;
      return *this;
   }

   for (size_t i = 0; i < rows; i++)
   {
      for (size_t j = 0; j < cols; j++)
      {
         matrix[i][j] += other(i, j);
      }
   }

   return *this;
}

/**
 * @brief Оператор вычитания матрицы из другой матрицы.
 * @tparam T Тип элементов матрицы.
 * @param other Другая матрица, которую нужно вычесть из текущей.
 * @return Ссылка на текущий объект матрицы после операции вычитания.
 */
template<typename T>
inline Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& other)
{
   if (rows != other.rows || cols != other.cols)
   {
      cout << "[!] Размеры матриц не совпадают" << endl;
      return *this;
   }

   for (size_t i = 0; i < rows; i++)
   {
      for (size_t j = 0; j < cols; j++)
      {
         matrix[i][j] -= other(i, j);
      }
   }

   return *this;
}

/**
 * @brief Оператор умножения матрицы на другую матрицу.
 * @tparam T Тип элементов матрицы.
 * @param other Другая матрица, на которую нужно умножить текущую.
 * @return Ссылка на текущий объект матрицы после операции умножения.
 */
template<typename T>
inline Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& other)
{
   *this = *this * other;
   return *this;
}

/**
 * @brief Оператор умножения матрицы на скаляр.
 * @tparam T Тип элементов матрицы.
 * @param scalar Скалярное значение, на которое нужно умножить каждый элемент матрицы.
 * @return Ссылка на текущий объект матрицы после операции умножения на скаляр.
 */
template<typename T>
inline Matrix<T>& Matrix<T>::operator*=(const T& scalar)
{
   for (size_t i = 0; i < rows; i++)
   {
      for (size_t j = 0; j < cols; j++)
      {
         matrix[i][j] *= scalar;
      }
   }

   return *this;
}

/**
 * @brief Проверка, является ли текущая матрица единичной (единицы только на главной диагонали).
 * @tparam T Тип элементов матрицы.
 * @return true, если матрица единичная, иначе false.
 */
template<typename T>
inline bool Matrix<T>::isIdentityMatrix() const
{
   if (rows != cols)
   {
      return false;
   }

   for (size_t i = 0; i < rows; i++)
   {
      for (size_t j = 0; j < cols; j++)
      {
         if (i == j && matrix[i][j] != T(1))
         {
            return false;
         }
         else if (i != j && matrix[i][j] != T())
         {
            return false;
         }
      }
   }

   return true;
}

/**
 * @brief Оператор вывода для матрицы.
 * @tparam T Тип элементов матрицы.
 * @param out Поток вывода, в который будет записана матрица.
 * @param other Матрица, которую нужно вывести.
 * @return Поток вывода, содержащий матрицу.
 */
template<typename T>
ostream& operator<<(ostream& out, const Matrix<T>& other)
{
   out << fixed << setprecision(3);
   for (size_t i = 0; i < other.rows; i++)
   {
      for (size_t j = 0; j < other.cols; j++)
      {
         out << setw(8) << other(i, j) << " ";
      }
      out << endl;
   }

   return out;
}

/**
 * @brief Оператор ввода для матрицы.
 * @tparam T Тип элементов матрицы.
 * @param in Поток ввода, из которого будут считаны элементы матрицы.
 * @param other Матрица, в которую будут записаны считанные элементы.
 * @return Поток ввода, содержащий элементы матрицы.
 */
template<typename T>
istream& operator>>(istream& in, Matrix<T>& other)
{
   cout << "Введите элементы матрицы построчно через пробел:" << endl;
   for (size_t i = 0; i < other.rows; i++)
   {
      for (size_t j = 0; j < other.cols; j++)
      {
         in >> other.matrix[i][j];
      }
   }

   return in;
}

/**
 * @brief Меняет местами две строки матрицы.
 * @tparam T Тип элементов матрицы.
 * @param row1 Индекс первой строки.
 * @param row2 Индекс второй строки.
 */
template<typename T>
inline void Matrix<T>::swapRows(const size_t row1, const size_t row2)
{
   if (row1 >= rows || row2 >= rows)
   {
      cerr << "[!] Индексы строк выходят за пределы допустимого диапазона" << endl;
      return;
   }

   swap(matrix[row1], matrix[row2]);
}


/**
 * @brief Меняет местами два столбца матрицы.
 * @tparam T Тип элементов матрицы.
 * @param col1 Индекс первого столбца.
 * @param col2 Индекс второго столбца.
 */
template<typename T>
inline void Matrix<T>::swapCols(const size_t col1, const size_t col2)
{
   if (col1 >= cols || col2 >= cols)
   {
      cerr << "[!] Индексы столбцов выходят за пределы допустимого диапазона" << endl;
      return;
   }

   for (size_t i = 0; i < rows; i++)
   {
      swap(matrix[i][col1], matrix[i][col2]);
   }
}

/**
 * @brief Вычитает одну строку матрицы умноженную на скаляр из другой строки.
 * @tparam T Тип элементов матрицы.
 * @param targetRow Индекс строки, из которой вычитается.
 * @param sourceRow Индекс строки, которая вычитается.
 * @param scalar Скаляр, на который умножается строка, которая вычитается.
 */
template<typename T>
inline void Matrix<T>::subtractRow(const size_t targetRow, const size_t sourceRow, const T scalar)
{
   if (targetRow >= rows || sourceRow >= rows)
   {
      cerr << "[!] Индексы строк выходят за пределы допустимого диапазона" << endl;
      return;
   }

   for (size_t j = 0; j < cols; j++)
   {
      matrix[targetRow][j] -= matrix[sourceRow][j] * scalar;
   }
}

/**
 * @brief Прибавляет одну строку матрицы, умноженную на скаляр, к другой строке.
 * @tparam T Тип элементов матрицы.
 * @param targetRow Индекс строки, к которой прибавляется.
 * @param sourceRow Индекс строки, которая прибавляется.
 * @param scalar Скаляр, на который умножается строка, которая прибавляется.
 */
template<typename T>
inline void Matrix<T>::addRow(const size_t targetRow, const size_t sourceRow, const T scalar)
{
   if (targetRow >= rows || sourceRow >= rows)
   {
      cerr << "[!] Индексы строк выходят за пределы допустимого диапазона" << endl;
      return;
   }

   for (size_t j = 0; j < cols; j++)
   {
      matrix[targetRow][j] += matrix[sourceRow][j] * scalar;
   }
}

/**
 * @brief Вычитает один столбец матрицы, умноженный на скаляр, из другого столбца.
 * @tparam T Тип элементов матрицы.
 * @param targetCol Индекс столбца, из которого вычитается.
 * @param sourceCol Индекс столбца, который вычитается.
 * @param scalar Скаляр, на который умножается столбец, который вычитается.
 */
template<typename T>
inline void Matrix<T>::subtractCol(const size_t targetCol, const size_t sourceCol, const T scalar)
{
   if (targetCol >= cols || sourceCol >= cols)
   {
      cerr << "[!] Индексы столбцов выходят за пределы допустимого диапазона" << endl;
      return;
   }

   for (size_t i = 0; i < rows; i++)
   {
      matrix[i][targetCol] -= matrix[i][sourceCol] * scalar;
   }
}

/**
 * @brief Прибавляет один столбец матрицы, умноженный на скаляр, к другому столбцу.
 * @tparam T Тип элементов матрицы.
 * @param targetCol Индекс столбца, к которому прибавляется.
 * @param sourceCol Индекс столбца, который прибавляется.
 * @param scalar Скаляр, на который умножается столбец, который прибавляется.
 */
template<typename T>
inline void Matrix<T>::addCol(const size_t targetCol, const size_t sourceCol, const T scalar)
{
   if (targetCol >= cols || sourceCol >= cols)
   {
      cerr << "[!] Индексы столбцов выходят за пределы допустимого диапазона" << endl;
      return;
   }

   for (size_t i = 0; i < rows; i++)
   {
      matrix[i][targetCol] += matrix[i][sourceCol] * scalar;
   }
}

/**
 * @brief Возвращает минор матрицы, удаляя указанную строку и столбец.
 * @tparam T Тип элементов матрицы.
 * @param data Матрица, для которой вычисляется минор.
 * @param row Индекс строки, которая будет удалена из матрицы.
 * @param col Индекс столбца, который будет удален из матрицы.
 * @return Минор матрицы без указанной строки и столбца.
 */
template<typename T>
inline vector<vector<T>> Matrix<T>::getMinor(const vector<vector<T>>& data, const size_t row, const size_t col) const
{
   const size_t dataSize = data.size();
   vector<vector<T>> minor(dataSize - 1, vector<T>(dataSize - 1));

   size_t k = 0;
   size_t p = 0;

   for (size_t i = 0; i < dataSize; i++)
   {
      if (i == row)
      {
         continue;
      }

      p = 0;
      for (size_t j = 0; j < dataSize; j++)
      {
         if (j == col)
         {
            continue;
         }

         minor[k][p++] = data[i][j];
      }

      k++;
   }

   return minor;
}

/**
 * @brief Возвращает минор текущей матрицы, удаляя указанную строку и столбец.
 * @tparam T Тип элементов матрицы.
 * @param row Индекс строки, которая будет удалена из матрицы.
 * @param col Индекс столбца, который будет удален из матрицы.
 * @return Минор текущей матрицы без указанной строки и столбца.
 */
template<typename T>
inline Matrix<T> Matrix<T>::getMinor(const size_t row, const size_t col) const
{
   return Matrix<T>(getMinor(matrix, row, col));
}

/**
 * @brief Вычисляет определитель квадратной матрицы методом разложения по строке.
 * @tparam T Тип элементов матрицы.
 * @param data Квадратная матрица, для которой вычисляется определитель.
 * @return Определитель матрицы.
 */
template<typename T>
inline T Matrix<T>::determinant(const vector<vector<T>>& data) const
{
   const size_t dataSize = data.size();

   if (dataSize == 1)
   {
      return data[0][0];
   }
   if (dataSize == 2)
   {
      return data[0][0] * data[1][1] - data[0][1] * data[1][0];
   }

   T det = 0;
   for (size_t j = 0; j < dataSize; j++)
   {
      det += ((j % 2 == 0) ? 1 : -1) * data[0][j] * determinant(getMinor(data, 0, j));
   }

   return det;
}

/**
 * @brief Вычисляет определитель текущей квадратной матрицы.
 * @tparam T Тип элементов матрицы.
 * @return Определитель матрицы.
 */
template<typename T>
inline T Matrix<T>::determinant() const
{
   if (rows != cols)
   {
      cerr << "[!] Матрица должна быть квадратной для вычисления детерминанта. Возвращён 0." << endl;
      return 0;
   }

   return determinant(matrix);
}

/**
 * @brief Возвращает транспонированную матрицу.
 * @tparam T Тип элементов матрицы.
 * @return Транспонированная матрица.
 */
template<typename T>
inline Matrix<T> Matrix<T>::transpose() const
{
   Matrix<T> result(cols, rows);
   for (size_t i = 0; i < rows; i++)
   {
      for (size_t j = 0; j < cols; j++)
      {
         result(j, i) = matrix[i][j];
      }
   }

   return result;
}

/**
 * @brief Вычисляет алгебраическое дополнение текущей квадратной матрицы.
 * @tparam T Тип элементов матрицы.
 * @return Матрица алгебраических дополнений.
 */
template<typename T>
inline Matrix<T> Matrix<T>::adjugate() const
{
   if (rows != cols)
   {
      cerr << "[!] Матрица должна быть квадратной для вычисления алгебраического дополнения" << endl;
      return Matrix<T>();
   }

   Matrix<T> result(rows, cols);
   for (size_t i = 0; i < rows; i++)
   {
      for (size_t j = 0; j < cols; j++)
      {
         result(i, j) = (((i + j) % 2 == 0) ? 1 : -1) * determinant(getMinor(matrix, i, j));
      }
   }

   return result;
}

/**
 * @brief Вычисляет обратную матрицу текущей матрицы.
 * @tparam T Тип элементов матрицы.
 * @return Обратная матрица.
 */
template<typename T>
inline Matrix<T> Matrix<T>::inverse() const
{
   const T det = determinant();
   if (det == 0)
   {
      cerr << "[!] Для данной матрицы не существует обратной" << endl;
      return Matrix<T>();
   }

   Matrix<T> adj = adjugate();

   return adj.transpose() / det;
}

/**
 * @brief Заменяет указанный столбец текущей матрицы столбцом из другой матрицы.
 * @tparam T Тип элементов матрицы.
 * @param targetCol Индекс столбца текущей матрицы, который будет заменен.
 * @param sourceMatrix Другая матрица, из которой берется столбец для замены.
 * @param sourceCol Индекс столбца в другой матрице, который будет использован для замены.
 */
template<typename T>
void Matrix<T>::replaceColumn(const size_t targetCol, const Matrix<T>& sourceMatrix, const size_t sourceCol)
{
   if (rows != sourceMatrix.rows)
   {
      cerr << "[!] Невозможно заменить столбец, так как количество строк в матрицах не совпадает" << endl;
      return;
   }

   if (targetCol >= cols || sourceCol >= sourceMatrix.cols)
   {
      cerr << "[!] Один из указанных столбцов находится за пределами размеров своей матрицы" << endl;
      return;
   }

   for (size_t i = 0; i < rows; i++)
   {
      matrix[i][targetCol] = sourceMatrix(i, sourceCol);
   }
}

/**
 * @brief Заменяет указанный столбец текущей матрицы столбцом из вектора значений.
 * @tparam T Тип элементов матрицы.
 * @param targetCol Индекс столбца текущей матрицы, который будет заменен.
 * @param source Вектор значений, который будет использован для замены столбца.
 */
template<typename T>
inline void Matrix<T>::replaceColumn(const size_t targetCol, const vector<T>& source)
{
   if (targetCol >= cols)
   {
      cerr << "[!] Индекс столбца выходит за пределы допустимого диапазона" << endl;
      return;
   }

   if (rows != source.size())
   {
      cerr << "[!] Невозможно заменить столбец, так как количество строк в матрицах не совпадает" << endl;
      return;
   }

   for (size_t i = 0; i < rows; i++)
   {
      matrix[i][targetCol] = source[i];
   }
}