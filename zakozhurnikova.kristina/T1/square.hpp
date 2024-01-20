#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "shape.hpp"

class Square : public Shape
{
public:
  Square() = delete;
  Square(const point_t& downLeft, double length) :
    downLeft_(downLeft),
    length_(length)
  {}
  Square(const Square& sq) :
    downLeft_(sq.downLeft_),
    length_(sq.length_)
  {}
  Square(Square&& sq) = default;

  ~Square()
  {}
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(const point_t& p);
  void move(double dx, double dy);
  void scale(double k);
private:
  point_t downLeft_;
  double length_;
};
#endif
