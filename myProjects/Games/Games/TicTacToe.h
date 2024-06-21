#include <stdbool.h>
#pragma once

/**
 * @brief ������� ��� �������� �������� ����
 * @param size ������ �������� ����
 * @return ������� ����
*/
char** creatField(const unsigned int size);

/**
 * @brief ������� ��� ������ �������� ����
 * @param field ������� ����
 * @param size ������ �������� ����
*/
void printGameField(const char** field, const int unsigned size);

/** 
 * @brief ���� ���� "�������� ������" 
*/
void TicTacToeGameMenu();

/**
 * @brief ������ ���� "�������� ������" 
 * @param field ������� ����
 * @param size ������ �������� ����
*/
void startGame(char** field, const unsigned int size);

/** 
* @brief  ������� ��� �������� ��������� ���� "�������� ������" 
 * @param field ������� ����
 * @param size ������ �������� ����
* @return �������� ���� ��� ���
*/
bool checkField(const char** field, const unsigned int size);