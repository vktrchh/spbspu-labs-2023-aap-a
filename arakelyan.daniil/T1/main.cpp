#include <iostream>
#include <stdexcept>
#include <cstring>
#include <inputLine.hpp>

#include "shape.hpp"
#include "base-types.hpp"
#include "inputAndOutputOperations.hpp"
#include "scaleOperations.hpp"
#include "shape-creation.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "parallelogram.hpp"

int main()
{
  using namespace arakelyan;
  size_t maxShapesCount = 1000;
  size_t currentShapesCount = 0;
  Shape **myShapes = new Shape * [maxShapesCount]{nullptr};

  bool errorsFlagShapes = false;
  bool errorsFlagScale = false;

  point_t scalePoint = {0.0, 0.0};
  double scaleK = 0;
  const char * targetWordScale = "SCALE";

  char *string = nullptr;

  bool readingFromInput = true;

  while (readingFromInput)
  {
    if (!std::cin.good())
    {
      freeMem(myShapes, currentShapesCount);
      std::cerr << "Somthing went wrong with input, might be EOF!\n";
      return 1;
    }

    try
    {
      string = inputLine(std::cin);
    }
    catch (const std::exception &e)
    {
      freeMem(myShapes, currentShapesCount);
      std::cerr << "Error: " << e.what() << "\n";
      return 1;
    }

    const char * foundScale = std::strstr(string, targetWordScale);
    if (foundScale != nullptr)
    {
      inputScaleParam(string, scalePoint, scaleK);

      readingFromInput = false;
    }
    else
    {
      try
      {
        defineAndCreateShape(myShapes, currentShapesCount, string);
      }
      catch (const std::exception &e)
      {
        errorsFlagShapes = true;
      }

      if (myShapes[currentShapesCount] != nullptr)
      {
        currentShapesCount++;
      }
    }

    delete [] string;
  }

  try
  {
    scaleFunction(myShapes, currentShapesCount, scalePoint, scaleK);
  }
  catch (const std::logic_error &e)
  {
    errorsFlagScale = true;
  }

  if (errorsFlagShapes)
  {
    std::cerr << "Something went wrong with shapes creation!\n";
  }
  if (errorsFlagScale)
  {
    std::cerr << "Something went wrong with scale process!\n";
    freeMem(myShapes, currentShapesCount);
    return 2;
  }

  if (currentShapesCount == 0)
  {
    std::cerr << "Nothing to scale!\n";
    freeMem(myShapes, currentShapesCount);
    return 2;
  }

  freeMem(myShapes, currentShapesCount);
  return 0;
}
