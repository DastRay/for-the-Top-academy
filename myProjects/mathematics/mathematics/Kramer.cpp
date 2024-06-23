#include "Kramer.h"

/**
 * @brief ������� ������� �������� �������������� ��������� (����) ������� �������.
 */
void Kramer::decision()
{
   cout << "������� ���������� �����������: ";
   cin >> unknown;
   cout << endl;

   A.resize(unknown, vector<double>(unknown));
   B.resize(unknown);

   readSLAY();
   Matrix<double> matrixA(A);

   cout << "----- ������� ���� ������� ������� -----\n\n����������� ������� AB:" << endl;
   printSLAY();
   const double det = matrixA.determinant();

   if (det == 0)
   {
      cout << "������������ ����� ����, ���� ����� ����������� ���������� ������� ��� �� ����� �������.\n\
�������������� ������ �������� ��� �������" << endl;
      return;
   }

   cout << "������������ ������� � �����: " << det << "\n" << endl;
   vector<double> result(unknown);

   for (int i = 0; i < unknown; i++)
   {
      Matrix<double> copyA = matrixA;
      copyA.replaceColumn(i, B);
      cout << "������ " << i + 1 << ":" << endl;
      cout << copyA << endl;

      const double detDelta = copyA.determinant();
      cout << "������������ ����� " << i + 1 << " = " << detDelta << "\n" << endl;
      result[i] = detDelta / det;
   }

   cout << "������� �������:" << endl;
   for (size_t i = 0; i < unknown; i++)
   {
      cout << "x[" << i + 1 << "] = " << result[i] << endl;
   }
}

/**
 * @brief ��������� ������������ � ��������� ����� ���� � �������.
 */
void Kramer::readSLAY()
{
   cout << "������� ����������� ���� (A) � ������� ��������� ������ (B):" << endl;
   for (size_t i = 0; i < unknown; i++)
   {
      for (size_t j = 0; j < unknown; j++)
      {
         cout << "A[" << i + 1 << "][" << j + 1 << "]: ";
         cin >> A[i][j];
      }
      
      cout << "B[" << i + 1 << "]: ";
      cin >> B[i];
   }

   cout << endl;
}

/**
 * @brief ������� ����������� ������� A|B �� �������.
 */
void Kramer::printSLAY()
{
   cout << fixed << setprecision(3);
   for (int i = 0; i < unknown; i++)
   {
      for (int j = 0; j < unknown; j++)
      {
         cout << setw(8) << "  " << A[i][j];
      }
      cout << setw(8) << "| " << B[i] << endl;
   }
   cout << endl;
}