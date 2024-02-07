#include "concave.hpp"
#include <stdexcept>

Concave::Concave(const point_t ver1, const point_t ver2, const point_t ver3, const point_t ver4) :
  ver1_(ver1),
  ver2_(ver2),
  ver3_(ver3),
  ver4_(ver4)
{
  if (!isTriangle(ver1_, ver2_, ver3_))
  {
    throw std::invalid_argument("The first three points do not form a triangle.");
  }
  if (!isInsideTriangle(ver1_, ver2_, ver3_, ver4_))
  {
    throw std::invalid_argument("The fourth point is not inside the triangle formed by the first three points.");
  }
}

Concave::~Concave()
{}

double Concave::getArea() const
{
  double area = ((ver2_.x - ver1_.x) * (ver3_.y - ver1_.x)) - ((ver3_.x - ver1_.x) * (ver2_.y - ver1_.y));
  if (area < 0)
  {
    area = area * -0.5;
  }
  else
  {
    area = area * 0.5;
  }
  double secondArea = ((ver4_.x - ver1_.x) * (ver3_.y - ver1_.x)) - ((ver3_.x - ver1_.x) * (ver4_.y - ver1_.y));
  if (secondArea < 0)
  {
    secondArea = secondArea * -0.5;
  }
  else
  {
    secondArea = secondArea * 0.5;
  }
  if ((area - secondArea) < 0)
  {
    return (area - secondArea) * -1.0;
  }
  else
  {
    return (area - secondArea);
  }
};

rectangle_t Concave::getFrameRect() const
{
  double xmin = 0.0;
  double ymin = 0.0;
  double xmax = 0.0;
  double ymax = 0.0;
  if (ver2_.x < xmin) xmin = ver2_.x;
  if (ver2_.x > xmax) xmax = ver2_.x;
  if (ver2_.y < ymin) ymin = ver2_.y;
  if (ver2_.y > ymax) ymax = ver2_.y;

  if (ver3_.x < xmin) xmin = ver3_.x;
  if (ver3_.x > xmax) xmax = ver3_.x;
  if (ver3_.y < ymin) ymin = ver3_.y;
  if (ver3_.y > ymax) ymax = ver3_.y;

  if (ver4_.x < xmin) xmin = ver4_.x;
  if (ver4_.x > xmax) xmax = ver4_.x;
  if (ver4_.y < ymin) ymin = ver4_.y;
  if (ver4_.y > ymax) ymax = ver4_.y;

  return rectangle_t{point_t{xmin + (xmax - xmin) / 2, ymin + (ymax - ymin) / 2} ,(xmax - xmin), (ymax - ymin)};
}

void Concave::move(point_t newPos)
{
  point_t oldPos = ver4_;
  double dx = newPos.x - oldPos.x;
  double dy = newPos.y - oldPos.y;
  ver4_.x += dx;
  ver4_.y += dy;
  ver1_.x += dx;
  ver1_.y += dy;
  ver2_.x += dx;
  ver2_.y += dy;
  ver3_.x += dx;
  ver3_.y += dy;
}

void Concave::move(double x, double y)
{
  ver1_.x += x;
  ver1_.y += y;
  ver2_.x += x;
  ver2_.y += y;
  ver3_.x += x;
  ver3_.y += y;
  ver4_.x += x;
  ver4_.y += y;
}

void Concave::scale(double k)
{
  double centerX = ver4_.x;
  double centerY = ver4_.y;

  ver1_.x = centerX + (ver1_.x - centerX) * k;
  ver1_.y = centerY + (ver1_.y - centerY) * k;

  ver2_.x = centerX + (ver2_.x - centerX) * k;
  ver2_.y = centerY + (ver2_.y - centerY) * k;

  ver3_.x = centerX + (ver3_.x - centerX) * k;
  ver3_.y = centerY + (ver3_.y - centerY) * k;
}

point_t Concave::getVer1() const
{
  return ver1_;
}

point_t Concave::getVer2() const
{
  return ver2_;
}

point_t Concave::getVer3() const
{
  return ver3_;
}

point_t Concave::getVer4() const
{
  return ver4_;
}

bool Concave::isTriangle(point_t first, point_t second, point_t third)
{
  bool is = (((third.x - first.x) / (second.x - first.x)) != ((third.y - first.y) / (second.y - first.y)));
  return is;
}

bool Concave::isInsideTriangle(const point_t& A, const point_t& B, const point_t& C, const point_t& P)
{
  double ABC = 0.5 * ((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y));
  double ABP = 0.5 * ((B.x - A.x) * (P.y - A.y) - (P.x - A.x) * (B.y - A.y));
  double ACP = 0.5 * ((C.x - A.x) * (P.y - A.y) - (P.x - A.x) * (C.y - A.y));

  return (ABC > 0 && ABP > 0 && ACP > 0) || (ABC < 0 && (ABP < 0 || ACP < 0));
}
