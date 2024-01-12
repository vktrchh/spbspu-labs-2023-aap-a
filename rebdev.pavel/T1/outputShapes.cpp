#include "outputShapes.hpp"

void rebdev::outputShapes(Shape ** shapes, int numOfShapes, std::ostream & out)
{
  double sum = 0;
  for (int i = 0; i < numOfShapes; ++i)
  {
    sum += shapes[i]->getArea();
  }

  out << std::fixed;
  out.precision(1);

  out << sum;

  for (int i = 0; i < numOfShapes; ++i)
  {
    rebdev::rectangle_t rect = shapes[i]->getFrameRect();
    rebdev::point_t lowLeft = {rect.pos_.x_ - rect.width_/2, rect.pos_.y_ - rect.height_/2};
    rebdev::point_t upRight = {lowLeft.x_ + rect.width_, lowLeft.y_ + rect.height_};
    out << ' ' << lowLeft.x_ << ' ' << lowLeft.y_;
    out << ' ' << upRight.x_ << ' ' << upRight.y_;
  }

  out << '\n';
};
