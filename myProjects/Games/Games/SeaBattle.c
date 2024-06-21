#include "SeaBattle.h"

//    '~'             //����
//   ,'X'             //���������
//   ,'#'             //������
//   ,'S'             //�������


void SeaBattleStartGame()
{
   Board player_1;
   player_1.gameBoard = createBoard(); // ���� �������� ������� ������
   player_1.HitsBoard = createBoard(); // ���� ��������� ������� ������
   player_1.numHits = 0;               // ���������� ��������� ������� ������

   Board player_2;
   player_2.gameBoard = createBoard(); // ���� �������� ������� ������
   player_2.HitsBoard = createBoard(); // ���� ��������� ������� ������
   player_2.numHits = 0;               // ���������� ��������� ������� ������

   printf("--- ���� ��������! ---\n\n");
   printf("��������� �������� ��� ������� ������\n");
   placeAllShip(player_1.gameBoard);
   system("pause");
   system("cls");

   printf("��������� �������� ��� ������� ������\n");
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
      if (move % 2 == 0) // ����� �1
      {
         while (1)
         {
            printf("��� ������ �1\n");
            printf("���� ���� ��������:\n");
            printBoard(player_1->gameBoard);
            printf("���� ���� ���������:\n");
            printBoard(player_1->HitsBoard);
            printf("���� ���������� ���������: %d\n\n", player_1->numHits);
            printf("������� ���������� ��� �������� (�������� �1): ");
            Coord coord = getCoordinateForHits();
            bool res1 = checkHits(player_1, player_2, coord.x, coord.y);

            if (player_1->numHits == COUNT_HITS_FOR_WIN)
            {
               printf("\n������� ����� �1! ���� ��������\n");
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
      else               // ����� �2
      {
         while (1)
         {
            printf("��� ������ �2\n");
            printf("���� ���� ��������:\n");
            printBoard(player_2->gameBoard);
            printf("���� ���� ���������:\n");
            printBoard(player_2->HitsBoard);
            printf("���� ���������� ���������: %d\n\n", player_2->numHits);
            printf("������� ���������� ��� �������� (�������� �1): ");
            Coord coord = getCoordinateForHits();
            bool res2 = checkHits(player_2, player_1, coord.x, coord.y);

            if (player_2->numHits == COUNT_HITS_FOR_WIN)
            {
               printf("\n������� ����� �2! ���� ��������\n");
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
      printf("[!] ������ ��������� ������!\n");
      return NULL;
   }

   for (int i = 0; i < BOARD_SIZE; i++)
   {
      gameBoard[i] = (char*)malloc(BOARD_SIZE * sizeof(char));
      if (!gameBoard[i])
      {
         printf("[!] ������ ��������� ������!\n");
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
   printf("������� ���������� ��� ������� �������� 1�1 (�������� �1): ");
   Coord coord = getCoordinateForShips(board);

   board[coord.x][coord.y] = 'S';
   printf("������� 1�1 ������� ����������\n\n");
}


void placeShip1x2(char** board)
{
   printf("������� ��������� ���������� ��� ������� �������� 1�2 (�������� �1): ");
   Coord coord = getCoordinateForShips(board);
   int x1 = coord.x;
   int y1 = coord.y;

   printf("������� �������� ���������� ��� ������� �������� 1�2 (�������� �1): ");
   coord = getCoordinateForShips(board);
   int x2 = coord.x;
   int y2 = coord.y;

   board[x1][y1] = 'S';
   board[x2][y2] = 'S';

   printf("������� 1�2 ������� ����������\n\n");
}


void placeShip1x3(char** board)
{
   printf("������� ��������� ���������� ��� ������� �������� 1�3 (�������� �1): ");
   Coord coord = getCoordinateForShips(board);
   int x1 = coord.x;
   int y1 = coord.y;

   printf("������� �������� ���������� ��� ������� �������� 1�3 (�������� �1): ");
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

   printf("������� 1�3 ������� ����������\n\n");
}


void placeShip1x4(char** board)
{
   printf("������� ��������� ���������� ��� ������� �������� 1�4 (�������� �1): ");
   Coord coord = getCoordinateForShips(board);
   int x1 = coord.x;
   int y1 = coord.y;

   printf("������� �������� ���������� ��� ������� �������� 1�4 (�������� �1): ");
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

   printf("������� 1�4 ������� ����������\n\n");
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

   printf("��� ������� ������� �����������\n\n");
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
         printf("���������� �������, ������� ������: ");
      }
      else if (board[x][y] == 'S')
      {
         printf("������ ����� ������, ������� ���������� ������: ");
      }
      else if (checkNoShipsNearby(board, x, y) == false)
      {
         printf("���������� ���������� �������! ����� ��� ����� �������. ������� ���������� ������: ");
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
         printf("���������� �������, ������� ������: ");
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
   // �������� ������� �������� ������ ������
   // ���� ������ ���� ���� �� ���� ������ � ������� ���������, ������ ���� ������� �����

   // �������� ������ ������ ��������� ������
   for (int i = x - 1; i <= x + 1; i++)
   {
      for (int j = y - 1; j <= y + 1; j++)
      {
         // ��������, ��� ���������� ������ ��������� � �������� �������� ����
         if (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE)
         {
            if (board[i][j] != '~')
            {
               return false; // ������ ������� �����
            }
         }
      }
   }

   return true; // ��� �������� �����
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
         printf("���������!\n");
         return true;
      }
      else
      {
         printf("������� ���������� ���������!\n");
         return true;
      }
   }
   else
   {
      printf("������!\n");
      AttackedPlayer->gameBoard[x][y] = '#';
      AttackingPlayer->HitsBoard[x][y] = '#';
      return false;
   }
}