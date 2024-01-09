#include "scale_figures.hpp"

#include <iostream>
#include <stdexcept>

void nikitov::scaleFigures(Shape** figures, size_t nFigures, std::string line)
{
  line = line.substr(6);
  const char* cLine = line.c_str();
  size_t coordinatePointer = 0;
  double coordinates[3] = {};
  for (size_t i = 0; i != 3; ++i)
  {
    coordinates[i] = std::stod(cLine, &coordinatePointer);
    cLine += coordinatePointer;
  }
  if (coordinates[2] > 0)
  {
    double sumOfAreas = 0;
    for(size_t i = 0; i != nFigures; ++i)
    {
      sumOfAreas += figures[i]->getArea();
    }
    std::cout << sumOfAreas << ' ';

    for(size_t i = 0; i != nFigures; ++i)
    {
      rectangle_t frame = figures[i]->getFrameRect();
      std::cout << frame.pos.x - frame.width / 2 << ' ';
      std::cout << frame.pos.y - frame.height / 2 << ' ';
      std::cout << frame.pos.x + frame.width / 2 << ' ';
      std::cout << frame.pos.y + frame.height / 2 << ' ';
    }
    std::cout << '\n';

    for(size_t i = 0; i != nFigures; ++i)
    {
      figures[i]->move({ coordinates[0], coordinates [1] });
      figures[i]->scale(coordinates[2]);
    }

    sumOfAreas = 0;
    for(size_t i = 0; i != nFigures; ++i)
    {
      sumOfAreas += figures[i]->getArea();
    }
    std::cout << sumOfAreas << ' ';

    for(size_t i = 0; i != nFigures; ++i)
    {
      rectangle_t frame = figures[i]->getFrameRect();
      std::cout << frame.pos.x - frame.width / 2 << ' ';
      std::cout << frame.pos.y - frame.height / 2 << ' ';
      std::cout << frame.pos.x + frame.width / 2 << ' ';
      std::cout << frame.pos.y + frame.height / 2 << ' ';
    }
    std::cout << '\n';
  }
  else
  {
    throw std::invalid_argument("Error");
  }
}
