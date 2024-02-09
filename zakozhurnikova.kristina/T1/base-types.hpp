#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace zakozhurnikova
{
  struct point_t
  {
    point_t() :
      x(0.0),
      y(0.0)
    {}
    point_t(double x, double y) :
      x(x),
      y(y)
    {}
    point_t(const point_t& p) :
      x(p.x),
      y(p.y)
    {}
    point_t(point_t&& p) = default;
    ~point_t()
    {}
    double getX() const
    {
      return x;
    }
    double getY() const
    {
      return y;
    }
    point_t scaleShift(double k, const point_t& p);
    double getDistance(const point_t& p) const;
    void operator+=(const point_t& p);
    void operator-=(const point_t& p);
    point_t operator+(const point_t& p) const;
    point_t operator*(double k) const;
    point_t operator/(double k) const;
    point_t operator-(const point_t& p) const;
    point_t& operator-();
    point_t& operator=(const point_t& point);
    point_t& operator=(point_t&& point);

    private:
      double x;
      double y;
  };

  struct rectangle_t
  {
    rectangle_t() = delete;
    rectangle_t(double width, double height, const point_t& pos) :
      width(width),
      height(height),
      pos(pos)
    {}
    rectangle_t(const rectangle_t& rec):
      width(rec.width),
      height(rec.height),
      pos(rec.pos)
    {}
    rectangle_t(rectangle_t&& rec) = default;
    ~rectangle_t()
    {}
    void showCoordinates() const;
    void showSquareCoords() const;
    point_t getCenter() const;
  private:
    double width;
    double height;
    point_t pos;
  };
}
#endif
