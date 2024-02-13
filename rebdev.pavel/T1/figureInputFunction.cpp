#include "figureInputFunction.hpp"
#include "rectangle.hpp"
#include "concave.hpp"
#include "polygon.hpp"

rebdev::Shape * rebdev::newFigure(std::istream & input, const std::string & name)
{
  if (name.find("RECTANGLE") != std::string::npos)
  {
    point_t vertexs[2] = {{0.0, 0.0}, {0.0, 0.0}};

    input >> vertexs[0].x >> vertexs[0].y >> vertexs[1].x >> vertexs[1].y;

    if (!input)
    {
      throw std::logic_error("input error");
    }

    return (new Rectangle(vertexs[0], vertexs[1]));
  }
  else if (name.find("CONCAVE") != std::string::npos)
  {
    point_t vertexs[4] = {{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}};

    for (size_t i = 0; i < 4; ++i)
    {
      input >> vertexs[i].x >> vertexs[i].y;
      if (!input)
      {
        throw std::logic_error("input error");
      }
    }

    return (new Concave(vertexs[0], vertexs[1], vertexs[2], vertexs[3]));
  }
  else if (name.find("POLYGON") != std::string::npos)
  {
    point_t * vertexs = new point_t[1];
    point_t * bufferArr = nullptr;
    size_t bufferSize = 1, numOfVertexs = 1;

    while (input >> vertexs[numOfVertexs - 1].x >> vertexs[numOfVertexs - 1].y)
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

          throw e;
        }

        for (size_t i = 0; i < numOfVertexs; ++i)
        {
          bufferArr[i] = vertexs[i];
        }
        for (size_t i = numOfVertexs; i < bufferSize; ++i)
        {
          bufferArr[i] = point_t{0.0, 0.0};
        }

        delete[] vertexs;
        vertexs = bufferArr;
        bufferArr = nullptr;
      }

      numOfVertexs += 1;
    }

    input.clear();

    numOfVertexs -= 1;

    point_t bufferArr2[numOfVertexs];

    for (size_t i = 0; i < numOfVertexs; ++i)
    {
      bufferArr2[i] = vertexs[i];
    }

    delete[] bufferArr;
    delete[] vertexs;

    return (new Polygon(bufferArr2, numOfVertexs));
  }

  return nullptr;
}
