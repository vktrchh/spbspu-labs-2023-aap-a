#include "iso_scale.hpp"

void belokurskaya::isoScale(Shape * shapes, const point_t & pos, double ratio)
{
  point_t init_pos = shapes->getFrameRect().pos;
  shapes->move(pos);
  point_t new_pos = shapes->getFrameRect().pos;
  shapes->scale(ratio);
  shapes->move(ratio * (init_pos.x - new_pos.x), ratio * (init_pos.y - new_pos.y));
}
