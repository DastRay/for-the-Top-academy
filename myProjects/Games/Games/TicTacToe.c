#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "TicTacToe.h"


char** creatField(const unsigned int size)
{
   char** field = (char**)malloc(size * sizeof(char*));
   if (!field)
   {
      printf("[!] ������ ��������� ������\n");
      exit(-1);
   }
   for (int i = 0; i < size; i++)
   {
      field[i] = (char*)malloc(size * sizeof(char));
      if (!field[i])
      {
         printf("[!] ������ ��������� ������\n");
         exit(-1);
      }
      for (int j = 0; j < size; j++)
      {
         field[i][j] = ' ';
      }
   }

   return field;
}

void printGameField(char** field, const int unsigned size)
{
   printf("   ");
   for (int n = 0; n < size; n++)
   {
      printf("%2d|", n + 1);
   }
   printf("\n");

   for (int i = 0; i < size; i++)
   {
      printf("%2d|", i + 1);

      for (int j = 0; j < size; j++)
      {
         printf("%2c|", field[i][j]);
      }
      printf("\n");
   }
}

void TicTacToeGameMenu()
{  
   printf("�������� ���� \"�������� ������\"\n");

   unsigned int size;
   printf("������� ������ ����: ");

   while (1)
   {
      scanf_s("%u", &size);
      if (size <= 0)
      {
         printf("������������ ������, ������� ������ ���� ��� ���: ");
      }
      else
      {
         break;
      }
   }

   char** field = creatField(size);

   printf("\n");
   printf("������� ����!\n");
   printGameField(field, size);
   printf("\n");

   startGame(field, size);
}

void startGame(char** field, const unsigned int size)
{
   unsigned int rows = 0;
   unsigned int cols = 0;
   unsigned int count = 0;

   while (1)
   {
      if (count % 2 == 0)
      {
         printf("����� \"�������\", ������� ����� ������ � ������� ����� ������: ");
         scanf_s("%u %u", &rows, &cols);
         while (1)
         {
            if (rows > size || cols > size)
            {
               printf("����� ������ ������� �� ����� �������� ����! ��������� �����\n������� ����� ������ � ������� ����� ������: ");
               scanf_s("%u %u", &rows, &cols);
            }
            else if (field[rows - 1][cols - 1] == 'X' || field[rows - 1][cols - 1] == '0')
            {
               printf("������ ������! ��������� �����\n������� ����� ������ � ������� ����� ������: ");
               scanf_s("%u %u", &rows, &cols);
            }
            else
            {
               break;
            }
         }
         field[rows - 1][cols - 1] = 'X';
         count++;
      }
      else
      {
         printf("����� \"�����\", ������� ����� ������ � ������� ����� ������: ");
         scanf_s("%u %u", &rows, &cols);
         while (1)
         {
            if (rows > size || cols > size)
            {
               printf("����� ������ ������� �� ����� �������� ����! ��������� �����\n������� ����� ������ � ������� ����� ������: ");
               scanf_s("%u %u", &rows, &cols);
            }
            else if (field[rows - 1][cols - 1] == 'X' || field[rows - 1][cols - 1] == '0')
            {
               printf("������ ������! ��������� �����\n������� ����� ������ � ������� ����� ������: ");
               scanf_s("%u %u", &rows, &cols);
            }
            else
            {
               break;
            }
         }
         field[rows - 1][cols - 1] = '0';
         count++;
      }

      printf("\n");
      printGameField(field, size);
      if (count == size * size)
      {  
         printf("�����!\n���� ��������\n");
         break;
      }
      else if (checkField(field, size) == true)
      {
         if ((count - 1) % 2 == 0)
         {
            printf("�������� \"��������\"!");
            break;
         }
         else
         {
            printf("�������� \"������\"!");
            break;
         }
      }
   }
}

bool checkField(const char** field, const unsigned int size)
{
   // �������� �����
   for (int i = 0; i < size; i++) 
   {
      bool isSame = true;
      char compare = field[i][0];

      if (compare != ' ') {
         for (int j = 1; j < size; j++) 
         {
            if (compare != field[i][j]) 
            {
               isSame = false;
               break;
            }
         }

         if (isSame == true) 
         {
            return true;
         }
      }
   }

   // �������� ��������
   for (int i = 0; i < size; i++) 
   {
      bool isSame = true;
      char compare = field[0][i];

      if (compare != ' ') {
         for (int j = 1; j < size; j++) 
         {
            if (compare != field[j][i]) 
            {
               isSame = false;
               break;
            }
         }

         if (isSame == true) {
            return true;
         }
      }
   }

   // �������� ������� ���������
   char compare = field[0][0];
   if (compare != ' ') 
   {
      bool isSame = true;
      for (int i = 1; i < size; i++) 
      {
         if (compare != field[i][i]) 
         {
            isSame = false;
            break;
         }
      }

      if (isSame == true) 
      {
         return true;
      }
   }

   // �������� �������� ���������
   compare = field[0][size - 1];
   if (compare != ' ') 
   {
      bool isSame = true;
      for (int i = 1; i < size; i++) 
      {
         if (compare != field[i][size - 1 - i]) 
         {
            isSame = false;
            break;
         }
      }

      if (isSame == true) 
      {
         return true;
      }
   }

   return false;
}