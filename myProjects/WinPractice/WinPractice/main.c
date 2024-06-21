#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "matrix.h"
#include "kramer.h"

int main()
{
    setlocale(LC_ALL, "RUS");

    ////////////////////////// ������� �1, ���������� �������� ������� //////////////////////////////////////

    int rows = 0;
    int cols = 0;
    printf("������� ���������� ����� � �������� ����� ������\n����������, ��� ��� ������������ ������� ����� �������� ����������: ");
    scanf_s("%d %d", &rows, &cols);
    if (rows != cols)
    {
        printf("��� ������������ ������� ����� �������� ����������!\n");
        return -1;
    }

    double** matrix = malloc(rows * sizeof(double*)); // ��������� ������ ��� ������ �������
    if (!matrix)
    {
       printf("[!] ������ ��������� ������!\n");
       return 1;
    }

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = malloc(cols * sizeof(double));
        if (!matrix[i])
        {
           printf("[!] ������ ��������� ������!\n");
           return 1;
        }
    }
    readMatrix(matrix, rows, cols);
    double** res = reverseMatrix(matrix, rows, cols); // ���������� �������� �������
    printf("�������� �������:\n");
    printMatrix(res, rows, cols);

    //////////////////////// ������� �2, ������� ���� ������� ������� //////////////////////////////////////

    int unk = 0;
    printf("������� ���������� �����������: ");
    scanf_s("%d", &unk);

    double** A = malloc(unk * sizeof(double*));
    if (!A)
    {
       printf("[!] ������ ��������� ������!\n");
       return 1;
    }

    for (int i = 0; i < unk; i++)
    {
       A[i] = malloc(unk * sizeof(double));
       if (!A[i])
       {
          printf("[!] ������ ��������� ������!\n");
          return 1;
       }
    }

    double* B = malloc(unk * sizeof(double));

    readSLAYmatrix(A, B, unk);

    CramerMethod(A, B, unk);

    return 0;
}