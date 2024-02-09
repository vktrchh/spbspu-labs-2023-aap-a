#include "input_output_shapes.hpp"
#include <string>
#include <map>
#include "rectangle.hpp"
#include "base-types.hpp"
#include "circle.hpp"
#include "complexquad.hpp"
#include "geometric_functions.hpp"

namestnikov::Shape ** namestnikov::inputShapes(std::istream & in, size_t & count)
{
  std::string possibleShapesNames[3] = {"RECTANGLE", "CIRCLE", "COMPLEXQUAD"};
  size_t shapesParametersCount[3] = {4, 3, 8};
  std::string currentShapeName = "";
  Shape ** currentShapes = nullptr;
  Shape ** oldShapes = nullptr;
  while (in >> currentShapeName)
  {
    if (currentShapeName == "SCALE")
    {
      break;
    }
    else if (currentShapeName == "")
    {
      std::cerr << "Wrong shape name\n";
    }
    else
    {
      for (size_t i = 0; i < 3; ++i)
      {
        std::string shapeName = possibleShapesNames[i];
        size_t possibleSize = shapesParametersCount[i];
        if (currentShapeName == shapeName)
        {
          double currentParameters[possibleSize]{};
          for (size_t i = 0; i < possibleSize; ++i)
          {
            in >> currentParameters[i];
          }
          if (!in)
          {
            if (currentShapes != nullptr)
            {
              namestnikov::deleteShapes(currentShapes, count);
            }
            throw std::invalid_argument("Error in input");
          }
          oldShapes = currentShapes;
          currentShapes = new Shape * [count + 1];
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
              currentShapes[count] = new Rectangle({currentParameters[0], currentParameters[1]}, {currentParameters[2], currentParameters[3]});
              ++count;
            }
            else if (currentShapeName == "CIRCLE")
            {
              currentShapes[count] = new Circle({currentParameters[0], currentParameters[1]}, currentParameters[2]);
              ++count;
            }
            else if (currentShapeName == "COMPLEXQUAD")
            {
              point_t firstPoint = {currentParameters[0], currentParameters[1]};
              point_t secondPoint = {currentParameters[2], currentParameters[3]};
              point_t thirdPoint = {currentParameters[4], currentParameters[5]};
              point_t fourthPoint = {currentParameters[6], currentParameters[7]};
              currentShapes[count] = new Complexquad(firstPoint, secondPoint, thirdPoint, fourthPoint);
              ++count;
            }
          }
          catch (const std::bad_alloc &)
          {
            namestnikov::deleteShapes(currentShapes, count);
            throw;
          }
          catch (const std::exception & e)
          {
            std::cerr << "Error: " << e.what() << "\n";
          }
        }
      }
      std::string s = "";
      getline(in, s);
    }
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
