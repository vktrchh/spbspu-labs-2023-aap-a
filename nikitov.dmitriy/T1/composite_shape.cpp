#include "composite_shape.hpp"
#include <limits>
#include <stdexcept>
#include "base-types.hpp"
#include "scale_figures.hpp"

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

double nikitov::CompositeShape::getArea() const
{
  double sumOfAreas = 0;
  for (size_t i = 0; i != sizeOfArray_; ++i)
  {
    sumOfAreas += figures_[i]->getArea();
  }
  return sumOfAreas;
}

nikitov::rectangle_t nikitov::CompositeShape::getFrameRect() const
{
  double maxX = std::numeric_limits < double >::min();
  double maxY = maxX;
  double minX = std::numeric_limits < double >::max();
  double minY = minX;
  for (size_t i = 0; i != sizeOfArray_; ++i)
  {
    rectangle_t frame = figures_[i]->getFrameRect();
    maxX = std::max(maxX, frame.pos.x + (frame.width / 2));
    maxY = std::max(maxY, frame.pos.y + (frame.height / 2));
    minX = std::min(minX, frame.pos.x - (frame.width / 2));
    minY = std::min(minY, frame.pos.y - (frame.height / 2));
  }
  point_t center = { minX + (maxX - minX) / 2, minY + (maxY - minY) / 2 };
  return { maxX - minX, maxY - minY, center };
}

void nikitov::CompositeShape::move(const point_t& point)
{
  point_t center = getFrameRect().pos;
  double dx = point.x - center.x;
  double dy = point.y - center.y;
  move(dx, dy);
}

void nikitov::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i != sizeOfArray_; ++i)
  {
    figures_[i]->move(dx, dy);
  }
}

void nikitov::CompositeShape::scale(double ratio)
{
  point_t center = getFrameRect().pos;
  for (size_t i = 0; i != sizeOfArray_; ++i)
  {
    scaleFigure(figures_[i], center, ratio);
  }
}

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
