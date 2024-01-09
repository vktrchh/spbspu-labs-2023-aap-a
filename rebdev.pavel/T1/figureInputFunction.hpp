#ifndef FIGUREINPUTFUNCTION_HPP
#define FIGUREINPUTFUNCTION_HPP
#include <iostream>
#include <cstddef>
#include "base-types.hpp"
#include "shape.hpp"
#include "concave.hpp"
#include "polygon.hpp"
#include "rectangle.hpp"

namespace rebdev
{
  bool isRectangle(point_t * pointsArr);
  bool isConcave(point_t * pointsArr);
  bool isPolygon(const point_t * pointsArr, const size_t size);
  bool isTriangle(const point_t f, const point_t s, const point_t t);

  bool isNameCorrect(std::istream & input, const int nameSize, const char * name);
  point_t * ipnutVertexs(std::istream & input, size_t & numOfVertexs);
  bool figureIsCorrect(point_t * vertexsArr, const size_t numOfVertexs, const int figureNumber);

  Shape * newFigure(point_t * vertexsArr, const size_t numOfVertexs, const int figureNumber);
}
#endif
