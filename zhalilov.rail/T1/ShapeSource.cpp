#include "ShapeSource.hpp"

#include <algorithm>
#include <stdexcept>

zhalilov::ShapeSource::ShapeSource() :
  m_shapes(new Shapes *[10]{nullptr}),
  m_shapesSize(10),
  m_sourceLen(0),
  scalePoint{0.0, 0.0},
  scale(1.0)
{}

zhalilov::ShapeSource::~ShapeSource()
{
  for (size_t i = 0; i < m_shapesSize; i++)
  {
    delete m_shapes[i];
  }
  delete[] m_shapes;
}

zhalilov::Shape *zhalilov::ShapeSource::operator[](size_t index)
{
  if (index <= 0 || index >= m_shapesSize)
  {
    throw std::out_of_range;
  }
  return m_shapes[index];
}

void zhalilov::resize(size_t newSize)
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
