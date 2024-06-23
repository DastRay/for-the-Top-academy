#include <locale>

#include "Sapper.h"

int main()
{
   setlocale(LC_ALL, "Russian");

   Sapper sapper;
   sapper.game();

   return 0;
}