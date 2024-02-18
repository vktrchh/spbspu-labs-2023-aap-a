#include "compositeShape.hpp"
#include <limits>
#include <cmath>
#include <stdexcept>

isaychev::CompositeShape::CompositeShape():
  capacity_(1000),
  currNumOfFigures_(0)
{
  figures_ = new Shape *[capacity_]{};
}

void deleteFigures(isaychev::Shape ** figures, size_t figureCount)
{
  for (size_t i = 0; i < figureCount; i++)
  {
    delete figures[i];
  }
}

isaychev::CompositeShape::~CompositeShape()
{
  deleteFigures(figures_, currNumOfFigures_);
  delete [] figures_;
}

isaychev::CompositeShape::CompositeShape(CompositeShape && diffCShape):
  capacity_(diffCShape.capacity_),
  currNumOfFigures_(diffCShape.currNumOfFigures_),
  figures_(diffCShape.figures_)
{
  diffCShape.figures_ = nullptr;
  diffCShape.currNumOfFigures_ = 0;
}

isaychev::CompositeShape & isaychev::CompositeShape::operator=(CompositeShape && diffCShape)
{
  deleteFigures(figures_, currNumOfFigures_);
  delete [] figures_;
  figures_ = diffCShape.figures_;
  diffCShape.figures_ = nullptr;
  capacity_ = diffCShape.capacity_;
  currNumOfFigures_ = diffCShape.currNumOfFigures_;
  diffCShape.currNumOfFigures_ = 0;
  return *this;
}

void isaychev::CompositeShape::pushBack(Shape * figure)
{
  figures_[currNumOfFigures_++] = figure;
}

void isaychev::CompositeShape::popBack()
{
  if (currNumOfFigures_ == 0)
  {
    throw std::out_of_range("There is nothing to delete");
  }
  delete figures_[currNumOfFigures_--];
}

void checkPosition(size_t n, size_t numOfPositions)
{
  if (n >= numOfPositions)
  {
    throw std::out_of_range("There is no such position in array");
  }
}

isaychev::Shape & isaychev::CompositeShape::at(size_t n)
{
  checkPosition(n, currNumOfFigures_);
  return *figures_[n];
}

const isaychev::Shape & isaychev::CompositeShape::at(size_t n) const
{
  checkPosition(n, currNumOfFigures_);
  return *figures_[n];
}

isaychev::Shape & isaychev::CompositeShape::operator[](size_t n)
{
  checkPosition(n, currNumOfFigures_);
  return *figures_[n];
}

const isaychev::Shape & isaychev::CompositeShape::operator[](size_t n) const
{
  checkPosition(n, currNumOfFigures_);
  return *figures_[n];
}

bool isaychev::CompositeShape::empty() const
{
  return (currNumOfFigures_ == 0);
}

size_t isaychev::CompositeShape::size() const
{
  return currNumOfFigures_;
}

size_t isaychev::CompositeShape::maxSize() const
{
  return capacity_;
}

double isaychev::CompositeShape::getArea() const
{
  double sumOfAreas = 0;
  for (size_t i =0; i < currNumOfFigures_; i++)
  {
    sumOfAreas += figures_[i]->getArea();
  }
  return sumOfAreas;
}

isaychev::rectangle_t isaychev::CompositeShape::getFrameRect() const
{
  double minX = 0.0, minY = 0.0, maxX = 0.0, maxY = 0.0;
  minX = minY = std::numeric_limits< double >::max();
  maxX = maxY = std::numeric_limits< double >::min();
  for (size_t i = 0; i < currNumOfFigures_; i++)
  {
    rectangle_t rec = figures_[i]->getFrameRect();
    double lX = rec.pos.x - rec.width / 2;
    double lY = rec.pos.y - rec.height / 2;
    double rX = rec.pos.x + rec.width / 2;
    double rY = rec.pos.y + rec.height / 2;
    if (minX > lX)
    {
      minX = lX;
    }
    if (minY > lY)
    {
      minY = lY;
    }
    if (maxX < rX)
    {
      maxX = rX;
    }
    if (maxY < rY)
    {
      maxY = rY;
    }
  }
  double width = maxX - minX;
  double height = maxY - minY;
  point_t pos = {maxX - width / 2, maxY - height / 2};
  return {width, height, pos};
}

void isaychev::CompositeShape::move(const point_t & newPos)
{
  for (size_t i = 0; i < currNumOfFigures_; i++)
  {
    rectangle_t rec = figures_[i]->getFrameRect();
    double dX = newPos.x - rec.pos.x;
    double dY = newPos.y - rec.pos.y;
    figures_[i]->move(dX, dY);
  }
}

void isaychev::CompositeShape::move(double dX, double dY)
{
  for (size_t i = 0; i < currNumOfFigures_; i++)
  {
    figures_[i]->move(dX, dY);
  }
}

void isoscaleFigure(const isaychev::point_t & center, double coeff, isaychev::Shape * figure)
{
  figure->scale(coeff);
  isaychev::rectangle_t rec = figure->getFrameRect();
  double dX = (rec.pos.x - center.x) * std::fabs(1.0 - coeff);
  double dY = (rec.pos.y - center.y) * std::fabs(1.0 - coeff);
  figure->move(dX, dY);
}

void isaychev::CompositeShape::scale(const double * scaleParams)
{
  for (size_t i = 0; i < currNumOfFigures_; i++)
  {
    isoscaleFigure({scaleParams[0], scaleParams[1]}, scaleParams[2], figures_[i]);
  }
}
