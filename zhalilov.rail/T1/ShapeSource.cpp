#include "ShapeSource.hpp"

#include <algorithm>
#include <stdexcept>

zhalilov::ShapeSource::ShapeSource() :
  m_shapesSize(15),
  m_sourceLen(10),
  scalePoint{0.0, 0.0},
  scaleRatio(1.0),
  wasBadShapes(false)
{
  m_shapes = new Shape*[10]{nullptr};
}

zhalilov::ShapeSource::ShapeSource(size_t size) :
  m_shapesSize(size + 5),
  m_sourceLen(size),
  scalePoint{0.0, 0.0},
  scaleRatio(1.0),
  wasBadShapes(false)
{
  m_shapes = new Shape*[size]{nullptr};
}

zhalilov::ShapeSource::~ShapeSource()
{
  for (size_t i = 0; i < m_sourceLen; i++)
  {
    delete m_shapes[i];
  }
  delete[] m_shapes;
}

zhalilov::Shape *&zhalilov::ShapeSource::at(size_t index)
{
  if (index < 0 || index >= m_shapesSize)
  {
    throw std::out_of_range("invalid index");
  }
  return m_shapes[index];
}

void zhalilov::ShapeSource::resize(size_t newSize)
{
  Shape **newShape = new Shape*[newSize];
  for (size_t i = 0; i < std::min(newSize, m_sourceLen); i++)
  {
    newShape[i] = m_shapes[i];
  }
  for (size_t i = m_sourceLen; i < newSize; i++)
  {
    newShape[i] = nullptr;
  }
  delete[] m_shapes;
  m_sourceLen = std::min(newSize, m_sourceLen);
  m_shapesSize = newSize;
  m_shapes = newShape;
}

size_t zhalilov::ShapeSource::getLength()
{
  return m_sourceLen;
}

size_t zhalilov::ShapeSource::getSize()
{
  return m_shapesSize;
}
