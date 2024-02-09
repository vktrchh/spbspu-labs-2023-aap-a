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

void nikitov::scaleFigures(Shape** figures, size_t nFigures, const point_t& isoScaleCenter, double ratio, std::ostream& output)
{
  output << std::fixed << std::setprecision(1);
  if (ratio > 0)
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
      figures[i]->move({ isoScaleCenter.x, isoScaleCenter.y });
      figures[i]->scale(ratio);
      double dx = (isoScaleCenter.x - center.x) * ratio;
      double dy = (isoScaleCenter.y - center.y) * ratio;
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
    throw std::invalid_argument("Error: Wrong scale parameters");
  }
}
