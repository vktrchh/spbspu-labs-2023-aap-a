#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

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

class Square: public Shape
{
public:
  Square(point_t a, double side)
  {
    side_ = side;
    pos_sq_.x_ = a.x_ + (side_ / 2.0);
    pos_sq_.y_ = a.y_ + (side_ / 2.0);
  }
  virtual double getArea()
  {
    return side_ * side_;
  }
  virtual rectangle_t getFrameRect()
  {
    rectangle_t newRect{ side_, side_, pos_sq_ };
    return newRect;
  }
  virtual void move(point_t s)
  {
    pos_sq_.x_ = s.x_;
    pos_sq_.y_ = s.y_;
  }
  virtual void move(double x, double y)
  {
    pos_sq_.x_ += x;
    pos_sq_.y_ += y;
  }
  virtual rectangle_t scale(point_t s, double k)
  {
    point_t point{ pos_sq_.x_, pos_sq_.y_ };
    move(s);
    side_ = side_ * k;
    std::cout << "IN SQUARE: SIDE: " << side_ << '\n';
    point_t new_pos{ pos_sq_.x_ - k * (pos_sq_.x_ - point.x_), pos_sq_.y_ - k * (pos_sq_.y_ - point.y_) };
    move(new_pos);
    rectangle_t newRect{ side_, side_, pos_sq_ };
    return newRect;
  }

private:
  double side_;
  point_t pos_sq_;
};

class Triangle: public Shape
{
public:
  Triangle(point_t point1, point_t point2, point_t point3)
  {
    pos_tri_.x_ = (point1.x_ + point2.x_ + point3.x_) / 3.0;
    pos_tri_.y_ = (point1.y_ + point2.y_ + point3.y_) / 3.0;
    double max_x = std::max({point1.x_, point2.x_, point3.x_});
    double min_x = std::min({point1.x_, point2.x_, point3.x_});
    double max_y = std::max({point1.y_, point2.y_, point3.y_});
    double min_y = std::min({point1.y_, point2.y_, point3.y_});
    std::cout << "MAX: x: " << max_x << " y: " << max_y << " MIN: x: " << min_x << " MIN: y: " << min_y << '\n';
    height_tri_ = max_y - min_y;
    width_tri_ = max_x - min_x;
    std::cout << "HEIGHT: " << height_tri_ << " WIDTH: " << width_tri_ << '\n';
    pos_.x_ = min_x + (width_tri_ / 2.0);
    pos_.y_ = min_y + (height_tri_ / 2.0);
  }
  virtual double getArea()
  {
    return height_tri_ * width_tri_;
  }
  virtual rectangle_t getFrameRect()
  {
    rectangle_t newRect{ height_tri_, width_tri_, pos_ };
    return newRect;
  }
  virtual void move(point_t s)
  {
    pos_tri_.x_ = s.x_;
    pos_tri_.y_ = s.y_;
  }
  virtual void move(double x, double y)
  {
    pos_tri_.x_ += x;
    pos_tri_.y_ += y;
  }
  virtual rectangle_t scale(point_t s, double k)
  {
    point_t point{ pos_tri_.x_, pos_tri_.y_ };
    move(s);
    height_tri_ = height_tri_ * k;
    width_tri_ = width_tri_ * k;
    std::cout << "IN TRI: HEIGHT: " << height_tri_ << "   WIDTH: " << width_tri_ << '\n';
    point_t new_pos{ pos_tri_.x_ - k * (pos_tri_.x_ - point.x_), pos_tri_.y_ - k * (pos_tri_.y_ - point.y_) };
    move(new_pos);
    rectangle_t newRect{ height_tri_, width_tri_, pos_tri_ };
    return newRect;
  }
private:
  double height_tri_;
  double width_tri_;
  point_t pos_tri_;
  point_t pos_;
};

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

  std::cout << "TEST_2:\n";
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

  std::cout << "\nTEST_3:\n";
  Shape *third = new Square({ -2.0, -2.0 }, 4.0);
  std::cout << "Area: " << third->getArea() << '\n';
  rectangle_t frame2 = third->getFrameRect();
  std::cout << "Frame.x: " << frame2.pos_.x_ << '\n';
  std::cout << "Frame.y: " << frame2.pos_.y_ << '\n';
  rectangle_t sc2 = third->scale({ 0.0, 0.0 }, 2.0);
  double scale2_x = sc2.pos_.x_;
  double scale2_y = sc2.pos_.y_;
  double side = sc2.height_;
  std::cout << "S: " << side << '\n';
  std::cout << "Scale: x: " << scale2_x << "  y: " << scale2_y << '\n';
  std::cout << (scale2_x - (side / 2.0)) << ' ' << (scale2_y - (side / 2.0)) << '\n';
  std::cout << (scale2_x + (side / 2.0)) << ' ' << (scale2_y + (side / 2.0)) << '\n';

  std::cout << "\nTEST_4:\n";
  Shape *four = new Triangle({ -2.0, 0.0 }, {-1.5, 2.5}, {-1.0, -2.0});
  std::cout << "Area: " << four->getArea() << '\n';
  rectangle_t frame3 = four->getFrameRect();
  std::cout << "Frame.x: " << frame3.pos_.x_ << '\n';
  std::cout << "Frame.y: " << frame3.pos_.y_ << '\n';
  rectangle_t sc3 = four->scale({ 0.0, 0.0 }, 2.0);
  double scale3_x = sc3.pos_.x_;
  double scale3_y = sc3.pos_.y_;
  double h4 = sc3.height_;
  double w4 = sc3.width_;
  std::cout << "H: " << h4 << " W: " << w4 << '\n';
  std::cout << "Scale: x: " << scale3_x << "  y: " << scale3_y << '\n';
  std::cout << (scale3_x - (w4 / 2.0)) << ' ' << (scale3_y - (h4 / 2.0)) << '\n';
  std::cout << (scale3_x + (w4 / 2.0)) << ' ' << (scale3_y + (h4 / 2.0)) << '\n';

  std::cout << "\nTEST_NUMBERS:\n";
  std::cout << "3.46 -> " << round(3.46 * 10) / 10 << '\n';
  std::cout << "3.44 -> " << round(3.44 * 10) / 10 << '\n';
  std::cout << "3.45 -> " << round(3.45 * 10) / 10 << '\n';
  std::cout << "3.4 -> " << round(3.4 * 10) / 10 << '\n';
  double f = 3.0;
  std::cout << "3.0 -> " << std::fixed << std::setprecision(1) << f << '\n';
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
