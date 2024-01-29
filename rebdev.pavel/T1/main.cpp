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
    for (int i = 0; i < 1000; ++i)
    {
      shapes[i] = nullptr;
    }
  }
  catch (const std::exception & e)
  {
    std::cerr << "Error in allocat dynamic memory";
    return 2;
  }

  int numOfShape = 0;
  bool isScale = 0, figureError = 0;

  while (std::getline(std::cin, figureName, ' '))
  {
    if (figureName.find('\n') == 0)
    {
      figureName.erase(0, 1);
    }
    std::cout << figureName << '\n';
    if (figureName == "SCALE")
    {
      rebdev::point_t isoPoint = {0.0, 0.0};
      double k = 0;
      std::cin >> isoPoint.x >> isoPoint.y >> k;

      if ((!std::cin) || (k <= 0))
      {
        break;
      }

      rebdev::outputShapes(shapes, numOfShape, std::cout);
      rebdev::isoScale(shapes, numOfShape, isoPoint, k);

      isScale = 1;
      break;
    }
    else
    {
      try
      {
        shapes[numOfShape] = rebdev::newFigure(std::cin, figureName);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error\n";
        shapes[numOfShape] = nullptr;
        figureError = 1;
      }

      numOfShape += (shapes[numOfShape] != nullptr);
    }
  }

  if (figureError)
  {
    std::cerr << "Some figure is incorrect!\n";
  }
  if (!isScale || (numOfShape == 0))
  {
    std::cerr << "Programm end without scale!\n";
    delete[] shapes;
    return 1;
  }

  rebdev::outputShapes(shapes, numOfShape, std::cout);

  delete[] shapes;
  return 0;
}
