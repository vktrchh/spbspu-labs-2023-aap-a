#include "composite_shape.hpp"

erohin::CompositeShape::CompositeShape() = default;

erohin::CompositeShape::CompositeShape(CompositeShape&& rhs) noexcept = default;

erohin::CompositeShape::~CompositeShape() = default;

erohin::CompositeShape& erohin::CompositeShape::operator=(CompositeShape&& rhs) noexcept = default;

erohin::Shape& erohin::CompositeShape::operator[](size_t index)
{
  return **shape_;
}

const erohin::Shape& erohin::CompositeShape::operator[](size_t index) const
{
  return **shape_;
}

erohin::Shape& erohin::CompositeShape::at(size_t index)
{
  return **shape_;
}

const erohin::Shape& erohin::CompositeShape::at(size_t index) const
{
  return **shape_;
}

void erohin::CompositeShape::push(const Shape& shape)
{}

void erohin::CompositeShape::pop()
{}

bool erohin::CompositeShape::empty() const
{
  return true;
}

size_t erohin::CompositeShape::size() const
{
  return 0;
}
