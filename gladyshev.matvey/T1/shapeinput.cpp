#include "shapeinput.hpp"
#include "definedata.hpp"

#include <iostream>

namespace gladyshev
{
  void shapeInput(std::istream& in, Shape ** shapes, point_t& pos, size_t& counter, double& factor)
  {
    size_t mainCounter = 0;
    bool unsupFig = false;
    std::string inputName = "";
    while (in >> inputName)
    {
      try
      {
        if (inputName == "SCALE")
        {
          if (mainCounter == 0)
          {
            throw std::out_of_range("lack of supported data");
          }
          counter = mainCounter;
          inputScale(in, pos, factor);
          if (unsupFig)
          {
            throw std::runtime_error("there are incorrect or unsupported figures");
          }
          return;
        }
        Shape * checkedShape = identifyShape(inputName, in);
        if (in.get() != '\n')
        {
          delete checkedShape;
          throw std::logic_error("too many args");
        }
        shapes[mainCounter++] = checkedShape;
      }
      catch (const std::invalid_argument& e)
      {
        unsupFig = true;
      }
      catch (const std::logic_error& e)
      {
        freeMemory(shapes, mainCounter);
        throw;
      }
    }
    if (in.eof())
    {
      freeMemory(shapes, mainCounter);
      throw std::out_of_range("EOF");
    }
  }
}
