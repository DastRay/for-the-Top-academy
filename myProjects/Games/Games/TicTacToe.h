#include <stdbool.h>
#pragma once

/**
 * @brief функция для создания игрового поля
 * @param size размер игрового поля
 * @return игровое поле
*/
char** creatField(const unsigned int size);

/**
 * @brief функция для печати игрового поля
 * @param field игровое поле
 * @param size размер игрового поля
*/
void printGameField(const char** field, const int unsigned size);

/** 
 * @brief меню игры "Крестики нолики" 
*/
void TicTacToeGameMenu();

/**
 * @brief запуск игры "Крестики нолики" 
 * @param field игровое поле
 * @param size размер игрового поля
*/
void startGame(char** field, const unsigned int size);

/** 
* @brief  функция для проверки окончания игры "Крестики нолики" 
 * @param field игровое поле
 * @param size размер игрового поля
* @return окончена игра или нет
*/
bool checkField(const char** field, const unsigned int size);