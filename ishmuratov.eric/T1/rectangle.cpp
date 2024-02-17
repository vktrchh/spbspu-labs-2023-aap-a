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

ishmuratov::Triangle * ishmuratov::Rectangle::triangleCut() const
{
  ishmuratov::Triangle topTri = { botLeft_, {botLeft_.x, topRight_.y}, topRight_ };
  ishmuratov::Triangle botTri = { botLeft_, {topRight_.x, botLeft_.y}, topRight_ };
  ishmuratov::Triangle * array = new ishmuratov::Triangle[2]{topTri, botTri};
  array[0] = topTri;
  array[1] = botTri;
  return array;
}

double ishmuratov::Rectangle::getArea() const
{
  ishmuratov::Triangle * triangles = triangleCut();
  ishmuratov::Triangle tri1 = triangles[0];
  ishmuratov::Triangle tri2 = triangles[1];
  delete [] triangles;
  return tri1.getArea() + tri2.getArea();
}

ishmuratov::rectangle_t ishmuratov::Rectangle::getFrameRect() const
{
  double frame_width = topRight_.x - botLeft_.x;
  double frame_height = topRight_.y - botLeft_.y;
  point_t frame_pos = { botLeft_.x + (frame_width / 2), botLeft_.y + (frame_height / 2) };
  return { frame_width, frame_height, frame_pos };
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
