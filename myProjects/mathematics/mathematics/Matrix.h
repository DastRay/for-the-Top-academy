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
 * @brief ����������� �� ��������� ��� ������ Matrix. ����������� � ������������ ������� ������� � � ��������.
 * @tparam T ��� ��������� �������.
 */
template<typename T>
inline Matrix<T>::Matrix()
   : rows(0), cols(0)
{
   cout << "������� ������ ������� ����� ������: ";
   cin >> rows >> cols;
   cout << "������� �������� ������� ��������� ����� ������:" << endl;
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
 * @brief ����������� ������ Matrix, ������� �������������� ������� �������.
 * @tparam T ��� ��������� �������.
 * @param data �������� ������ ��� ���������� �������.
 */
template<typename T>
inline Matrix<T>::Matrix(const vector<vector<T>>& data)
   : rows(data.size()), cols(data.empty() ? 0 : data[0].size()), matrix(data)
{
   for (size_t i = 1; i < data.size(); i++)
   {
      if (data[i].size() != cols)
      {
         cerr << "[!] ������� ����������� ������� ������ ���� ���������� �����" << endl;
         matrix.clear();
         rows = 0;
         cols = 0;
         break;
      }
   }
}

/**
 * @brief �������� ���������� ����� � �������.
 * @tparam T ��� ��������� �������.
 * @return ���������� ����� � �������.
 */
template<typename T>
inline size_t Matrix<T>::numRows() const
{
   return rows;
}

/**
 * @brief �������� ���������� �������� � �������.
 * @tparam T ��� ��������� �������.
 * @return ���������� �������� � �������.
 */
template<typename T>
inline size_t Matrix<T>::numCols() const
{
   return cols;
}

/**
 * @brief ������ � �������� ������� ��� �����������.
 * @tparam T ��� ��������� �������.
 * @param row ������ ������ ��������.
 * @param col ������ ������� ��������.
 * @return ������ �� ������� � ��������� �������.
 */
template<typename T>
inline T& Matrix<T>::operator()(const size_t row, const size_t col)
{
   if (row >= rows || col >= cols)
   {
      cout << "[!] ��������� ������� ������� �� ������� ����������� ���������" << endl;
      exit(EXIT_FAILURE);
   }

   return matrix[row][col];
}

/**
 * @brief ������ � �������� ������� ��� ������.
 * @tparam T ��� ��������� �������.
 * @param row ������ ������ ��������.
 * @param col ������ ������� ��������.
 * @return ����������� ������ �� ������� � ��������� �������.
 */
template<typename T>
inline const T& Matrix<T>::operator()(const size_t row, const size_t col) const
{
   if (row >= rows || col >= cols)
   {
      cout << "[!] ��������� ������� ������� �� ������� ����������� ���������" << endl;
      exit(EXIT_FAILURE);
   }

   return matrix[row][col];
}

/**
 * @brief �������� ������������ ��� ������.
 * @tparam T ��� ��������� �������.
 * @param other ������ ������ ������� ��� ������������.
 * @return ������ �� ������� ������ ������� ����� ������������.
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
 * @brief �������� �������� ��������� ������.
 * @tparam T ��� ��������� �������.
 * @param other ������ ������ ������� ��� ���������.
 * @return true, ���� ��� �������� ������� �����, ����� false.
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
 * @brief �������� �������� ����������� ������.
 * @tparam T ��� ��������� �������.
 * @param other ������ ������ ������� ��� ���������.
 * @return true, ���� ��� �������� ������� �� �����, ����� false.
 */
template<typename T>
inline bool Matrix<T>::operator!=(const Matrix<T>& other) const
{
   return !(*this == other);
}

/**
 * @brief �������� ��������� (������) ��� ������.
 * @tparam T ��� ��������� �������.
 * @param other ������ ������ ������� ��� ���������.
 * @return true, ���� ������� ������� ������ ������, ����� false.
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
 * @brief �������� ��������� (������) ��� ������.
 * @tparam T ��� ��������� �������.
 * @param other ������ ������ ������� ��� ���������.
 * @return true, ���� ������� ������� ������ ������, ����� false.
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
 * @brief �������� ��������� (������ ��� �����) ��� ������.
 * @tparam T ��� ��������� �������.
 * @param other ������ ������ ������� ��� ���������.
 * @return true, ���� ������� ������� ������ ��� ����� ������, ����� false.
 */
template<typename T>
inline bool Matrix<T>::operator>=(const Matrix<T>& other) const
{
   return (*this > other) || (*this == other);
}

/**
 * @brief �������� ��������� (������ ��� �����) ��� ������.
 * @tparam T ��� ��������� �������.
 * @param other ������ ������ ������� ��� ���������.
 * @return true, ���� ������� ������� ������ ��� ����� ������, ����� false.
 */
template<typename T>
inline bool Matrix<T>::operator<=(const Matrix<T>& other) const
{
   return (*this < other) || (*this == other);
}

/**
 * @brief �������� ������� ������� �� ������.
 * @tparam T ��� ��������� �������.
 * @param scalar ��������� ��������, �� ������� ������� ������ ������� �������.
 * @return �������������� ������� ����� ������� �� ������.
 */
template<typename T>
inline Matrix<T> Matrix<T>::operator/(const T& scalar) const
{
   if (scalar == 0)
   {
      cerr << "[!] ������� �� ����" << endl;
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
 * @brief �������� ��� �������� ������.
 * @tparam T ��� ��������� �������.
 * @param other �������, ������� ����� ������� � �������.
 * @return ����� �������, ���������� ����������� �������� ������� ������� � 'other'.
 */
template<typename T>
inline Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const
{
   if (rows != other.rows || cols != other.cols)
   {
      cout << "[!] ������� ������ �� ��������� ��� ��������" << endl;
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
 * @brief �������� ��� ��������� ������.
 * @tparam T ��� ��������� �������.
 * @param other �������, ������� ����� ������� �� �������.
 * @return ����� �������, ���������� ����������� ��������� 'other' �� ������� �������.
 */
template<typename T>
inline Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const
{
   if (rows != other.rows || cols != other.cols)
   {
      cout << "[!] ������� ������ �� ��������� ��� ���������" << endl;
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
 * @brief �������� ��� ��������� ������.
 * @tparam T ��� ��������� �������.
 * @param other �������, �� ������� ����� �������� ������� �������.
 * @return ����� �������, ���������� ����������� ��������� ������� ������� �� 'other'.
 */
template<typename T>
inline Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const
{
   if (cols != other.rows)
   {
      cerr << "[!] ������������ ������� ������ ��� ���������" << endl;
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
 * @brief �������� ��������� ������� �� ������.
 * @tparam T ��� ��������� �������.
 * @param scalar ��������� ��������, �� ������� ���������� ������ ������� �������.
 * @return �������������� ������� ����� ��������� �� ������.
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
 * @brief �������� ������� ������� �� ������.
 * @tparam T ��� ��������� �������.
 * @param scalar ��������� ��������, �� ������� ������� ������ ������� �������.
 * @return �������������� ������� ����� ������� �� ������.
 */
template<typename T>
inline Matrix<T>& Matrix<T>::operator/=(const T& scalar)
{
   if (scalar == 0)
   {
      cerr << "[!] ������� �� ����" << endl;
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
 * @brief �������� �������� ������� � ������ ��������.
 * @tparam T ��� ��������� �������.
 * @param other ������ �������, ������� ����� �������� � �������.
 * @return ������ �� ������� ������ ������� ����� �������� ��������.
 */
template<typename T>
inline Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& other)
{
   if (rows != other.rows || cols != other.cols)
   {
      cout << "[!] ������� ������ �� ���������" << endl;
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
 * @brief �������� ��������� ������� �� ������ �������.
 * @tparam T ��� ��������� �������.
 * @param other ������ �������, ������� ����� ������� �� �������.
 * @return ������ �� ������� ������ ������� ����� �������� ���������.
 */
template<typename T>
inline Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& other)
{
   if (rows != other.rows || cols != other.cols)
   {
      cout << "[!] ������� ������ �� ���������" << endl;
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
 * @brief �������� ��������� ������� �� ������ �������.
 * @tparam T ��� ��������� �������.
 * @param other ������ �������, �� ������� ����� �������� �������.
 * @return ������ �� ������� ������ ������� ����� �������� ���������.
 */
template<typename T>
inline Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& other)
{
   *this = *this * other;
   return *this;
}

/**
 * @brief �������� ��������� ������� �� ������.
 * @tparam T ��� ��������� �������.
 * @param scalar ��������� ��������, �� ������� ����� �������� ������ ������� �������.
 * @return ������ �� ������� ������ ������� ����� �������� ��������� �� ������.
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
 * @brief ��������, �������� �� ������� ������� ��������� (������� ������ �� ������� ���������).
 * @tparam T ��� ��������� �������.
 * @return true, ���� ������� ���������, ����� false.
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
 * @brief �������� ������ ��� �������.
 * @tparam T ��� ��������� �������.
 * @param out ����� ������, � ������� ����� �������� �������.
 * @param other �������, ������� ����� �������.
 * @return ����� ������, ���������� �������.
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
 * @brief �������� ����� ��� �������.
 * @tparam T ��� ��������� �������.
 * @param in ����� �����, �� �������� ����� ������� �������� �������.
 * @param other �������, � ������� ����� �������� ��������� ��������.
 * @return ����� �����, ���������� �������� �������.
 */
template<typename T>
istream& operator>>(istream& in, Matrix<T>& other)
{
   cout << "������� �������� ������� ��������� ����� ������:" << endl;
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
 * @brief ������ ������� ��� ������ �������.
 * @tparam T ��� ��������� �������.
 * @param row1 ������ ������ ������.
 * @param row2 ������ ������ ������.
 */
template<typename T>
inline void Matrix<T>::swapRows(const size_t row1, const size_t row2)
{
   if (row1 >= rows || row2 >= rows)
   {
      cerr << "[!] ������� ����� ������� �� ������� ����������� ���������" << endl;
      return;
   }

   swap(matrix[row1], matrix[row2]);
}


/**
 * @brief ������ ������� ��� ������� �������.
 * @tparam T ��� ��������� �������.
 * @param col1 ������ ������� �������.
 * @param col2 ������ ������� �������.
 */
template<typename T>
inline void Matrix<T>::swapCols(const size_t col1, const size_t col2)
{
   if (col1 >= cols || col2 >= cols)
   {
      cerr << "[!] ������� �������� ������� �� ������� ����������� ���������" << endl;
      return;
   }

   for (size_t i = 0; i < rows; i++)
   {
      swap(matrix[i][col1], matrix[i][col2]);
   }
}

/**
 * @brief �������� ���� ������ ������� ���������� �� ������ �� ������ ������.
 * @tparam T ��� ��������� �������.
 * @param targetRow ������ ������, �� ������� ����������.
 * @param sourceRow ������ ������, ������� ����������.
 * @param scalar ������, �� ������� ���������� ������, ������� ����������.
 */
template<typename T>
inline void Matrix<T>::subtractRow(const size_t targetRow, const size_t sourceRow, const T scalar)
{
   if (targetRow >= rows || sourceRow >= rows)
   {
      cerr << "[!] ������� ����� ������� �� ������� ����������� ���������" << endl;
      return;
   }

   for (size_t j = 0; j < cols; j++)
   {
      matrix[targetRow][j] -= matrix[sourceRow][j] * scalar;
   }
}

/**
 * @brief ���������� ���� ������ �������, ���������� �� ������, � ������ ������.
 * @tparam T ��� ��������� �������.
 * @param targetRow ������ ������, � ������� ������������.
 * @param sourceRow ������ ������, ������� ������������.
 * @param scalar ������, �� ������� ���������� ������, ������� ������������.
 */
template<typename T>
inline void Matrix<T>::addRow(const size_t targetRow, const size_t sourceRow, const T scalar)
{
   if (targetRow >= rows || sourceRow >= rows)
   {
      cerr << "[!] ������� ����� ������� �� ������� ����������� ���������" << endl;
      return;
   }

   for (size_t j = 0; j < cols; j++)
   {
      matrix[targetRow][j] += matrix[sourceRow][j] * scalar;
   }
}

/**
 * @brief �������� ���� ������� �������, ���������� �� ������, �� ������� �������.
 * @tparam T ��� ��������� �������.
 * @param targetCol ������ �������, �� �������� ����������.
 * @param sourceCol ������ �������, ������� ����������.
 * @param scalar ������, �� ������� ���������� �������, ������� ����������.
 */
template<typename T>
inline void Matrix<T>::subtractCol(const size_t targetCol, const size_t sourceCol, const T scalar)
{
   if (targetCol >= cols || sourceCol >= cols)
   {
      cerr << "[!] ������� �������� ������� �� ������� ����������� ���������" << endl;
      return;
   }

   for (size_t i = 0; i < rows; i++)
   {
      matrix[i][targetCol] -= matrix[i][sourceCol] * scalar;
   }
}

/**
 * @brief ���������� ���� ������� �������, ���������� �� ������, � ������� �������.
 * @tparam T ��� ��������� �������.
 * @param targetCol ������ �������, � �������� ������������.
 * @param sourceCol ������ �������, ������� ������������.
 * @param scalar ������, �� ������� ���������� �������, ������� ������������.
 */
template<typename T>
inline void Matrix<T>::addCol(const size_t targetCol, const size_t sourceCol, const T scalar)
{
   if (targetCol >= cols || sourceCol >= cols)
   {
      cerr << "[!] ������� �������� ������� �� ������� ����������� ���������" << endl;
      return;
   }

   for (size_t i = 0; i < rows; i++)
   {
      matrix[i][targetCol] += matrix[i][sourceCol] * scalar;
   }
}

/**
 * @brief ���������� ����� �������, ������ ��������� ������ � �������.
 * @tparam T ��� ��������� �������.
 * @param data �������, ��� ������� ����������� �����.
 * @param row ������ ������, ������� ����� ������� �� �������.
 * @param col ������ �������, ������� ����� ������ �� �������.
 * @return ����� ������� ��� ��������� ������ � �������.
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
 * @brief ���������� ����� ������� �������, ������ ��������� ������ � �������.
 * @tparam T ��� ��������� �������.
 * @param row ������ ������, ������� ����� ������� �� �������.
 * @param col ������ �������, ������� ����� ������ �� �������.
 * @return ����� ������� ������� ��� ��������� ������ � �������.
 */
template<typename T>
inline Matrix<T> Matrix<T>::getMinor(const size_t row, const size_t col) const
{
   return Matrix<T>(getMinor(matrix, row, col));
}

/**
 * @brief ��������� ������������ ���������� ������� ������� ���������� �� ������.
 * @tparam T ��� ��������� �������.
 * @param data ���������� �������, ��� ������� ����������� ������������.
 * @return ������������ �������.
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
 * @brief ��������� ������������ ������� ���������� �������.
 * @tparam T ��� ��������� �������.
 * @return ������������ �������.
 */
template<typename T>
inline T Matrix<T>::determinant() const
{
   if (rows != cols)
   {
      cerr << "[!] ������� ������ ���� ���������� ��� ���������� ������������. ��������� 0." << endl;
      return 0;
   }

   return determinant(matrix);
}

/**
 * @brief ���������� ����������������� �������.
 * @tparam T ��� ��������� �������.
 * @return ����������������� �������.
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
 * @brief ��������� �������������� ���������� ������� ���������� �������.
 * @tparam T ��� ��������� �������.
 * @return ������� �������������� ����������.
 */
template<typename T>
inline Matrix<T> Matrix<T>::adjugate() const
{
   if (rows != cols)
   {
      cerr << "[!] ������� ������ ���� ���������� ��� ���������� ��������������� ����������" << endl;
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
 * @brief ��������� �������� ������� ������� �������.
 * @tparam T ��� ��������� �������.
 * @return �������� �������.
 */
template<typename T>
inline Matrix<T> Matrix<T>::inverse() const
{
   const T det = determinant();
   if (det == 0)
   {
      cerr << "[!] ��� ������ ������� �� ���������� ��������" << endl;
      return Matrix<T>();
   }

   Matrix<T> adj = adjugate();

   return adj.transpose() / det;
}

/**
 * @brief �������� ��������� ������� ������� ������� �������� �� ������ �������.
 * @tparam T ��� ��������� �������.
 * @param targetCol ������ ������� ������� �������, ������� ����� �������.
 * @param sourceMatrix ������ �������, �� ������� ������� ������� ��� ������.
 * @param sourceCol ������ ������� � ������ �������, ������� ����� ����������� ��� ������.
 */
template<typename T>
void Matrix<T>::replaceColumn(const size_t targetCol, const Matrix<T>& sourceMatrix, const size_t sourceCol)
{
   if (rows != sourceMatrix.rows)
   {
      cerr << "[!] ���������� �������� �������, ��� ��� ���������� ����� � �������� �� ���������" << endl;
      return;
   }

   if (targetCol >= cols || sourceCol >= sourceMatrix.cols)
   {
      cerr << "[!] ���� �� ��������� �������� ��������� �� ��������� �������� ����� �������" << endl;
      return;
   }

   for (size_t i = 0; i < rows; i++)
   {
      matrix[i][targetCol] = sourceMatrix(i, sourceCol);
   }
}

/**
 * @brief �������� ��������� ������� ������� ������� �������� �� ������� ��������.
 * @tparam T ��� ��������� �������.
 * @param targetCol ������ ������� ������� �������, ������� ����� �������.
 * @param source ������ ��������, ������� ����� ����������� ��� ������ �������.
 */
template<typename T>
inline void Matrix<T>::replaceColumn(const size_t targetCol, const vector<T>& source)
{
   if (targetCol >= cols)
   {
      cerr << "[!] ������ ������� ������� �� ������� ����������� ���������" << endl;
      return;
   }

   if (rows != source.size())
   {
      cerr << "[!] ���������� �������� �������, ��� ��� ���������� ����� � �������� �� ���������" << endl;
      return;
   }

   for (size_t i = 0; i < rows; i++)
   {
      matrix[i][targetCol] = source[i];
   }
}