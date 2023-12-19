#include "strunit.hpp"
#include "string.hpp"
#include <cstddef>
#include <algorithm>

char* erohin::strunit(char* result, const char* source)
{
  size_t first_length = length(result);
  size_t second_length = length(source);
  size_t less_length = std::min(first_length, second_length);
  for (size_t i = 2 * less_length; i < first_length + second_length; ++i)
  {
    result[i] = (first_length > second_length) ? result[i - less_length] : source[i - less_length];
  }
  for (size_t i = 2 * less_length; i > 0; --i)
  {
    result[i - 1] = (i % 2 == 0) ? source[(i / 2) - 1] : result[i / 2];
  }
  result[first_length + second_length] = '\0';
  return result;
}
