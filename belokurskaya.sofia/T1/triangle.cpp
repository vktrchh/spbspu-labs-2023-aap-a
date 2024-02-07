#include "triangle.hpp"
#include <stdexcept>

Triangle::Triangle(const point_t& vertex1, const point_t& vertex2, const point_t& vertex3) : vertex1_(vertex1), vertex2_(vertex2), vertex3_(vertex3)
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

    if (vertex1_ == vertex2_  vertex1_ == vertex3_  vertex2_ == vertex3_)
    {
        throw std::invalid_argument("Invalid triangle: vertices cannot be equal.");
    }
}

double Triangle::getArea() const
{
}

rectangle_t Triangle::getFrameRect() const
{
}

void Triangle::move(const point_t& new_pos)
{
}

void Triangle::move(double dx, double dy)
{
}

void Triangle::scale(double factor)
{
}

point_t Triangle::calculateCentroid() const
{
}
