#pragma once
#include "Matrix.h"

class Kramer
{
private:
   vector<vector<double>> A;
   vector<double> B;
   size_t unknown;

   void readSLAY();
   void printSLAY();

public:
   void decision();
};