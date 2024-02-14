#ifndef concave_hpp
#define concave_hpp

#include "shape.hpp"

class Concave : public Shape
{
public:
  Concave(const point_t ver1, const point_t ver2, const point_t ver3, const point_t ver4);
  ~Concave();
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(point_t newPos);
  void move(double x, double y);
  void scale(double k);
  point_t getVer1() const;
  point_t getVer2() const;
  point_t getVer3() const;
  point_t getVer4() const;
private:
  bool isTriangle(point_t first, point_t second, point_t third);
  bool isInsideTriangle(const point_t& A, const point_t& B, const point_t& C, const point_t& D);
  point_t ver1_;
  point_t ver2_;
  point_t ver3_;
  point_t ver4_;
};

#endif
