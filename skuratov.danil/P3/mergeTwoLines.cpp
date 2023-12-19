#include "mergeTwoLines.hpp"
#include <string>

std::string mergeTwoLines(const std::string& line1, const std::string& line2)
{
  std::string result;
  size_t r = 0;

  while (r < line1.length() && r < line2.length())
  {
    result += line1[r];
    result += line2[r];
    ++r;
  }
  while (r < line1.length())
  {
    result += line1[r];
    ++r;
  }
  while (r < line2.length())
  {
    result += line2[r];
    ++r;
  }
  return result;
}
