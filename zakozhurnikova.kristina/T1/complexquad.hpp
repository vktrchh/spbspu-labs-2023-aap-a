#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP
#include "shape.hpp"

namespace zakozhurnikova
{
  class Complexquad : public Shape
  {
  public:
    Complexquad() = delete;
    Complexquad(const point_t& p1, const point_t& p2, const point_t& p3, const point_t& p4) :
      p1_(p1),
      p2_(p2),
      p3_(p3),
      p4_(p4)
    {}
    Complexquad(const Complexquad& comp) :
      p1_(comp.p1_),
      p2_(comp.p2_),
      p3_(comp.p3_),
      p4_(comp.p4_)
    {}
    Complexquad(Complexquad&& comp) = default;
    ~Complexquad()
    {}
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t& p);
    void move(double dx, double dy);
    void scale(double k);
    point_t getCenter() const;
  private:
    point_t p1_;
    point_t p2_;
    point_t p3_;
    point_t p4_;
  };
}
#endif

