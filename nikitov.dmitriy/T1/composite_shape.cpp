#include "composite_shape.hpp"
#include "base-types.hpp"

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
    figures_[i] = other.figures_[i]->clone();
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

Shape* nikitov::CompositeShape::operator[](size_t index)
{

}

const Shape* nikitov::CompositeShape::operator[](size_t index) const
{

}

void nikitov::CompositeShape::push_back(Shape* figure)
{

}

void nikitov::CompositeShape::pop_back()
{

}

Shape* nikitov::CompositeShape::at(size_t index)
{

}

const Shape* nikitov::CompositeShape::at(size_t index) const
{

}

size_t nikitov::CompositeShape::size() const
{

}

bool nikitov::CompositeShape::empty() const
{

}

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
