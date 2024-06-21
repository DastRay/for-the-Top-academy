#pragma once

/**
 * @brief ������� �� ���������� �������
 * @param A_ ������� �������������
 * @param B_ ������� ��������� ������
 * @param n_ ���������� �����������
*/
void readSLAYmatrix(double** A_, double* B_, int n_);

/**
 * @brief ����� ����������� �������
 * @param A_ ������� �������������
 * @param B_ ������� ��������� ������
 * @param n_ ���������� �����������
*/
void printSLAYmatrix(double** A_, double* B_, int n_);

/**
 * @brief ������� ������� �������� � ������� ���� ������� �� ������
 * @param matrix_ ������� � ������� �������� �������
 * @param rows_ ���������� ����� � �������
 * @param newCols_ ����� �������, ������� ��������
 * @param newColumn_ ����� �������
*/
void replaceColumn(double** arr_, int rows_, int newCols_, double* newColumn_);

/**
 * @brief ������� �� ���������� ������������
 * @param matrix_ ������� ������������ ������� �������
 * @param size_ ������ �������
 * @return ������������ �������
*/
double determinantSlay(double** matrix_, double size_);

/**
 * @brief ������� �������� ���� ������� �������
 * @param A_ ������� �������������
 * @param B_ ������� ��������� ������
 * @param n_ ���������� �����������
*/
void CramerMethod(double** A_, double* B_, int n_);