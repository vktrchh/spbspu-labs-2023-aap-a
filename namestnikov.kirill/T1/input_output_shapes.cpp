#include "input_output_shapes.hpp"
#include <string>
#include "rectangle.hpp"
#include "base-types.hpp"
#include "circle.hpp"
#include "complexquad.hpp"
#include "geometric_functions.hpp"

void namestnikov::inputRectangle(std::istream & in, Shape ** shapes, size_t & count)
{
  const size_t size = 4;
  double rectangleParameters[size] = {};
  for (size_t i = 0; i < size; ++i)
  {
    in >> rectangleParameters[i];
  }
  if (!in)
  {
    throw std::invalid_argument("Error in input\n");
  }
  shapes[count++] = new Rectangle({rectangleParameters[0], rectangleParameters[1]}, {rectangleParameters[2], rectangleParameters[3]});
}

void namestnikov::inputCircle(std::istream & in, Shape ** shapes, size_t & count)
{
  const size_t size = 3;
  double circleParameters[size] = {};
  for (size_t i = 0; i < size; ++i)
  {
    in >> circleParameters[i];
    if (!in)
    {
      throw std::invalid_argument("Error in input");
    }
  }
  shapes[count++] = new Circle({circleParameters[0], circleParameters[1]}, circleParameters[2]);
}

void namestnikov::inputComplexquad(std::istream & in, Shape ** shapes, size_t & count)
{
  const size_t size = 8;
  double complexquadParameters[size] = {};
  for (size_t i = 0; i < size; ++i)
  {
    in >> complexquadParameters[i];
    if (!in)
    {
      throw std::invalid_argument("Error in input");
    }
  }
  point_t points[4] = {};
  for (size_t i = 0; i < 8; i += 2)
  {
    points[i / 2] = {complexquadParameters[i], complexquadParameters[i + 1]};
  }
  shapes[count++] = new Complexquad(points[0], points[1], points[2], points[3]);
}

namestnikov::Shape ** namestnikov::inputShapes(std::istream & in, size_t & count)
{
  std::string currentShapeName = "";
  Shape ** currentShapes = nullptr;
  Shape ** oldShapes = nullptr;
  while ((in >> currentShapeName) && (currentShapeName != "SCALE"))
  {
    oldShapes = currentShapes;
    currentShapes = new Shape * [count + 1]{};
    if (oldShapes)
    {
      for (size_t i = 0; i < count; ++i)
      {
        currentShapes[i] = oldShapes[i];
      }
    }
    delete [] oldShapes;
    try
    {
      if (currentShapeName == "RECTANGLE")
      {
        inputRectangle(in, currentShapes, count);
      }
      else if (currentShapeName == "CIRCLE")
      {
        inputCircle(in, currentShapes, count);
      }
      else if (currentShapeName == "COMPLEXQUAD")
      {
        inputComplexquad(in, currentShapes, count);
      }
    }
    catch (const std::bad_alloc &)
    {
      namestnikov::deleteShapes(currentShapes, count);
      throw;
    }
    catch (const std::invalid_argument & e)
    {
      std::cerr << "Error: " << e.what() << "\n";
    }
    std::string skippedLine = "";
    getline(in, skippedLine);
  }
  return currentShapes;
}

std::ostream & namestnikov::outputShapes(std::ostream & out, const Shape * const * shapes, size_t count)
{
  if (count == 0)
  {
    throw std::invalid_argument("Nothing to output");
  }
  double square = 0.0;
  for (size_t i = 0; i < count; ++i)
  {
    square += shapes[i]->getArea();
  }
  out << square;
  for (size_t i = 0; i < count; ++i)
  {
    double width = shapes[i]->getFrameRect().width;
    double height = shapes[i]->getFrameRect().height;
    point_t position = shapes[i]->getFrameRect().pos;
    point_t leftCornerPoint = {position.x - (width / 2.0), position.y - (height / 2.0)};
    point_t rightCornerPoint = {position.x + (width / 2.0), position.y + (height / 2.0)};
    out << " " << leftCornerPoint.x << " " << leftCornerPoint.y << " " << rightCornerPoint.x << " " << rightCornerPoint.y;
  }
  return out;
}
