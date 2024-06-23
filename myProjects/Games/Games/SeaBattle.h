#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 10         // размер игрового поля
#define COUNT_HITS_FOR_WIN 16 // количество клеточек занятых кораблями


// структура для хранения информации об игроке
typedef struct {
   char** gameBoard; // поле кораблей
   char** HitsBoard; // поле выстрелов
   int numHits;      // количество попаданий
} Board;

typedef struct Coord {
   int x;
   int y;
} Coord;


/**
 * @brief функция для запуска игры "Морской бой"
*/
void SeaBattleStartGame();

/**
 * @brief функция для реализации игры "Морской бой"
 * @param player_1 данные о первом игроке
 * @param player_2 данные о втором игроке
*/
void SeaBattlePlayGame(Board* player_1, Board* player_2);

/**
 * @brief функция для создания игрового поля для игры "Морской бой"
 * @return игровое поле для игры "Морской бой"
*/
char** createBoard();

/**
 * @brief функция для печати игрового поля
 * @param gameBoard игровое поле
*/
void printBoard(const char** gameBoard);

/**
 * @brief функция для установки на поле корабля размером 1х1
 * @param board игровое поле
*/
void placeShip1x1(char** board);

/**
 * @brief функция для установки на поле корабля размером 1х2
 * @param board игровое поле
*/
void placeShip1x2(char** board);

/**
 * @brief функция для установки на поле корабля размером 1х3
 * @param board игровое поле
*/
void placeShip1x3(char** board);

/**
 * @brief функция для установки на поле корабля размером 1х4
 * @param board игровое поле
*/
void placeShip1x4(char** board);

/**
 * @brief функция для установки на поле всех кораблей которые требуются по правилам игры (4 корабля по
 одной клеточке, 3 корабля по 2 клеточки, 2 — по 3 клеточки и один — четырехпалубный)
 * @param board игровое поле
*/
void placeAllShip(char** board);

/**
 * @brief функция для получения координат для установки кораблей (учитывается проверка на правильность координат и
 и не стоит ли уже корабль на этом месте)
 * @param board игрове поле
 * @return cтруктура с координатами
*/
Coord getCoordinateForShips(const char** board);

/**
 * @brief функция для получения координат для установки выстрела (учитывается проверка на правильность координат)
 * @return cтруктура с координатами
*/
Coord getCoordinateForHits();

/**
 * @brief функция для проверки координат на правильность (не выходят ли они за пределы поля)
 * @param x координата х
 * @param y координата у
 * @return true если координаты верны, false иначе
*/
bool chekCoordinate(const int x, const int y);

/**
 * @brief функция для проверки уничтожен ли корабль
 * @param board игровое поле
 * @param x координата х
 * @param y координата у
 * @return true если корабль уничтожен, false иначе
*/
bool checkDestroy(const Board* board, const int x, const int y);

/**
 * @brief функция для проверки попадания
 * @param AttackingPlayer аткакующий игрок
 * @param AttackedPlayer атакованный игрок
 * @param x координата выстрела по х
 * @param y координата выстрела по у
 * @return true если игрок попал, false иначе
*/
bool checkHits(Board* AttackingPlayer, Board* AttackedPlayer, const int x, const int y);

/**
 * @brief функция для проверки, что нет кораблей рядом (проверка наличия кораблей вокруг клетки, если вокруг есть хотя бы одна клетка с занятым значением, значит есть корабль рядом)
 * @param board игровое поле
 * @param x координата по х
 * @param y координата по у
 * @return true - если кораблей нет рядом, false - если есть корабль рядом
*/
bool checkNoShipsNearby(const char** board, const int x, const int y);