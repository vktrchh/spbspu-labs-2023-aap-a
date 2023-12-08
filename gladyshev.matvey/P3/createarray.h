#ifndef CREATEARRAY_H
#define CREATEARRAY_H

#include <cstddef>

namespace gladyshev
{
  char * createFinalArray(const char * start, char * finish, size_t len, const char * vowels, const int vowelSize);
}

#endif
