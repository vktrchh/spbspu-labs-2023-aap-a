#include "composite_shape.hpp"
#include <stdexcept>
#include <cstddef>
#include <cstring>
#include "shape.hpp"
#include "base-types.hpp"
#include "geometric_functions.hpp"

zaitsev::CompositeShape::CompositeShape():
    size_(0),
    capacity_(8),
    shapes_(new Shape* [8])
{
}

zaitsev::CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < size_; ++i)
  {
    delete shapes_[i];
  }
  delete[] shapes_;
}

zaitsev::CompositeShape& zaitsev::CompositeShape::operator=(const CompositeShape& other)
{
  if (this == std::addressof(other))
  {
    return *this;
  }
  Shape** temp = new Shape* [other.capacity_];
  size_ = other.size_;
  capacity_ = other.capacity_;
  for (size_t i = 0; i < size_; ++i)
  {
    delete shapes_[i];
  }
  delete[] shapes_;

  shapes_ = temp;
  for (size_t i = 0; i < size_; ++i)
  {
    shapes_[i] = other[i].clone();
  }

  return *this;
}

zaitsev::CompositeShape::CompositeShape(const CompositeShape& other):
    size_(other.size_),
    capacity_(other.capacity_),
    shapes_(new Shape* [other.capacity_])
{
  for (size_t i = 0; i < size_; ++i)
  {
    shapes_[i] = other[i].clone();
  }
}

zaitsev::CompositeShape& zaitsev::CompositeShape::operator=(CompositeShape&& other)
{
  if (this == std::addressof(other))
  {
    return *this;
  }
  for (size_t i = 0; i < size_; ++i)
  {
    delete shapes_[i];
  }
  delete[] shapes_;
  size_ = other.size_;
  capacity_ = other.capacity_;
  shapes_ = other.shapes_;
  other.size_ = 0;
  other.capacity_ = 0;
  other.shapes_ = nullptr;
  return *this;
}

void zaitsev::CompositeShape::push_back(Shape* shape)
{
  if (!shape)
  {
    return;
  }
  if (size_ == capacity_)
  {
    Shape** temp = new Shape*[capacity_ * 2];
    std::memcpy(temp, shapes_, sizeof(Shape*) * size_);
    capacity_ *= 2;
  }
  shapes_[size_] = shape;
  ++size_;
}

void zaitsev::CompositeShape::pop_back()
{
  if (size_ == 0)
  {
    return;
  }

  delete shapes_[size_ - 1];
  --size_;
}

zaitsev::CompositeShape::CompositeShape(CompositeShape&& other):
    size_(other.size_),
    capacity_(other.capacity_),
    shapes_(other.shapes_)
{
  other.size_ = 0;
  other.capacity_ = 0;
  other.shapes_ = nullptr;
}

zaitsev::Shape& zaitsev::CompositeShape::at(size_t pos)
{
  if (pos >= size_)
  {
    throw std::out_of_range("Shape size is less than the required position");
  }
  return *(shapes_[pos]);
}

const zaitsev::Shape& zaitsev::CompositeShape::at(size_t pos) const
{
  if (pos >= size_)
  {
    throw std::out_of_range("Shape size is less than the required position");
  }
  return *(shapes_[pos]);
}

zaitsev::Shape& zaitsev::CompositeShape::operator[](size_t pos)
{
  return *(shapes_[pos]);
}

const zaitsev::Shape& zaitsev::CompositeShape::operator[](size_t pos) const
{
  return *(shapes_[pos]);
}

bool zaitsev::CompositeShape::empty() const
{
  return size_ > 0 ? true : false;
}

size_t zaitsev::CompositeShape::size() const
{
  return size_;
}

double zaitsev::CompositeShape::getArea() const
{
  double area = 0;
  for (size_t i = 0; i < size_; ++i)
  {
    area += shapes_[i]->getArea();
  }
  return area;
}

zaitsev::rectangle_t zaitsev::CompositeShape::getFrameRect() const
{
  if (empty())
  {
    throw std::runtime_error("Shape has no components");
  }
  rectangle_t rect = shapes_[0]->getFrameRect();
  point_t left_corner = { rect.pos.x - rect.width, rect.pos.y - rect.height };
  point_t right_corner = { rect.pos.x + rect.width, rect.pos.y + rect.height };
  for (size_t i = 1; i < size_; ++i)
  {
    rect = shapes_[i]->getFrameRect();
    changeRectangleBounds(left_corner, right_corner, { rect.pos.x - rect.width, rect.pos.y - rect.height });
    changeRectangleBounds(left_corner, right_corner, { rect.pos.x + rect.width, rect.pos.y + rect.height });
  }
  return transformRectangleBounds(left_corner, right_corner);
}

void zaitsev::CompositeShape::move(const point_t& dest_pos)
{
  for (size_t i = 0; i < size_; ++i)
  {
    shapes_[i]->move(dest_pos);
  }
}

void zaitsev::CompositeShape::move(double x_shift, double y_shift)
{
  for (size_t i = 0; i < size_; ++i)
  {
    shapes_[i]->move(x_shift, y_shift);
  }
}

void zaitsev::CompositeShape::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Scale factor must be positive");
  }
  point_t center = getCenter();
  for (size_t i = 0; i < size_; ++i)
  {
    zaitsev::scale(shapes_[i], factor, center);
  }
}

zaitsev::point_t zaitsev::CompositeShape::getCenter() const
{
  return getFrameRect().pos;
}
