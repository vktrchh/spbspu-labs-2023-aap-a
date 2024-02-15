#include "figureInputFunction.hpp"
#include "rectangle.hpp"
#include "concave.hpp"
#include "polygon.hpp"

rebdev::Shape * rebdev::newFigure(std::istream & input, const std::string & name)
{
  if (name.find("RECTANGLE") != std::string::npos)
  {
    point_t vertexs[2] = {{0.0, 0.0}, {0.0, 0.0}};
    inputVertexs(input, vertexs, 2);
    return (new Rectangle(vertexs[0], vertexs[1]));
  }
  else if (name.find("CONCAVE") != std::string::npos)
  {
    point_t vertexs[4] = {{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}};
    inputVertexs(input, vertexs, 4);
    return (new Concave(vertexs[0], vertexs[1], vertexs[2], vertexs[3]));
  }
  else if (name.find("POLYGON") != std::string::npos)
  {
    point_t * vertexs = new point_t[1];
    point_t * bufferArr = nullptr;
    size_t bufferSize = 0, numOfVertexs = 0;

    while (input >> vertexs[numOfVertexs].x >> vertexs[numOfVertexs].y)
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
          delete[] vertexs;

          throw;
        }

        bufferArr[0] = vertexs[0];
        for (size_t i = 1; i < numOfVertexs; ++i)
        {
          bufferArr[i] = vertexs[i];
        }

        delete[] vertexs;
        vertexs = bufferArr;
        bufferArr = nullptr;
      }

      numOfVertexs += 1;
    }

    input.clear();

    bufferArr = new point_t[numOfVertexs];

    for (size_t i = 0; i < numOfVertexs; ++i)
    {
      bufferArr[i] = vertexs[i];
    }

    delete[] vertexs;
    vertexs = bufferArr;
    bufferArr = nullptr;
    Shape * polygon = nullptr;
    try
    {
      polygon = new Polygon(vertexs, numOfVertexs);
    }
    catch (const std::logic_error & e)
    {
      delete[] vertexs;
      throw;
    }
    delete[] vertexs;
    return polygon;
  }

  return nullptr;
}

void rebdev::inputVertexs(std::istream & input, point_t * vertexs, size_t numOfVertexs)
{
    for (size_t i = 0; i < numOfVertexs; ++i)
    {
      input >> vertexs[i].x >> vertexs[i].y;

      if (!input)
      {
        throw std::logic_error("input error");
      }
    }
}
