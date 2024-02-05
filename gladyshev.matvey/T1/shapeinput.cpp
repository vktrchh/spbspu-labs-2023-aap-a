#include <iostream>

#include "shapeinput.hpp"
#include "memoryallocate.hpp"
#include "definedata.hpp"
#include "inputarray.hpp"

namespace gladyshev
{
  void shapeInput(std::istream& in, Shape ** shapes, bool& incorFig, bool& unsupFig, point_t& pos, size_t& counter, double& factor)
  {
    size_t mainCounter = 0;
    char * rectangleData = nullptr;
    std::string inputName = "";
    while (in >> inputName)
    {
      try
      {
        rectangleData = inputArray(in);
      }
      catch (const std::bad_alloc& e)
      {
        freeMemory(shapes, mainCounter);
        throw;
      }
      if (inputName == "RECTANGLE" || inputName == "PARALLELOGRAM" || inputName == "CIRCLE")
      {
        Shape * checkedShape = nullptr;
        try
        {
          checkedShape = identifyShape(inputName, rectangleData);
        }
        catch (const std::logic_error& e)
        {
          delete[] rectangleData;
          freeMemory(shapes, mainCounter);
          throw;
        }
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
          delete[] rectangleData;
          throw std::logic_error("lack of supported data");
        }
        counter = mainCounter;
        try
        {
          inputScale(rectangleData, pos, factor);
        }
        catch (const std::logic_error& e)
        {
          delete[] rectangleData;
          freeMemory(shapes, mainCounter);
          throw;
        }
        delete[] rectangleData;
        return;
      }
      else
      {
        unsupFig = true;
      }
      delete[] rectangleData;
    }
    if (in.eof())
    {
      freeMemory(shapes, mainCounter);
      throw std::runtime_error("EOF");
    }
  }
}
