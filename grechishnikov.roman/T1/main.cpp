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
  double* db = nullptr;
  point_t* points = nullptr;
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
    std::cout << "bad_alloc" << '\n';
    return 1;
  }
  catch (const std::logic_error &e)
  {
    delete[] str;
    delete[] db;
    std::cout << e.what() << '\n';
    return 1;
  }
  catch (...)
  {
    delete[] str;
    delete[] db;
    std::cout << "AAAAA" << '\n';
    return 1;
  }

  for (size_t i = 0; i < size; ++i)
  {
    std::cout << db[i] << ' ';
  }
  std::cout << '\n';
  delete[] str;
  delete[] db;
}
