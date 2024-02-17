#include "data_process.hpp"

double ishmuratov::triangleArea(const point_t & point1, const point_t & point2, const point_t & point3)
{
  return 0.5 * std::abs(point1.x * (point2.y - point3.y) + point2.x * (point3.y - point1.y) + point3.x * (point1.y - point2.y));
}

ishmuratov::point_t ishmuratov::triangleCenter(const point_t & point1, const point_t & point2, const point_t & point3)
{
  double center_x = (point1.x + point2.x + point3.x) / 3.0;
  double center_y = (point1.y + point2.y + point3.y) / 3.0;
  return { center_x, center_y };
}

ishmuratov::point_t ishmuratov::diamondCenter(const point_t & point1, const point_t & point2, const point_t & point3)
{
  point_t pointArray[3] = {point1, point2, point3};
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if ((pointArray[i].x == pointArray[j].x) && (i != j))
      {
        for (int k = 0; k < 3; k++)
        {
          if ((k != i) && (k != j) && (pointArray[i].y == pointArray[k].y))
          {
            return pointArray[i];
          }
          else if ((k != i) && (k != j) && (pointArray[i].y == pointArray[k].y))
          {
            return pointArray[j];
          }
        }
      }
    }
  }
  return { 0, 0 };
}

