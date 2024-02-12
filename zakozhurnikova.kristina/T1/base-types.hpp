#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
#include <iosfwd>

namespace zakozhurnikova
{
  struct point_t
  {
    double x;
    double y;

    point_t scaleShift(double k, const point_t& p) const;
    double getDistance(const point_t& p) const;
    void operator+=(const point_t& p);
    void operator-=(const point_t& p);
    point_t operator+(const point_t& p) const;
    point_t operator*(double k) const;
    point_t operator/(double k) const;
    point_t operator-(const point_t& p) const;
    point_t& operator-();
    bool operator==(const point_t& p) const;
  };

  struct rectangle_t
  {
    double width;
    double height;
    point_t pos;

    void showCoordinates(std::ostream& out) const;
  };
}
#endif
