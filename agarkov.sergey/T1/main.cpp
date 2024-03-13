#include <iostream>

#include "square.hpp"

int main()
{
  agarkov::Square sq = agarkov::Square({1, 1}, 2);
  std::cout << sq.getArea() << "\n";
}
