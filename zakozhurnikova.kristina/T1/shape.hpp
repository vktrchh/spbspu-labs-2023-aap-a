#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle : public Shape
{
public:
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(const point_t& p);
  void move(double dx, double dy);
  void scale(double k);
private:
  point_t downLeft_;
  point_t upRight_;
};
#endif
