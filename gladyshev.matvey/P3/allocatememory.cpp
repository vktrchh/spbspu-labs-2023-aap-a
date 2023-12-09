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
    delete[] basicar;
    throw;
  }
  for (size_t i = 0; i < len; ++i)
  {
    newarr[i] = basicar[i];
  }
  delete[] basicar;
  return newarr;
}
