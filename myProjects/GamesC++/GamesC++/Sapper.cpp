#include "Sapper.h"

int Sapper::getRandomNumber(const int min, const int max) noexcept
{
   random_device rd;
   mt19937 gen(rd());

   uniform_int_distribution<> dist(min, max);

   return dist(gen);
}

void Sapper::printFieldPlayer() const noexcept
{
   cout << "    ";
   for (int i = 0; i < fieldSize; i++)
   {
      cout << std::setw(2) << i + 1 << " ";
   }
   cout << "\n   ";

   for (int i = 0; i < fieldSize; i++)
   {
      cout << " __";
   }

   cout << endl;
   for (int i = 0; i < fieldSize; i++)
   {
      cout << setw(2) << i + 1 << " |";

      for (int j = 0; j < fieldSize; j++)
      {
         cout << setw(2) << fieldPlayer[i][j] << " ";
      }
      cout << endl;
   }

   cout << endl;
}

void Sapper::printEndGameField() const noexcept
{
   cout << "    ";
   for (int i = 0; i < fieldSize; i++)
   {
      cout << setw(2) << i + 1 << " ";
   }
   cout << "\n   ";
   for (int i = 0; i < fieldSize; i++)
   {
      cout << " __";
   }
   cout << endl;;

   for (int i = 0; i < fieldSize; i++)
   {
      cout << setw(2) << i + 1 << " |";
      for (int j = 0; j < fieldSize; j++)
      {
         const char temp = (fieldMines[i][j] == '@') ? '@' : fieldPlayer[i][j];
         cout << setw(2) << temp << " ";
      }
      cout << endl;
   }

   cout << endl;
}

void Sapper::createFields()
{
   fieldPlayer = new char* [fieldSize];
   fieldMines = new char* [fieldSize];

   for (int i = 0; i < fieldSize; i++)
   {
      fieldPlayer[i] = new char[fieldSize];
      fieldMines[i] = new char[fieldSize];

      for (int j = 0; j < fieldSize; j++)
      {
         fieldPlayer[i][j] = '#';
         fieldMines[i][j] = '#';
      }
   }

   cout << "���� ������� �������\n" << endl;
}

void Sapper::setMines()
{
   int countSetMines = 0;
   while (countSetMines < numberMines)
   {
      const int coordX = getRandomNumber(0, fieldSize - 1);
      const int coordY = getRandomNumber(0, fieldSize - 1);

      if (fieldMines[coordX][coordY] == '#')
      {
         countSetMines++;
         fieldMines[coordX][coordY] = '@';
      }
   }

   cout << "���� ������� �����������\n" << endl;
}

int Sapper::countMinesNearby(const int x, const int y) const noexcept
{
   int count = 0;
   for (int i = x - 1; i <= x + 1; i++)
   {
      for (int j = y - 1; j <= y + 1; j++)
      {
         if (i >= 0 && i < fieldSize && j >= 0 && j < fieldSize)
         {
            if (fieldMines[i][j] == '@')
            {
               count++;
            }
         }
      }
   }

   return count;
}

void Sapper::openingCells(const int x, const int y)
{
   if (x < 0 || x >= fieldSize || y < 0 || y >= fieldSize || fieldPlayer[x][y] != '#')
   {
      return;
   }

   const int countNearMines = countMinesNearby(x, y);
   if (countNearMines == 0)
   {
      fieldPlayer[x][y] = '~';
      for (int i = x - 1; i <= x + 1; i++)
      {
         for (int j = y - 1; j <= y + 1; j++)
         {
            if (i != x || j != y)
            {
               openingCells(i, j);
            }
         }
      }
   }
   else
   {
      fieldPlayer[x][y] = countNearMines + '0';
   }
}

int Sapper::countHashes() const noexcept
{
   int count = 0;
   for (int i = 0; i < fieldSize; i++)
   {
      for (int j = 0; j < fieldSize; j++)
      {
         if (fieldPlayer[i][j] == '#')
         {
            count++;
         }
      }
   }

   return count;
}

