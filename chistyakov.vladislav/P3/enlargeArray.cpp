#include "enlargeArray.hpp"
#include <cstddef>

char* chistyakov::enlargeArray(char* array, size_t size)
{
  char* newArray = nullptr;

  try
  {
    char* newArray = new char[size + 1] {};

    for (size_t i = 0; i < size; ++i)
    {
      newArray[i] = array[i];
    }
    return newArray;
  }
  catch (std::logic_error& e)
  {
    delete[] newArray;
    throw e.what();
  }
}
