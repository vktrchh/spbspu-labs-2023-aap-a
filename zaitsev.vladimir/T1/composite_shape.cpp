#include "composite_shape.hpp"
#include <stdexcept>
#include <cstddef>
#include <cstring>
#include "shape.hpp"

zaitsev::CompositeShape::CompositeShape(): size_(0), capacity_(8), shapes_(new Shape* [8])
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
    size_(other.size_), capacity_(other.capacity_), shapes_(new Shape* [other.capacity_])
{
  for (size_t i = 0; i < size_; ++i)
  {
    shapes_[i] = other[i].clone();
  }
}

zaitsev::CompositeShape& zaitsev::CompositeShape::operator=(CompositeShape&& other)
{
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
    size_(other.size_), capacity_(other.capacity_), shapes_(other.shapes_)
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
