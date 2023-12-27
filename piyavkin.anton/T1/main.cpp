#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"

class Triangle : public Shape
{
public:
  Triangle(point_t p1, point_t p2, point_t p3) :
    a_(p1),
    b_(p2),
    c_(p3)
  {}
  virtual double getArea()
  {
    double ab_ = std::sqrt((a_.x - b_.x) * (a_.x - b_.x) + (a_.y - b_.y) * (a_.y - b_.y));
    double ac_ = std::sqrt((a_.x - c_.x) * (a_.x - c_.x) + (a_.y - c_.y) * (a_.y - c_.y));
    double bc_ = std::sqrt((b_.x - c_.x) * (b_.x - c_.x) + (b_.y - c_.y) * (b_.y - c_.y));
    double semiperimeter = (ab_ + bc_ + ac_) / 2;
    return std::sqrt(semiperimeter * (semiperimeter - ab_) * (semiperimeter - bc_) * (semiperimeter - ac_));
  }
  virtual rectangle_t getFrameRect()
  {
    double heigth = (std::max(std::max(a_.y, b_.y), c_.y) - std::min(std::min(a_.y, b_.y), c_.y));
    double width = (std::max(std::max(a_.x, b_.x), c_.x) - std::min(std::min(a_.x, b_.x), c_.x));
    return { width, heigth, pos_ };
  }
  virtual void move(point_t bias)
  {
    this->move(bias.x - pos_.x, bias.y - pos_.y);
  }
  virtual void move(double dx, double dy)
  {
    pos_.x += dx;
    pos_.y += dy;
    a_.x += dx;
    a_.y += dy;
    b_.x += dx;
    b_.y += dy;
    c_.x += dx;
    c_.y += dy;
  }
  virtual void scale(double k)
  {
    a_.x = k * (pos_.x - a_.x);
    a_.y = k * (pos_.y - a_.y);
    b_.x = k * (pos_.x - b_.x);
    b_.y = k * (pos_.y - b_.y);
    c_.x = k * (pos_.x - c_.x);
    c_.y = k * (pos_.y - c_.y);
  }
private:
  point_t a_;
  point_t b_;
  point_t c_;
  double heigth_ = (std::max(std::max(a_.y, b_.y), c_.y) - std::min(std::min(a_.y, b_.y), c_.y));
  double width_ = (std::max(std::max(a_.x, b_.x), c_.x) - std::min(std::min(a_.x, b_.x), c_.x));
  point_t pos_ = { std::min(std::min(a_.x, b_.x), c_.x) + width_ / 2, std::min(std::min(a_.y, b_.y), c_.y) + heigth_ / 2 };
};

int main()
{
}
