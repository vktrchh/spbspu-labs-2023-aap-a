#include "string.hpp"
#include <stdexcept>

char* resize(char* str, size_t size, size_t shift)
{
  char* resized = nullptr;
  try
  {
    resized = new char[size + shift + 1]{};
  }
  catch (const std::bad_alloc& e)
  {
    throw e;
  }
  for (size_t i = 0; i < size; ++i)
  {
  resized[i] = str[i];
  }
  resized[size + shift] = '\0';
  delete[] str;
  str = resized;
  return str;
}
