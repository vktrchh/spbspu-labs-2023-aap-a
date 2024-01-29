#include <string>
#include <map>
#include "input_output_shapes.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"
#include "circle.hpp"
#include "complexquad.hpp"
#include "geometric_functions.hpp"


namestnikov::Shape ** namestnikov::inputShapes(std::istream & in, size_t & count)
{
  using namespace namestnikov;
  std::map<std::string, size_t> possibleShapes;
  possibleShapes["RECTANGLE"] = 4;
  possibleShapes["CIRCLE"] = 3;
  possibleShapes["COMPLEXQUAD"] = 8;
  double * currentParameters = nullptr;
  std::string currentShapeName = "";
  namestnikov::Shape ** currentShapes = nullptr;
  namestnikov::Shape ** oldShapes = nullptr;
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
      for (auto now : possibleShapes)
      {
        std::string shapeName = now.first;
        size_t possibleSize = now.second;
        if (currentShapeName == shapeName)
        {
          try
          {
            currentParameters = new double[possibleSize];
          }
          catch (const std::bad_alloc & e)
          {
            if (currentShapes != nullptr)
            {
              namestnikov::deleteShapes(currentShapes, count);
            }
            throw e;
          }
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
            delete [] currentParameters;
            throw std::invalid_argument("Error in input\n");
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
              point_t points[4]{};
              for (size_t i = 0; i < 8; i += 2)
              {
                points[i / 2] = {currentParameters[i], currentParameters[i + 1]};
              }
              currentShapes[count] = new Complexquad(points);
              ++count;
            }
          }
          catch (const std::bad_alloc &)
          {
            delete [] currentParameters;
            namestnikov::deleteShapes(currentShapes, count);
            throw;
          }
          catch (const std::exception & e)
          {
            std::cerr << "Error: " << e.what() << "\n";
          }
          delete [] currentParameters;
        }
      }
      in >> std::noskipws;
      char sym = 0;
      while (sym != '\n')
      {
        in >> sym;
      }
      in >> std::skipws;
    }
  }
  return currentShapes;
}

std::ostream & namestnikov::outputShapes(std::ostream & out, size_t count, Shape ** shapes)
{
  if (count == 0)
  {
    throw std::invalid_argument("Nothing to output\n");
  }
  out << std::fixed;
  out.precision(1);
  double square = 0.0;
  for (size_t i = 0; i < count; ++i)
  {
    if (shapes[i])
    {
      square += shapes[i]->getArea();
    }
  }
  out << square << " ";
  for (size_t i = 0; i < count; ++i)
  {
    if (shapes[i])
    {
      double width = shapes[i]->getFrameRect().width;
      double height = shapes[i]->getFrameRect().height;
      point_t position = shapes[i]->getFrameRect().pos;
      double positionX = position.x;
      double positionY = position.y;
      out << positionX - (width / 2.0) << " " << positionY - (height / 2.0) << " "
           << positionX + (width / 2.0) << " " << positionY + (height / 2.0);
    }
  }
  out << "\n";
  return out;
}
