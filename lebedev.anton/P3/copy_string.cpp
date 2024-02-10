#include "copy_string.hpp"

char * lebedev::copyString(char * string)
{
  size_t string_size = 10;
  size_t current_index = 0;
  char * copy = new char[string_size];

  while (string[current_index] != '\0')
  {
    if (current_index + 1 == string_size)
    {
      try
      {
        char * buffer = new char[string_size + 5];
        for (size_t i = 0; i < string_size; ++i)
        {
          buffer[i] = copy[i];
        }
        delete[] copy;
        copy = buffer;
        string_size += 5;
      }
      catch (...)
      {
        delete[] copy;
        throw;
      }
    }
    copy[current_index] = string[current_index];
    ++current_index;
  }
  copy[current_index] = '\0';
  return copy;
}
