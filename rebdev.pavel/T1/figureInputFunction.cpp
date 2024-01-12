#include "figureInputFunction.hpp"
#include <cmath>

bool rebdev::isRectangle(point_t * pointsArr)
{
  if ((pointsArr[0].x_ > pointsArr[1].x_) && (pointsArr[0].y_ > pointsArr[1].y_))
  {
    pointsArr[0].x_ += pointsArr[1].x_;
    pointsArr[1].x_ = pointsArr[0].x_ - pointsArr[1].x_;
    pointsArr[0].x_ -= pointsArr[1].x_;

    pointsArr[0].y_ += pointsArr[1].y_;
    pointsArr[1].y_ = pointsArr[0].y_ - pointsArr[1].y_;
    pointsArr[0].y_ -= pointsArr[1].y_;
  }
  else if (!((pointsArr[0].x_ < pointsArr[1].x_) && (pointsArr[0].y_ < pointsArr[1].y_)))
  {
    return 0;
  }
  return 1;
};

bool rebdev::isConcave(point_t * pointsArr)
{
  for (int i = 0; i < 4; ++i)
  {
    if (isTriangle(pointsArr[i], pointsArr[(i + 1) % 4], pointsArr[(i + 2) % 4]))
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
        arr[j] = (pointsArr[(i + j) % 4].x_ - pointsArr[(i + 3) % 4].x_)
          * (pointsArr[(i + (j + 1) % 3) % 4].y_ - pointsArr[(i + j) % 4].y_);
        arr[j] -= (pointsArr[(i + (j + 1) % 3) % 4].x_ - pointsArr[(i + j) % 4].x_)
          * (pointsArr[(i + j) % 4].y_ - pointsArr[(i + 3) % 4].y_);
      }

      bool identicalSigns = ((arr[0] > 0) && (arr[1] > 0) && (arr[2] > 0));
      identicalSigns = (identicalSigns || ((arr[0] < 0) && (arr[1] < 0) && (arr[2] < 0)));

      if (identicalSigns)
      {
        point_t newPointArr[4] = {pointsArr[i], pointsArr[(i + 1) % 4], pointsArr[(i + 2) % 4], pointsArr[(i + 3) % 4]};
        for (int i = 0; i < 4; ++i)
        {
          pointsArr[i] = newPointArr[i];
        }
        return 1;
      }
    }
  }
  return 0;
};

bool rebdev::isPolygon(const point_t * pointsArr, const size_t size)
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

bool rebdev::isTriangle(const point_t f, const point_t s, const point_t t)
{
    return (((t.x_ - f.x_) / (s.x_ - f.x_)) != ((t.y_ - f.y_) / (s.y_ - f.y_)));
};

bool rebdev::isNameCorrect(std::istream & input, const int nameSize, const char * name)
{
char sym = 0;
  for (int i = 1; i < nameSize; ++i)
  {
    input >> sym;
    if (sym != name[i])
    {
      return 0;
    }
  }

  return 1;
};

rebdev::point_t * rebdev::ipnutVertexs(std::istream & input, size_t & numOfVertexs)
{
  point_t * vertexsArr = nullptr;
  if (numOfVertexs != 0)
  {
    try
    {
      vertexsArr = new point_t[numOfVertexs];
    }
    catch (const std::exception & e)
    {
      delete[] vertexsArr;
      return nullptr;
    }
    for (size_t i = 0; i < numOfVertexs; ++i)
    {
      input >> vertexsArr[i].x_ >> vertexsArr[i].y_;
      if (!input)
      {
        delete[] vertexsArr;
        return nullptr;
      }
    }
  }
  else
  {
    point_t * bufferArr = nullptr;
    size_t bufferSize = 0;
    while (input.peek() != '\n')
    {
      if (numOfVertexs == bufferSize)
      {
        bufferSize += 10;
        try
        {
          bufferArr = new point_t[bufferSize];
        }
        catch (const std::exception & e)
        {
          delete[] bufferArr;
          delete[] vertexsArr;
          return nullptr;
        }
        for (size_t i = 0; i < numOfVertexs; ++i)
        {
          bufferArr[i] = vertexsArr[i];
        }
        for (size_t i = numOfVertexs; i < bufferSize; ++i)
        {
          bufferArr[i] = point_t{0.0, 0.0};
        }
        delete[] vertexsArr;
        vertexsArr = bufferArr;
        bufferArr = nullptr;
      }

      input >> vertexsArr[numOfVertexs].x_ >> vertexsArr[numOfVertexs].y_;
      numOfVertexs += 1;
    }
    try
    {
      bufferArr = new point_t[numOfVertexs];
    }
    catch (const std::exception & e)
    {
      delete[] bufferArr;
      delete[] vertexsArr;
      return nullptr;
    }

    for (size_t i = 0; i < numOfVertexs; ++i)
    {
      bufferArr[i] = vertexsArr[i];
    }

    delete[] vertexsArr;
    vertexsArr = bufferArr;
    bufferArr = nullptr;
  }

  return vertexsArr;
};

bool rebdev::figureIsCorrect(point_t * vertexsArr, const size_t numOfVertexs, const int figureNumber)
{
  if (figureNumber == 0)
  {
    return isRectangle(vertexsArr);
  }
  else  if (figureNumber == 1)
  {
    return isConcave(vertexsArr);
  }
  else  if (figureNumber == 2)
  {
    return isPolygon(vertexsArr, numOfVertexs);
  }
  return 0;
};

rebdev::Shape * rebdev::newFigure(point_t * vertexsArr, const size_t numOfVertexs, const int figureNumber)
{
  if (figureNumber == 0)
  {
    return (new Rectangle(vertexsArr[0], vertexsArr[1]));
  }
  else  if (figureNumber == 1)
  {
    return (new Concave(vertexsArr));
  }
  else  if (figureNumber == 2)
  {
    return (new Polygon(vertexsArr, numOfVertexs));
  }
  return nullptr;
};
