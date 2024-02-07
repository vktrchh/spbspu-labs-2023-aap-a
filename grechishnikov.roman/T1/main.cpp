#include <stdexcept>
#include <iostream>
#include "inputString.hpp"
#include "inputShapes.hpp"
#include "parametersLogic.hpp"
#include "base-types.hpp"
#include "polygon.hpp"
#include "shape.hpp"

int main()
{
  using namespace grechishnikov;
  size_t size = 0;
  const char* str = nullptr;
  const double* db = nullptr;
  const point_t* points = nullptr;
  Shape* sh = nullptr;
  try
  {
    str = inputString(std::cin);
    sh = inputShape(str);
  }
  catch (const std::bad_alloc &e)
  {
    delete[] str;
    delete sh;
    std::cout << "bad_alloc" << '\n';
    return 1;
  }
  catch (const std::logic_error &e)
  {
    delete[] str;
    delete sh;
    std::cout << e.what() << '\n';
    return 1;
  }
  catch (...)
  {
    delete[] str;
    delete sh;
    std::cout << "AAAAA" << '\n';
    return 1;
  }

  std::cout << sh->getArea() << '\n';

  delete[] str;
  delete sh;
}
