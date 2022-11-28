#include <iostream>
#include <ostream>
#include "ElementaryFunction.h"

int main (int argc, char *argv[])
{
  float coefficients[4] = {3,2,1,1};
  ElementaryFunction *polynom = new ElementaryFunction(3);
  polynom->FillPolynom(coefficients);
  polynom->Display();

  delete polynom;
  return 0;
}

