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
    rectangle_t newRect{height_rect_, width_rect_, pos_rect_};
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
    point_t point{pos_rect_.x_, pos_rect_.y_};
    move(s);
    height_rect_ = height_rect_ * k;
    width_rect_ = width_rect_ * k;
    move(k * (point.x_ - pos_rect_.x_), k * (point.y_ - pos_rect_.y_));
    rectangle_t newRect{height_rect_, width_rect_, pos_rect_};
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
    rectangle_t newRect{side_, side_, pos_sq_};
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
    point_t point{pos_sq_.x_, pos_sq_.y_};
    move(s);
    side_ = side_ * k;
    move(k * (point.x_ - pos_sq_.x_), k * (point.y_ - pos_sq_.y_));
    rectangle_t newRect{side_, side_, pos_sq_};
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
    p1_.x_ = point1.x_;
    p1_.y_ = point1.y_;
    p2_.x_ = point2.x_;
    p2_.y_ = point2.y_;
    p3_.x_ = point3.x_;
    p3_.y_ = point3.y_;
    pos_tri_.x_ = (point1.x_ + point2.x_ + point3.x_) / 3.0;
    pos_tri_.y_ = (point1.y_ + point2.y_ + point3.y_) / 3.0;
    double max_x = std::max({point1.x_, point2.x_, point3.x_});
    double min_x = std::min({point1.x_, point2.x_, point3.x_});
    double max_y = std::max({point1.y_, point2.y_, point3.y_});
    double min_y = std::min({point1.y_, point2.y_, point3.y_});
    height_tri_ = max_y - min_y;
    width_tri_ = max_x - min_x;
    pos_.x_ = min_x + (width_tri_ / 2.0);
    pos_.y_ = min_y + (height_tri_ / 2.0);
  }
  virtual double getArea()
  {
    return 0.5 * (std::abs ((p2_.x_ - p1_.x_) * (p3_.y_ - p1_.y_) - (p3_.x_ - p1_.x_) * (p2_.y_ - p1_.y_)));
  }
  virtual rectangle_t getFrameRect()
  {
    rectangle_t newRect{height_tri_, width_tri_, pos_};
    return newRect;
  }
  virtual void move(point_t s)
  {
    pos_tri_.x_ = s.x_;
    pos_tri_.y_ = s.y_;
  }
  virtual void move(double x, double y)
  {
    pos_.x_ += x;
    pos_.y_ += y;
    p1_.x_ += x;
    p1_.y_ += y;
    p2_.x_ += x;
    p2_.y_ += y;
    p3_.x_ += x;
    p3_.y_ += y;
  }
  virtual rectangle_t scale(point_t s, double k)
  {
    point_t point{pos_tri_.x_, pos_tri_.y_};
    move(s);
    height_tri_ = height_tri_ * k;
    width_tri_ = width_tri_ * k;
    move(k * (point.x_ - pos_tri_.x_), k * (point.y_ - pos_tri_.y_));
    rectangle_t newRect{height_tri_, width_tri_, pos_};
    return newRect;
  }
private:
  point_t p1_;
  point_t p2_;
  point_t p3_;
  double height_tri_;
  double width_tri_;
  point_t pos_tri_;
  point_t pos_;
};

class Diamond: public Shape
{
public:
  Diamond(point_t central, point_t side_x, point_t side_y)
  {
    height_diam_ = std::abs (side_y.y_ - central.y_);
    width_diam_ = std::abs (side_x.x_ - central.x_);
    pos_diam_.x_ = central.x_;
    pos_diam_.y_ = central.y_;
  }
  virtual double getArea()
  {
    return (0.5 * height_diam_ * width_diam_);
  }
  virtual rectangle_t getFrameRect()
  {
    rectangle_t newRect{height_diam_, width_diam_, pos_diam_};
    return newRect;
  }
  virtual void move(point_t s)
  {
    pos_diam_.x_ = s.x_;
    pos_diam_.y_ = s.y_;
  }
  virtual void move(double x, double y)
  {
    pos_diam_.x_ += x;
    pos_diam_.y_ += y;
  }
  virtual rectangle_t scale(point_t s, double k)
  {
    point_t point{pos_diam_.x_, pos_diam_.y_};
    move(s);
    height_diam_ = height_diam_ * k;
    width_diam_ = width_diam_ * k;
    move(k * (point.x_ - pos_diam_.x_), k * (point.y_ - pos_diam_.y_));
    rectangle_t newRect{ height_diam_, width_diam_, pos_diam_ };
    return newRect;
  }
private:
  double height_diam_;
  double width_diam_;
  point_t pos_diam_;
};


bool isCentralPoint(point_t point1, point_t point2, point_t point3)
{
  if (((point1.x_ == point2.x_) && (point1.y_ == point3.y_)) || ((point1.x_ == point3.x_) && (point1.y_ == point2.y_)))
  {
    return true;
  }
  return false;
}

point_t defineSidePointX(point_t point1, point_t point2, point_t point3)
{
  if (point1.x_ == point2.x_)
  {
    return point3;
  }
  else
  {
    return point2;
  }
}

point_t defineSidePointY(point_t point1, point_t point2, point_t point3)
{
    if (point1.y_ == point2.y_)
  {
    return point3;
  }
  else
  {
    return point2;
  }
}

