#ifndef EXTENDSTRING_H
#define EXTENDSTRING_H
#include <cstddef>
#include <cctype>
#include <iostream>
namespace strelyaev
{
  char * extendString(std::istream &);
  int checkRepDgt(char *);
}
#endif
