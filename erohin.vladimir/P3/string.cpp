#include "string.hpp"
#include <stdexcept>

char* erohin::resize(char* str, size_t size, size_t shift)
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

size_t erohin::length(const char* str)
{
  size_t i = 0;
  while (str[i++] != '\0');
  return (i - 1);
}

char* erohin::copy(char* str)
{
  char* result = nullptr;
  try
  {
    result = new char[length(str) + 1];
  }
  catch(const std::bad_alloc& e)
  {
    throw e;
  }
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    result[i] = str[i];
  }
  result[length(str)] = '\0';
  return result;
}
