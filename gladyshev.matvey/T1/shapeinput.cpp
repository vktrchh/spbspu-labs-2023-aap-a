#include <iostream>

#include "shapeinput.hpp"
#include "definedata.hpp"

namespace gladyshev
{
  void shapeInput(std::istream& in, Shape ** shapes, bool& incorFig, bool& unsupFig, point_t& pos, size_t& counter, double& factor)
  {
    size_t mainCounter = 0;
    std::string inputName = "";
    while (in >> inputName)
    {
      try
      {
        if (inputName == "RECTANGLE" || inputName == "PARALLELOGRAM" || inputName == "CIRCLE")
        {
          Shape * checkedShape = identifyShape(inputName, in);
          if (checkedShape == nullptr)
          {
            incorFig = true;
          }
          else
          {
            shapes[mainCounter++] = checkedShape;
          }
        }
        else if (inputName == "SCALE")
        {
          if (mainCounter == 0)
          {
            throw std::runtime_error("lack of supported data");
          }
          counter = mainCounter;
          inputScale(in, pos, factor);
          return;
        }
        else
        {
          unsupFig = true;
        }
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
      throw std::runtime_error("EOF");
    }
  }
}
