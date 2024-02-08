#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include <stdexcept>

namespace zakozhurnikova
{

  class Rectangle : public Shape
  {
  public:
    Rectangle() = delete;
    Rectangle(const point_t& pointOne, const point_t& pointTwo) :
      downLeft_(pointOne),
      upRight_(pointTwo)
    {
     if (pointOne.getX() >= pointTwo.getX() || pointOne.getY() >= pointTwo.getY())
  {
    throw std::invalid_argument("Invalid rectangle parameters");
  }
    }
    Rectangle(const Rectangle& rec):
      downLeft_(rec.downLeft_),
      upRight_(rec.upRight_)
    {}
    Rectangle(Rectangle&& rec) = default;
    ~Rectangle()
    {}
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t& p);
    void move(double dx, double dy);
    void scale(double k);

  private:
    point_t downLeft_;
    point_t upRight_;
  };
}
#endif
