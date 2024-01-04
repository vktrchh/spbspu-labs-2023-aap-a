#include "checkingTheFigures.hpp"

bool rebdev::isRectangle(point_t & firstPoint, point_t & secondPoint)
{
  if ((firstPoint.x_ > secondPoint.x_) && (firstPoint.y_ > secondPoint.y_))
  {
    firstPoint.x_ += secondPoint.x_;
    secondPoint.x_ = firstPoint.x_ - secondPoint.x_;
    firstPoint.x_ -= secondPoint.x_;

    firstPoint.y_ += secondPoint.y_;
    secondPoint.y_ = firstPoint.y_ - secondPoint.y_;
    firstPoint.y_ -= secondPoint.y_;
  }
  else if (!((firstPoint.x_ < secondPoint.x_) && (firstPoint.y_ < secondPoint.y_)))
  {
    return 0;
  }
  return 1;
};
bool rebdev::isConcave(point_t * pointArr)
{
  for (int i = 0; i < 4; ++i)
  {
    if (isTriangle(pointArr[i], pointArr[(i + 1) % 4], pointArr[(i + 2) % 4]))
    {
      double arr[3];
      /*
      Проверка пренадлежит ли точка треугольнику:
      (x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0)
      (x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0)
      (x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0)
      знаки должны быть одинаковы
      */
      for (int j = 0; j < 3; ++j)
      {
        arr[j] = (pointArr[(i + j) % 4].x_ - pointArr[(i + 3) % 4].x_)
          * (pointArr[(i + (j + 1) % 3) % 4].y_ - pointArr[(i + j) % 4].y_);
        arr[j] -= (pointArr[(i + (j + 1) % 3) % 4].x_ - pointArr[(i + j) % 4].x_)
          * (pointArr[(i + j) % 4].y_ - pointArr[(i + 3) % 4].y_);
      }

      bool identicalSigns = ((arr[0] > 0) && (arr[1] > 0) && (arr[2] > 0));
      identicalSigns = (identicalSigns || ((arr[0] < 0) && (arr[1] < 0) && (arr[2] < 0)));

      if (identicalSigns)
      {
        point_t newPointArr[4] = {pointArr[i], pointArr[(i + 1) % 4], pointArr[(i + 2) % 4], pointArr[(i + 3) % 4]};
        for (int i = 0; i < 4; ++i)
        {
          pointArr[i] = newPointArr[i];
        }
        return 1;
      }
    }
  }
  return 0;
};
bool rebdev::isPolygon(const point_t * pointsArr, size_t size)
{
  if (size < 3)
  {
    return 0;
  }
  for (size_t i = 0; i < (size - 1); ++i)
  {
    for (size_t j = (i + 1); j < size; ++j)
    {
      if ((pointsArr[i].x_ == pointsArr[j].x_) && (pointsArr[i].y_ == pointsArr[j].y_))
      {
        return 0;
      }
    }
  }
  return 1;
};

bool rebdev::isTriangle(point_t f, point_t s, point_t t)
{
  return (((t.x_ - f.x_) / (s.x_ - f.x_)) != ((t.y_ - f.y_) / (s.y_ - f.y_)));
};
