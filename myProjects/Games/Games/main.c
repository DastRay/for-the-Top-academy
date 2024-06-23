#include <locale.h>
#include <time.h>

#include "TicTacToe.h"
#include "BullsAndCows.h"
#include "SeaBattle.h"


int main()
{
   setlocale(LC_ALL, "Russian");
   srand(time(NULL));

   printf("Добро пожаловать!\nВыберите игру в которую хотите сыграть:\n");
   do
   {
      printf("0 - Закрыть меню\n1 - \"Крестики нолики\"\n2 - \"Быки и коровы\"\n3 - \"Морской бой\"\n: ");
      int choice = 0;
      scanf_s("%d", &choice);
      printf("\n");
      switch (choice)
      {
      case 0:
      {
         printf("До свидания!\n");
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
         printf("Неверный выбор!\n\n");
         break;
      }
   } while (1);

   return 0;
}
