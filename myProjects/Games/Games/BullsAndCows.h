#pragma once

/**
 * @brief ������� ��� ��������� ���������������� ����� ����� size
 * @param size ����� ���������������� �����
 * @return ��������������� ����� � �������
*/
int* generationRandomNumber(int size);

/**
 * @brief ������� �� ���������� ����� � ������������ ������
 * @param size ����� �����
 * @return ��������� ����� � ������������ �������
*/
int* readNumArray(int size);

/**
 * @brief ������ ���� <���� � ������>
*/
void startGameBullsAndCows();

/**
* @brief ���� <���� � ������>
* @param num_hidden ���������� �����
* @param size ����� ����������� �����
*/
void PlayBullsAndCows(int* num_hidden, int size);