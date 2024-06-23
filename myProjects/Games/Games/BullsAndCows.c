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
         printf("Пожалуйста, введите %d значное число: ", size);
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
   printf("Добро пожаловать! Это игра \"Быки и коровы\" \nОзнакомьтесь с правилами игры: Быки и коровы — логическая игра,\nв\
ходе которой за несколько попыток один игрок должен определить,\nкакое число загадал \
другой игрок. После каждой попытки задумавший игрок выставляет «оценку», \nуказывая количество угаданного \
без совпадения с их позициями (количество «коров») и \nполных совпадений (количество «быков»). \
В нашем случае в роли игрока, который загадывает число выступает комьютер, \nпопробуйте отгадать его \
число за наименьшее число попыток. Удачи!\n");
   printf("\n__________________________________________________________________________________________________________________\n");
   int size;
   printf("Введите длину числа которое будет использоваться в игре: ");
   scanf_s("%d", &size);

   int* num_hidden = (int*)malloc(size * sizeof(int)); // массив для хранения загаданного числа

   int choice;
   while (1)
   {
      printf("Введите 1 если хотите играть со вторым игроком\nВведите 2 если хотите играть с компьютером\n");
      printf(": ");
      scanf_s("%d", &choice);

      switch (choice)
      {
      case 1:
      {
         printf("Запущена игра вдвоём\n");
         printf("Загадайте %d значное число: ", size);
         num_hidden = readNumArray(size);
         system("cls");
         PlayBullsAndCows(num_hidden, size);
         exit(1);
      }
      case 2:
      {
         printf("Запущена игра с компьютером\n");
         num_hidden = generationRandomNumber(size);
         PlayBullsAndCows(num_hidden, size);
         exit(1);
      }
      default:
         printf("Неверное действие\n\n");
         break;
      }
   }
}

void PlayBullsAndCows(int* num_hidden, int size)
{
   int* num_attemp = (int*)malloc(size * sizeof(int)); // число которое будет предлагать игрок как возможный ответ
   int bulls = 0;         // количество <быков>
   int cows = 0;          // количество <коров>
   int count_attemts = 0; // количество предпринятых попыток

   printf("Отгадывайте число\n");

   while (bulls < 4)
   {
      bulls = 0;
      cows = 0;
      count_attemts++;

      printf("Попытка номер %d\n", count_attemts);
      printf("Введите число: ");

      num_attemp = readNumArray(size);

      printf("--------------------------\n");

      for (int i = 0; i < size; i++) // проверка чисел игрока и второго игрока / компьютера
      {
         if (num_hidden[i] == num_attemp[i]) // если число и позиция совпадают, то bulls увеличивается на единицу
         {
            bulls++;
         }
         else
         {     /*
              если числа на одинаковых позициях не равны то выполняется else: проверяются одинаковые числа, но уже на разных позициях
              если такие числа есть, то cows увеличивается на единицу при каждом совпадении, иначе не изменяется.
              если не использовать else, а просто запустить цикл в цикле то возможен неправильный подсчёт, т.к. в cows будут
              записываться и найденные bulls
              */
            for (int n = 0; n < size; n++)
            {
               if (num_hidden[i] == num_attemp[n]) // если число и позиция не совпадают, то cows увеличивается на единицу
                  cows++;
            }
         }
      }
      printf("Быки: %d\n", bulls);  //общее число <быков>
      printf("Коровы: %d\n", cows); //общее число <коров>
   }

   printf("Поздравляю! Вы угадали число\n");
   printf("Загаданное число: ");
   int a = 0;
   while (a < size)
   {
      printf("%d", num_hidden[a]);
      a++;
   }
   printf("\nЧисло попыток: %d", count_attemts);
}