#ifndef STRINGMANIPULATIONS_HPP
#define STRINGMANIPULATIONS_HPP

#include <cstddef>

namespace isaychev
{
  int checkString(const char * string, const char * strForCheck);
  size_t countWSpaces(const char * str);
  void skipParameter(char * str);
  void parseParams(char * str, const size_t numOfParameters, double * parameters);
  void copyString(const char * str, char * str2, size_t len);
}

#endif
