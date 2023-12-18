struct point_t
{
  double x;
  double y;
}

struct rectangle_t
{
  double width;
  double heigth;
  point_t pos;
}

class Shape
{
  virtual double getArea() = 0;
  virtual rectangle_t getFrameRect() = 0;
  virtual point_t move() = 0;
  virtual void scale() = 0;
}

int main()
{
}
