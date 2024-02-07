#include "triangle.hpp"
#include <stdexcept>

belokurskaya::Triangle::Triangle(const point_t& vertex1, const point_t& vertex2, const point_t& vertex3):
vertex1_(vertex1), vertex2_(vertex2), vertex3_(vertex3)
{
    double a = std::hypot(vertex1_.x - vertex2_.x, vertex1_.y - vertex2_.y);
    double b = std::hypot(vertex2_.x - vertex3_.x, vertex2_.y - vertex3_.y);
    double c = std::hypot(vertex3_.x - vertex1_.x, vertex3_.y - vertex1_.y);
    double s = (a + b + c) / 2.0;
    double area = std::sqrt(s * (s - a) * (s - b) * (s - c));

    if (area == 0)
    {
        throw std::invalid_argument("Invalid triangle: degenerate triangle (zero area).");
    }

    if (vertex1_ == vertex2_ || vertex1_ == vertex3_ || vertex2_ == vertex3_)
    {
        throw std::invalid_argument("Invalid triangle: vertices cannot be equal.");
    }
}

double belokurskaya::Triangle::getArea() const
{
  double a = std::hypot(vertex1_.x - vertex2_.x, vertex1_.y - vertex2_.y);
  double b = std::hypot(vertex2_.x - vertex3_.x, vertex2_.y - vertex3_.y);
  double c = std::hypot(vertex3_.x - vertex1_.x, vertex3_.y - vertex1_.y);
  double s = (a + b + c) / 2.0;
  return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

rectangle_t belokurskaya::Triangle::getFrameRect() const
{
  double min_x = std::min({vertex1_.x, vertex2_.x, vertex3_.x});
  double max_x = std::max({vertex1_.x, vertex2_.x, vertex3_.x});
  double min_y = std::min({vertex1_.y, vertex2_.y, vertex3_.y});
  double max_y = std::max({vertex1_.y, vertex2_.y, vertex3_.y});

  double width = max_x - min_x;
  double height = max_y - min_y;

  point_t center{(min_x + max_x) / 2.0, (min_y + max_y) / 2.0};

  return {center, width, height};
}

void belokurskaya::Triangle::move(const point_t& new_pos)
{
  point_t centroid = calculateCentroid();
  double dx = new_pos.x - centroid.x;
  double dy = new_pos.y - centroid.y;

  vertex1_.x += dx;
  vertex1_.y += dy;
  vertex2_.x += dx;
  vertex2_.y += dy;
  vertex3_.x += dx;
  vertex3_.y += dy;
}

void belokurskaya::Triangle::move(double dx, double dy)
{
  vertex1_.x += dx;
  vertex1_.y += dy;
  vertex2_.x += dx;
  vertex2_.y += dy;
  vertex3_.x += dx;
  vertex3_.y += dy;
}

void belokurskaya::Triangle::scale(double factor)
{
  point_t centroid = calculateCentroid();

  vertex1_.x = centroid.x + (vertex1_.x - centroid.x) * factor;
  vertex1_.y = centroid.y + (vertex1_.y - centroid.y) * factor;

  vertex2_.x = centroid.x + (vertex2_.x - centroid.x) * factor;
  vertex2_.y = centroid.y + (vertex2_.y - centroid.y) * factor;

  vertex3_.x = centroid.x + (vertex3_.x - centroid.x) * factor;
  vertex3_.y = centroid.y + (vertex3_.y - centroid.y) * factor;
}

point_t belokurskaya::Triangle::calculateCentroid() const
{
  double centroid_x = (vertex1_.x + vertex2_.x + vertex3_.x) / 3.0;
  double centroid_y = (vertex1_.y + vertex2_.y + vertex3_.y) / 3.0;
  return {centroid_x, centroid_y};
}
