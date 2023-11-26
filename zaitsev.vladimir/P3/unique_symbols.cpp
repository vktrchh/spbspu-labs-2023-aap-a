#include "unique_symbols.h"
#include <stdexcept>
#include <cstddef>
#include "input.h"

char* unique_chars(const char* str1, const char* str2)
{
  char* res = nullptr;
  size_t capacity = 0;
  size_t size = 0;
  try
  {
    const size_t basic_size = 20;
    res = new char[basic_size];
    res[0] = '\0';
    capacity = basic_size;
    add_unique(str1, str2, std::addressof(res), std::addressof(capacity), std::addressof(size));
    add_unique(str2, str1, std::addressof(res), std::addressof(capacity), std::addressof(size));
  }
  catch (const std::bad_alloc&)
  {
    delete[] res;
    return nullptr;
  }

  return res;
}

int is_char_in_str(const char* str, char c)
{
  if (!str)
  {
    return 0;
  }
  while (*str)
  {
    if (*str == c)
    {
      return 1;
    }
    ++str;
  }
  return 0;
}

void add_unique(const char* basic_str, const char* comp_str, char** res_str, size_t* capacity, size_t* size)
{
  const size_t step = 20;
  const char* pos = basic_str;
  while (*pos)
  {
    if (!is_char_in_str(comp_str, *pos) && !is_char_in_str(*res_str, *pos))
    {
      if (size == capacity - 1)
      {
        resize_str(res_str, *capacity, *capacity + step);
        *capacity += step;
      }
      (*res_str)[*size] = *pos;
      (*res_str)[*size + 1] = '\0';
      ++* size;
    }
    ++pos;
  }
  return;
}