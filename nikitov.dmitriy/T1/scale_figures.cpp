#include "scale_figures.hpp"
#include <iostream>
#include "shape.hpp"

void nikitov::outputFrame(Shape* figure, std::ostream& output)
{
  rectangle_t frame = figure->getFrameRect();
  output << ' ' << frame.pos.x - frame.width / 2;
  output << ' ' << frame.pos.y - frame.height / 2;
  output << ' ' << frame.pos.x + frame.width / 2;
  output << ' ' << frame.pos.y + frame.height / 2;
}

void nikitov::scaleComposition(CompositeShape& composition, const point_t& isoScaleCenter, double ratio)
{
  point_t center = composition.getFrameRect().pos;
  composition.move(isoScaleCenter);
  composition.scale(ratio);
  double dx = (isoScaleCenter.x - center.x) * ratio;
  double dy = (isoScaleCenter.y - center.y) * ratio;
  composition.move(-dx, -dy);
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
