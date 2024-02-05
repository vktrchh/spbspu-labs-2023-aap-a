#include <stdexcept>
#include <iostream>
#include "inputString.hpp"
#include "parametersLogic.hpp"
#include "base-types.hpp"

int main()
{
  using namespace grechishnikov;
  size_t size = 0;
  const char* str = nullptr;
  const double* db = nullptr;
  const point_t* points = nullptr;
  try
  {
    str = inputString(std::cin);
    db = parseValues(str, size);
    points = makePairs(db, size);
  }
  catch (const std::bad_alloc &e)
  {
    delete[] str;
    delete[] db;
    delete[] points;
    std::cout << "bad_alloc" << '\n';
    return 1;
  }
  catch (const std::logic_error &e)
  {
    delete[] str;
    delete[] db;
    delete[] points;
    std::cout << e.what() << '\n';
    return 1;
  }
  catch (...)
  {
    delete[] str;
    delete[] db;
    delete[] points;
    std::cout << "AAAAA" << '\n';
    return 1;
  }

  for (size_t i = 0; i < size; i++)
  {
    std::cout << db[i] << ' ';
  }
  std::cout << '\n';
  for (size_t i = 0; i < size / 2; i++)
  {
    std::cout << points[i].x << ' ' << points[i].y << '\n';
  }
  std::cout << '\n';

  delete[] points;
  delete[] str;
  delete[] db;
}
