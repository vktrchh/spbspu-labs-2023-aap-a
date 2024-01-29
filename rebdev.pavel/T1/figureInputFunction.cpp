#include "figureInputFunction.hpp"
#include "rectangle.hpp"
#include "concave.hpp"
#include "polygon.hpp"

rebdev::Shape * rebdev::newFigure(std::istream & input, const std::string & name)
{
  Shape * figure = nullptr;

  if (name == "RECTANGLE")
  {
    point_t vertexs[2] = {{0.0, 0.0}, {0.0, 0.0}};
    input >> vertexs[0].x >> vertexs[0].y >> vertexs[1].x >> vertexs[1].y;

    if (!input)
    {
      throw "input error";
    }

    figure = new Rectangle(vertexs);
  }
  else if (name == "CONCAVE")
  {
    point_t vertexs[4] = {{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}};

    for (size_t i = 0; i < 4; ++i)
    {
      input >> vertexs[i].x >> vertexs[i].y;
      if (!input)
      {
        throw "input error";
      }
    }

    figure = new Concave(vertexs);
  }
  else if (name == "POLYGON")
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

    try
    {
      bufferArr = new point_t[numOfVertexs];
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

    delete[] vertexs;
    vertexs = bufferArr;
    bufferArr = nullptr;

    try
    {
      figure = new Polygon(vertexs, numOfVertexs);
    }
    catch (const std::exception & e)
    {
      delete[] vertexs;

      throw e;
    }

    delete[] vertexs;
  }

  return figure;
};
