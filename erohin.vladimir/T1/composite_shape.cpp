#include "composite_shape.hpp"
#include <utility>
#include <stdexcept>

erohin::CompositeShape::CompositeShape():
  capacity_(4),
  size_(0),
  shape_(new Shape* [4])
{
  for (size_t i = 0; i < size_; ++i)
  {
    shape_[i] = nullptr;
  }
}

erohin::CompositeShape::CompositeShape(CompositeShape&& rhs) noexcept:
  capacity_(rhs.capacity_),
  size_(rhs.size_),
  shape_(rhs.shape_)
{
  rhs.capacity_ = 0;
  rhs.size_ = 0;
  shape_ = nullptr;
}

erohin::CompositeShape::~CompositeShape()
{
  for(size_t i = 0; i < size_; ++i)
  {
    delete shape_[i];
  }
  delete[] shape_;
}

void erohin::CompositeShape::swap(CompositeShape& rhs)
{
  std::swap(capacity_, rhs.capacity_);
  std::swap(size_, rhs.size_);
  std::swap(shape_, rhs.shape_);
}

erohin::CompositeShape& erohin::CompositeShape::operator=(CompositeShape&& rhs) noexcept
{
  if (this != &rhs)
  {
    CompositeShape temp(std::move(rhs));
    swap(temp);
  }
  return *this;
}

erohin::Shape& erohin::CompositeShape::operator[](size_t index)
{
  return *shape_[index];
}

const erohin::Shape& erohin::CompositeShape::operator[](size_t index) const
{
  return *shape_[index];
}

erohin::Shape& erohin::CompositeShape::at(size_t index)
{
  if (index > size_)
  {
    throw std::out_of_range("Index is out of range");
  }
  return *shape_[index];
}

const erohin::Shape& erohin::CompositeShape::at(size_t index) const
{
  if (index > size_)
  {
    throw std::out_of_range("Index is out of range");
  }
  return *shape_[index];
}

void erohin::CompositeShape::push(const Shape& shape)
{
  if (size_ == capacity_)
  {
    resize(2 * capacity_);
  }
  *shape_[size_++] = shape;
}

void erohin::CompositeShape::pop()
{
  if (empty())
  {
    throw std::underflow_error("Composite shape is empty");
  }
  delete shape_[size_--];
}

bool erohin::CompositeShape::empty() const
{
  return (size_ == 0);
}

size_t erohin::CompositeShape::size() const
{
  return size_;
}

void erohin::CompositeShape::resize(size_t length)
{
  if (length < size_)
  {
    for (size_t i = length; i < size_; ++i)
    {
      delete shape_[i];
    }
  }
  else if (length > capacity_)
  {
    Shape** resized = new Shape* [length];
    capacity_ = length;
    for (size_t i = 0; i < capacity_; ++i)
    {
      resized[i] = (i < size_) ? shape_[i] : nullptr;
      delete shape_[i];
    }
  }
}
