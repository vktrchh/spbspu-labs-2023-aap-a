#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

struct point_t
{
  point_t() :
    x_(0.0),
    y_(0.0)
  {}
  point_t(double x, double y) :
    x_(x),
    y_(y)
  {}
  point_t(const point_t& p) :
    x_(p.x_),
    y_(p.y_)
  {}
  ~point_t()
  {}
  double getX() const
  {
    return x_;
  }
  double getY() const
  {
    return y_;
  }

  private:
    double x_;
    double y_;
};
