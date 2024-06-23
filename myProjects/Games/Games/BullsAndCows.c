#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "BullsAndCows.h"

int* generationRandomNumber(int size)
{
   int* number = (int*)malloc(size * sizeof(int));
   if (!number)
   {
      return NULL;
   }

   for (int i = 0; i < size; i++)
   {
      number[i] = rand() % 10;
   }

   while (number[0] == 0)
   {
      number[0] = rand() % 10;
   }

   return number;
}

int* readNumArray(int size)
{
   int temp;
   scanf_s("%d", &temp);

   while (1)
   {
      if (temp < (int)pow(10, size - 1) || temp >((int)pow(10, size) - 1))
      {
         printf("����������, ������� %d ������� �����: ", size);
         scanf_s("%d", &temp);
      }
      else
      {
         break;
      }
   }

   int* result = (int*)malloc(size * sizeof(int));
   if (!result)
      return NULL;

   for (int i = size - 1; i >= 0; i--)
   {
      result[i] = temp % 10;
      temp /= 10;
   }

   return result;
}

void startGameBullsAndCows()
{
   printf("����� ����������! ��� ���� \"���� � ������\" \n������������ � ��������� ����: ���� � ������ � ���������� ����,\n�\
���� ������� �� ��������� ������� ���� ����� ������ ����������,\n����� ����� ������� \
������ �����. ����� ������ ������� ���������� ����� ���������� �������, \n�������� ���������� ���������� \
��� ���������� � �� ��������� (���������� ������) � \n������ ���������� (���������� ������). \
� ����� ������ � ���� ������, ������� ���������� ����� ��������� ��������, \n���������� �������� ��� \
����� �� ���������� ����� �������. �����!\n");
   printf("\n__________________________________________________________________________________________________________________\n");
   int size;
   printf("������� ����� ����� ������� ����� �������������� � ����: ");
   scanf_s("%d", &size);

   int* num_hidden = (int*)malloc(size * sizeof(int)); // ������ ��� �������� ����������� �����

   int choice;
   while (1)
   {
      printf("������� 1 ���� ������ ������ �� ������ �������\n������� 2 ���� ������ ������ � �����������\n");
      printf(": ");
      scanf_s("%d", &choice);

      switch (choice)
      {
      case 1:
      {
         printf("�������� ���� �����\n");
         printf("��������� %d ������� �����: ", size);
         num_hidden = readNumArray(size);
         system("cls");
         PlayBullsAndCows(num_hidden, size);
         exit(1);
      }
      case 2:
      {
         printf("�������� ���� � �����������\n");
         num_hidden = generationRandomNumber(size);
         PlayBullsAndCows(num_hidden, size);
         exit(1);
      }
      default:
         printf("�������� ��������\n\n");
         break;
      }
   }
}

void PlayBullsAndCows(int* num_hidden, int size)
{
   int* num_attemp = (int*)malloc(size * sizeof(int)); // ����� ������� ����� ���������� ����� ��� ��������� �����
   int bulls = 0;         // ���������� <�����>
   int cows = 0;          // ���������� <�����>
   int count_attemts = 0; // ���������� ������������ �������

   printf("����������� �����\n");

   while (bulls < 4)
   {
      bulls = 0;
      cows = 0;
      count_attemts++;

      printf("������� ����� %d\n", count_attemts);
      printf("������� �����: ");

      num_attemp = readNumArray(size);

      printf("--------------------------\n");

      for (int i = 0; i < size; i++) // �������� ����� ������ � ������� ������ / ����������
      {
         if (num_hidden[i] == num_attemp[i]) // ���� ����� � ������� ���������, �� bulls ������������� �� �������
         {
            bulls++;
         }
         else
         {     /*
              ���� ����� �� ���������� �������� �� ����� �� ����������� else: ����������� ���������� �����, �� ��� �� ������ ��������
              ���� ����� ����� ����, �� cows ������������� �� ������� ��� ������ ����������, ����� �� ����������.
              ���� �� ������������ else, � ������ ��������� ���� � ����� �� �������� ������������ �������, �.�. � cows �����
              ������������ � ��������� bulls
              */
            for (int n = 0; n < size; n++)
            {
               if (num_hidden[i] == num_attemp[n]) // ���� ����� � ������� �� ���������, �� cows ������������� �� �������
                  cows++;
            }
         }
      }
      printf("����: %d\n", bulls);  //����� ����� <�����>
      printf("������: %d\n", cows); //����� ����� <�����>
   }

   printf("����������! �� ������� �����\n");
   printf("���������� �����: ");
   int a = 0;
   while (a < size)
   {
      printf("%d", num_hidden[a]);
      a++;
   }
   printf("\n����� �������: %d", count_attemts);
}