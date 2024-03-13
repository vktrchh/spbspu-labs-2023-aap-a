#include <iostream>

#include "square.hpp"

int main()
{
  agarkov::Square sq = agarkov::Square({1, 1}, 1);
  std::cout << sq.left_bottom_.x_ << " " << sq.left_bottom_.y_<< "\n";
  sq.move({1,1});
  std::cout << sq.left_bottom_.x_ << " " << sq.left_bottom_.y_<< "\n";
}
