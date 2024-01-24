#include "mergeTwoLines.hpp"

#include <cstddef>
#include <cstring>

char* skuratov::mergeTwoLines(char* line1, char* line2)
{
  size_t size1 = 0;
  while (*line1 != '\0')
  {
    size1++;
    line1++;
  }
  size_t size2 = 0;
  while (*line2 != '\0')
  {
    size2++;
    line2++;
  }
  int c = size1;
  int c2 = size2;
  while (c > 0)
  {
    line1--;
    c--;
  }
  while (c2 > 0)
  {
    line2--;
    c2--;
  }
  size_t size = size1 + size2;
  char* result = new char[size + 1];

  size_t r = 0;
  int i = 0;
  while (*line1 != '\0' || *line2 != '\0')
  {
    if (*line1 != '\0')
    {
      result[i] = *line1;
      i++;
      line1++;
    }
    if (*line2 != '\0')
    {
      result[i] = *line2;
      i++;
      line2++;
    }
  }
  result[i] = '\0';
  return result;
}
