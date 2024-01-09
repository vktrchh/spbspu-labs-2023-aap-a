#include <iostream>
#include "shape.hpp"
#include "concave.hpp"
#include "polygon.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"
#include "figureInputFunction.hpp"
#include "isoScale.hpp"

int main()
{
  const char * figureName = nullptr;
  const char rectangleName[] = {"RECTANGLE"};
  const char concaveName[] = {"CONCAVE"};
  const char polygonName[] = {"POLYGON"};

  const int sizeOfFigureName[] = {9, 7, 7};

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
  char sym = 0;

  while (std::cin >> sym)
  {
    rebdev::point_t * pointArr = nullptr;
    int figureNumber = -1;
    size_t numberOfVertexs = 0;
    figureName = nullptr;

    if (sym == 'S')
    {
      if (rebdev::isNameCorrect(std::cin, 5, "SCALE"))
      {
        rebdev::point_t isoPoint {0.0, 0.0};
        double k = 0;
        std::cin >> isoPoint.x_ >> isoPoint.y_ >> k;

        if ((!std::cin) || (k <= 0))
        {
          break;
        }

        double sum = 0;
        for (int i = 0; i < numOfShape; ++i)
        {
          sum += shapes[i]->getArea();
        }
        std::cout << sum << '\n';
        for (int i = 0; i < numOfShape; ++i)
        {
          rebdev::rectangle_t rect = shapes[i]->getFrameRect();
          rebdev::point_t lowLeft = {rect.pos_.x_ - rect.width_/2, rect.pos_.y_ - rect.height_/2};
          rebdev::point_t upRight = {lowLeft.x_ + rect.width_, lowLeft.y_ + rect.height_};
          std::cout << lowLeft.x_ << " " << lowLeft.y_ << " ";
          std::cout << upRight.x_ << " " << upRight.y_ << '\n';
        }

        rebdev::isoScale(shapes, numOfShape, isoPoint, k);
        isScale = 1;
        break;
      }
    }
    else if (sym == 'R')
    {
      figureNumber = 0;
      numberOfVertexs = 2;
      figureName = rectangleName;
    }
    else if (sym == 'C')
    {
      figureNumber = 1;
      numberOfVertexs = 4;
      figureName = concaveName;
    }
    else if (sym == 'P')
    {
      figureNumber = 2;
      numberOfVertexs = 0;
      figureName = polygonName;
    }

    if (figureNumber != -1)
    {
      if (rebdev::isNameCorrect(std::cin, sizeOfFigureName[figureNumber], figureName))
      {
        pointArr = rebdev::ipnutVertexs(std::cin, numberOfVertexs);
        if (pointArr != nullptr)
        {
          if (rebdev::figureIsCorrect(pointArr, numberOfVertexs, figureNumber))
          {
            shapes[numOfShape] = newFigure(pointArr, numberOfVertexs, figureNumber);
            numOfShape += 1;
          }
          else
          {
            std::cout << "1\n";
            figureError = 1;
          }
        }
        else
        {
          std::cout << "0\n";
          figureError = 1;
        }
      }
    }
  }

  if (figureError)
  {
    std::cerr << "Some figure is incorrect!\n";
  }
  if (!isScale)
  {
   std::cerr << "Programm end without scale!\n";
   return 1;
  }

  double sum = 0;
  for (int i = 0; i < numOfShape; ++i)
  {
    sum += shapes[i]->getArea();
  }
  std::cout << sum << '\n';
  for (int i = 0; i < numOfShape; ++i)
  {
    rebdev::rectangle_t rect = shapes[i]->getFrameRect();
    rebdev::point_t lowLeft = {rect.pos_.x_ - rect.width_/2, rect.pos_.y_ - rect.height_/2};
    rebdev::point_t upRight = {lowLeft.x_ + rect.width_, lowLeft.y_ + rect.height_};
    std::cout << lowLeft.x_ << " " << lowLeft.y_ << " ";
    std::cout << upRight.x_ << " " << upRight.y_ << '\n';
    delete[] shapes[i];
  }

  delete[] shapes;
  return 0;
}
