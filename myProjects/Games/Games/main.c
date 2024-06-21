#include <locale.h>
#include <time.h>

#include "TicTacToe.h"
#include "BullsAndCows.h"
#include "SeaBattle.h"


int main()
{
   setlocale(LC_ALL, "Russian");
   srand(time(NULL));

   printf("����� ����������!\n�������� ���� � ������� ������ �������:\n");
   do
   {
      printf("0 - ������� ����\n1 - \"�������� ������\"\n2 - \"���� � ������\"\n3 - \"������� ���\"\n: ");
      int choice = 0;
      scanf_s("%d", &choice);
      printf("\n");
      switch (choice)
      {
      case 0:
      {
         printf("�� ��������!\n");
         return 0;
      }
      case 1:
      {
         TicTacToeGameMenu();
         break;
      }
      case 2:
      {
         startGameBullsAndCows();
         break;
      }
      case 3:
      {
         SeaBattleStartGame();
         break;
      }
      default:
         printf("�������� �����!\n\n");
         break;
      }
   } while (1);

   return 0;
}
