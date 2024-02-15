#include <iostream>
#include <string>
#include "shape.hpp"
#include "concave.hpp"
#include "polygon.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"
#include "figureInputFunction.hpp"
#include "isoScale.hpp"
#include "outputShapes.hpp"

int main()
{
  std::string figureName;

  rebdev::Shape ** shapes = nullptr;
  try
  {
    shapes = new rebdev::Shape * [1000];
    for (size_t i = 0; i < 1000; ++i)
    {
      shapes[i] = nullptr;
    }
  }
  catch (const std::exception & e)
  {
    std::cerr << "Error in allocat dynamic memory";
    return 2;
  }

  size_t numOfShape = 0;
  bool isScale = 0, figureError = 0;

  while (std::getline(std::cin, figureName, ' '))
  {
    if (figureName.find('\n') == 0)
    {
      figureName.erase(0, 1);
    }

    if (figureName.find("SCALE") != std::string::npos)
    {
      rebdev::point_t isoPoint = {0.0, 0.0};
      double k = 0;
      std::cin >> isoPoint.x >> isoPoint.y >> k;

      if ((!std::cin) || (k <= 0))
      {
        break;
      }

      rebdev::printSum(shapes, numOfShape, std::cout);
      rebdev::printShapes(shapes, numOfShape, std::cout);
      std::cout << '\n';
      rebdev::isoScale(shapes, numOfShape, isoPoint, k);

      isScale = 1;
      break;
    }
    else
    {
      try
      {
        shapes[numOfShape] = rebdev::newFigure(std::cin, figureName);
        numOfShape += (shapes[numOfShape] != nullptr);
      }
      catch (const std::exception & e)
      {
        delete shapes[numOfShape];
        figureError = 1;
      }
    }

    figureName.clear();
  }

  if (figureError)
  {
    std::cerr << "Some figure is incorrect!\n";
  }
  if (!isScale || (numOfShape == 0))
  {
    std::cerr << "Programm end without scale!\n";
    for (size_t i = 0; i < numOfShape; ++i)
    {
      delete shapes[i];
    }
    delete[] shapes;
    return 1;
  }

  rebdev::printSum(shapes, numOfShape, std::cout);
  rebdev::printShapes(shapes, numOfShape, std::cout);
  std::cout << '\n';

  for (size_t i = 0; i < numOfShape; ++i)
  {
    delete shapes[i];
  }

  delete[] shapes;
  return 0;
}
