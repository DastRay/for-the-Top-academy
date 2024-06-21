#pragma once

/**
 * @brief функция для генерации псевдослучайного числа длины size
 * @param size длина псевдослучайного числа
 * @return псевдослучайное число в массиве
*/
int* generationRandomNumber(int size);

/**
 * @brief функция по считыванию числа в динамический массив
 * @param size длина числа
 * @return считанное число в динамическом массиве
*/
int* readNumArray(int size);

/**
 * @brief запуск игры <Быки и коровы>
*/
void startGameBullsAndCows();

/**
* @brief игра <Быки и коровы>
* @param num_hidden загаданное число
* @param size длина загаданного числа
*/
void PlayBullsAndCows(int* num_hidden, int size);