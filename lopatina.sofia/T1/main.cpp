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
public:
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
    height_rect_ = b.y_ - a.y_;
    width_rect_ = b.x_ - a.x_;
    pos_rect_.x_ = (a.x_ + b.x_) / 2.0;
    pos_rect_.y_ = (a.y_ + b.y_) / 2.0;
  }
  virtual double getArea()
  {
    return height_rect_ * width_rect_;
  }
  virtual rectangle_t getFrameRect()
  {
    rectangle_t newRect{ height_rect_, width_rect_, pos_rect_ };
    return newRect;
  }
  virtual void move(point_t s)
  {
    pos_rect_.x_ = s.x_;
    pos_rect_.y_ = s.y_;
  }
  virtual void move(double x, double y)
  {
    pos_rect_.x_ += x;
    pos_rect_.y_ += y;
  }
  virtual rectangle_t scale(point_t s, double k)
  {
    point_t point{ pos_rect_.x_, pos_rect_.y_ };
    move(s);
    height_rect_ = height_rect_ * k;
    width_rect_ = width_rect_ * k;
    std::cout << "IN RECT: HEIGHT: " << height_rect_ << "   WIDTH: " << width_rect_ << '\n';
    point_t new_pos{ pos_rect_.x_ - k * (pos_rect_.x_ - point.x_), pos_rect_.y_ - k * (pos_rect_.y_ - point.y_) };
    move(new_pos);
    rectangle_t newRect{ height_rect_, width_rect_, pos_rect_ };
    return newRect;
  }
private:
  double height_rect_;
  double width_rect_;
  point_t pos_rect_;
};

/*
class Square: public Shape
{
public:
  Square(point_t a, double side)
  {
    side_ = side;
    pos.x =
    pos.y =
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

private:
  double side_;
  point_t pos_sq_;
};
*/

int main()
{
  std::string array[1000] = {};
//-----------
  std::cout << "TEST:\n";
  Shape *first = new Rectangle({ 1.0, 1.0 }, { 3.0, 4.0 });
  std::cout << first->getArea() << '\n';
  first->move({ 3.0, 5.0 });
  std::cout << first->getFrameRect().pos_.x_ << '\n';
  first->move(2.0, 1.0);
  std::cout << first->getFrameRect().pos_.x_ << '\n';

  std::cout << "TEST2:\n";
  Shape *second = new Rectangle({ -1.0, -1.0 }, { 1.0, 1.0 });
  std::cout << "Area: " << second->getArea() << '\n';
  rectangle_t frame = second->getFrameRect();
  std::cout << "Frame.x: " << frame.pos_.x_ << '\n';
  std::cout << "Frame.y: " << frame.pos_.y_ << '\n';
  rectangle_t sc = second->scale({ 0.0, 0.0 }, 2.0);
  double scale_x = sc.pos_.x_;
  double scale_y = sc.pos_.y_;
  double height = sc.height_;
  double width = sc.width_;
  std::cout << "H: " << height << "  W: " << width << '\n';
  std::cout << "Scale: x: " << scale_x << "  y: " << scale_y << '\n';
  std::cout << (scale_x - (width / 2.0)) << ' ' << (scale_y - (height / 2.0)) << '\n';
  std::cout << (scale_x + (width / 2.0)) << ' ' << (scale_y + (height / 2.0)) << '\n';

  std::cout << "------\n";
//-----------
  size_t counter = 0;
  while (counter != 1000)
  {
    std::string filler = "";
    std::cin >> filler;
    //array[counter] = filler;
    std::cout << "Test: filler: " << filler << "  array: " << array[counter] << "  counter: " << counter << '\n';
    if (filler == "SCALE")
    {
      break;
    }
    if (filler == "RECTANGLE")
    {
      double low_left_x = 0, low_left_y = 0, up_right_x = 0, up_right_y = 0;
      std::cin >> low_left_x >> low_left_y >> up_right_x >> up_right_y;
      std::cout << "Test rect: " << low_left_x << ' ' << low_left_y << ' ' << up_right_x << ' ' << up_right_y;
      Rectangle *first = new Rectangle({ low_left_x, low_left_y }, { up_right_x, up_right_y });
    }
    if (filler == "SQUARE")
    {
      double low_left_x = 0, low_left_y = 0, side = 0;
      std::cin >> low_left_x >> low_left_y >> side;
      std::cout << "Test square: " << low_left_x << ' ' << low_left_y << ' ' << side;
    }
    if (filler == "TRIANGLE")
    {
      double point1_x = 0, point1_y = 0, point2_x = 0, point2_y = 0, point3_x = 0, point3_y = 0;
      std::cin >> point1_x >> point1_y >> point2_x >> point2_y >> point3_x >> point3_y;
      std::cout << "Test tri: " <<  point1_x << ' ' << point1_y << ' ' << point2_x << ' ' << point2_y << ' ' << point3_x << ' ' << point3_y;
    }
    if (filler == "DIAMOND")
    {
      double point1_x = 0, point1_y = 0, point2_x = 0, point2_y = 0, point3_x = 0, point3_y = 0;
      std::cin >> point1_x >> point1_y >> point2_x >> point2_y >> point3_x >> point3_y;
      std::cout << "Test diamond: " <<  point1_x << ' ' << point1_y << ' ' << point2_x << ' ' << point2_y << ' ' << point3_x << ' ' << point3_y;
    }
    counter += 1;
  }
  //std::cout << array[counter] << '\n';
  std::cout << counter << '\n';
}
