#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "diamond.hpp"

namespace zakozhurnikova
{

  class Diamond : public Shape
  {
  public:
    Square() = delete;
    Square(const point_t& pointOne, const point_t& pointTwo, const point_t& pointThree)
    {
      if (pointOne.getX() != pointTwo.getX() && pointOne.getY() != pointTwo.getY)
      {
        center_(pointOne);
        pointOne_(pointTwo);
        pointTwo_(pointThree);
      }

    }
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
    point_t pointOne_;
    point_t pointTwo_;
    point_t center_;
  };
}
#endif
