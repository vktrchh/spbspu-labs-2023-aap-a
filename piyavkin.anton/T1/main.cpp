struct point_t
{
  double x;
  double y;
};

struct rectangle_t
{
  double width;
  double heigth;
  point_t pos;
};

class Shape
{
  public:
    virtual double getArea() = 0;
    virtual rectangle_t getFrameRect() = 0;
    virtual point_t move() = 0;
    virtual void scale() = 0;
};

class Rectangle: public Shape
{
  public:
    Rectangle(point_t p1, point_t p2):
      p1_(p1),
      p2_(p2)
    {}
    virtual double getArea()
    {
      return std::abs((p1_.x - p2_.x) * (p1_.y - p2_.y));
    }
    virtual rectangle_t getFrameRect()
    {
      
    }
  private:
    point_t p1_;
    point_t p2_;
};

int main()
{
  Rectangle rectangle1;
  std::cout << rectangle1.getArea(5, 5);
}
