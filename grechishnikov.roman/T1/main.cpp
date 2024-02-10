#include <stdexcept>
#include <iostream>
#include "inputString.hpp"
#include "inputShapes.hpp"
#include "parametersLogic.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "polygon.hpp"
#include "isoScale.hpp"
#include "outputShapes.hpp"

int main()
{
  using namespace grechishnikov;

  const char* str = nullptr;
  const char* name = nullptr;
  Shape* shapes[1000] = { nullptr };

  size_t count = 0;
  bool endOfInput = false;
  try
  {
    while (!endOfInput)
    {
      const char* tempStr = inputString(std::cin);
      delete[] str;
      str = tempStr;
      const char* tempName = parseName(str);
      delete[] name;
      name = tempName;

      if (!isEqualStr(name, "SCALE\0"))
      {
        shapes[count] = inputShape(str);
        count++;
      }

      if (isEqualStr(name, "SCALE\0"))
      {
        endOfInput = true;

        if (count == 0)
        {
          throw std::logic_error("Nothing to scale");
        }
        size_t size = 0;
        const double* values = parseValues(str + 5, size);
        if (size != 3)
        {
          delete[] values;
          throw std::logic_error("Incorrect number of parameters to scale");
        }

        outputShapes(std::cout, shapes, count);
        std::cout << '\n';
        for (size_t g = 0; g < count; g++)
        {
          isoScale(shapes[g], { values[0], values[1] }, values[2]);
        }
        outputShapes(std::cout, shapes, count);
        std::cout << '\n';

        delete[] values;
        delete[] str;
        delete[] name;
      }
    }
  }
  catch (const std::bad_alloc &e)
  {
    delete[] str;
    delete[] name;
    freeShapes(shapes, count);
    std::cout << "Error: Cannot allocate enough memory" << '\n';
    return 2;
  }
  catch (const std::logic_error &e)
  {
    delete[] str;
    delete[] name;
    freeShapes(shapes, count);
    std::cout << "Error: " << e.what() << '\n';
    return 1;
  }

  if (!checkEnteredShapes(shapes, count))
  {
    std::cerr << "Some shapes were not processed" << '\n';
  }

  freeShapes(shapes, count);
}
