#include "changeString.hpp"

char* novokhatskiy::changeString(char* in, char* out)
{
  char* result = out;
  do
  {
    std::isalpha(*in) || (*out++ = *in);
  }
  while (*in++);
  return result;
}
