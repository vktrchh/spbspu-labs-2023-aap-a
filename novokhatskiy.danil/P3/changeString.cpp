#include <iostream>
#include <cctype>

void novokhatskiy::changeString(const char* in, char* out)
{
  do
  {
    if (!std::isalpha(*in))
    {
      *out++ = *in;
    }
  }
  while (*++in);
}