void outputResult(std::ostream & output, Shape ** array, size_t counter)
{
  double sum_area = 0.0;
  for (size_t i = 0; i < counter; ++i)
  {
    sum_area += array[i]->getArea();
  }
  output << std::fixed << std::setprecision(1) << sum_area;
  for (size_t i = 0; i < counter; ++i)
  {
    rectangle_t frame = array[i]->getFrameRect();
    double height = frame.height_;
    double width = frame.width_;
    double pos_x = frame.pos_.x_;
    double pos_y = frame.pos_.y_;
    output << ' ' << round((pos_x - (width / 2.0)) * 10) / 10 << ' ' << round((pos_y - (height / 2.0)) * 10) / 10;
    output << ' ' << round((pos_x + (width / 2.0)) * 10) / 10 << ' ' << round((pos_y + (height / 2.0)) * 10) / 10;
  }
  output << '\n';
}

int main()
{
  Shape * array[1000] = {};
  size_t counter = 0;
  int error_flag = 0;

  while (counter != 1000)
  {
    std::string name = "";
    std::cin >> name;
    if (name == "SCALE")
    {
      double center_x = 0.0, center_y = 0.0, index = 0.0;
      std::cin >> center_x >> center_y >> index;
      if (index <= 0.0)
      {
        std::cerr << "Incorrect scale index\n";
        return 1;
      }

      if (counter != 0)
      {
        outputResult(std::cout, array, counter);
        for (size_t i = 0; i < counter; ++i)
        {
          array[i]->scale({center_x, center_y}, index);
        }
        outputResult(std::cout, array, counter);

        if (error_flag == 1)
        {
          std::cerr << "Some figure has wrong parameters\n";
        }
      }
      break;
    }
    if (!std::cin)
    {
      std::cerr << "No SCALE command entered\n";
      return 1;
    }

    if (name == "RECTANGLE")
    {
      double low_left_x = 0.0, low_left_y = 0.0, up_right_x = 0.0, up_right_y = 0.0;
      std::cin >> low_left_x >> low_left_y >> up_right_x >> up_right_y;
      if ((low_left_x == up_right_x) || (low_left_y == up_right_y))
      {
        error_flag = 1;
        std::cout << "RECT ERROR\n";
      }
      else if (((low_left_x > up_right_x) && (low_left_y < up_right_y)) || ((low_left_y > up_right_y) && (low_left_x < up_right_x)))
      {
        error_flag = 1;
      }
      else
      {
        if (low_left_x > up_right_x)
        {
          double x1 = low_left_x, x2 = up_right_x;
          low_left_x = x2;
          up_right_x = x1;
        }
        if (low_left_y > up_right_y)
        {
          double y1 = low_left_y, y2 = up_right_y;
          low_left_y = y2;
          up_right_y = y1;
        }
        array[counter++] = new Rectangle({low_left_x, low_left_y}, {up_right_x, up_right_y});
      }
    }

    if (name == "SQUARE")
    {
      double low_left_x = 0.0, low_left_y = 0.0, side = 0.0;
      std::cin >> low_left_x >> low_left_y >> side;
      if (side <= 0.0)
      {
        error_flag = 1;
      }
      else
      {
        array[counter++] = new Square({low_left_x, low_left_y}, side);
      }
    }

    if (name == "TRIANGLE")
    {
      double point1_x = 0.0, point1_y = 0.0, point2_x = 0.0, point2_y = 0.0, point3_x = 0.0, point3_y = 0.0;
      std::cin >> point1_x >> point1_y >> point2_x >> point2_y >> point3_x >> point3_y;
      if (((point1_x == point2_x) && (point1_y == point2_y)) || ((point2_x == point3_x) && (point2_y == point3_y)) || ((point3_x == point1_x) && (point3_y == point1_y)))
      {
        error_flag = 1;
      }
      else if (((point1_x == point2_x) && (point2_x  == point3_x)) || ((point1_y == point2_y) && (point2_y == point3_y)))
      {
        error_flag = 1;
      }
      else
      {
        array[counter++] = new Triangle({point1_x, point1_y}, {point2_x, point2_y}, {point3_x, point3_y});
      }
    }

    if (name == "DIAMOND")
    {
      double point1_x = 0.0, point1_y = 0.0, point2_x = 0.0, point2_y = 0.0, point3_x = 0.0, point3_y = 0.0;
      std::cin >> point1_x >> point1_y >> point2_x >> point2_y >> point3_x >> point3_y;
      if (((point1_x == point2_x) && (point1_y == point2_y)) || ((point2_x == point3_x) && (point2_y == point3_y)) || ((point3_x == point1_x) && (point3_y == point1_y)))
      {
        error_flag = 1;
      }
      else
      {
        point_t point1 = {0.0, 0.0};
        point_t point2 = {0.0, 0.0};
        point_t point3 = {0.0, 0.0};
        point_t central_point = {0.0, 0.0};
        point_t side_point_x = {0.0, 0.0};
        point_t side_point_y = {0.0, 0.0};
        int flag = 0;

        for (size_t i = 1; i < 4; ++i)
        {
          if (i == 1)
          {
            point1 = {point1_x, point1_y};
            point2 = {point2_x, point2_y};
            point3 = {point3_x, point3_y};
          }
          if (i == 2)
          {
            point1 = {point2_x, point2_y};
            point2 = {point1_x, point1_y};
            point3 = {point3_x, point3_y};
          }
          if (i == 3)
          {
            point1 = {point3_x, point3_y};
            point2 = {point1_x, point1_y};
            point3 = {point2_x, point2_y};
          }
          if (isCentralPoint(point1, point2, point3))
          {
            flag = 1;
            central_point = {point1.x_, point1.y_};
            side_point_x = defineSidePointX(point1, point2, point3);
            side_point_y = defineSidePointY(point1, point2, point3);
          }
        }
        if (flag == 0)
        {
          error_flag = 1;
        }
        else
        {
          array[counter++] = new Diamond(central_point, side_point_x, side_point_y);
        }
      }
    }
  }
}
