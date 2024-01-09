#include "scale_figures.hpp"
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "shape.hpp"

double countAreasSum(nikitov::Shape** figures, size_t nFigures)
{
  double areasSum = 0.0;
  for(size_t i = 0; i != nFigures; ++i)
  {
    areasSum += figures[i]->getArea();
  }
  return areasSum;
}

void outputFrame(nikitov::Shape* figure, std::ostream& output)
{
  nikitov::rectangle_t frame = figure->getFrameRect();
  output << ' ' << frame.pos.x - frame.width / 2;
  output << ' ' << frame.pos.y - frame.height / 2;
  output << ' ' << frame.pos.x + frame.width / 2;
  output << ' ' << frame.pos.y + frame.height / 2;
}

void nikitov::scaleFigures(Shape** figures, std::string line, size_t nFigures, std::ostream& output)
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

  output << std::fixed << std::setprecision(1);
  if (coordinates[2] > 0)
  {
    output << countAreasSum(figures, nFigures);

    for(size_t i = 0; i != nFigures; ++i)
    {
      outputFrame(figures[i], output);
    }
    output << '\n';

    for(size_t i = 0; i != nFigures; ++i)
    {
      point_t center = figures[i]->getFrameRect().pos;
      figures[i]->move({ coordinates[0], coordinates[1] });
      figures[i]->scale(coordinates[2]);
      double dx = (coordinates[0] - center.x) * coordinates[2];
      double dy = (coordinates[1] - center.y) * coordinates[2];
      figures[i]->move(-dx, -dy);
    }

    output << countAreasSum(figures, nFigures);

    for(size_t i = 0; i != nFigures; ++i)
    {
      outputFrame(figures[i], output);
    }
    std::cout << '\n';
  }
  else
  {
    throw std::invalid_argument("Error");
  }
}
