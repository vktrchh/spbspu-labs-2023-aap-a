#include "composite_shape.hpp"
#include "base-types.hpp"
#include <stdexcept>

nikitov::CompositeShape::CompositeShape():
  sizeOfArray_(0),
  figures_(nullptr)
{}

nikitov::CompositeShape::CompositeShape(const CompositeShape& other):
  sizeOfArray_(other.sizeOfArray_),
  figures_(new Shape*[sizeOfArray_])
{
  for (size_t i = 0; i != sizeOfArray_; ++i)
  {
    figures_[i] = other[i].clone();
  }
}

nikitov::CompositeShape::CompositeShape(CompositeShape&& other):
  sizeOfArray_(other.sizeOfArray_),
  figures_(other.figures_)
{
  other.figures_ = nullptr;
}

nikitov::CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i != sizeOfArray_; ++i)
  {
    delete[] figures_[i];
  }
  delete[] figures_;
}

/*
CompositeShape& nikitov::CompositeShape::operator=(CompositeShape& other)
{

}

CompositeShape& nikitov::CompositeShape::operator=(CompositeShape&& other)
{

}
*/
nikitov::Shape& nikitov::CompositeShape::operator[](size_t index)
{
  return *(figures_[index]);
}

const nikitov::Shape& nikitov::CompositeShape::operator[](size_t index) const
{
  return *(figures_[index]);
}

void nikitov::CompositeShape::push_back(Shape* figure)
{
  increaseArray();
  figures_[sizeOfArray_ - 1] = figure;
}

void nikitov::CompositeShape::pop_back()
{
  delete figures_[sizeOfArray_];
  decreaseArray();
}

nikitov::Shape* nikitov::CompositeShape::at(size_t index)
{
  if (index >= sizeOfArray_)
  {
    throw std::out_of_range("Error: Index out of range");
  }
  return figures_[index];
}

const nikitov::Shape* nikitov::CompositeShape::at(size_t index) const
{
  if (index >= sizeOfArray_)
  {
    throw std::out_of_range("Error: Index out of range");
  }
  return figures_[index];
}

size_t nikitov::CompositeShape::size() const
{
  return sizeOfArray_;
}

bool nikitov::CompositeShape::empty() const
{
  return sizeOfArray_;
}
/*
double nikitov::CompositeShape::getArea() const
{

}

rectangle_t nikitov::CompositeShape::getFrameRect() const
{

}

void nikitov::CompositeShape::move(const point_t& point)
{

}

void nikitov::CompositeShape::move(double dx, double dy)
{

}

void nikitov::CompositeShape::scale(double ratio)
{

}
*/
void nikitov::CompositeShape::increaseArray()
{
  Shape** temp = new Shape*[sizeOfArray_ + 1];
  for (size_t i = 0; i != sizeOfArray_; ++i)
  {
    temp[i] = figures_[i];
  }
  delete[] figures_;
  ++sizeOfArray_;
  figures_ = temp;
}

void nikitov::CompositeShape::decreaseArray()
{
  Shape** temp = new Shape*[sizeOfArray_ - 1];
  for (size_t i = 0; i != sizeOfArray_ - 1; ++i)
  {
    temp[i] = figures_[i];
  }
  delete[] figures_;
  --sizeOfArray_;
  figures_ = temp;
}
