#pragma once
/**
 * @brief ���������� �������
 * @param matrix_ �������, ���� ���������
 * @param row_ ���������� ����� �������
 * @param cols_ ���������� �������� �������
*/
void readMatrix(double** matrix_, int rows_, int cols_);

/**
* @brief ����� �������
* @param matrix_ �������, ������� �������
 * @param row_ ���������� ����� �������
 * @param cols_ ���������� �������� �������
*/
void printMatrix(double** matrix_, int rows_, int cols_);

/**
* @brief ������� �� ���������� �������
* @param matrix_ �������, ������� ��������
* @param rows_ ���������� ����� � �������, ������� ��������
* @param cols_ ���������� �������� � �������, ������� ��������
* @return ������������� �������
*/
double** copyMatrix(double** matrix_, int rows_, int cols_);

/**
* @brief �������, ������� ����� ������� ��� ������ � �������
* @param matrix_ �������, � ������� ��������
* @param row1_ ������ ������
* @param row2_ ������ ������
* @param n_ ������ �������
*/
void swapRows(double** matrix_, int row1_, int row2_, int n_);

/**
* @brief �������, ������� �������� �� ����� ������ ������
* @param matrix_ �������, � ������� ��������
* @param row1_ ������ ������, ������� ��������
* @param row2_ ������ ������, �� ������� ��������
* @param n_ ������ �������
* @param s_ ����������� ���������
*/
void subtractRows(double** matrix_, int row1_, int row2_, int n_, double s_);

/**
* @brief �������, ������� ��������� ������������ �������
* @param matrix_ �������, ������������� ������� �������
* @param n_ ������ �������
* @return ������������ �������
*/
double determinant(double** matrix_, int n_);

/**
* @brief �������, ������� �������� ������� � ������������ ����
* @param matrix_ �������, � ������� ��������
* @param n_ ������ �������
*/
void zerosAboveDiagonal(double** matrix_, int n_);

/**
 * @brief ������� �� ���������������� �������
 * @param matrix_ ��������, ������� �������������
 * @param rows_ ���������� ����� � �������, ������� �������������
 * @param cols_ ���������� ������� � �������, ������� �������������
 * @return ����������������� �������
*/
double** transposeMatrix(double** matrix_, int rows_, int cols_);

/**
 * @brief �������, ������ ����� ������ ������� ������� �� �����
 * @param matrix_ ������� �������� ������� �����
 * @param rows_ ���������� ����� � �������
 * @param cols_ ���������� ������� � �������
 * @param div_ ����������� �������
*/
void divideMatrix(double** matrix_, int rows_, int cols_, double div_);

/**
 * @brief ������� ������� ������� ����� � ����� n_ m_
 * @param matrix_ �������, � ������� ������� �����
 * @param rows_ ���������� ����� � �������
 * @param cols_ ���������� �������� � �������
 * @param n_ ����� ������, � ������� ���� �����
 * @param m_ ����� �������, � ������� ���� �����
 * @return ����� � ����� n_ m_
*/
double** findMinor(double** matrix_, int rows_, int cols_, int n_, int m_);

/**
 * @brief ������� �� ���������� �������������� ����������
 * @param matrix_ �������, � ������� ��������� �������������� ����������
 * @param rows_ ���������� ����� � �������
 * @param cols_ ���������� �������� � �������
 * @return ������ �� �������������� ����������
*/
double** findAlgComplement(double** matrix_, int rows_, int cols_);

/**
 * @brief ������� �� ���������� �������� �������
 * @param matrix_ �������, � ������� ������� ��������
 * @param rows_ ���������� ����� � �������
 * @param cols_ ���������� �������� � �������
 * @return �������� �������
*/
double** reverseMatrix(double** matrix_, int rows_, int cols_);

