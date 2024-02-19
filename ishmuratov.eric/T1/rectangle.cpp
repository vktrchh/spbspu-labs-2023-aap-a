#include "rectangle.hpp"

ishmuratov::Rectangle::Rectangle(const point_t & point1, const point_t & point2):
  botLeft_(point1),
  topRight_(point2)
{
  if ((botLeft_.x >= topRight_.x) || (botLeft_.y >= topRight_.y))
  {
    throw std::invalid_argument("Incorrect rectangle corners coordinates!");
  }
}

ishmuratov::Rectangle::~Rectangle() = default;

void ishmuratov::Rectangle::triangleCut(Triangle * array)
{
  array[0] = { botLeft_, {botLeft_.x, topRight_.y}, topRight_ };
  array[1] = { botLeft_, {topRight_.x, botLeft_.y}, topRight_ };
}

double ishmuratov::Rectangle::getArea()
{
  Triangle array[2] = { { { 0, 0 }, { 0, 1 }, { 1, 0 } }, { { 0, 0 }, { 0, 1 }, { 1, 0 } } };
  triangleCut(array);
  return array[0].getArea() + array[1].getArea();
}

ishmuratov::rectangle_t ishmuratov::Rectangle::getFrameRect() const
{
  Triangle tri = { botLeft_, {botLeft_.x, topRight_.y}, topRight_ };
  return tri.getFrameRect();
}

void ishmuratov::Rectangle::move(point_t & position)
{
  double center_x = getFrameRect().pos.x;
  double center_y = getFrameRect().pos.y;
  botLeft_ = { botLeft_.x + position.x - center_x, botLeft_.y + position.y - center_y };
  topRight_ = { topRight_.x + position.x - center_x, topRight_.y + position.y - center_y };
}

void ishmuratov::Rectangle::move(double dx, double dy)
{
  botLeft_ = { botLeft_.x + dx, botLeft_.y + dy };
  topRight_ = { topRight_.x + dx, topRight_.y + dy };
}

void ishmuratov::Rectangle::scale(double factor)
{
  double dxLeft = (botLeft_.x - getFrameRect().pos.x) * (factor - 1);
  double dyLeft = (botLeft_.y - getFrameRect().pos.y) * (factor - 1);
  double dxRight = (topRight_.x - getFrameRect().pos.x) * (factor - 1);
  double dyRight = (topRight_.y - getFrameRect().pos.y) * (factor - 1);
  botLeft_ = { botLeft_.x + dxLeft, botLeft_.y + dyLeft };
  topRight_ = { topRight_.x + dxRight, topRight_.y + dyRight };
}
