#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"

class Triangle : public Shape
{
public:
  Triangle(point_t p1, point_t p2, point_t p3);
  virtual double getArea();
  virtual rectangle_t getFrameRect();
  virtual void move(point_t bias);
  virtual void move(double dx, double dy);
  virtual void scale(double k);
private:
  point_t a_;
  point_t b_;
  point_t c_;
  double heigth_ = (std::max(std::max(a_.y, b_.y), c_.y) - std::min(std::min(a_.y, b_.y), c_.y));
  double width_ = (std::max(std::max(a_.x, b_.x), c_.x) - std::min(std::min(a_.x, b_.x), c_.x));
  point_t pos_ = { std::min(std::min(a_.x, b_.x), c_.x) + width_ / 2, std::min(std::min(a_.y, b_.y), c_.y) + heigth_ / 2 };
};

#endif
