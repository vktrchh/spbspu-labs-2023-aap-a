#include <iostream>

struct point_t
{
  double x_;
  double y_;
};

struct rectangle_t
{
  double height_;
  double width_;
  point_t pos_;
};

class Shape
{
  virtual double getArea() = 0;
  virtual rectangle_t getFrameRect() = 0;
  virtual void move1() = 0;
  virtual void move2() = 0;
  virtual rectangle_t scale() = 0;
};

int main()
{
  std::string array[1000] = {};
}
