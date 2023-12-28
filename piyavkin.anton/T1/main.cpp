#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "isoscale.hpp"

class Parallelogram : public Shape
{
public:
  Parallelogram(point_t p1, point_t p2, point_t p3) :
    a_(p1),
    b_(p2),
    c_(p3)
  {
    double ab = std::sqrt((a_.x - b_.x) * (a_.x - b_.x) + (a_.y - b_.y) * (a_.y - b_.y));
    double ac = std::sqrt((a_.x - c_.x) * (a_.x - c_.x) + (a_.y - c_.y) * (a_.y - c_.y));
    double bc = std::sqrt((b_.x - c_.x) * (b_.x - c_.x) + (b_.y - c_.y) * (b_.y - c_.y));
    if ((a_.y != c_.y && a_.y != b_.y) || ab >= ac + bc || bc >= ab + ac || ac >= ab + bc)
    {
      throw std::logic_error("It is not parallelogram");
    }
  }
  virtual double getArea()
  {
    double h = std::abs(b_.y - c_.y);
    double a = (a_.y == b_.y) ? std::abs(a_.x - b_.x) : std::abs(a_.x - c_.x);
    return a * h;
  }
  virtual rectangle_t getFrameRect()
  {
    double heigth = std::abs(b_.y - c_.y);
    double width = 2 * ((a_.y == b_.y) ? std::abs(a_.x - b_.x) : std::abs(a_.x - c_.x)) + (c_.x - b_.x);
    point_t pos = { (b_.x + c_.x) / 2, (b_.y + c_.y) / 2 };
    return { width, heigth, pos };
  }
  virtual void move(point_t bias)
  {
    point_t pos = { (b_.x + c_.x) / 2, (b_.y + c_.y) / 2 };
    move(bias.x - pos.x, bias.y - pos.y);
  }
  virtual void move(double dx, double dy)
  {
    a_.x += dx;
    a_.y += dy;
    b_.x += dx;
    b_.y += dy;
    c_.x += dx;
    c_.y += dy;
  }
  virtual void scale(double k)
  {
    point_t pos = { (b_.x + c_.x) / 2, (b_.y + c_.y) / 2 };
    a_.x = k * (a_.x - pos.x) + pos.x;
    a_.y = k * (a_.y - pos.y) + pos.y;
    b_.x = k * (b_.x - pos.x) + pos.x;
    b_.y = k * (b_.y - pos.y) + pos.y;
    c_.x = k * (c_.x - pos.x) + pos.x;
    c_.y = k * (c_.y - pos.y) + pos.y;
  }
private:
  point_t a_;
  point_t b_;
  point_t c_;
};

int main()
{
}
