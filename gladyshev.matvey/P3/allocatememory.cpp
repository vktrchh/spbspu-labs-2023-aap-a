#include "allocatememory.h"

char * gladyshev::newMemory(const char * basicar, size_t len)
{
  char * newarr = nullptr;
  try
  {
    newarr = new char[len + 11];
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Error in data\n";
    delete[] basicar;
    throw;
  }
  for (size_t i = 0; i < len; ++i)
  {
    newarr[i] = basicar[i];
  }
  for (size_t i = len; i < len + 11; ++i)
  {
    newarr[i] = 0;
  }
  delete[] basicar;
  return newarr;
}
