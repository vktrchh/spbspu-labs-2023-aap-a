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

int main()
{
  using namespace grechishnikov;

  size_t size = 0;
  const char* str = nullptr;
  const char* name = nullptr;
  Shape* shapes[1000] = { nullptr };
  const size_t legalNameCount = 3;
  const char* legalName[] = { "RECTANGLE\0", "TRIANGLE\0", "POLYGON\0" };

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

      for (size_t i = 0; i < legalNameCount; i++)
      {
        if (isEqualStr(legalName[i], name))
        {
          shapes[count] = inputShape(str);
          count++;
        }
      }

      if (isEqualStr(name, "SCALE\0"))
      {
        delete[] str;
        delete[] name;
        endOfInput = true;
      }
    }
  }
  catch (const std::bad_alloc &e)
  {
    delete[] str;
    delete[] name;
    freeShapes(shapes, count);
    std::cout << "bad_alloc" << '\n';
    return 1;
  }
  catch (const std::logic_error &e)
  {
    delete[] str;
    delete[] name;
    freeShapes(shapes, count);
    std::cout << e.what() << '\n';
    return 1;
  }

  for (size_t i = 0; i < count; i++)
  {
    std::cout << shapes[i]->getArea() << '\n';
  }

  freeShapes(shapes, count);
}
