#include <iostream>
#include <iomanip>
#include <string>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "inputShapes.hpp"


int main ()
{
  std::cin >> std::noskipws;
  char * string = inputString(std::cin);
  std::cin >> std::skipws;
  Shape * r1 = inputTriangle(string);
}
