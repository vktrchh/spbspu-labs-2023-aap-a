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
  virtual void move(point_t s) = 0;
  virtual void move(double x, double y) = 0;
  virtual rectangle_t scale(point_t s, double k) = 0;
};

class Rectangle: public Shape
{
public:
  Rectangle(point_t a, point_t b)
  {
    height = b.y_ - a.y_;
    width = b.x_ - a.x_;
    pos.x_ = (a.x_ + b.x_) / 2.0;
    pos.y_ = (a.y_ + b.y_) / 2.0;
  }
  virtual double getArea()
  {
    return height * width;
  }
  virtual rectangle_t getFrameRect()
  {
    rectangle_t newRect{ height, width, pos };
    return newRect;
  }
  virtual void move(point_t s)
  {
    pos.x_ = s.x_;
    pos.y_ = s.y_;
  }
  virtual void move(double x, double y)
  {
    pos.x_ += x;
    pos.y_ += y;
  }
  virtual rectangle_t scale(point_t s, double k)
  {
    point_t point{ pos.x_, pos.y_ };
    move(s);
    height = height * k;
    width = width * k;
    point_t new_pos{ pos.x_ - k * (pos.x_ - point.x_), pos.y_ - k * (pos.y_ - point.y_) };
    move(new_pos);
    rectangle_t newRect{ height, width, pos };
    return newRect;
  }
private:
  double height;
  double width;
  point_t pos;
};

int main()
{
  std::string array[1000] = {};
//-----------
  Rectangle* first = new Rectangle({ 1.0, 1.0 }, { 3.0, 4.0 });
  std::cout << first->getArea() << '\n';
  first->move({ 3.0, 5.0 });
  std::cout << first->getFrameRect().pos_.x_ << '\n';
  first->move(2.0, 1.0);
  std::cout << first->getFrameRect().pos_.x_ << '\n';
  std::cout << first->scale({ 5.0, 2.0 }, 2.0).pos_.y_ << '\n';
//-----------
  size_t counter = 0;
  while (counter != 1000)
  {
    std::string filler = "";
    std::cin >> filler;
    array[counter] = filler;
    std::cout << "Test: filler: " << filler << "  array: " << array[counter] << "  counter: " << counter << '\n';
    if (filler == "SCALE")
    {
      break;
    }
    counter += 1;
  }
  std::cout << array[counter] << '\n';
  std::cout << counter << '\n';

}
