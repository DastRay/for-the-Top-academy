#include "Matrix.h"
#include "Kramer.h"

#include<locale>

int main()
{
   setlocale(LC_ALL, "Russian");

   Kramer kramer;
   kramer.decision();

   return 0;
}