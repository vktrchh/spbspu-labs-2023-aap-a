#ifndef EXTRACTCHARS_HPP
#define EXTRACTCHARS_HPP

#include <cstddef>

namespace isaychev
{
  void extractChars(const char * str_base, const char * str_sec, char * wk_str);
  size_t checkForSameElem(const char * str2, char charForCheck);
}

#endif
