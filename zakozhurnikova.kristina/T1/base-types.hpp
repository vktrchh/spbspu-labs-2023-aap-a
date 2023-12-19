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
  double getDistance(const point_t& p) const;
  void operator+=(const point_t& p);
  void operator-=(const point_t& p);
  point_t operator+(const point_t& p) const;
  point_t operator*(double k) const;
  point_t operator/(double k) const;
  point_t operator-(const point_t& p) const;

  private:
    double x_;
    double y_;
};

struct rectangle_t
{
  rectangle_t() = delete;
  rectangle_t(double width, double height, const point_t& pos) :
    width_(width),
    height_(height),
    pos_(pos)
  {}
  rectangle_t(const rectangle_t& rec):
    width_(rec.width_),
    height_(rec.height_),
    pos_(rec.pos_)
  {}
  ~rectangle_t()
  {}
  void showCoordinates() const;
private:
  double width_;
  double height_;
  point_t pos_;
};
#endif
