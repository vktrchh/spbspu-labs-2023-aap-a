#ifndef ARRAYINPUT_H
#define ARRAYINPUT_H
#include <cstddef>

namespace strelyaev
{
  void moveArray(const char * old_array, size_t old_array_size, char * new_array);
  char * inputArray(char * old_array, size_t old_array_size, size_t * current_array_size);
}
#endif
