#include "changeString.hpp"

char* novokhatskiy::changeString(const char* in, char* out)
{
  char* result = out;
  do
  {
    if (!std::isalpha(*in))
    {
      *out++ = *in;
    }
  }
  while (*in++);
  return result;
}
