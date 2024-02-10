#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"
#include "geometryFunc.hpp"
#include <limits>
#include <stdexcept>
namespace zakozhurnikova
{
  class Diamond : public Shape
  {
  public:
    Diamond() = delete;
    Diamond(const point_t& pointOne, const point_t& pointTwo, const point_t& pointThree) :
      pointOne_(point_t()),
      pointTwo_(point_t()),
      center_(point_t())
    {
      const double EPSILON = 1e-6;
      point_t points[3]{};
      initPoints(points, pointOne, pointTwo, pointThree);
      center_ = points[0];
      pointOne_ = points[1];
      pointTwo_ = points[2];
      const bool CONDITION = ((std::abs(center_.x - pointOne_.x) <= EPSILON) && (std::abs(center_.y - pointTwo_.y) <= EPSILON)) ||
        ((std::abs(center_.x - pointTwo_.x) <= EPSILON) && (std::abs(center_.y - pointOne_.y) <= EPSILON));
      if (!CONDITION)
      {
        throw std::invalid_argument("These points do not define a diamond");
      }
    }
    Diamond(const Diamond& di) :
      pointOne_(di.pointOne_),
      pointTwo_(di.pointTwo_),
      center_(di.center_)
    {}
    Diamond(Diamond&& sq) = default;
    ~Diamond()
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
