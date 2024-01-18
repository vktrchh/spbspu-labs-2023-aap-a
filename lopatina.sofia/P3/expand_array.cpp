#include "expand_array.hpp"

char * lopatina::expandArray(char * arr, size_t size)
{
  size_t new_size = size + 1;
  char * new_arr = new char[new_size];
  for (size_t i = 0; i < (size - 1); ++i)
  {
    new_arr[i] = arr[i];
  }
  return new_arr;
}
