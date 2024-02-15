#include "scale_figures.hpp"
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "shape.hpp"

void outputFrame(nikitov::Shape* figure, std::ostream& output)
{
  nikitov::rectangle_t frame = figure->getFrameRect();
  output << ' ' << frame.pos.x - frame.width / 2;
  output << ' ' << frame.pos.y - frame.height / 2;
  output << ' ' << frame.pos.x + frame.width / 2;
  output << ' ' << frame.pos.y + frame.height / 2;
}

void nikitov::scaleFigure(Shape* figure, const point_t& isoScaleCenter, double ratio)
{
  point_t center = figure->getFrameRect().pos;
  figure->move({ isoScaleCenter.x, isoScaleCenter.y });
  figure->scale(ratio);
  double dx = (isoScaleCenter.x - center.x) * ratio;
  double dy = (isoScaleCenter.y - center.y) * ratio;
  figure->move(-dx, -dy);
}

void nikitov::scaleFigures(CompositeShape& composition, const point_t& isoScaleCenter, double ratio, std::ostream& output)
{
  output << std::fixed << std::setprecision(1);
  if (ratio > 0)
  {
    output << composition.getArea();

    for (size_t i = 0; i != composition.size(); ++i)
    {
      outputFrame(&composition[i], output);
    }
    output << '\n';

    composition.move(isoScaleCenter);
    composition.scale(ratio);

    output << composition.getArea();

    for (size_t i = 0; i != composition.size(); ++i)
    {
      outputFrame(&composition[i], output);
    }
    std::cout << '\n';
  }
  else
  {
    throw std::invalid_argument("Error: Wrong scale parameters");
  }
}
