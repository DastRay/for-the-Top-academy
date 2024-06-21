#pragma once
#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>
using namespace std;


//       '#' - пустая клетка
//       '@' - мина
//       '~' - открытая пустая клетка

class Sapper
{
private:
   char** fieldPlayer;
   char** fieldMines;
   int fieldSize;
   int numberMines;

   int getRandomNumber(const int min, const int max) noexcept;
   void printFieldPlayer() const noexcept;
   void printEndGameField() const noexcept;
   void createFields();
   void setMines();
   int countMinesNearby(const int x, const int y) const noexcept;
   void openingCells(const int x, const int y);
   int countHashes() const noexcept;
   void startGame();
   void play();
   void deleteFields();

public:
   ~Sapper();
   void game();
};