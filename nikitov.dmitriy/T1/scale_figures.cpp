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

void scaleFigure(nikitov::Shape* figure, const nikitov::point_t& isoScaleCenter, double ratio)
{
  nikitov::point_t center = figure->getFrameRect().pos;
  figure->move({ isoScaleCenter.x, isoScaleCenter.y });
  figure->scale(ratio);
  double dx = (isoScaleCenter.x - center.x) * ratio;
  double dy = (isoScaleCenter.y - center.y) * ratio;
  figure->move(-dx, -dy);
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
      scaleFigure(figures[i], isoScaleCenter, ratio);
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
