#include "Kramer.h"

/**
 * @brief Решение системы линейных алгебраических уравнений (СЛАУ) методом Крамера.
 */
void Kramer::decision()
{
   cout << "Введите количество неизвестных: ";
   cin >> unknown;
   cout << endl;

   A.resize(unknown, vector<double>(unknown));
   B.resize(unknown);

   readSLAY();
   Matrix<double> matrixA(A);

   cout << "----- Решение СЛАУ методом Крамера -----\n\nРасширенная матрица AB:" << endl;
   printSLAY();
   const double det = matrixA.determinant();

   if (det == 0)
   {
      cout << "Определитель равен нулю, СЛАУ имеет бесконечное количество решений или не имеет решений.\n\
Воспользуйтесь другим способом для решения" << endl;
      return;
   }

   cout << "Определитель матрицы А равен: " << det << "\n" << endl;
   vector<double> result(unknown);

   for (int i = 0; i < unknown; i++)
   {
      Matrix<double> copyA = matrixA;
      copyA.replaceColumn(i, B);
      cout << "Дельта " << i + 1 << ":" << endl;
      cout << copyA << endl;

      const double detDelta = copyA.determinant();
      cout << "Определитель дельа " << i + 1 << " = " << detDelta << "\n" << endl;
      result[i] = detDelta / det;
   }

   cout << "Решение системы:" << endl;
   for (size_t i = 0; i < unknown; i++)
   {
      cout << "x[" << i + 1 << "] = " << result[i] << endl;
   }
}

/**
 * @brief Считывает коэффициенты и свободные члены СЛАУ с консоли.
 */
void Kramer::readSLAY()
{
   cout << "Введите коэффиценты СЛАУ (A) и столбец свободных членов (B):" << endl;
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
 * @brief Выводит расширенную матрицу A|B на консоль.
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