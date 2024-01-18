#include "add_numbers.hpp"

size_t countNumbers(const char * str)
{
  size_t i = 0, count = 0;
  while (str[i] != 0)
  {
    if (isdigit(str[i]))
    {
      count += 1;
    }
    i += 1;
  }
  return count;
}

char * lopatina::addNumbers(char * first_str, const char * second_str, size_t size1, size_t size2)
{
  size_t num_dig = countNumbers(second_str);
  if (num_dig == 0)
  {
    return first_str;
  }
  char * result = new char[size1 + num_dig];
  size_t last = 0;
  for (size_t i = 0; i < size1; ++i)
  {
    if (first_str[i] == '\0')
    {
      last = i - 1;
      break;
    }
    result[i] = first_str[i];
  }
  for (size_t j = 0; j < size2; ++j)
  {
    if (isdigit(second_str[j]))
    {
      last += 1;
      result[last] = second_str[j];
    }
  }
  result[last + 1] = '\0';
  return result;
}
