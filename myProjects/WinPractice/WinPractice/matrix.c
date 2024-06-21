#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "kramer.h"

void readMatrix(double** matrix_, int rows_, int cols_)
{
    printf("Введите элементы матрицы построчно:\n");
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            scanf_s("%lf", &matrix_[i][j]);
        }
    }
    printf("\n");
}

void printMatrix(double** matrix_, int rows_, int cols_)
{
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            printf("%8.3lf ", matrix_[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

double** copyMatrix(double** matrix_, int rows_, int cols_)
{
    double** copy = malloc(rows_ * sizeof(double*));
    if (!copy)
       return 1;

    for (int i = 0; i < rows_; i++)
    {
        copy[i] = malloc(cols_ * sizeof(double));
        if (!copy[i])
           return 1;
        for (int j = 0; j < cols_; j++)
        {
            copy[i][j] = matrix_[i][j];
        }
    }
    return copy;
}

void swapRows(double** matrix_, int row1_, int row2_, int n_)
{
    for (int i = 0; i < n_; i++)
    {
        double copy = matrix_[row1_][i];
        matrix_[row1_][i] = matrix_[row2_][i];
        matrix_[row2_][i] = copy;
    }
}

void subtractRows(double** matrix_, int row1_, int row2_, int n_, double s_)
{
    for (int i = 0; i < n_; i++)
    {
        matrix_[row2_][i] -= s_ * matrix_[row1_][i];
    }
}

double determinant(double** matrix_, int n_)
{
    double det = 1.0;
    int sign = 1;

    for (int i = 0; i < n_; i++)
    {
        int max_row = i;
        for (int j = i + 1; j < n_; j++)
        {
            if (abs(matrix_[j][i]) > abs(matrix_[max_row][i]))
            {
                max_row = j;
            }
        }

        if (max_row != i)
        {
            swapRows(matrix_, i, max_row, n_);
            sign *= -1;
        }

        if (matrix_[i][i] == 0)
        {
            return 0;
        }

        for (int j = i + 1; j < n_; j++)
        {
            double del = matrix_[j][i] / matrix_[i][i];
            subtractRows(matrix_, i, j, n_, del);
        }

        det *= matrix_[i][i];
    }

    return det * sign;
}

void zerosAboveDiagonal(double** matrix_, int n_)
{
    for (int i = n_ - 1; i > 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            double div = matrix_[j][i] / matrix_[i][i];
            subtractRows(matrix_, i, j, n_, div);
        }
    }
}

double** transposeMatrix(double** matrix_, int rows_, int cols_)
{
    double** transp = malloc(cols_ * sizeof(double*));
    if (!transp)
       return 1;

    for (int i = 0; i < cols_; i++)
    {
        transp[i] = malloc(rows_ * sizeof(double));
        if (!transp[i])
           return 1;
        for (int j = 0; j < rows_; j++)
        {
            transp[i][j] = matrix_[j][i];
        }
    }
    return transp;
}

void divideMatrix(double** matrix_, int rows_, int cols_, double div_)
{
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            matrix_[i][j] /= div_;
        }
    }
}

double** findMinor(double** matrix_, int rows_, int cols_, int n_, int m_)
{
    double** temp = malloc(rows_ * sizeof(double*));
    if (!temp)
        return 1;

    for (int i = 0; i < rows_; i++)
    {
        temp[i] = malloc(cols_ * sizeof(double));
        if (!temp[i])
            return 1;
    }

    int k = 0;
    int p = 0;

    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            if (i != n_ && j != m_)
            {
                temp[k][p] = matrix_[i][j];
                p++;

                if (p == rows_ - 1)
                {
                    p = 0;
                    k++;
                }
            }
        }
    }
    return temp;
}

double** findAlgComplement(double** matrix_, int rows_, int cols_)
{
    double** res = malloc(rows_ * sizeof(double*)); // выделение памяти под каждый столбец
    if (!res)
        return 1;

    for (int i = 0; i < rows_; i++)
    {
        res[i] = malloc(cols_ * sizeof(double*));
        if (!res[i])
            return 1;
    }

    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            double** temp = findMinor(matrix_, rows_, cols_, i, j);

            int sign = 1;
            if ((i + j) % 2 != 0)
            {
                sign = -1;
            }

            res[i][j] = sign * determinant(temp, rows_ - 1);

            for (int k = 0; k < rows_ - 1; k++)
            {
                free(temp[k]);
            }
            free(temp);
        }
    }
    return res;
}

double** reverseMatrix(double** matrix_, int rows_, int cols_)
{
    double** copy = copyMatrix(matrix_, rows_, cols_);

    double det = determinant(copy, rows_);
    if (det == 0)
    {
        printf("Опредедитель матрицы равен нулю, обратную матрицу найти невозможно!\n");
        return -1;
    }
    printf("Определитель матрицы равен: %.4lf\n", det);

    double** temp = findAlgComplement(matrix_, rows_, cols_);
    printf("Матрица алгебраических дополнений:\n");
    printMatrix(temp, rows_, cols_);

    double** transopse_temp = transposeMatrix(temp, rows_, cols_);
    printf("Транспонированная матрица алгебраических дополнений:\n");
    printMatrix(transopse_temp, rows_, cols_);

    divideMatrix(transopse_temp, rows_, cols_, det);

    return transopse_temp;
}