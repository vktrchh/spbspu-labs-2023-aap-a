#include <iostream>

#include "square.hpp"
#include "rectangle.hpp"
#include "parallelogram.hpp"
#include "diamond.hpp"
#include "isoScale.hpp"

int main()
{
  agarkov::Square sq = agarkov::Square({1, 1}, 2);
  std::cout << sq.left_bottom_.x_ << " " << sq.left_bottom_.y_ << " " << sq.getArea() << "\n";
  sq.scale(3);
  std::cout << sq.left_bottom_.x_ << " " << sq.left_bottom_.y_<< " " << sq.getArea() << "\n";
  agarkov::Rectangle rc = agarkov::Rectangle({1, 1}, {2, 2});
  std::cout << rc.left_bottom_.x_ << " " << rc.left_bottom_.y_ << " " << rc.getArea() << "\n";
  rc.scale(3);
  std::cout << rc.left_bottom_.x_ << " " << rc.left_bottom_.y_<< " " << rc.getArea() << "\n";
  agarkov::Parallelogram pr = agarkov::Parallelogram({1, 1}, {2, 1}, {2, 2});
  std::cout << pr.point1_.x_ << " " << pr.point1_.y_ << " " << pr.getArea() << "\n";
  pr.scale(3);
  std::cout << pr.point1_.x_ << " " << pr.point1_.y_<< " " << pr.getArea() << "\n";
  agarkov::Diamond dm = agarkov::Diamond({0, 0.5}, {1, 0}, {0, 0});
  std::cout << dm.point1_.x_ << " " << dm.point1_.y_ << " " << dm.getArea() << "\n";
  dm.scale(3);
  std::cout << dm.point1_.x_ << " " << dm.point1_.y_<< " " << dm.getArea() << "\n";
  isoScale(&sq, {1,1}, 2);
  std::cout << sq.left_bottom_.x_ << " " << sq.left_bottom_.y_<< " " << sq.getArea() << "\n";
}
