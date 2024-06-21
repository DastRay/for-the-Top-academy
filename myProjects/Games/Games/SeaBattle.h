#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 10         // ������ �������� ����
#define COUNT_HITS_FOR_WIN 16 // ���������� �������� ������� ���������


// ��������� ��� �������� ���������� �� ������
typedef struct {
   char** gameBoard; // ���� ��������
   char** HitsBoard; // ���� ���������
   int numHits;      // ���������� ���������
} Board;

typedef struct Coord {
   int x;
   int y;
} Coord;


/**
 * @brief ������� ��� ������� ���� "������� ���"
*/
void SeaBattleStartGame();

/**
 * @brief ������� ��� ���������� ���� "������� ���"
 * @param player_1 ������ � ������ ������
 * @param player_2 ������ � ������ ������
*/
void SeaBattlePlayGame(Board* player_1, Board* player_2);

/**
 * @brief ������� ��� �������� �������� ���� ��� ���� "������� ���"
 * @return ������� ���� ��� ���� "������� ���"
*/
char** createBoard();

/**
 * @brief ������� ��� ������ �������� ����
 * @param gameBoard ������� ����
*/
void printBoard(const char** gameBoard);

/**
 * @brief ������� ��� ��������� �� ���� ������� �������� 1�1
 * @param board ������� ����
*/
void placeShip1x1(char** board);

/**
 * @brief ������� ��� ��������� �� ���� ������� �������� 1�2
 * @param board ������� ����
*/
void placeShip1x2(char** board);

/**
 * @brief ������� ��� ��������� �� ���� ������� �������� 1�3
 * @param board ������� ����
*/
void placeShip1x3(char** board);

/**
 * @brief ������� ��� ��������� �� ���� ������� �������� 1�4
 * @param board ������� ����
*/
void placeShip1x4(char** board);

/**
 * @brief ������� ��� ��������� �� ���� ���� �������� ������� ��������� �� �������� ���� (4 ������� ��
 ����� ��������, 3 ������� �� 2 ��������, 2 � �� 3 �������� � ���� � ���������������)
 * @param board ������� ����
*/
void placeAllShip(char** board);

/**
 * @brief ������� ��� ��������� ��������� ��� ��������� �������� (����������� �������� �� ������������ ��������� �
 � �� ����� �� ��� ������� �� ���� �����)
 * @param board ������ ����
 * @return c�������� � ������������
*/
Coord getCoordinateForShips(const char** board);

/**
 * @brief ������� ��� ��������� ��������� ��� ��������� �������� (����������� �������� �� ������������ ���������)
 * @return c�������� � ������������
*/
Coord getCoordinateForHits();

/**
 * @brief ������� ��� �������� ��������� �� ������������ (�� ������� �� ��� �� ������� ����)
 * @param x ���������� �
 * @param y ���������� �
 * @return true ���� ���������� �����, false �����
*/
bool chekCoordinate(const int x, const int y);

/**
 * @brief ������� ��� �������� ��������� �� �������
 * @param board ������� ����
 * @param x ���������� �
 * @param y ���������� �
 * @return true ���� ������� ���������, false �����
*/
bool checkDestroy(const Board* board, const int x, const int y);

/**
 * @brief ������� ��� �������� ���������
 * @param AttackingPlayer ���������� �����
 * @param AttackedPlayer ����������� �����
 * @param x ���������� �������� �� �
 * @param y ���������� �������� �� �
 * @return true ���� ����� �����, false �����
*/
bool checkHits(Board* AttackingPlayer, Board* AttackedPlayer, const int x, const int y);

/**
 * @brief ������� ��� ��������, ��� ��� �������� ����� (�������� ������� �������� ������ ������, ���� ������ ���� ���� �� ���� ������ � ������� ���������, ������ ���� ������� �����)
 * @param board ������� ����
 * @param x ���������� �� �
 * @param y ���������� �� �
 * @return true - ���� �������� ��� �����, false - ���� ���� ������� �����
*/
bool checkNoShipsNearby(const char** board, const int x, const int y);