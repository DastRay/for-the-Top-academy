#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "matrix.h"
#include "kramer.h"

int main()
{
    setlocale(LC_ALL, "RUS");

    ////////////////////////// Задание №1, нахождение обратной матрицы //////////////////////////////////////

    int rows = 0;
    int cols = 0;
    printf("Введите количество строк и столбцов через пробел\nУчитывайте, что для неквадратной матрицы найти обратную невозможно: ");
    scanf_s("%d %d", &rows, &cols);
    if (rows != cols)
    {
        printf("Для неквадратной матрицы найти обратную невозможно!\n");
        return -1;
    }

    double** matrix = malloc(rows * sizeof(double*)); // выделение памяти под каждый столбец
    if (!matrix)
    {
       printf("[!] Ошибка выделения памяти!\n");
       return 1;
    }

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = malloc(cols * sizeof(double));
        if (!matrix[i])
        {
           printf("[!] Ошибка выделения памяти!\n");
           return 1;
        }
    }
    readMatrix(matrix, rows, cols);
    double** res = reverseMatrix(matrix, rows, cols); // нахождение обратной матрицы
    printf("Обратная матрица:\n");
    printMatrix(res, rows, cols);

    //////////////////////// Задание №2, решение слау методом Крамера //////////////////////////////////////

    int unk = 0;
    printf("Введите количество неизвестных: ");
    scanf_s("%d", &unk);

    double** A = malloc(unk * sizeof(double*));
    if (!A)
    {
       printf("[!] Ошибка выделения памяти!\n");
       return 1;
    }

    for (int i = 0; i < unk; i++)
    {
       A[i] = malloc(unk * sizeof(double));
       if (!A[i])
       {
          printf("[!] Ошибка выделения памяти!\n");
          return 1;
       }
    }

    double* B = malloc(unk * sizeof(double));

    readSLAYmatrix(A, B, unk);

    CramerMethod(A, B, unk);

    return 0;
}