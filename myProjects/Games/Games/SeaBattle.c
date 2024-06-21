#include "SeaBattle.h"

//    '~'             //Поле
//   ,'X'             //Попадание
//   ,'#'             //Промах
//   ,'S'             //Корабль


void SeaBattleStartGame()
{
   Board player_1;
   player_1.gameBoard = createBoard(); // поле кораблей первого игрока
   player_1.HitsBoard = createBoard(); // поле попаданий первого игрока
   player_1.numHits = 0;               // количество попаданий первого игрока

   Board player_2;
   player_2.gameBoard = createBoard(); // поле кораблей второго игрока
   player_2.HitsBoard = createBoard(); // поле попаданий второго игрока
   player_2.numHits = 0;               // количество попаданий второго игрока

   printf("--- Игра началась! ---\n\n");
   printf("Установка кораблей для первого игрока\n");
   placeAllShip(player_1.gameBoard);
   system("pause");
   system("cls");

   printf("Установка кораблей для второго игрока\n");
   placeAllShip(player_2.gameBoard);
   system("pause");
   system("cls");

   SeaBattlePlayGame(&player_1, &player_2);
}


void SeaBattlePlayGame(Board* player_1, Board* player_2)
{
   int move = 0;
   while (player_1->numHits < COUNT_HITS_FOR_WIN && player_2->numHits < COUNT_HITS_FOR_WIN)
   {
      if (move % 2 == 0) // игрок №1
      {
         while (1)
         {
            printf("Ход игрока №1\n");
            printf("Ваше поле кораблей:\n");
            printBoard(player_1->gameBoard);
            printf("Ваше поле выстрелов:\n");
            printBoard(player_1->HitsBoard);
            printf("Ваше количество попаданий: %d\n\n", player_1->numHits);
            printf("Введите координаты для выстрела (например А1): ");
            Coord coord = getCoordinateForHits();
            bool res1 = checkHits(player_1, player_2, coord.x, coord.y);

            if (player_1->numHits == COUNT_HITS_FOR_WIN)
            {
               printf("\nПобедил игрок №1! Игра окончена\n");
               return;
            }
            if (res1 == false)
            {
               break;
            }
         }
         system("pause");
         system("cls");
      }
      else               // игрок №2
      {
         while (1)
         {
            printf("Ход игрока №2\n");
            printf("Ваше поле кораблей:\n");
            printBoard(player_2->gameBoard);
            printf("Ваше поле выстрелов:\n");
            printBoard(player_2->HitsBoard);
            printf("Ваше количество попаданий: %d\n\n", player_2->numHits);
            printf("Введите координаты для выстрела (например А1): ");
            Coord coord = getCoordinateForHits();
            bool res2 = checkHits(player_2, player_1, coord.x, coord.y);

            if (player_2->numHits == COUNT_HITS_FOR_WIN)
            {
               printf("\nПобедил игрок №2! Игра окончена\n");
               return;
            }
            if (res2 == false)
            {
               break;
            }
         }
         system("pause");
         system("cls");
      }
      move++;
   }
}


char** createBoard()
{
   char** gameBoard = (char**)malloc(BOARD_SIZE * sizeof(char*));
   if (!gameBoard)
   {
      printf("[!] Ошибка выделения памяти!\n");
      return NULL;
   }

   for (int i = 0; i < BOARD_SIZE; i++)
   {
      gameBoard[i] = (char*)malloc(BOARD_SIZE * sizeof(char));
      if (!gameBoard[i])
      {
         printf("[!] Ошибка выделения памяти!\n");
         return NULL;
      }

      for (int j = 0; j < BOARD_SIZE; j++)
      {
         gameBoard[i][j] = '~';
      }
   }

   return gameBoard;
}


void printBoard(char** gameBoard)
{
   printf("  ");
   for (int i = 0; i < BOARD_SIZE; i++)
   {
      printf("%d ", i + 1);
   }
   printf("\n");

   for (int i = 0; i < BOARD_SIZE; i++)
   {
      printf("%c ", 'A' + i);

      for (int j = 0; j < BOARD_SIZE; j++)
      {
         printf("%c ", gameBoard[i][j]);
      }
      printf("\n");
   }

   printf("\n");
}


void placeShip1x1(char** board)
{
   printf("Введите координаты для корабля размером 1х1 (например А1): ");
   Coord coord = getCoordinateForShips(board);

   board[coord.x][coord.y] = 'S';
   printf("Корабль 1х1 успешно установлен\n\n");
}


void placeShip1x2(char** board)
{
   printf("Введите начальную координату для корабля размером 1х2 (например А1): ");
   Coord coord = getCoordinateForShips(board);
   int x1 = coord.x;
   int y1 = coord.y;

   printf("Введите конечную координату для корабля размером 1х2 (например А1): ");
   coord = getCoordinateForShips(board);
   int x2 = coord.x;
   int y2 = coord.y;

   board[x1][y1] = 'S';
   board[x2][y2] = 'S';

   printf("Корабль 1х2 успешно установлен\n\n");
}


void placeShip1x3(char** board)
{
   printf("Введите начальную координату для корабля размером 1х3 (например А1): ");
   Coord coord = getCoordinateForShips(board);
   int x1 = coord.x;
   int y1 = coord.y;

   printf("Введите конечную координату для корабля размером 1х3 (например А1): ");
   coord = getCoordinateForShips(board);
   int x2 = coord.x;
   int y2 = coord.y;

   board[x1][y1] = 'S';
   board[x2][y2] = 'S';

   if (x1 == x2)
   {
      board[x2][y2 - 1] = 'S';
   }
   else
   {
      board[x2 - 1][y2] = 'S';
   }

   printf("Корабль 1х3 успешно установлен\n\n");
}


