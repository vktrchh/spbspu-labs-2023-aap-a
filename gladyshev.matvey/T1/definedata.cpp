#include <iostream>

#include "definedata.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "parallelogram.hpp"

namespace gladyshev
{
  Shape * inputRectangle(const char * string)
  {
    double p[4] = { 0 };
    size_t counter = 0;
    const char * tempString = string;
    for (size_t i = 0; i < 4; i++)
    {
      p[i] = std::stod(tempString, std::addressof(counter));
      tempString += counter;
    }
    if (*tempString != '\0')
    {
      throw std::invalid_argument("too many args for rectangle");
    }
    if ((p[0] == p[2]) || (p[1] == p[3]) || (p[2] < p[0]) || (p[3] < p[1]))
    {
      return nullptr;
    }
    return new Rectangle({ p[0], p[1] }, { p[2], p[3] });
  }

  void inputScale(const char * string, point_t& pos, double& factor)
  {
    double dataScale[3] = { 0 };
    size_t counter = 0;
    const char * tempString = string;
    for (size_t i = 0; i < 3; ++i)
    {
      dataScale[i] = std::stod(tempString, std::addressof(counter));
      tempString += counter;
    }
    if (*tempString != '\0')
    {
      throw std::logic_error("too many arguments for scale");
    }
    if (dataScale[2] <= 0)
    {
      throw std::logic_error("factor of scale must be positive");
    }
    pos = { dataScale[0], dataScale[1] };
    factor = dataScale[2];
  }
  Shape* inputCircle(const char * string)
  {
    double rectCoords[3] = { 0 };
    size_t counter = 0;
    const char * tempString = string;
    for (size_t i = 0; i < 3; ++i)
    {
      rectCoords[i] = std::stod(tempString, std::addressof(counter));
      tempString += counter;
    }
    if (*tempString != '\0')
    {
      throw std::logic_error("too many arguments for circle");
    }
    if (rectCoords[2] <= 0)
    {
      return nullptr;
    }
    return new Circle({ rectCoords[0], rectCoords[1] }, rectCoords[2]);
  }
  Shape * inputParallelogram(const char * string)
  {
    double p[6] = { 0 };
    size_t counter = 0;
    const char * tempString = string;
    for (size_t i = 0; i < 6; ++i)
    {
      p[i] = std::stod(tempString, std::addressof(counter));
      tempString += counter;
    }
    if (*tempString != '\0')
    {
      throw std::logic_error("too many arguments for parallelogram");
    }
    if (!(((p[1] == p[3]) && (p[3] != p[5]) && (p[0] != p[2])) || ((p[3] == p[5]) && (p[5] != p[1]) && (p[2] != p[4]))))
    {
      return nullptr;
    }
    return new Parallelogram({ p[0], p[1] }, { p[2], p[3] }, { p[4], p[5] });
  }
  void freeMemory(Shape ** shapes, size_t amount)
  {
    for (size_t i = 0; i < amount; ++i)
    {
      delete shapes[i];
    }
  }
  Shape * identifyShape(std::string inputName, const char* string)
  {
    const char* names[] = { "RECTANGLE", "PARALLELOGRAM", "CIRCLE" };
    for (size_t i = 0; i < 3; ++i)
    {
      if (inputName == names[i])
      {
        switch (i)
        {
          case 0:
            return inputRectangle(string);
          case 1:
            return inputParallelogram(string);
          case 2:
            return inputCircle(string);
        }
      }
    }
  }
}