void Sapper::startGame()
{
   cout << "����� ���������� � ���� \"����\"!\n����������� � ���������:" << endl;
   cout << "���� ���� \"����\" � ������� ������ ������, �� ������ ��� ���� �� �����, ���������� ����.\n\
��� ����� �� ������ ��� �����������. ���� � ��� ��������� ���� �� ���� ����������� � ����� �����������.\n\
���� � ����� ������ ���� ���, �� ���� ���� � �������� �������, �� ������������ �����, ��������������� ���������� ��� � �������� �������.\n\
��������� �������� ����� � ������� ��������� �� ���� � �� �� ����, ��� ��������� ����� ���������� ������� ������.\n\
���� �� � ����� ������, �� � �������� � ��� ������� ��� ���, �� ����������� ��� �������� ������ ������.\n\
���� ������������, ��� ������ ������� ��� ������, �� ���������� ���.\n" << endl;
cout << "����������� � ��������� �������������:\n'#' - ������ ������\n'@' - ����\n'~' - �������� ������ ������\n����� - ���������� ���\
 ������ ������\n" << endl;

   int choice = 0;
   do {
      cout << "�������� ���������:\n1 - ������� 9x9 ������� 10 ���\n2 - ��������: 16x16 ������, 40 ���\n\
3 - ������������: 30x30 ������, 99 ���\n4 - ���� ���������\n0 - ������� ����\n: ";
      cin >> choice;
      if (choice < 0 || choice > 4)
      {
         cout << "�������� �����!\n" << endl;
      }
      else
      {
         break;
      }
   } while (1);

   switch (choice)
   {
   case 0:
   {
      cout << "����������!" << endl;
      exit(1);
   }
   case 1:
   {
      fieldSize = 9;
      numberMines = 10;
      break;
   }
   case 2:
   {
      fieldSize = 16;
      numberMines = 40;
      break;
   }
   case 3:
   {
      fieldSize = 30;
      numberMines = 99;
      break;
   }
   case 4:
   {
      do {
         cout << "������� ������ ����: ";
         cin >> fieldSize;

         if (fieldSize <= 0)
         {
            cout << "����� �������� ������!" << endl;
         }
         else
         {
            break;
         }
      } while (1);

      do {
         cout << "������� ���������� ��� �� ����: ";
         cin >> numberMines;

         if (numberMines < 0 || (numberMines >= fieldSize * fieldSize))
         {
            cout << "������ �������� ���������� ���!" << endl;
         }
         else
         {
            break;
         }
      } while (1);

      break;
   }
   default:
   {
      break;
   }
   }
}

void Sapper::play()
{
   int numberOfMoves = fieldSize * fieldSize - numberMines;

   while (numberOfMoves != 0)
   {
      int coordX = 0;
      int coordY = 0;
      do {
         cout << "��� �������� ������ ������� ����� ������ � ����� ������� ����� ������: ";
         cin >> coordX >> coordY;
         coordX--;
         coordY--;

         if (coordY >= fieldSize || coordY < 0 || coordX >= fieldSize || coordX < 0)
         {
            cout << "�������� ����������" << endl;
         }
         else
         {
            break;
         }
      } while (1);

      if (fieldMines[coordX][coordY] == '@')
      {
         fieldPlayer[coordX][coordY] = '@';
         printFieldPlayer();
         cout << "�� ���������!\n���� ��������\n" << endl;
         printEndGameField();
         cout << endl;

         int choice = 0;
         cout << "������ ������� ��� ���?\n1 - ��\n2 - ���\n: ";
         cin >> choice;
         if (choice == 1)
         {
            deleteFields();
            system("cls");
            game();
         }
         return;
      }
      else if(fieldMines[coordX][coordY] == '#')
      {
         openingCells(coordX, coordY);
         printFieldPlayer();

         numberOfMoves = countHashes() - numberMines;
      }
      else
      {
         cout << "��� ������ ��� ���� �������!" << endl;
      }
   }

   cout << "�����������, �� ��������!\n" << endl;
   printEndGameField();
}

void Sapper::deleteFields()
{
   for (int i = 0; i < fieldSize; i++)
   {
      delete[] fieldPlayer[i];
      delete[] fieldMines[i];
   }
   delete[] fieldPlayer;
   delete[] fieldMines;
}

Sapper::~Sapper()
{
   deleteFields();
}

void Sapper::game()
{
   startGame();
   createFields();
   setMines();
   printFieldPlayer();
   play();
}