void placeShip1x4(char** board)
{
   printf("Введите начальную координату для корабля размером 1х4 (например А1): ");
   Coord coord = getCoordinateForShips(board);
   int x1 = coord.x;
   int y1 = coord.y;

   printf("Введите конечную координату для корабля размером 1х4 (например А1): ");
   coord = getCoordinateForShips(board);
   int x2 = coord.x;
   int y2 = coord.y;

   board[x1][y1] = 'S';
   board[x2][y2] = 'S';

   if (x1 == x2)
   {
      board[x2][y1 + 1] = 'S';
      board[x2][y2 - 1] = 'S';
   }
   else
   {
      board[x1 + 1][y2] = 'S';
      board[x2 - 1][y2] = 'S';
   }

   printf("Корабль 1х4 успешно установлен\n\n");
}


void placeAllShip(char** board)
{
   printBoard(board);
   for (int i = 1; i <= 4; i++)
   {
      placeShip1x1(board);
      printBoard(board);
   }
   for (int i = 1; i <= 2; i++)
   {
      placeShip1x2(board);
      printBoard(board);
   }
   for (int i = 1; i <= 2; i++)
   {
      placeShip1x3(board);
      printBoard(board);
   }
   placeShip1x4(board);
   printBoard(board);

   printf("Все корабли успешно установлены\n\n");
}


Coord getCoordinateForShips(const char** board)
{
   char letter;
   int number = 0;
   int x = 0;
   int y = 0;

   do {
      scanf_s(" %c", &letter);
      scanf_s("%d", &number);
      x = letter - 'A';
      y = number - 1;

      if (chekCoordinate(x, y) == false)
      {
         printf("Координаты неверны, введите заново: ");
      }
      else if (board[x][y] == 'S')
      {
         printf("Данное место занято, введите координаты заново: ");
      }
      else if (checkNoShipsNearby(board, x, y) == false)
      {
         printf("Невозможно установить корабль! Рядом уже стоит корабль. Введите координаты заново: ");
      }
      else
      {
         break;
      }
   } while (1);

   Coord coord;
   coord.x = x;
   coord.y = y;

   return coord;
}


Coord getCoordinateForHits()
{
   char letter;
   int number = 0;
   int x = 0;
   int y = 0;

   do {
      scanf_s(" %c", &letter);
      scanf_s("%d", &number);
      x = letter - 'A';
      y = number - 1;

      if (chekCoordinate(x, y) == false)
      {
         printf("Координаты неверны, введите заново: ");
      }
      else
      {
         break;
      }

   } while (1);

   Coord coord;
   coord.x = x;
   coord.y = y;

   return coord;
}


bool chekCoordinate(const int x, const int y)
{
   if (x >= BOARD_SIZE || x < 0 || y >= BOARD_SIZE || y < 0)
   {
      return false;
   }
   else
   {
      return true;
   }
}


bool checkNoShipsNearby(const char** board, const int x, const int y)
{
   // Проверка наличия кораблей вокруг клетки
   // Если вокруг есть хотя бы одна клетка с занятым значением, значит есть корабль рядом

   // Проверка клеток вокруг выбранной клетки
   for (int i = x - 1; i <= x + 1; i++)
   {
      for (int j = y - 1; j <= y + 1; j++)
      {
         // Проверка, что координаты клетки находятся в пределах игрового поля
         if (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE)
         {
            if (board[i][j] != '~')
            {
               return false; // Найден корабль рядом
            }
         }
      }
   }

   return true; // Нет кораблей рядом
}


bool checkDestroy(const Board* board, const int x, const int y)
{
   for (int i = x; i >= 0 && board->gameBoard[i][y] != '~'; i--)
   {
      if (board->gameBoard[i][y] == 'S')
      {
         return false;
      }
   }

   for (int i = x; i < BOARD_SIZE && board->gameBoard[i][y] != '~'; i++)
   {
      if (board->gameBoard[i][y] == 'S')
      {
         return false;
      }
   }

   for (int i = y; i >= 0 && board->gameBoard[x][i] != '~'; i--)
   {
      if (board->gameBoard[x][i] == 'S')
      {
         return false;
      }
   }

   for (int i = y; i < BOARD_SIZE && board->gameBoard[x][i] != '~'; i++)
   {
      if (board->gameBoard[x][i] == 'S')
      {
         return false;
      }
   }

   return true;
}

bool checkHits(Board* AttackingPlayer, Board* AttackedPlayer, const int x, const int y)
{
   if (AttackedPlayer->gameBoard[x][y] == 'S')
   {
      AttackingPlayer->numHits++;
      AttackedPlayer->gameBoard[x][y] = 'X';
      AttackingPlayer->HitsBoard[x][y] = 'X';

      if (checkDestroy(AttackedPlayer, x, y) == false)
      {
         printf("Попадание!\n");
         return true;
      }
      else
      {
         printf("Корабль противника уничтожен!\n");
         return true;
      }
   }
   else
   {
      printf("Промах!\n");
      AttackedPlayer->gameBoard[x][y] = '#';
      AttackingPlayer->HitsBoard[x][y] = '#';
      return false;
   }
}